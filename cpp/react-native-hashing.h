#ifndef react_native_hashing_h
#define react_native_hashing_h

#include <jsi/jsilib.h>
#include <jsi/jsi.h>
#include "hash-library/sha256.h"
#include "hash-library/md5.h"
#include "hash-library/sha1.h"
#include "hash-library/sha3.h"
#include <map>


using namespace std;

namespace RNHashing {
    enum HashTypes { sha256, md5, sha1, sha3 };
    static HashTypes hTypes;
    static SHA256 sha256Convertor;
    static MD5 md5Convertor;
    static SHA1 sha1Convertor;
    static SHA3 sha3Convertor;
    void installHashing(facebook::jsi::Runtime &rt);
    void cleanUpHashing();
}

#endif /* react_native_hashing_h */
