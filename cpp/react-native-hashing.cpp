#include "react-native-hashing.h"
#include "sha256.h"

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
                return {};
            }
            if (!args[0].isString()) {
                jsi::detail::throwJSError(rt, "arguement for sha256 needs to be of type string");
                return {};
            }
            string input = args[0].asString(rt).utf8(rt);
            SHA256 converter;
            return jsi::Value(rt, jsi::String::createFromUtf8(rt, converter(input)));
        }
                        );
        jsi::Object module = jsi::Object(rt);
        module.setProperty(rt, "sha256", move(sha256));
        rt.global().setProperty(rt, "RNHashing", move(module));
    }
    void cleanUpHashing() {
        
    }
}
