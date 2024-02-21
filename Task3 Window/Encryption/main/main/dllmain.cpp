#include <iostream>
#include <sstream>
#include <string>

/* Thư viện CryptoPP */
#include "cryptopp/rsa.h"
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSA;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
#include "cryptopp/base64.h"
using CryptoPP::Base64Decoder;
using CryptoPP::Base64Encoder;
#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
#include "cryptopp/sha.h"
using CryptoPP::SHA1;
#include "cryptopp/pem.h"
#include "cryptopp/pem_common.h"
#include "cryptopp/filters.h"
using CryptoPP::PK_DecryptorFilter;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;
#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/SecBlock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/cryptlib.h"
using CryptoPP::DecodingResult;
using CryptoPP::Exception;

#include <string>
using std::string;

#include <exception>
using std::exception;

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
void Encode(const char* filename, const CryptoPP::BufferedTransformation& bt);
void Decode(const char* filename, CryptoPP::BufferedTransformation& bt);
void EncodePublicKey(const char* filename, const RSA::PublicKey& key);
void EncodePrivateKey(const char* filename, const RSA::PrivateKey& key);
void DecodePublicKey(const char* filename, RSA::PublicKey& key);
void DecodePrivateKey(const char* filename, RSA::PrivateKey& key);
using CryptoPP::byte;
string GetString(const char* fileName)
{
    string output;
    ifstream file;
    file.open(fileName);
    output.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return output;
}
int filePath(const std::string& path)
{
    std::string extension = path.substr(path.find_last_of(".") + 1);
    if (extension == "ber")
    {
        return 1;
    }
    else return 2;
}

double EncryptionBerBase64(const char* PublicFile,const char* PlainFile,const char* EncrytionFile,int type)
{
    string plain;
    if (type == 2) plain = PlainFile;
    else plain = GetString(PlainFile);
    string cipher,data;
    RSA::PublicKey publicKey;
    AutoSeededRandomPool rng;
    DecodePublicKey(PublicFile, publicKey);
    RSAES_OAEP_SHA_Encryptor e(publicKey);
    StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++)
    {
        data.clear();
        StringSource(cipher, true, new Base64Encoder(new StringSink(data)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 1000.0;
    StringSource(data, true, new FileSink(EncrytionFile));
    return averageTime;
}
double EncryptionBerHex(const char* PublicFile, const char* PlainFile, const char* EncrytionFile, int type)
{
    string plain;
    if (type == 2) plain = PlainFile;
    else plain = GetString(PlainFile);
    string cipher, data;
    RSA::PublicKey publicKey;
    AutoSeededRandomPool rng;
    DecodePublicKey(PublicFile, publicKey);
    RSAES_OAEP_SHA_Encryptor e(publicKey);
    StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++)
    {
        data.clear();
        StringSource(cipher, true, new HexEncoder(new StringSink(data)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 1000.0;
    StringSource(data, true, new FileSink(EncrytionFile));
    return averageTime;
}

double EncryptionPemBase64(const char* PublicFile, const char* PlainFile, const char* EncrytionFile,int type)
{
    string plain;
    if (type == 2) plain = PlainFile;
    else plain = GetString(PlainFile);
    string cipher, data;
    AutoSeededRandomPool rng;
    RSA::PublicKey publicKey;
    FileSink FilePublic(PublicFile, true);
    PEM_Load(FilePublic, publicKey);
    RSAES_OAEP_SHA_Encryptor e(publicKey);
    StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++)
    {
        data.clear();
        StringSource(cipher, true, new Base64Encoder(new StringSink(data)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 1000.0;
    StringSource(data, true, new FileSink(EncrytionFile));
    return averageTime;
}
double EncryptionPemHex(const char* PublicFile, const char* PlainFile, const char* EncrytionFile, int type)
{
    string plain;
    if (type == 2) plain = PlainFile;
    else plain = GetString(PlainFile);
    string cipher, data;
    AutoSeededRandomPool rng;
    RSA::PublicKey publicKey;
    FileSink FilePublic(PublicFile, true);
    PEM_Load(FilePublic, publicKey);
    RSAES_OAEP_SHA_Encryptor e(publicKey);
    StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++)
    {
        data.clear();
        StringSource(cipher, true, new HexEncoder(new StringSink(data)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 1000.0;
    StringSource(data, true, new FileSink(EncrytionFile));
    return averageTime;
}
extern "C" {
    __declspec(dllexport) double Encryption(const char* datafile, const char* PublicFile, const char* EncryptionFile, int choosen,int Form);
}
double Encryption(const char* datafile, const char* PublicFile, const char* EncryptionFile, int choosen,int Form)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int type = filePath(PublicFile);
    switch (Form)
    {
    case 1:
    {
        switch (type)
        {
        case 1:
        {
            double Time = EncryptionBerBase64(PublicFile, datafile, EncryptionFile, choosen);
            return Time;
            break;
        }
        case 2:
        {
            double Time = EncryptionPemBase64(PublicFile, datafile, EncryptionFile, choosen);
            return Time;
            break;
        }
        default:
            return (double)-1;
            break;
        }
        break;
    }
    case 2:
    {
        switch (type)
        {
        case 1:
        {
            double Time = EncryptionBerHex(PublicFile, datafile, EncryptionFile, choosen);
            return Time;
            break;
        }
        case 2:
        {
            double Time = EncryptionPemHex(PublicFile, datafile, EncryptionFile, choosen);
            return Time;
            break;
        }
        default:
            return (double)-1;
            break;
        }
        break;
    }
    default:
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