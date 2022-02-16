cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

# Specifies a path to native header files.
include_directories(
            ../cpp
            "${NODE_MODULES_DIR}/react-native/React"
            "${NODE_MODULES_DIR}/react-native/React/Base"
            "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
)

add_library(hashing
            SHARED
            "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp"
            ../cpp/react-native-hashing.cpp
            ../cpp/react-native-hashing.h
            ../cpp/hash-library/*.cpp
            ../cpp/hash-library/*.h
            cpp-adapter.cpp
)
target_link_libraries(hashing)
