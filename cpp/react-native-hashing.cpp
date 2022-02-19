#include "react-native-hashing.h"

using namespace facebook;
using namespace std;

namespace RNHashing {
    string hashValue(const string &input, const HashTypes type) {
        string result = {};
        if (type == sha256) {
            result = sha256Convertor(input);
        }
        
        if (type == md5) {
            result = md5Convertor(input);
        }
        
        if (type == sha1) {
            result = sha1Convertor(input);
        }
        
        if (type == sha3) {
            result = sha3Convertor(input);
        }
        return result;
    }

    string nameFromType(const HashTypes type) {
        string result = {};
        if (type == sha256) {
            result = "sha256";
        }
        
        if (type == md5) {
            result = "md5";
        }
        
        if (type == sha1) {
            result = "sha1";
        }
        
        if (type == sha3) {
            result = "sha3";
        }
        return result;
    }
    
    void installHashing(jsi::Runtime &rt) {
        jsi::Object module = jsi::Object(rt);
        for (int i = sha256; i <= sha3; i++) {
            auto hashFunction = jsi::Function::createFromHostFunction(rt,
                                                                      jsi::PropNameID::forAscii(rt, nameFromType(HashTypes(i))),
                                                                      1,
                                                                      [&i](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
                string argCountError = nameFromType(HashTypes(i)) + " requires one arguement";
                string argTypeError = "arguement for " + nameFromType(HashTypes(i)) + " needs to be of type string";
                if (count == 0 || count > 1) {
                      jsi::detail::throwJSError(rt, argCountError.c_str());
                      return jsi::Value::undefined();
                }
                if (!args[0].isString()) {
                     jsi::detail::throwJSError(rt, argTypeError.c_str());
                     return jsi::Value::undefined();
                }
                string input = args[0].asString(rt).utf8(rt);
                return jsi::Value(rt, jsi::String::createFromUtf8(rt, hashValue(input, HashTypes(i))));
                }
            );
            module.setProperty(rt, nameFromType(HashTypes(i)).c_str(), move(hashFunction));
        }
        rt.global().setProperty(rt, "RNHashing", move(module));
    }
    void cleanUpHashing() {
        
    }
}
