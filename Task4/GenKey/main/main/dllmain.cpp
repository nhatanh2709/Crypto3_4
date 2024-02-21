#include <iostream>
#include <sstream>
#include <string>


#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "cryptoPP/osrng.h"
#include "cryptopp/pem.h"
#include "cryptopp/pem_common.h"
#include "cryptopp/filters.h"
// using CryptoPP::AutoSeededX917RNG;
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/sha.h"
using CryptoPP::SHA1;

#include "Cryptopp/filters.h"
#include <assert.h>
#include "cryptopp/base64.h"
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::ArraySink;
using CryptoPP::SignerFilter;
using CryptoPP::SignatureVerificationFilter;
using CryptoPP::Base64Decoder;
using CryptoPP::Base64Encoder;
#include "cryptoPP/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::DL_GroupParameters_EC;


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::wstring;
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
/* Chuyển đổi string <--> utf8*/
#include <locale>
using std::wstring_convert;
#include <codecvt>
using std::codecvt_utf8;
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
#include "cryptopp/oids.h"
using CryptoPP::OID;
using CryptoPP::byte;

wstring string_to_wstring(const string& str)
{
    wstring_convert<codecvt_utf8<wchar_t>> towstring;
    return towstring.from_bytes(str);
}

string wstring_to_string(const wstring& str)
{
    wstring_convert<codecvt_utf8<wchar_t>> tostring;
    return tostring.to_bytes(str);
}
string GetString(string fileName)
{
    string output;
    ifstream file;
    file.open(fileName);
    output.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return output;
}
void OutputString(string text)
{
    string FileName;
    cout << "Enter FileName:";
    cin.ignore();
    cin >> FileName;
    StringSource(text, true, new FileSink(FileName.data()));
}

void GeneratePrivateKey(const OID& oid, ECDSA<ECP, SHA1>::PrivateKey& key)
{
    AutoSeededRandomPool prng;
    key.Initialize(prng, oid);
}
void GeneratePublicKey(const ECDSA<ECP, SHA1>::PrivateKey& privateKey, ECDSA<ECP, SHA1>::PublicKey& publicKey)
{
    AutoSeededRandomPool prng;
    assert(privateKey.Validate(prng, 3));
    privateKey.MakePublicKey(publicKey);

}
void EncodePrivateKeyBer(const string& filename, const ECDSA<ECP, SHA1>::PrivateKey& key)
{
    key.Save(FileSink(filename.c_str(), true).Ref());
}
void EncodePublicKeyBer(const string& filename, const ECDSA<ECP, SHA1>::PublicKey& key)
{
    key.Save(FileSink(filename.c_str(), true).Ref());
}

void genKeyBer(const char* PrivateFile, const char* PublicFile)
{
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    ECDSA<ECP, SHA1>::PublicKey publicKey;
    GeneratePrivateKey(CryptoPP::ASN1::secp256k1(), privateKey);
    GeneratePublicKey(privateKey, publicKey);
    EncodePrivateKeyBer(PrivateFile, privateKey);
    EncodePublicKeyBer(PublicFile, publicKey);
}


void genKeyPem(const char* PrivateFile, const char* PublicFile)
{
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    ECDSA<ECP, SHA1>::PublicKey publicKey;
    GeneratePrivateKey(CryptoPP::ASN1::secp256k1(), privateKey);
    GeneratePublicKey(privateKey, publicKey);
    FileSink FilePrivate(PrivateFile, true);
    PEM_Save(FilePrivate, privateKey);
    FileSink FilePublic(PublicFile, true);
    PEM_Save(FilePublic, publicKey);
}
extern "C" {
    __declspec(dllexport) bool genKey(const char* PrivateFile, const char* PublicFile, int choosen);
}
bool genKey(const char* PrivateFile, const char* PublicFile, int choosen)
{
    switch (choosen)
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
