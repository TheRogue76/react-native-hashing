#include <jni.h>
#include "react-native-hashing.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativehashing_HashingModule_initialize(JNIEnv *env, jclass clazz, jlong jsiPtr) {
    RNHashing::installHashing(*reinterpret_cast<facebook::jsi::Runtime *>(jsiPtr));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativehashing_HashingModule_destruct(JNIEnv *env, jclass clazz) {
    RNHashing::cleanUpHashing();
}
