#ifndef react_native_hashing_h
#define react_native_hashing_h

#include <jsi/jsilib.h>
#include <jsi/jsi.h>


namespace RNHashing {
    void installHashing(facebook::jsi::Runtime &rt);
    void cleanUpHashing();
}

#endif /* react_native_hashing_h */
