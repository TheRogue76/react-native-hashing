#include "react-native-hashing.h"

using namespace facebook;
using namespace std;

namespace RNHashing {
    void installHashing(jsi::Runtime &rt) {
        auto sha256 = jsi::Function::createFromHostFunction(rt,
                                                            jsi::PropNameID::forAscii(rt, "sha256"),
                                                            1,
                                                            [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
            if (count == 0 || count > 1) {
                jsi::detail::throwJSError(rt, "sha256 requires one arguement");
                return jsi::Value::undefined();
            }
            if (!args[0].isString()) {
                jsi::detail::throwJSError(rt, "arguement for sha256 needs to be of type string");
                return jsi::Value::undefined();
            }
            string input = args[0].asString(rt).utf8(rt);
            return jsi::Value(rt, jsi::String::createFromUtf8(rt, sha256Convertor(input)));
        }
                                );
        auto md5 = jsi::Function::createFromHostFunction(rt,
                                                            jsi::PropNameID::forAscii(rt, "md5"),
                                                            1,
                                                            [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
            if (count == 0 || count > 1) {
                jsi::detail::throwJSError(rt, "md5 requires one arguement");
                return jsi::Value::undefined();
            }
            if (!args[0].isString()) {
                jsi::detail::throwJSError(rt, "arguement for md5 needs to be of type string");
                return jsi::Value::undefined();
            }
            string input = args[0].asString(rt).utf8(rt);
            return jsi::Value(rt, jsi::String::createFromUtf8(rt, md5Convertor(input)));
        }
                                                                 );
        auto sha1 = jsi::Function::createFromHostFunction(rt,
                                                            jsi::PropNameID::forAscii(rt, "sha1"),
                                                            1,
                                                            [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
            if (count == 0 || count > 1) {
                jsi::detail::throwJSError(rt, "sha1 requires one arguement");
                return jsi::Value::undefined();
            }
            if (!args[0].isString()) {
                jsi::detail::throwJSError(rt, "arguement for sha1 needs to be of type string");
                return jsi::Value::undefined();
            }
            string input = args[0].asString(rt).utf8(rt);
            return jsi::Value(rt, jsi::String::createFromUtf8(rt, sha1Convertor(input)));
        }
                                                                 );
        auto sha3 = jsi::Function::createFromHostFunction(rt,
                                                            jsi::PropNameID::forAscii(rt, "sha3"),
                                                            1,
                                                            [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
            if (count == 0 || count > 1) {
                jsi::detail::throwJSError(rt, "sha3 requires one arguement");
                return jsi::Value::undefined();
            }
            if (!args[0].isString()) {
                jsi::detail::throwJSError(rt, "arguement for sha3 needs to be of type string");
                return jsi::Value::undefined();
            }
            string input = args[0].asString(rt).utf8(rt);
            return jsi::Value(rt, jsi::String::createFromUtf8(rt, sha3Convertor(input)));
        }
                                                                 );
        jsi::Object module = jsi::Object(rt);
        module.setProperty(rt, "sha256", move(sha256));
        module.setProperty(rt, "md5", move(md5));
        module.setProperty(rt, "sha1", move(sha1));
        module.setProperty(rt, "sha3", move(sha3));
        rt.global().setProperty(rt, "RNHashing", move(module));
    }
    void cleanUpHashing() {
        
    }
}
