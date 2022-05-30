#ifndef UNSIGNED_BIG_INTEGER_HPP
#define UNSIGNED_BIG_INTEGER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <exception>
#include <limits>
#include <bitset>

#include "apa-base-configs.hpp"

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

    constexpr static size_t BASE_BITS = (sizeof(base_t)*8);
    constexpr static size_t BASE_BITS_MINUS1 = BASE_BITS-1;
    constexpr static size_t BASE_BYTES = BASE_BITS/8;

    constexpr static size_t LIMB_BITS = BASE_BITS*2;
    constexpr static size_t LIMB_BYTES = BASE_BYTES*2;

    const static size_t INITIAL_LIMB_CAPACITY = 2;
    const static size_t INITIAL_LIMB_LENGTH = 1;
    const static size_t LIMB_GROWTH = 2;

    constexpr static base_t BASE_MAX = std::numeric_limits<base_t>::max();

    class ubint {

        private:
        
            size_t capacity;
            size_t length;
            limb_t *limbs;

        public:
            
            // Constructors
            ubint();
            ubint(base_t num);
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

            // Index Operator
            limb_t& operator[](size_t i);
            limb_t& operator[](size_t i) const;

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

            void bit_realloc(const ubint& op);
            void remove_leading_zeros();

            void bit_flip(size_t padding=0);
            void bit_and(const ubint& op);
            void bit_or(const ubint& op);
            void bit_xor(const ubint& op);
            
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

            // pre-fix increment/decrement
            ubint& operator++();
            ubint& operator--();

            // post-fix increment/decrement
            ubint operator++(int);
            ubint operator--(int);

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
            void printBin_spaced_out() const;
            void printStatus(std::string printIdentifier="default") const;
            
            /// @return returns a string that represent the value of a ubint number in base 10 form or decimal.
            std::string to_base10_string() const;

            /// @return returns a string that represent the value of a ubint number in base 16 form or hexadecimal.
            std::string to_base16_string() const;

            // Member Access Methods
            void set_length(size_t length);
            size_t capacity_size() const;
            size_t limb_size() const;
            size_t byte_size() const;
            size_t bit_size() const;
            const limb_t *limb_view() const;
            const uint8_t *byte_view() const;
    };

    // functions
    void swap(ubint& a, ubint& b);

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const ubint &num);
    std::istream& operator>>(std::istream &in, ubint &num);

    // ubint constants
    static const ubint __UBINT_ZERO = 0;
    static const ubint __UBINT_ONE = 1;
    static const ubint __UBINT_TWO = 2;
}
#endif