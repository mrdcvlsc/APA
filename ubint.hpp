#ifndef UNSIGNED_BIG_INTEGER_HPP
#define UNSIGNED_BIG_INTEGER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <exception>

#include "apa-base-configs.hpp"

#define BITS_PER_BYTE 8
#define LESS -1
#define EQUAL 0
#define GREAT 1

#define PADDING(LENGTH,BLOCK) (LENGTH%BLOCK==0) ? 0 : (BLOCK-(LENGTH%BLOCK))

namespace apa {

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
            ubint(std::string text, size_t base=10);
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
            explicit operator bool() const noexcept;

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
            
            /// @return returns a string that represent the value of a ubint number in base 10 form or decimal.
            std::string to_base10_string() const;

            /// @return returns a string that represent the value of a ubint number in base 16 form or hexadecimal.
            std::string to_base16_string() const;
    };

    void swap(ubint& a, ubint& b);
}
#endif

#ifndef _MAKE_LIB
#include "ubint.cpp"
#endif