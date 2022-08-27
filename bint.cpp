#ifndef SIGNED_BIG_INTEGER_CPP
#define SIGNED_BIG_INTEGER_CPP

#include <iostream>

#include "config.hpp"
#include "integer.hpp"
#ifdef _MAKE_LIB
    #include "bint.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
    #include "bint.hpp"
#endif

namespace apa {
    // ####################### bint exception class methods #######################
    bint_error::bint_error(unsigned int error_code) : error_code(error_code) {
        switch (error_code) {
            case 1:
                error_message = "assignment of an empty string literal to a bint is not allowed";
                break;
            case BIN:
                error_message = "invalid digit found in assigned \"binary\" number";
                break;
            case OCT:
                error_message = "invalid digit found in assigned \"octal\" number";
                break;
            case DEC:
                error_message = "invalid digit found in assigned \"decimal\" number";
                break;
            case HEX:
                error_message = "invalid digit found in assigned \"hex\" number";
                break;
        }
    }

    unsigned int bint_error::get_error_code() const {
        return this->error_code;
    }

    const char *bint_error::what() const throw() {
        return error_message.c_str();
    }

    // ####################### bint class methods #######################

    bint::bint(char num) {
        sign = (num < 0);
        if (num == std::numeric_limits<char>::min()) {
            char new_num = num + 1;
            number = integer((size_t) std::abs(new_num));
            number++;
        } else {
            number = integer((size_t) std::abs(num));
        }
    }

    bint::bint(unsigned char num) {
        sign = POSITIVE;
        number = integer((size_t) num);
    }

    bint::bint(short num) {
        sign = (num < 0);
        if (num == std::numeric_limits<short>::min()) {
            short new_num = num + 1;
            number = integer((size_t) std::abs(new_num));
            number++;
        } else {
            number = integer((size_t) std::abs(num));
        }
    }

    bint::bint(unsigned short num) {
        sign = POSITIVE;
        number = integer((size_t) num);
    }

    bint::bint(int num) {
        sign = (num < 0);
        if (num == std::numeric_limits<int>::min()) {
            int new_num = num + 1;
            number = integer((size_t) std::abs(new_num));
            number++;
        } else {
            number = integer((size_t) std::abs(num));
        }
    }

    bint::bint(unsigned int num) {
        sign = POSITIVE;
        number = integer((size_t) num);
    }

    bint::bint(long num) {
        sign = (num < 0);
        if (num == std::numeric_limits<long>::min()) {
            long new_num = num + 1;
            number = integer((size_t) std::abs(new_num));
            number++;
        } else {
            number = integer((size_t) std::abs(num));
        }
    }

    bint::bint(unsigned long num) {
        sign = POSITIVE;
        number = integer((size_t) num);
    }

    bint::bint(long long num) {
        sign = (num < 0);
        if (num == std::numeric_limits<long long>::min()) {
            long long new_num = num + 1;
            number = integer((size_t) std::abs(new_num));
            number++;
        } else {
            number = integer((size_t) std::abs(num));
        }
    }

    bint::bint(unsigned long long num) {
        sign = POSITIVE;
        number = integer((size_t) num);
    }

    bint::bint() {
        number = integer();
        sign = POSITIVE;
    }

    bint::bint(size_t capacity, size_t length, bool AllocateSpace) {
        number = integer(capacity, length, AllocateSpace);
        sign = POSITIVE;
    }

    /**
     * @brief constructor for conveniece, check if the input string is a valid
     * integral.
     *
     * @param input the string representation of an integral type,
     * it could be in binary, octal, hex, and decimal format.
     * @return int value 0 if is a valid type, 1 if string is empty
     * , 2 if invalid binary, 8 if invalid octal, 10 if invalid dec,
     * 16 if invalid hex, 20 if invalid number format.
     */
    bint::bint(const std::string &input) {
        if (input.empty())
            throw bint_error(EMPTY); // empty

        size_t start_index = input[0] == '-';
        size_t base = 0;

        if (input.size() == 1 && (input[0] >= '0' && input[0] <= '9')) {
            base = DEC;
        } else if (input[start_index] == '0') {
            start_index++;
            if (input[start_index] == 'b') { // check if valid binary
                start_index++;
                for (size_t i = start_index; i < input.size(); ++i) {
                    if ((input[i] < '0') ^ (input[i] > '1')) {
                        throw bint_error(BIN);
                    }
                }
                base = BIN;
            } else if (input[start_index] == 'o') { // check if valid octal
                start_index++;
                for (size_t i = start_index; i < input.size(); ++i) {
                    if ((input[i] < '0') ^ (input[i] > '7')) {
                        throw bint_error(OCT);
                    }
                }
                base = OCT;
            } else if (input[start_index] == 'x') { // check if valid hex
                start_index++;
                for (size_t i = start_index; i < input.size(); ++i) {
                    if (CHAR_TO_HEX[(size_t) input[i]] == 0xff) {
                        throw bint_error(HEX);
                    }
                }
                base = HEX;
            } else {
                throw bint_error(INVALID);
            }
        } else { // should be dec
            for (size_t i = start_index; i < input.size(); ++i) {
                if ((input[i] < '0') ^ (input[i] > '9')) {
                    throw bint_error(DEC);
                }
            }
            base = DEC;
        }

        sign = input[0] == '-';
        number = integer(std::string(input.begin() + start_index, input.end()), base);
        number.remove_leading_zeros();
    }

    bint::bint(const char *input) {
        *this = bint(std::string(input));
    }

    // read only constuctor
    bint::bint(limb_t *arr, size_t capacity, size_t length, limb_t sign) {
        number = integer(arr, capacity, length);
        this->sign = sign;
    }

    /// copy constructor.
    bint::bint(const bint &src) {
        number = src.number;
        sign = src.sign;
    }

    /// move constructor.
    bint::bint(bint &&src) noexcept {
        number = std::move(src.number);
        sign = src.sign;
    }

    /// copy assignment.
    bint &bint::operator=(const bint &src) {
        if (this != &src) {
            number = src.number;
            sign = src.sign;
        }
        return *this;
    }

    /// move assignment.
    bint &bint::operator=(bint &&src) noexcept {
        if (this != &src) {
            number = std::move(src.number);
            sign = src.sign;
        }
        return *this;
    }

    bint::bint(limb_t sign, const integer &number) {
        this->number = number;
        this->sign = sign;
    }

    bint::bint(limb_t sign, integer &&number) noexcept {
        this->number = std::move(number);
        this->sign = sign;
    }

    bint::bint(std::initializer_list<limb_t> limbs, limb_t sign) {
        number = integer(limbs);
        this->sign = sign;
    }

    bint::~bint() {
        this->sign = 0;
    }

    int bint::compare(const bint &op) const {
        if (LPOS_RNEG(sign, op.sign)) {
            return GREAT;
        } else if (LNEG_RPOS(sign, op.sign)) {
            return LESS;
        } else if (SIGN_NEGATIVE(sign)) {
            return CMP_RES_FLIP(number.compare(op.number));
        }
        return number.compare(op.number);
    }

    // Logical Operators

    bool bint::operator<(const bint &op) const {
        return compare(op) == LESS;
    }

    bool bint::operator>(const bint &op) const {
        return compare(op) == GREAT;
    }

    bool bint::operator==(const bint &op) const {
        return compare(op) == EQUAL;
    }

    bool bint::operator!=(const bint &op) const {
        return !(*this == op);
    }

    bool bint::operator<=(const bint &op) const {
        return compare(op) <= EQUAL;
    }

    bool bint::operator>=(const bint &op) const {
        return compare(op) >= EQUAL;
    }

    // Bit-Wise Logical Operators

    void bint::bitwise_prepare(bint &left, bint &right) {
        size_t lpadding = 0, rpadding = 0;

        if (left.limb_size() < right.limb_size()) {
            lpadding = right.limb_size() - left.limb_size();
        } else {
            rpadding = left.limb_size() - right.limb_size();
        }

        if (SIGN_NEGATIVE(left.sign)) {
            left.number.bit_flip(lpadding);
            ++left.number;
        }

        if (SIGN_NEGATIVE(right.sign)) {
            right.number.bit_flip(rpadding);
            ++right.number;
        }

        if (lpadding) {
            left.number.bit_realloc(right.number);
        } else if (rpadding) {
            right.number.bit_realloc(left.number);
        }
    }

    bint &bint::operator&=(const bint &op) {
        if (sign | op.sign) {
            bint left = *this, right = op;

            bitwise_prepare(left, right);

            left.number.bit_and(right.number);
            left.sign &= right.sign;

            if (SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this, left);
        } else {
            number &= op.number;
        }
        return *this;
    }

    bint bint::operator&(const bint &op) const {
        bint bw = *this;
        return bw &= op;
    }

    bint &bint::operator|=(const bint &op) {
        if (sign | op.sign) {
            bint left = *this, right = op;

            bitwise_prepare(left, right);

            left.number.bit_or(right.number);
            left.sign |= right.sign;

            if (SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this, left);
        } else {
            number |= op.number;
        }
        return *this;
    }

    bint bint::operator|(const bint &op) const {
        bint bw = *this;
        return bw |= op;
    }

    bint &bint::operator^=(const bint &op) {
        if (sign | op.sign) {
            bint left = *this, right = op;

            bitwise_prepare(left, right);

            left.number.bit_xor(right.number);
            left.sign ^= right.sign;

            if (SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this, left);
        } else {
            number ^= op.number;
        }
        return *this;
    }

    bint bint::operator^(const bint &op) const {
        bint bw = *this;
        return bw ^= op;
    }

    bint bint::operator~() const {
        bint bwn = *this;
        if (SIGN_NEGATIVE(sign)) {
            --bwn.number;
        } else {
            ++bwn.number;
        }

        bwn.sign = !bwn.sign;
        return bwn;
    }

    // Logical Operators
    bint::operator bool() const noexcept {
        return (bool) number;
    }

    // Arithmetic Operators
    bint &bint::operator+=(const bint &op) {
        if (sign != op.sign) {
            int cmp = number.compare(op.number);
            if (cmp == GREAT) {
                number -= op.number;
            } else if (cmp == LESS) {
                number = op.number - number;
                sign = op.sign;
            } else {
                number.length = 1;
                number[0] = 0;
                sign = POSITIVE;
            }
        } else {
            number += op.number;
        }
        return *this;
    }

    bint bint::operator+(const bint &op) const {
        if (sign != op.sign) {
            int cmp = number.compare(op.number);
            if (cmp == GREAT) {
                return bint(sign, number - op.number);
            } else if (cmp == LESS) {
                return bint(op.sign, op.number - number);
            } else {
                return __BINT_ZERO;
            }
        }
        return bint(sign, number + op.number);
    }

    bint &bint::operator-=(const bint &op) {
        if (sign != op.sign) {
            number += op.number; // correct - final
        } else {
            int cmp = compare(op);
            if (cmp == EQUAL) {
                number.length = 1;
                number[0] = 0;
            } else if (SIGN_NEGATIVE(sign)) {
                if (cmp == GREAT) {
                    number = op.number - number;
                    sign = POSITIVE;
                } else {
                    number -= op.number;
                    sign = NEGATIVE;
                }
            } else {
                if (cmp == GREAT) {
                    number -= op.number;
                    sign = POSITIVE;
                } else {
                    number = op.number - number;
                    sign = NEGATIVE;
                }
            }
        }
        return *this;
    }

    bint bint::operator-(const bint &op) const {
        if (sign == op.sign) {
            int cmp = compare(op);
            if (cmp == EQUAL) {
                return __BINT_ZERO;
            } else if (SIGN_NEGATIVE(sign)) {
                if (cmp == GREAT) {
                    return bint(POSITIVE, op.number - number);
                } else {
                    return bint(NEGATIVE, number - op.number);
                }
            } else {
                if (cmp == GREAT) {
                    return bint(POSITIVE, number - op.number);
                } else {
                    return bint(NEGATIVE, op.number - number);
                }
            }
        }
        return bint(sign, number + op.number);
    }

    bint &bint::operator*=(const bint &op) {
        bint product = *this * op;
        swap(product, *this);
        return *this;
    }

    bint bint::mul_naive(const bint &op) const {
        bint product(!(sign == op.sign), number * op.number);
        if (!product.number) {
            product.sign = 0;
        }
        return product;
    }

    bint bint::add_partial(
        const limb_t *num1, size_t num1_len, size_t num1_index, const limb_t *num2, size_t num2_len, size_t num2_index
    ) {
        size_t len = std::max(num1_len, num2_len) + 1;
        bint sum(len + 1, len);
        std::memset(sum.number.limbs, 0x00, LIMB_BYTES * sum.number.capacity);

        for (size_t i = 0; i < num1_len; ++i) {
            sum.number.limbs[i] = num1[num1_index + i];
        }

        limb_t carry = 0;
        for (size_t i = 0; i < num2_len; ++i) {
            cast_t sum_index = (cast_t) sum.number.limbs[i] + num2[num2_index + i] + carry;
            sum.number.limbs[i] = sum_index;
            carry = sum_index >> BASE_BITS;
        }

        for (size_t i = num2_len; i < sum.number.length; ++i) {
            cast_t sum_index = (cast_t) sum.number.limbs[i] + carry;
            sum.number.limbs[i] = sum_index;
            carry = sum_index >> BASE_BITS;
        }
        sum.number.limbs[sum.number.length] += carry;

        sum.number.remove_leading_zeros();
        return sum;
    }

    void bint::mul_karatsuba(
        limb_t *out, size_t out_len, size_t out_index, const limb_t *num1, size_t num1_len, size_t num1_index,
        const limb_t *num2, size_t num2_len, size_t num2_index
    ) {
        if (num2_len < KARATSUBA_SIZE || num1_len < KARATSUBA_SIZE) {
            size_t i = 0, j = 0;
            limb_t carry = 0;
            for (j = 0; j < num1_len; ++j) {
                cast_t product_index =
                    (cast_t) num1[j + num1_index] * num2[num2_index] + carry;
                out[j + out_index] = product_index;
                carry = (product_index >> BASE_BITS);
            }
            out[num1_len + out_index] = carry;

            for (i = 1; i < num2_len; ++i) {
                carry = 0;
                for (j = 0; j < num1_len; ++j) {
                    cast_t product_index =
                        (cast_t) num1[j + num1_index] * num2[i + num2_index] + out[i + j + out_index] + carry;
                    out[i + j + out_index] = product_index;
                    carry = (product_index >> BASE_BITS);
                }
                out[i + num1_len + out_index] = carry;
            }
            return;
        }

        size_t max_len = std::max(num1_len, num2_len);
        size_t split_len = max_len - (max_len / 2);

        // prep logics
        size_t a_len, b_len, c_len, d_len;

        // left hand side split
        if (num1_len > split_len) {
            a_len = num1_len - split_len;
            b_len = split_len;
        } else {
            a_len = 0;
            b_len = num1_len;
        }

        // right hand side split
        if (num2_len > split_len) {
            c_len = num2_len - split_len;
            d_len = split_len;
        } else {
            c_len = 0;
            d_len = num2_len;
        }

        // karatsuba

        // z0 --------------------------------------------------------------
        size_t z0_padding = split_len * 2;
        if (a_len && c_len) {
            mul_karatsuba(
                out, out_len, out_index + z0_padding, num1, a_len, split_len + num1_index, num2, c_len,
                split_len + num2_index
            );
        }
        bint z0;
        if (a_len && c_len) {
            z0 = bint(out + out_index + z0_padding, a_len + c_len + 1, a_len + c_len, 0);
        } else {
            z0 = bint(__BINT_ZERO.number.limbs, 1, 1, 0);
        }
        z0.number.remove_leading_zeros();

        // z1 --------------------------------------------------------------
        mul_karatsuba(out, out_len, out_index, num1, b_len, num1_index, num2, d_len, num2_index);
        bint z1 = bint(out + out_index, b_len + d_len + 1, b_len + d_len, 0);
        z1.number.remove_leading_zeros();

        // z2 --------------------------------------------------------------
        bint lsplit_add, rsplit_add;

        if (a_len) {
            lsplit_add = add_partial(num1, a_len, split_len + num1_index, num1, b_len, num1_index);
        } else {
            lsplit_add = add_partial(__BINT_ZERO.number.limbs, 1, 0, num1, b_len, num1_index);
        }

        if (c_len) {
            rsplit_add = add_partial(num2, c_len, split_len + num2_index, num2, d_len, num2_index);
        } else {
            rsplit_add = add_partial(__BINT_ZERO.number.limbs, 1, 0, num2, d_len, num2_index);
        }

        bint z2(
            lsplit_add.number.length + rsplit_add.number.length + 1, lsplit_add.number.length + rsplit_add.number.length
        );
        std::memset(z2.number.limbs, 0x00, z2.number.capacity * LIMB_BYTES);
        mul_karatsuba(
            z2.number.limbs, z2.number.length, 0, lsplit_add.number.limbs, lsplit_add.number.length, 0,
            rsplit_add.number.limbs, rsplit_add.number.length, 0
        );
        z2.number.remove_leading_zeros();

        // z3 --------------------------------------------------------------
        bint z3 = std::move(z2);
        z3 -= z1;
        z3 -= z0;
        z0.detach();
        z1.detach();

        // z4 --------------------------------------------------------------
        limb_t carry = 0;
        for (size_t i = 0; i < z3.number.length; ++i) {
            cast_t sum_index = (cast_t) out[i + split_len + out_index] + z3.number.limbs[i] + carry;
            out[i + split_len + out_index] = sum_index;
            carry = sum_index >> BASE_BITS;
        }

        // for(size_t i=out_index+split_len+z3.number.length; i < out_len; ++i) {
        for (size_t i = out_index + split_len + z3.number.length; carry; ++i) {
            cast_t sum_index = (cast_t) out[i] + carry;
            out[i] = sum_index;
            carry = sum_index >> BASE_BITS;
        }
        // out[out_index+split_len+z3.number.length] += carry;
    }

    bint bint::operator*(const bint &op) const {
        if (number.length < KARATSUBA_SIZE || op.number.length < KARATSUBA_SIZE) {
            return mul_naive(op);
        }

        size_t len = number.length + op.number.length;
        bint product(len + 1, len);
        std::memset(product.number.limbs, 0x00, product.number.capacity * LIMB_BYTES);
        mul_karatsuba(
            product.number.limbs, product.number.length, 0, number.limbs, number.length, 0, op.number.limbs,
            op.number.length, 0
        );
        product.number.remove_leading_zeros();
        product.sign = !(sign == op.sign);
        return product;
    }

    bint &bint::operator/=(const bint &op) {
        bint quotient = *this / op;
        swap(quotient, *this);
        return *this;
    }

    bint bint::operator/(const bint &op) const {
        bint quotient(!(sign == op.sign), number / op.number);
        if (!quotient.number) {
            quotient.sign = 0;
        }
        return quotient;
    }

    bint &bint::operator%=(const bint &op) {
        bint remainder = *this % op;
        swap(remainder, *this);
        return *this;
    }

    bint bint::operator%(const bint &op) const {
        bint mod(sign, number % op.number);
        if (!mod.number) {
            mod.sign = 0;
        }
        return mod;
    }

    bint bint::operator-() const {
        bint negate = *this;
        negate.sign = !negate.sign;
        return negate;
    }

    // pre-fix increment/decrement
    bint &bint::operator++() {
        return *this += __BINT_ONE;
    }

    bint &bint::operator--() {
        return *this -= __BINT_ONE;
    }

    // post-fix increment/decrement
    bint bint::operator++(int) {
        bint prev = *this;
        ++*this;
        return prev;
    }

    bint bint::operator--(int) {
        bint prev = *this;
        --*this;
        return prev;
    }

    // Shift Operators
    bint &bint::operator<<=(size_t bits) {
        number <<= bits;
        return *this;
    }

    bint &bint::operator>>=(size_t bits) {
        number >>= bits;
        number += sign;
        return *this;
    }

    bint bint::operator<<(size_t bits) const {
        bint shifted = *this;
        return shifted <<= bits;
    }

    bint bint::operator>>(size_t bits) const {
        bint shifted = *this;
        return shifted >>= bits;
    }

    void bint::printHex() const {
        if (SIGN_NEGATIVE(sign)) {
            std::cout << "-";
        }
        number.printHex();
    }

    void bint::printHex_spaced_out() const {
        number.printHex_spaced_out();
        std::cout << ((SIGN_NEGATIVE(sign)) ? "\nNegative:" : "\nPositive\n");
    }

    void bint::printStatus(std::string printIdentifier) const {
        number.printStatus(printIdentifier);
        std::cout << ((SIGN_NEGATIVE(sign)) ? "\nNegative:" : "\nPositive\n");
    }

    std::string bint::to_base10_string() const {
        std::string Base10 = "";
        if (SIGN_NEGATIVE(sign)) {
            Base10.push_back('-');
        }

        Base10.append(number.to_base10_string());
        return Base10;
    }

    std::string bint::to_base16_string() const {
        std::string Base16 = "";
        if (SIGN_NEGATIVE(sign)) {
            Base16.push_back('-');
        }

        Base16.append(number.to_base16_string());
        return Base16;
    }

    // Member Access Methods
    size_t bint::capacity_size() const {
        return number.capacity;
    }

    size_t bint::limb_size() const {
        return number.length;
    }

    size_t bint::byte_size() const {
        return number.byte_size();
    }

    size_t bint::bit_size() const {
        return number.bit_size();
    }

    const limb_t *bint::limb_view() const {
        return (const limb_t *) number.limbs;
    }

    const limb_t *bint::byte_view() const {
        return (const limb_t *) number.limbs;
    }

    limb_t *bint::detach() {
        sign = 0;
        return number.detach();
    }

    void swap(bint &a, bint &b) {
        bint temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    // IO Operators
    std::ostream &operator<<(std::ostream &out, const bint &num) {
        out << num.to_base16_string();
        return out;
    }

    std::istream &operator>>(std::istream &in, bint &num) {
        std::string input;
        in >> input;
        num = bint(input);
        return in;
    }
} // namespace apa

#endif
