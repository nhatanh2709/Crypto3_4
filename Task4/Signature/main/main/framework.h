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
int check_file_extension(string filename)
{
    string extension = filename.substr(filename.find_last_of(".") + 1);
    if (extension == "pem") return 2;
    else return 1;
}

void DecodePrivateKey(const string& filename, ECDSA<ECP, SHA1>::PrivateKey& key)
{
    key.Load(FileSource(filename.c_str(), true).Ref());
}
bool SignMessage(const ECDSA<ECP, SHA1>::PrivateKey& key, const string& message, string& signature)
{
    AutoSeededRandomPool prng;
    signature.erase();
    StringSource(message, true,
        new SignerFilter(prng,
            ECDSA<ECP, SHA1>::Signer(key),
            new StringSink(signature)
        )
    );
    string encoded;
    StringSource(signature, true,
        new Base64Encoder(
            new StringSink(encoded)
        )
    );
    signature = encoded;
    return !signature.empty();
}
void SignatureBer(const char* PrivateFile, const char* MessFile,const char* SignatureFile,int choosen)
{
    string message;
    if (choosen == 1) message = GetString(MessFile);
    else message = MessFile;
    string signature;
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    DecodePrivateKey(PrivateFile, privateKey);
    SignMessage(privateKey, message, signature);
    StringSource(signature, true, new FileSink(SignatureFile));
}
void SignaturePem(const char* PrivateFile, const char* MessFile, const char* SignatureFile,int choosen)
{
    string message;
    if (choosen == 1) message = GetString(MessFile);
    else message = MessFile;
    string signature;
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    FileSink FilePrivate(PrivateFile, true);
    PEM_Load(FilePrivate, privateKey);
    SignMessage(privateKey, message, signature);
    StringSource(signature, true, new FileSink(SignatureFile));
}
extern "C" {
    __declspec(dllexport) bool Sign(const char* MessFile, const char* PrivateFile, const char* SignatureFile, int choosen);
}
bool Sign(const char* MessFile, const char* PrivateFile, const char* SignatureFile, int choosen)
{
    int type;
    type = check_file_extension(PrivateFile);
    switch (type)
    {
    case 1:
    {
        SignatureBer(PrivateFile, MessFile, SignatureFile,choosen);
        return true;
        break;
    }
    case 2:
    {
        SignaturePem(PrivateFile, MessFile, SignatureFile,choosen);
        return true;
        break;
    }
    return false;
    break;
    }
}

