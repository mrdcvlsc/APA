#ifndef UNSIGNED_BIG_INTEGER_HPP
#define UNSIGNED_BIG_INTEGER_HPP

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <exception>

// #define _BASE2_64

#ifdef _BASE2_64
    #if (__MINGW64__ || __MINGW64)
        #define PRINT_LIMBHEX_NOPAD "%llx"
        #define PRINT_LIMBHEX "%16llx"
        #define PRINT_LIMBHEX_SPACED " %16llx"
    #elif (__clang__ || __GNUC__ || __GNUG__)
        #define PRINT_LIMBHEX_NOPAD "%lx"
        #define PRINT_LIMBHEX "%016lx"
        #define PRINT_LIMBHEX_SPACED " %016lx"
    #else
        #error not supported
    #endif
#elif defined(_BASE2_32)
    #if (__MINGW64__ || __MINGW64)
        #define PRINT_LIMBHEX_NOPAD "%llx"
        #define PRINT_LIMBHEX "%08llx"
        #define PRINT_LIMBHEX_SPACED " %08llx"
    #elif (__clang__ || __GNUC__ || __GNUG__)
        #define PRINT_LIMBHEX_NOPAD "%lx"
        #define PRINT_LIMBHEX "%08lx"
        #define PRINT_LIMBHEX_SPACED " %08lx"
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

#define BITS_PER_BYTE 8
#define LESS -1
#define EQUAL 0
#define GREAT 1

#define PADDING(LENGTH,BLOCK) (LENGTH%BLOCK==0) ? 0 : (BLOCK-(LENGTH%BLOCK))

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

    constexpr static size_t BASE_BITS = (sizeof(base_t)*8);
    constexpr static size_t BASE_BITS_MINUS1 = BASE_BITS-1;
    constexpr static size_t BASE_BYTES = BASE_BITS/8;

    constexpr static size_t LIMB_BITS = BASE_BITS*2;
    constexpr static size_t LIMB_BYTES = BASE_BYTES*2;

    const static size_t INITIAL_LIMB_CAPACITY = 2;
    const static size_t INITIAL_LIMB_LENGTH = 1;
    const static size_t LIMB_GROWTH = 2;

    class ubint {
        public:
            size_t capacity;
            size_t length;
            limb_t *limbs;

            // Constructors
            ubint();
            ubint(limb_t num);
            ubint(std::string text, bool isHex=true);
            ubint(std::initializer_list<base_t> limbs);
            ubint(size_t capacity, size_t length, bool AllocateSpace=true);

            // ubint Constructors.
            ubint(const ubint& src);     // copy.
            ubint(ubint&& src) noexcept; // move.

            // ubint Assignments.
            ubint& operator=(const ubint& src);     // copy.
            ubint& operator=(ubint&& src) noexcept; // move.

            ~ubint();

            /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
            int compare(const ubint& with) const;

            // Relational Operators
            bool operator<(const ubint& op) const;
            bool operator>(const ubint& op) const;
            bool operator==(const ubint& op) const;
            bool operator!=(const ubint& op) const;
            bool operator<=(const ubint& op) const;
            bool operator>=(const ubint& op) const;

            // Bit-Wise Logical Operators
            ubint& operator&=(const ubint& op);
            ubint& operator|=(const ubint& op);
            ubint& operator^=(const ubint& op);
            ubint operator&(const ubint& op) const;
            ubint operator|(const ubint& op) const;
            ubint operator^(const ubint& op) const;
            ubint operator~() const;
            
            // Logical Operators
            // explicit operator bool() const noexcept;
            bool boolean() const;
            bool operator&&(const ubint& op) const;
            bool operator||(const ubint& op) const;
            bool operator!() const;

            // Arithmetic Operators
            ubint bit_division(const ubint& op) const;
            ubint bit_modulo(const ubint& op) const;

            ubint& operator+=(const ubint& op);
            ubint& operator-=(const ubint& op);
            ubint& operator*=(const ubint& op);
            ubint& operator/=(const ubint& op);
            ubint& operator%=(const ubint& op);
            ubint operator+(const ubint& op) const;
            ubint operator-(const ubint& op) const;
            ubint operator*(const ubint& op) const;
            ubint operator/(const ubint& op) const;
            ubint operator%(const ubint& op) const;

            // Shift Operators
            ubint& operator<<=(size_t bits);
            ubint& operator>>=(size_t bits);
            ubint operator<<(size_t bits) const;
            ubint operator>>(size_t bits) const;
            // for left shift (<<) with parameter ubint type use the formula : x*2^k
            // for right shift (>>) with parameter ubint type use the formula : x/2^k

            // Print Methods
            void printHex() const;
            void printHex_spaced_out() const;
            void printStatus(std::string printIdentifier="default") const;
            std::string to_base10_string() const;
    };

    void swap(ubint& a, ubint& b);
}
#endif

#ifndef _MAKE_LIB
#include "ubint.cpp"
#endif