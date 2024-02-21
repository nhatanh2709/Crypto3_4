#ifdef _WIN32
#include <windows.h>
#endif
// Cryptopp library
#include "cryptopp/rsa.h"
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSA;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;

#include "cryptopp/sha.h"
using CryptoPP::SHA1;
using CryptoPP::SHA256;

#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/hex.h"
using CryptoPP::HexDecoder;
using CryptoPP::HexEncoder;

#include "cryptopp/base64.h"
using CryptoPP::Base64Decoder;
using CryptoPP::Base64Encoder;

#include "cryptopp/filters.h"
using CryptoPP::PK_DecryptorFilter;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/files.h"
using CryptoPP::ArraySink;
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/cryptlib.h"
using CryptoPP::BufferedTransformation;
using CryptoPP::DecodingResult;
using CryptoPP::Exception;
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;

#include <string>
using std::string;

#include <exception>
using std::exception;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::ostringstream;

#include <assert.h>
#include <fstream>
using std::ifstream;

using namespace std;



void Encode(const string& filename, const BufferedTransformation& bt);     // hàm lưu xuống file
void Decode(const string& filename, BufferedTransformation& bt);           // hàm load file lên
void EncodePublicKey(const string& filename, const RSA::PublicKey& key);   // encode public key in binary format
void EncodePrivateKey(const string& filename, const RSA::PrivateKey& key); // encode private key in binary format
void DecodePublicKey(const string& filename, RSA::PublicKey& key);         // decode public key in binary format
void DecodePrivateKey(const string& filename, RSA::PrivateKey& key);       // decode private key in binary format
void EncodeBase64PrivateKey(const string& filename, RSA::PrivateKey& key);
void EncodeBase64PublicKey(const string& filename, RSA::PublicKey& key);
void DecodeBase64PrivateKey(const string& filename, RSA::PrivateKey& key);
void DecodeBase64PublicKey(const string& filename, RSA::PublicKey& key);

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
#ifdef _linux_
    std::locale::global(std::locale("C.UTF-8"));
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
        EncodePrivateKey(PrivateFile, privateKey);
        EncodePublicKey(PublicFile, publicKey);
        break;
    }
    case 2:
    {
        string PublicFile;
        cout << "Enter Public File Name\n";
        cin >> PublicFile;
        string plain = GetInput();
        int form;
        cout << "Enter the Type\n"
             <<" 1.Base64\n"
             <<" 2.Hex\n"
             <<" Enter the option: ";
        cin>> form;  
        string cipher,data;
        RSA::PublicKey publicKey;
        AutoSeededRandomPool rng;
        DecodePublicKey(PublicFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        StringSource(plain, true,new PK_EncryptorFilter(rng, e,new StringSink(cipher)));
        switch(form)
        {
            case 1:
            {
                auto BeginTime = std::chrono::high_resolution_clock::now();
                for (int i = 1; i <= 1000; i++)
                {
                    data.clear();
                    StringSource(cipher, true, new Base64Encoder(new StringSink(data)));
                    
                }
                auto EndTime = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
                double averageTime = static_cast<double>(duration) / 1000.0;
                OutputCipher(data);
                cout << "Operation Time : " << averageTime ;
                break;
            }
            case 2:
            {
                auto BeginTime = std::chrono::high_resolution_clock::now();
                for (int i = 1; i <= 1000; i++)
                {
                    data.clear();
                    StringSource(cipher, true, new HexEncoder(new StringSink(data)));
                }
                auto EndTime = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - BeginTime).count();
                double averageTime = static_cast<double>(duration) / 1000.0;
                OutputCipher(data);
                cout << "Operation Time : " << averageTime ;
                break;
            }
        }
        
        break;
    }
    case 3:
    {
        string PrivateFile;
        cout << " Enter Private File Name\n";
        cin >> PrivateFile;
        string cipher, decoded, recovered;
        cipher = GetInput();
        int form;
        cout << "Enter the Type\n"
             <<" 1.Base64\n"
             <<" 2.Hex\n"
             <<" Enter the option: ";
        cin>> form;
        AutoSeededRandomPool rng;
        RSA::PrivateKey privateKey;
        DecodePrivateKey(PrivateFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        switch(form)
        {
            case 1:
            {
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
                OutputRecovered(recovered);
                cout << "Operation Time : " << averageTime ;
                break;
            }
            case 2:
            {
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
                OutputRecovered(recovered);
                cout << "Operation Time : " << averageTime ;
                break;
            }
        }
        break;
    }
    default:
        break;
    }
}

/* convert integer to string */
string integer_to_string(const CryptoPP::Integer& t)
{
    std::ostringstream oss;
    oss.str("");
    oss.clear();
    oss << t;
    std::string encoded(oss.str());
    return encoded;
}

void Encode(const string& filename, const BufferedTransformation& bt)
{
    FileSink file(filename.c_str());

    bt.CopyTo(file);
    file.MessageEnd();
}

void Decode(const string& filename, BufferedTransformation& bt)
{
    // http://www.cryptopp.com/docs/ref/class_file_source.html
    FileSource file(filename.c_str(), true);

    file.TransferTo(bt);
    bt.MessageEnd();
}


void EncodePublicKey(const string& filename, const RSA::PublicKey& key)
{
    ByteQueue queue;
    key.DEREncodePublicKey(queue);

    Encode(filename, queue);
}

void EncodePrivateKey(const string& filename, const RSA::PrivateKey& key)
{
    ByteQueue queue;
    key.DEREncodePrivateKey(queue);

    Encode(filename, queue);
}

void DecodePrivateKey(const string& filename, RSA::PrivateKey& key)
{
    ByteQueue queue;

    Decode(filename, queue);
    key.BERDecodePrivateKey(queue, false /*optParams*/, queue.MaxRetrievable());
}

void DecodePublicKey(const string& filename, RSA::PublicKey& key)
{
    ByteQueue queue;

    Decode(filename, queue);
    key.BERDecodePublicKey(queue, false /*optParams*/, queue.MaxRetrievable());
}
