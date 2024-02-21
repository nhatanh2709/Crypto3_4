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
using CryptoPP::HexDecoder;
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
int check_file_extension(string filename)
{
    string extension = filename.substr(filename.find_last_of(".") + 1);
    if (extension == "pem") return 2;
    else return 1;
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


double DecryptionBerBase64(const char* PrivateFile, const char* CipherFile, const char* DecryptionFile,int type)
{
    string cipher, decoded ,recovered;
    if (type == 2)cipher = CipherFile;
    else  cipher = GetString(CipherFile);
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    DecodePrivateKey(PrivateFile, privateKey);
    RSAES_OAEP_SHA_Decryptor d(privateKey);
    StringSource(cipher, true, new Base64Decoder(new StringSink(decoded)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; i++)
    {
        recovered.clear();
        StringSource(decoded, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 100.0;
    StringSource(recovered, true, new FileSink(DecryptionFile));
    return averageTime;
}
double DecryptionBerHex(const char* PrivateFile, const char* CipherFile, const char* DecryptionFile, int type)
{
    string cipher, decoded, recovered;
    if (type == 2)cipher = CipherFile;
    else  cipher = GetString(CipherFile);
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    DecodePrivateKey(PrivateFile, privateKey);
    RSAES_OAEP_SHA_Decryptor d(privateKey);
    StringSource(cipher, true, new HexDecoder(new StringSink(decoded)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; i++)
    {
        recovered.clear();
        StringSource(decoded, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 100.0;
    StringSource(recovered, true, new FileSink(DecryptionFile));
    return averageTime;
}
double DecryptionPemBase64(const char* PrivateFile, const char* CipherFile, const char* DecryptionFile,int type)
{
    string cipher, decoded, recovered;
    if (type == 2)cipher = CipherFile; 
    else cipher = GetString(PrivateFile);
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    FileSink FilePrivate(PrivateFile, true);
    PEM_Load(FilePrivate, privateKey);
    RSAES_OAEP_SHA_Decryptor d(privateKey);
    StringSource(cipher, true, new Base64Decoder(new StringSink(decoded)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; i++)
    {
        recovered.clear();
        StringSource(decoded, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 100.0;
    StringSource(recovered, true, new FileSink(DecryptionFile));
    return averageTime;
}
double DecryptionPemHex(const char* PrivateFile, const char* CipherFile, const char* DecryptionFile, int type)
{
    string cipher, decoded, recovered;
    if (type == 2)cipher = CipherFile;
    else cipher = GetString(PrivateFile);
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    FileSink FilePrivate(PrivateFile, true);
    PEM_Load(FilePrivate, privateKey);
    RSAES_OAEP_SHA_Decryptor d(privateKey);
    StringSource(cipher, true, new HexDecoder(new StringSink(decoded)));
    auto BeginTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; i++)
    {
        recovered.clear();
        StringSource(decoded, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));
    }
    auto EndTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
    double averageTime = static_cast<double>(duration) / 100.0;
    StringSource(recovered, true, new FileSink(DecryptionFile));
    return averageTime;
}
extern "C" {
    __declspec(dllexport) double Decrypt(const char* CipherFile, const char* PrivateFile, const char* DecryptionFile, int choosen,int Form);
}
double Decrypt(const char* CipherFile, const char* PrivateFile, const char* DecryptionFile, int choosen,int Form)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int type = filePath(PrivateFile);
    switch (Form)
    {
    case 1:
    {
        switch (type)
        {
        case 1:
        {
            double Time = DecryptionBerBase64(PrivateFile, CipherFile, DecryptionFile, choosen);
            return Time;
            break;
        }
        case 2:
        {
            double Time = DecryptionPemBase64(PrivateFile, CipherFile, DecryptionFile, choosen);
            return Time;
            break;
        }
        default:
            return -1;
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
            double Time = DecryptionBerHex(PrivateFile, CipherFile, DecryptionFile, choosen);
            return Time;
            break;
        }
        case 2:
        {
            double Time = DecryptionPemHex(PrivateFile, CipherFile, DecryptionFile, choosen);
            return Time;
            break;
        }
        default:
            return -1;
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