#pragma once

#if defined(_WIN32)
#define BASE64_SYSTEM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#define BASE64_SYSTEM_IOS
#elif TARGET_OS_MAC
#define BASE64_SYSTEM_MACOS
#else
#error This Apple operating system is not supported by BASE64 library
#endif
#elif defined(__unix__)
#if defined(__ANDROID__)
#define BASE64_SYSTEM_ANDROID
#elif defined(__linux__)
#define BASE64_SYSTEM_LINUX
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define BASE64_SYSTEM_FREEBSD
#else
#error This UNIX operating system is not supported by BASE64 library
#endif
#else
#error This operating system is not supported by BASE64 library
#endif

#if !defined(BASE64_STATIC)
#if defined(BASE64_SYSTEM_WINDOWS)
#define BASE64_SYMBOL_EXPORT __declspec(dllexport)
#define BASE64_SYMBOL_IMPORT __declspec(dllimport)
#ifdef _MSC_VER
#pragma warning(disable : 4251)
#endif
#else // Linux, FreeBSD, Mac OS X
#if __GNUC__ >= 4
#define BASE64_SYMBOL_EXPORT __attribute__((__visibility__("default")))
#define BASE64_SYMBOL_IMPORT __attribute__((__visibility__("default")))
#else
#define BASE64_SYMBOL_EXPORT
#define BASE64_SYMBOL_IMPORT
#endif
#endif
#else
#define BASE64_SYMBOL_EXPORT
#define BASE64_SYMBOL_IMPORT
#endif

#if defined(BASE64_BUILDING_THE_LIB)
#define BASE64_API BASE64_SYMBOL_EXPORT
#else
#define BASE64_API BASE64_SYMBOL_IMPORT
#endif
