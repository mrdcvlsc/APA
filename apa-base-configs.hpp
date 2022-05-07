#ifndef APA_BASE_CONFIGS_HPP
#define APA_BASE_CONFIGS_HPP

// #define _BASE2_64

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
    typedef uint64_t base_t;
    typedef __uint128_t limb_t;
    #elif defined(_BASE2_32)
    typedef uint32_t base_t;
    typedef uint64_t limb_t;
    #elif defined(_BASE2_16)
    typedef uint16_t base_t;
    typedef uint32_t limb_t;
    #endif
}

#endif