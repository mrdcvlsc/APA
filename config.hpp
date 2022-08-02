#ifndef APA_CONFIG_HPP
#define APA_CONFIG_HPP

#ifndef _APA_TESTING_PHASE
    #if defined(_FORCE_BASE2_64)
        #define _BASE2_64
    #elif defined(_FORCE_BASE2_32)
        #define _BASE2_32
    #elif defined(_FORCE_BASE2_16) 
        #define _BASE2_16
    #elif defined(__SIZEOF_INT128__) || defined(UINT128MAX)
        #define _BASE2_64
    #elif defined(UINT64_MAX) || defined(UINT64_WIDTH)
        #define _BASE2_32
    #elif defined(UINT32_MAX) || defined(UINT32_WIDTH)
        #define _BASE2_16
    #else
#error "ubint is not supported in this system."
    #endif
#endif

#ifdef _BASE2_64
    #if (__MINGW64__ || __MINGW64)
        #define PRINT_LIMBHEX_NOPAD "%llx"
        #define PRINT_LIMBHEX "%016llx"
        #define PRINT_LIMBHEX_SPACED " %016llx"
    #elif (__clang__ || __GNUC__ || __GNUG__)
        #define PRINT_LIMBHEX_NOPAD "%lx"
        #define PRINT_LIMBHEX "%016lx"
        #define PRINT_LIMBHEX_SPACED " %016lx"
    #else
        #error not supported
    #endif
#elif defined(_BASE2_32)
    #if (__MINGW64__ || __MINGW64)
        #define PRINT_LIMBHEX_NOPAD "%x"
        #define PRINT_LIMBHEX "%08x"
        #define PRINT_LIMBHEX_SPACED " %08x"
    #elif (__clang__ || __GNUC__ || __GNUG__)
        #define PRINT_LIMBHEX_NOPAD "%x"
        #define PRINT_LIMBHEX "%08x"
        #define PRINT_LIMBHEX_SPACED " %08x"
    #else
        #error not supported
    #endif
#elif defined(_BASE2_16)
    #if (__MINGW64__ || __MINGW64)
        #define PRINT_LIMBHEX_NOPAD "%x"
        #define PRINT_LIMBHEX "%04x"
        #define PRINT_LIMBHEX_SPACED " %04x"
    #elif (__clang__ || __GNUC__ || __GNUG__)
        #define PRINT_LIMBHEX_NOPAD "%x"
        #define PRINT_LIMBHEX "%04x"
        #define PRINT_LIMBHEX_SPACED " %04x"
    #else
#error not supported in this system
    #endif
#endif

namespace apa {

#ifdef _APA_TESTING_PHASE
    static const size_t KARATSUBA_SIZE = 4;
#else
    // most efficient limb size where karatsuba should activate.
    static const size_t KARATSUBA_SIZE = 50;
#endif

    // 'cast_t' should always be double the size of 'limb_t', this is to avoid overflows.
#ifdef _BASE2_64
    #ifndef _APA_TESTING_PHASE
        #pragma message("compiling with base2^64 types - fastest performance")
    #endif
    typedef int64_t bint_arg_t;
    typedef uint64_t limb_t;
    typedef __uint128_t cast_t;
#elif defined(_BASE2_32)
    #ifndef _APA_TESTING_PHASE
        #pragma message("compiling with base2^32 - average performance")
    #endif
    typedef int32_t bint_arg_t;
    typedef uint32_t limb_t;
    typedef uint64_t cast_t;
#elif defined(_BASE2_16)
    #ifndef _APA_TESTING_PHASE
        #pragma message("compiling with base2^16 - slowest performance")
    #endif
    typedef int16_t bint_arg_t;
    typedef uint16_t limb_t;
    typedef uint32_t cast_t;
#endif
}

#endif