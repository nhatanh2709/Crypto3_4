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
void Encode(const string& filename, const CryptoPP::BufferedTransformation& bt);
void EncodeBase64PrivateKey(const string& filename, const CryptoPP::PrivateKey& key);
void EncodeBase64PublicKey(const string& filename, const CryptoPP::PublicKey& key);
void DecodeBase64(const string& filename, CryptoPP::BufferedTransformation& bt);
void DecodeBase64PublicKey(const string& filename, CryptoPP::PublicKey& key);
void DecodeBase64PrivateKey(const string& filename, CryptoPP::PrivateKey& key);
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

string GetInput()
{
    int choosen;
    cout << " How to get input:\n"
        << " 1.From screen:\n"
        << " 2.From File:\n"
        << " Enter the option: ";
    cin >> choosen;
    string input;
    switch (choosen)
    {
    case 1:
    {
        cout << "Please enter input: ";
        getline(cin, input);
        cin.ignore();
        return input;
        break;
    }
    case 2:
    {
        string filename;
        cout << "Please enter filename: ";
        cin >> filename;

        string input = GetString(filename);
        return input;
        break;
    }
    default:
        break;
    }
    return "";
}
void OutputCipher(string output)
{
    int Show;
    cout << " How to display output :\n"
        << " 1.To screen:\n"
        << " 2.To File:\n"
        << " Enter the option: ";
    cin >> Show;
    switch (Show)
    {
    case 1:
    {
        cout << "cipher: " << output << endl;
        break;
    }
    case 2:
    {
        OutputString(output);
        break;
    }
    default:
        break;
    }
}
void OutputRecovered(string output)
{
    int Show;
    cout << " Choosen one option :\n"
        << " 1.To screen:\n"
        << " 2.To File:\n"
        << " Enter the option: ";
    cin >> Show;
    switch (Show)
    {
    case 1:
    {
        cout << "Recoverd: " << output << endl;
        break;
    }
    case 2:
    {
        OutputString(output);
        break;
    }
    default:
        break;
    }
}
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    cout << "Choosen option:\n"
        << "1.Enter data:\n"
        << "2.Encode:\n"
        << "3.Decode:\n"
        << "would you like to do (1/2/3): ";
    int Choosen;
    cin >> Choosen;
    cin.ignore();
    switch (Choosen)
    {
    case 1:
    {
        string PrivateFile, PublicFile;
        cout << "Enter private key file: ";
        cin >> PrivateFile;
        cout << "Enter public key file: ";
        cin >> PublicFile;
        AutoSeededRandomPool rng;
        InvertibleRSAFunction parameters;
        parameters.GenerateRandomWithKeySize(rng, 3072);
        RSA::PrivateKey privateKey(parameters);
        RSA::PublicKey publicKey(parameters);
        EncodeBase64PrivateKey(PrivateFile, privateKey);
        EncodeBase64PublicKey(PublicFile, publicKey);
        break;
    }
    case 2:
    {
        string PublicFile;
        cout << "Enter Public File Name\n";
        cin >> PublicFile;
        string plain = GetInput();
        string cipher, data;
        RSA::PublicKey publicKey;
        AutoSeededRandomPool rng;
        DecodeBase64PublicKey(PublicFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        auto BeginTime = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 1000; i++)
        {
            cipher.clear();
            StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
        }
        auto EndTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
        double averageTime = static_cast<double>(duration) / 1000.0;
        cout << "Time: " << averageTime << " ms" << std::endl;
        StringSource(cipher, true, new Base64Encoder(new StringSink(data)));
        OutputCipher(data);
        break;
    }
    case 3:
    {
        string PrivateFile;
        cout << " Enter Private File Name\n";
        cin >> PrivateFile;
        string cipher, decoded, recorvered;
        cipher = GetInput();
        AutoSeededRandomPool rng;
        RSA::PrivateKey privateKey;
        DecodeBase64PrivateKey(PrivateFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        StringSource(cipher, true, new Base64Decoder(new StringSink(decoded)));
        auto BeginTime = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 1000; i++)
        {
            recorvered.clear();
            StringSource(decoded, true, new PK_DecryptorFilter(rng, d, new StringSink(recorvered)));
        }
        auto EndTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
        double averageTime = static_cast<double>(duration) / 1000.0;
        cout << "Time: " << averageTime << " ms" << std::endl;
        OutputRecovered(recorvered);
        break;
    }
    default:
        break;
    }
}
void Encode(const string& filename, const CryptoPP::BufferedTransformation& bt)
{
    FileSink file(filename.c_str());
    bt.CopyTo(file);
    file.MessageEnd();
}
void EncodeBase64PrivateKey(const string& filename, const CryptoPP::PrivateKey& key)
{
    ByteQueue queue;
    key.Save(queue);
    Base64Encoder encoder;
    queue.CopyTo(encoder);
    encoder.MessageEnd();
    Encode(filename, encoder);
}
void EncodeBase64PublicKey(const string& filename, const CryptoPP::PublicKey& key)
{
    ByteQueue queue;
    key.Save(queue);
    Base64Encoder encoder;
    queue.CopyTo(encoder);
    encoder.MessageEnd();
    Encode(filename, encoder);
}


void DecodeBase64(const string& filename, CryptoPP::BufferedTransformation& bt)
{
    FileSource file(filename.c_str(), true, new Base64Decoder);
    file.TransferTo(bt);
    bt.MessageEnd();
}
void DecodeBase64PublicKey(const string& filename, CryptoPP::PublicKey& key)
{
    ByteQueue queue;
    DecodeBase64(filename, queue);
    key.Load(queue);
}
void DecodeBase64PrivateKey(const string& filename, CryptoPP::PrivateKey& key)
{
    ByteQueue queue;
    DecodeBase64(filename, queue);
    key.Load(queue);
}
