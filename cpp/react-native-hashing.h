#ifndef react_native_hashing_h
#define react_native_hashing_h

#include <jsi/jsilib.h>
#include <jsi/jsi.h>
#include "hash-library/sha256.h"
#include "hash-library/md5.h"


namespace RNHashing {
    static SHA256 shaConvertor;
    static MD5 md5Convertor;
    void installHashing(facebook::jsi::Runtime &rt);
    void cleanUpHashing();
}

#endif /* react_native_hashing_h */
