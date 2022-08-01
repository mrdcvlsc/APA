#ifndef APA_INTEGER_HPP
#define APA_INTEGER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <exception>
#include <limits>
#include <bitset>

#include "config.hpp"

#define PADDING(LENGTH,BLOCK) (LENGTH%BLOCK==0) ? 0 : (BLOCK-(LENGTH%BLOCK))

namespace apa {

    /// binary - base2.
    constexpr static size_t BIN = 2;

    /// octal - base8.
    constexpr static size_t OCT = 8;

    /// decimal - base10.
    constexpr static size_t DEC = 10;

    /// decimal - base16.
    constexpr static size_t HEX = 16;

    typedef std::vector<uint8_t> byte_array;

    constexpr static int LESS = -1;
    constexpr static int EQUAL = 0;
    constexpr static int GREAT = 1;

    constexpr static int BITS_PER_BYTE = 8;

    constexpr static size_t BASE_BITS = (sizeof(limb_t)*8);
    constexpr static size_t BASE_BITS_MINUS1 = BASE_BITS-1;
    constexpr static size_t BASE_BYTES = BASE_BITS/8;

    constexpr static size_t LIMB_BITS = BASE_BITS;
    constexpr static size_t LIMB_BYTES = BASE_BYTES;

    constexpr static size_t CAST_BITS = BASE_BITS*2;
    constexpr static size_t CAST_BYTES = BASE_BYTES*2;

    const static size_t INITIAL_LIMB_CAPACITY = 2;
    const static size_t INITIAL_LIMB_LENGTH = 1;
    const static size_t LIMB_GROWTH = 2;

    constexpr static limb_t BASE_MAX = std::numeric_limits<limb_t>::max();

    struct integer {
        size_t capacity;
        size_t length;
        limb_t* limbs;

        // Constructors
        integer();
        integer(limb_t num);
        integer(std::string text, size_t base=10);
        integer(std::initializer_list<limb_t> limbs);
        integer(size_t capacity, size_t length, bool AllocateSpace=true);
        integer(limb_t* arr, size_t capacity, size_t length);

        // integer Constructors.
        integer(const integer& src);     // copy.
        integer(integer&& src) noexcept; // move.

        // integer Assignments.
        integer& operator=(const integer& src);     // copy.
        integer& operator=(integer&& src) noexcept; // move.

        ~integer();

        // Index Operator
        limb_t& operator[](size_t i);
        limb_t& operator[](size_t i) const;

        /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
        int compare(const integer& with) const;

        // Relational Operators
        bool operator<(const integer& op) const;
        bool operator>(const integer& op) const;
        bool operator==(const integer& op) const;
        bool operator!=(const integer& op) const;
        bool operator<=(const integer& op) const;
        bool operator>=(const integer& op) const;

        // Bit-Wise Logical Operators
        integer& operator&=(const integer& op);
        integer& operator|=(const integer& op);
        integer& operator^=(const integer& op);
        integer operator&(const integer& op) const;
        integer operator|(const integer& op) const;
        integer operator^(const integer& op) const;
        integer operator~() const;

        void bit_realloc(const integer& op);
        void remove_leading_zeros();

        void bit_flip(size_t padding=0);
        void bit_and(const integer& op);
        void bit_or(const integer& op);
        void bit_xor(const integer& op);
        
        // Logical Operators
        explicit operator bool() const noexcept;

        // Arithmetic Operators
        integer bit_division(const integer& op) const;
        integer bit_modulo(const integer& op) const;

        integer& operator+=(const integer& op);
        integer& operator-=(const integer& op);
        integer& operator*=(const integer& op);
        integer& operator/=(const integer& op);
        integer& operator%=(const integer& op);
        integer operator+(const integer& op) const;
        integer operator-(const integer& op) const;
        integer operator*(const integer& op) const;
        integer operator/(const integer& op) const;
        integer operator%(const integer& op) const;

        // pre-fix increment/decrement
        integer& operator++();
        integer& operator--();

        // post-fix increment/decrement
        integer operator++(int);
        integer operator--(int);

        // Shift Operators
        integer& operator<<=(size_t bits);
        integer& operator>>=(size_t bits);
        integer operator<<(size_t bits) const;
        integer operator>>(size_t bits) const;
        // for left shift (<<) with parameter integer type use the formula : x*2^k
        // for right shift (>>) with parameter integer type use the formula : x/2^k

        // Print Methods
        void printHex() const;
        void printHex_spaced_out() const;
        void printBin_spaced_out() const;
        void printStatus(std::string printIdentifier="default") const;
        
        /// @return returns a string that represent the value of a integer number in base 10 form or decimal.
        std::string to_base10_string() const;

        /// @return returns a string that represent the value of a integer number in base 16 form or hexadecimal.
        std::string to_base16_string() const;

        // Methods
        size_t byte_size() const;
        size_t bit_size() const;
        limb_t* detach();
    };

    // functions
    void swap(integer& a, integer& b);

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const integer &num);
    std::istream& operator>>(std::istream &in, integer &num);

    // integer constants
    static const integer __INTEGER_ZERO = 0;
    static const integer __INTEGER_ONE = 1;
    static const integer __INTEGER_TWO = 2;
}
#endif