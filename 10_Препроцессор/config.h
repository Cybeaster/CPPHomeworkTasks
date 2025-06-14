#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

// VERSION: major*10000 + minor*100 + patch
#define VERSION(major, minor, patch) \
(((major) * 10000) + ((minor) * 100) + (patch))

// Stringification
#define TOSTRING_INNER(x) #x
#define TOSTRING(x)        TOSTRING_INNER(x)

// LOG: только при DEBUG
#ifdef DEBUG
#define LOG(fmt, ...) \
do { \
std::fprintf(stderr, "[%s:%d] " fmt "\n", \
__FILE__, __LINE__, ##__VA_ARGS__); \
} while (0)
#else
#define LOG(fmt, ...) \
do { } while (0)
#endif

// ASSERT: проверка и abort
#define ASSERT(expr) \
do { \
if (!(expr)) { \
std::cerr << "Assertion failed: " #expr \
<< ", file " << __FILE__ \
<< ", line " << __LINE__ << std::endl; \
std::abort(); \
} \
} while (0)
