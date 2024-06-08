#include <napi.h>
#include "CryptoLib.h"

Napi::String GeneratePrimeNumber(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    long prime = CryptoLib::generatePrimeNumber();
    return Napi::String::New(env, std::to_string(prime));
}

Napi::String EncryptAES(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string message = info[0].As<Napi::String>().Utf8Value();
    long key = std::stol(info[1].As<Napi::String>().Utf8Value());
    std::string encrypted = CryptoLib::encryptAES(message, key);
    return Napi::String::New(env, encrypted);
}

Napi::String DecryptAES(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string cipher = info[0].As<Napi::String>().Utf8Value();
    long key = std::stol(info[1].As<Napi::String>().Utf8Value());
    std::string decrypted = CryptoLib::decryptAES(cipher, key);
    return Napi::String::New(env, decrypted);
}

Napi::String HashFunction(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string message = info[0].As<Napi::String>().Utf8Value();
    std::string hash = CryptoLib::hashFunction(message);
    return Napi::String::New(env, hash);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "generatePrimeNumber"), Napi::Function::New(env, GeneratePrimeNumber));
    exports.Set(Napi::String::New(env, "encryptAES"), Napi::Function::New(env, EncryptAES));
    exports.Set(Napi::String::New(env, "decryptAES"), Napi::Function::New(env, DecryptAES));
    exports.Set(Napi::String::New(env, "hashFunction"), Napi::Function::New(env, HashFunction));
    return exports;
}

NODE_API_MODULE(cryptolib, Init)
