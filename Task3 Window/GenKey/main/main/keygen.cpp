#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

//#include "cryptlib.h"
//using CryptoPP::Exception;
//using CryptoPP::DecodingResult;

// work with queue of byte
#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;
using CryptoPP::BufferedTransformation;
#include <string>
using std::string;

#include <exception>
using std::exception;
#include "cryptopp/pem.h"

//c++ library
#include <iostream>
#include <windows.h>

using std::cout;
using std::cerr;
using std::endl;
using namespace std;
// using namespace CryptoPP;
#include <assert.h>

// Def function
void Encode(const char* filename, const CryptoPP::BufferedTransformation& bt);
void Decode(const char* filename, CryptoPP::BufferedTransformation& bt);
void EncodePublicKey(const char* filename, const RSA::PublicKey& key);
void EncodePrivateKey(const char* filename, const RSA::PrivateKey& key);
void DecodePublicKey(const char* filename, RSA::PublicKey& key);
void DecodePrivateKey(const char* filename, RSA::PrivateKey& key);



void genKeyBer(const char* PrivateFile, const char* PublicFile)
{
    AutoSeededRandomPool rng;
    InvertibleRSAFunction parameters;
    parameters.GenerateRandomWithKeySize(rng, 3072);
    RSA::PrivateKey privateKey(parameters);
    RSA::PublicKey publicKey(parameters);
    EncodePrivateKey(PrivateFile, privateKey);
    EncodePublicKey(PublicFile, publicKey);


}

void genKeyPem(const char* PrivateFile, const char* PublicFile)
{
    AutoSeededRandomPool rng;
    InvertibleRSAFunction parameters;
    parameters.GenerateRandomWithKeySize(rng, 3072);
    RSA::PrivateKey privateKey(parameters);
    RSA::PublicKey publicKey(parameters);
    CryptoPP::FileSink FilePrivate(PrivateFile, true);
    CryptoPP::PEM_Save(FilePrivate, privateKey);
    CryptoPP::FileSink FilePublic(PublicFile, true);
    CryptoPP::PEM_Save(FilePublic, publicKey);
}
extern "C" {
    __declspec(dllexport) bool genKey(const char* PrivateFile, const char* PublicFile, int type);
}
bool genKey(const char* PrivateFile, const char* PublicFile, int type)
{
    switch (type)
    {
    case 1:
    {
        genKeyBer(PrivateFile, PublicFile);
        return true;
        break;
    }
    case 2:
    {
        genKeyPem(PrivateFile, PublicFile);
        return true;
        break;
    }
    default:
        return false;
        break;
    }
}
void Encode(const char* filename, const CryptoPP::BufferedTransformation& bt)
{
    FileSink file(filename);

    bt.CopyTo(file);
    file.MessageEnd();
}
void Decode(const char* filename, CryptoPP::BufferedTransformation& bt)
{
    FileSource file(filename, true /*pumpAll*/);

    file.TransferTo(bt);
    bt.MessageEnd();
}
void EncodePublicKey(const char* filename, const RSA::PublicKey& key)
{
    ByteQueue queue;
    key.DEREncodePublicKey(queue);

    Encode(filename, queue);
}
void EncodePrivateKey(const char* filename, const RSA::PrivateKey& key)
{
    ByteQueue queue;
    key.DEREncodePrivateKey(queue);

    Encode(filename, queue);
}
void DecodePrivateKey(const char* filename, RSA::PrivateKey& key)
{
    ByteQueue queue;

    Decode(filename, queue);
    key.BERDecodePrivateKey(queue, false /*optParams*/, queue.MaxRetrievable());
}

void DecodePublicKey(const char* filename, RSA::PublicKey& key)
{
    ByteQueue queue;

    Decode(filename, queue);
    key.BERDecodePublicKey(queue, false /*optParams*/, queue.MaxRetrievable());
}