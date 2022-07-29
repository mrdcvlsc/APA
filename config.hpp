#ifndef APA_CONFIG_HPP
#define APA_CONFIG_HPP

// #define _BASE2_64

#ifndef _APA_TESTING_PHASE
    #if defined(__SIZEOF_INT128__) || defined(UINT128MAX) || defined(_FORCE_BASE2_64)
        #define _BASE2_64
    #elif defined(UINT64_MAX) || defined(UINT64_WIDTH) || defined(_FORCE_BASE2_32)
        #define _BASE2_32
    #elif defined(UINT32_MAX) || defined(UINT32_WIDTH) || defined(_FORCE_BASE2_16)
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
        #error not supported
    #endif
#endif

namespace apa {
    // 'limb_t' should always be double the size of 'base_t', this is to avoid overflows.
    #ifdef _BASE2_64
    typedef int64_t bint_arg_t;
    typedef uint64_t base_t;
    typedef __uint128_t limb_t;
    #elif defined(_BASE2_32)
    typedef int32_t bint_arg_t;
    typedef uint32_t base_t;
    typedef uint64_t limb_t;
    #elif defined(_BASE2_16)
    typedef int16_t bint_arg_t;
    typedef uint16_t base_t;
    typedef uint32_t limb_t;
    #endif
}

#endif