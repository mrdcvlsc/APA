#ifndef SIGNED_BIG_INTEGER_HPP
#define SIGNED_BIG_INTEGER_HPP

#include "integer.hpp"

/// Left Positive - Right Negative.
#define LPOS_RNEG(SIGN_A, SIGN_B) (SIGN_A < SIGN_B)

/// Left Negative - Right Positive.
#define LNEG_RPOS(SIGN_A, SIGN_B) (SIGN_A > SIGN_B)

/// true if sign is positive.
#define SIGN_POSITIVE(SIGN) (!SIGN)

/// true if sign is negative.
#define SIGN_NEGATIVE(SIGN) (SIGN)

/// bint::compare -> integer.compare result sign flip.
#define CMP_RES_FLIP(CMP_RESULT) (-CMP_RESULT)

namespace apa {
    /// Positive Sign Value Indicator.
    static const limb_t POSITIVE = 0;

    /// Negative Sign Value Indicator.
    static const limb_t NEGATIVE = 1;

    class bint_error : public std::exception {
      private:
        unsigned int error_code;
        std::string error_message;

      public:
        bint_error(unsigned int error_code);
        unsigned int get_error_code() const;
        const char *what() const throw();
    };

    class bint {
      private:
        integer number;
        limb_t sign; // 1 if negative, 0 if positive

        /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
        int compare(const bint &with) const;
        static void bitwise_prepare(bint &left, bint &right);

      public:
        // Constructors

        template <typename T>
        bint(T num) {
            sign = (num < 0); // 1 if negative, 0 if positive.
            number = integer(std::abs(num));
        }

        bint();
        bint(const std::string &input);
        bint(const char *input);
        bint(std::initializer_list<limb_t> limbs, limb_t sign = 0);
        bint(limb_t *arr, size_t capacity, size_t length, limb_t sign);

        /// automatically sets the sign to `POSITIVE`.
        bint(size_t capacity, size_t length, bool AllocateSpace = true);

        // bint Constructors.
        bint(const bint &src);     // copy.
        bint(bint &&src) noexcept; // move.

        // bint Assignments.
        bint &operator=(const bint &src);     // copy.
        bint &operator=(bint &&src) noexcept; // move.

        // integer Constructors
        bint(limb_t sign, const integer &number);     // integer copy.
        bint(limb_t sign, integer &&number) noexcept; // integer move.

        ~bint();

        // Relational Operators
        bool operator<(const bint &op) const;
        bool operator>(const bint &op) const;
        bool operator==(const bint &op) const;
        bool operator!=(const bint &op) const;
        bool operator<=(const bint &op) const;
        bool operator>=(const bint &op) const;

        // Bit-Wise Logical Operators
        bint &operator&=(const bint &op);
        bint &operator|=(const bint &op);
        bint &operator^=(const bint &op);
        bint operator&(const bint &op) const;
        bint operator|(const bint &op) const;
        bint operator^(const bint &op) const;
        bint operator~() const;

        // Logical Operators
        explicit operator bool() const noexcept;

        // Arithmetic Operators

        static bint add_partial(
            const limb_t *l, size_t l_len, size_t l_index, const limb_t *r, size_t r_len, size_t r_index
        );

        static void sub_partial(
            limb_t *output, size_t out_len, size_t out_index, const limb_t *m, size_t m_len, size_t m_index
        );

        /**
         * mul_karatsuba.
         * @param limb_t* test.
         * */
        static void mul_karatsuba(
            limb_t *output, size_t out_len, size_t out_index, const limb_t *l, size_t l_len, size_t l_index,
            const limb_t *r, size_t r_len, size_t r_index
        );
        bint mul_naive(const bint &op) const;

        bint &operator+=(const bint &op);
        bint &operator-=(const bint &op);
        bint &operator*=(const bint &op);
        bint &operator/=(const bint &op);
        bint &operator%=(const bint &op);

        bint operator+(const bint &op) const;
        bint operator-(const bint &op) const;
        bint operator*(const bint &op) const;
        bint operator/(const bint &op) const;
        bint operator%(const bint &op) const;

        bint operator-() const;

        // pre-fix increment/decrement
        bint &operator++();
        bint &operator--();

        // post-fix increment/decrement
        bint operator++(int);
        bint operator--(int);

        // Shift Operators
        bint &operator<<=(size_t bits);
        bint &operator>>=(size_t bits);
        bint operator<<(size_t bits) const;
        bint operator>>(size_t bits) const;
        // for left shift (<<) with parameter bint type use the formula : x*2^k
        // for right shift (>>) with parameter bint type use the formula : x/2^k

        // Print Methods
        void printHex() const;
        void printHex_spaced_out() const;
        void printStatus(std::string printIdentifier = "default") const;

        /// @return returns a string that represent the value of a bint number in base
        /// 10 form or decimal.
        std::string to_base10_string() const;

        /// @return returns a string that represent the value of a bint number in base
        /// 16 form or hexadecimal.
        std::string to_base16_string() const;

        // Member Access Methods
        size_t capacity_size() const;
        size_t limb_size() const;
        size_t byte_size() const;
        size_t bit_size() const;
        const limb_t *limb_view() const;
        const limb_t *byte_view() const;
        limb_t *detach();
    };

    // functions
    void swap(bint &a, bint &b);

    // IO Operators
    std::ostream &operator<<(std::ostream &out, const bint &num);
    std::istream &operator>>(std::istream &in, bint &num);

    // bint constants
    static const bint __BINT_ZERO = 0;
    static const bint __BINT_ONE = 1;
    static const bint __BINT_TWO = 2;
} // namespace apa

#endif
