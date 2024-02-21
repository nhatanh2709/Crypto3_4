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
void DecodePublicKey(const string& filename, ECDSA<ECP, SHA1>::PublicKey& key)
{
    key.Load(FileSource(filename.c_str(), true).Ref());
}
bool VerifyMessage(const ECDSA<ECP, SHA1>::PublicKey& key, const string& message, const string& signature)
{
    bool result = false;
    StringSource(signature + message, true,
        new SignatureVerificationFilter(
            ECDSA<ECP, SHA1>::Verifier(key),
            new ArraySink((byte*)&result, sizeof(result))
        ) // SignatureVerificationFilter
    );
    return result;
}
void VerifyBer(const char* PublicFile, const char* MessFile, const char* SignatureFile, const char* VerifyFile)
{
    string message = GetString(MessFile);
    string signature = GetString(SignatureFile);
    string decoded;
    StringSource(signature, true, new Base64Decoder(new StringSink(decoded)));
    signature = decoded;
    ECDSA<ECP, SHA1>::PublicKey publicKey;
    DecodePublicKey(PublicFile, publicKey);
    bool check = VerifyMessage(publicKey, message, signature);
    string output = (check ? "Sucessfully" : "Failed");
    StringSource(output, true, new FileSink(VerifyFile));

}

void VerifyPem(const char* PublicFile, const char* MessFile, const char* SignatureFile, const char* VerifyFile)
{
    string message = GetString(MessFile);
    string signature =GetString(SignatureFile);
    ECDSA<ECP, SHA1>::PublicKey publicKey;
    FileSink FilePrivate(PublicFile, true);
    PEM_Load(FilePrivate, publicKey);
    bool check = VerifyMessage(publicKey, message, signature);
    string output = (check ? "Sucessfully" : "Failed");
    StringSource(output, true, new FileSink(VerifyFile));

}
extern "C" {
    __declspec(dllexport)  void Veri(const char* datafile, const char* PublicFile, const char* SignatureFile, const char* VerifyFile);
}
void Veri(const char* datafile, const char* PublicFile, const char* SignatureFile, const char* VerifyFile)
{
    int type = check_file_extension(PublicFile);
    switch (type)
    {
    case 1:
        VerifyBer(PublicFile, datafile, SignatureFile, VerifyFile);
    }
}
