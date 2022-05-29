#ifndef SIGNED_BIG_INTEGER_HPP
#define SIGNED_BIG_INTEGER_HPP

#include "ubint.hpp"

/// Left Positive - Right Negative.
#define LPOS_RNEG(SIGN_A,SIGN_B) (SIGN_A<SIGN_B)

/// Left Negative - Right Positive.
#define LNEG_RPOS(SIGN_A,SIGN_B) (SIGN_A>SIGN_B)

/// true if sign is positive.
#define SIGN_POSITIVE(SIGN) (!SIGN)

/// true if sign is negative.
#define SIGN_NEGATIVE(SIGN) (SIGN)

/// bint::compare -> ubint.compare result sign flip.
#define CMP_RES_FLIP(CMP_RESULT) (-CMP_RESULT)

namespace apa {

    /// Positive Sign Value Indicator.
    static const uint8_t POSITIVE = 0;

    /// Negative Sign Value Indicator.
    static const uint8_t NEGATIVE = 1;

    class bint {

        private:

            ubint number;
            uint8_t sign; // 1 if negative, 0 if positive

            static void bitwise_prepare(bint& left, bint& right);

        public:

            // Constructors
            bint();
            bint(bint_arg_t num);
            bint(std::string text, size_t base=10);
            bint(std::initializer_list<base_t> limbs, uint8_t sign=0);
            bint(size_t capacity, size_t length, bool AllocateSpace=true);

            // bint Constructors.
            bint(const bint& src);     // copy.
            bint(bint&& src) noexcept; // move.

            // bint Assignments.
            bint& operator=(const bint& src);     // copy.
            bint& operator=(bint&& src) noexcept; // move.

            // ubint Constructors
            bint(uint8_t sign, const ubint& number); // ubint copy.
            bint(uint8_t sign, ubint&& number) noexcept; // ubint move.

            ~bint();

            /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
            int compare(const bint& with) const;

            // Relational Operators
            bool operator<(const bint& op) const;
            bool operator>(const bint& op) const;
            bool operator==(const bint& op) const;
            bool operator!=(const bint& op) const;
            bool operator<=(const bint& op) const;
            bool operator>=(const bint& op) const;

            // Bit-Wise Logical Operators
            bint& operator&=(const bint& op);
            bint& operator|=(const bint& op);
            bint& operator^=(const bint& op);
            bint operator&(const bint& op) const;
            bint operator|(const bint& op) const;
            bint operator^(const bint& op) const;
            bint operator~() const;

            // Logical Operators
            explicit operator bool() const noexcept;

            // Arithmetic Operators
            bint mul_karatsuba(const bint& op) const;

            bint& operator+=(const bint& op);
            bint& operator-=(const bint& op);
            bint& operator*=(const bint& op);
            bint& operator/=(const bint& op);
            bint& operator%=(const bint& op);

            bint operator+(const bint& op) const;
            bint operator-(const bint& op) const;
            bint operator*(const bint& op) const;
            bint operator/(const bint& op) const;
            bint operator%(const bint& op) const;

            bint operator-() const;

            // pre-fix increment/decrement
            bint& operator++();
            bint& operator--();

            // post-fix increment/decrement
            bint operator++(int);
            bint operator--(int);

            // Shift Operators
            bint& operator<<=(size_t bits);
            bint& operator>>=(size_t bits);
            bint operator<<(size_t bits) const;
            bint operator>>(size_t bits) const;
            // for left shift (<<) with parameter bint type use the formula : x*2^k
            // for right shift (>>) with parameter bint type use the formula : x/2^k

            // Print Methods
            void printHex() const;
            void printHex_spaced_out() const;
            void printStatus(std::string printIdentifier="default") const;
            
            /// @return returns a string that represent the value of a bint number in base 10 form or decimal.
            std::string to_base10_string() const;

            /// @return returns a string that represent the value of a bint number in base 16 form or hexadecimal.
            std::string to_base16_string() const;

            // Member Access Methods
            size_t capacity_size() const;
            size_t limb_size() const;
            size_t byte_size() const;
            size_t bit_size() const;
            const limb_t *limb_view() const;
            const uint8_t *byte_view() const;
    };

    // functions
    void swap(bint& a, bint& b);

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const bint &num);
    std::istream& operator>>(std::istream &in, bint &num);

    // bint constants
    static const bint __bint_ZERO = 0;
    static const bint __bint_ONE = 1;
    static const bint __bint_TWO = 2;
}

#endif
