#ifndef APA_INTEGER_CPP
#define APA_INTEGER_CPP

#ifdef _MAKE_LIB
    #include "integer.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
    #include "integer.hpp"
#endif

namespace apa {
    integer::integer() {
        capacity = INITIAL_LIMB_CAPACITY;
        length = INITIAL_LIMB_LENGTH;
        limbs = (limb_t *) std::malloc(INITIAL_LIMB_CAPACITY * LIMB_BYTES);
    }

    integer::integer(size_t num) {
        capacity = sizeof(size_t) / sizeof(limb_t);
        length = capacity;
        limbs = (limb_t *) std::calloc(capacity, sizeof(limb_t));
        std::memcpy(limbs, &num, sizeof(num));
        remove_leading_zeros();
    }

    integer::integer(size_t capacity, size_t length, bool AllocateSpace) {
        this->capacity = capacity;
        this->length = length;

        if (AllocateSpace) {
            limbs = (limb_t *) std::malloc(capacity * LIMB_BYTES);
        } else {
            limbs = NULL;
        }
    }

    // constructor for conveniece
    integer::integer(const std::string& text, size_t base) {
        std::vector<uint8_t> output(text.size(), 0);
        std::string newText;

        if (base > 1 && base < HEX) {
            for (size_t i = 0; i < text.size(); ++i) {
                uint8_t carry = text[i] - '0';
                size_t j = text.size();
                while (j--) {
                    uint8_t tmp = output[j] * base + carry;
                    output[j] = tmp % 16;
                    carry = tmp / 16;
                }
            }

            size_t leading_zeros = 0;
            while (output.size() > 1 && !output[leading_zeros]) {
                leading_zeros++;
            }

            output.erase(output.begin(), output.begin() + leading_zeros);

            std::string stringForm(output.size(), '0');

            for (size_t i = 0; i < stringForm.size(); ++i) {
                stringForm[i] = HEX_TO_CHAR[output[i]];
            }

            newText = stringForm;
        } else if (base != HEX) {
            throw std::domain_error(
                "integer - string contructor : supported number "
                "base range is only from 2 to 16"
            );
        } else {
            newText = text;
        }

        size_t blocks = newText.size() / (CAST_BYTES);
        size_t remain = newText.size() % (CAST_BYTES);

        length = blocks;
        length += !!remain;

        capacity = length + LIMB_GROWTH;
        limbs = (limb_t *) std::calloc(capacity, sizeof(limb_t));

        for (size_t i = 0; i < newText.size(); ++i) {
            unsigned char CharByte = CHAR_TO_HEX[(unsigned char) newText[newText.size() - 1 - i]];
            if (CharByte == 0xff)
                break;

            size_t multiplier = std::pow(0x10, i % CAST_BYTES);
            limbs[i / CAST_BYTES] |= CharByte * multiplier;
        }

        remove_leading_zeros();
    }

    // a read only constructor
    integer::integer(limb_t *arr, size_t capacity, size_t length) {
        this->capacity = capacity;
        this->length = length;
        this->limbs = arr;
    }

    /// copy constructor.
    integer::integer(const integer &src) {
        capacity = src.capacity;
        length = src.length;
        limbs = (limb_t *) std::malloc(capacity * LIMB_BYTES);
        std::memcpy(limbs, src.limbs, length * LIMB_BYTES);
    }

    /// move constructor.
    integer::integer(integer &&src) noexcept {
        capacity = src.capacity;
        length = src.length;
        limbs = src.limbs;
        src.limbs = NULL;
    }

    /// copy assignment.
    integer &integer::operator=(const integer &src) {
        if (this != &src) {
            if (capacity <= src.length) {
                limbs = (limb_t *) std::realloc(limbs, src.capacity * LIMB_BYTES);
                capacity = src.capacity;
            }

            length = src.length;
            std::memcpy(limbs, src.limbs, src.length * LIMB_BYTES);
        }
        return *this;
    }

    /// move assignment.
    integer &integer::operator=(integer &&src) noexcept {
        if (this != &src) {
            std::free(limbs);
            capacity = src.capacity;
            length = src.length;
            limbs = src.limbs;
            src.limbs = NULL;
        }
        return *this;
    }

    integer::integer(std::initializer_list<limb_t> limbs) {
        capacity = limbs.size() + LIMB_GROWTH;
        length = limbs.size();
        this->limbs = (limb_t *) std::malloc(capacity * LIMB_BYTES);
        size_t i = 0;

        for (auto limb: limbs) {
            this->limbs[length - 1 - i++] = limb;
        }
    }

    integer::~integer() {
        std::free(limbs);
        capacity = 0;
        length = 0;
    }

    // Index Operator
    limb_t &integer::operator[](size_t i) {
        return limbs[i];
    }

    limb_t &integer::operator[](size_t i) const {
        return limbs[i];
    }

    /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
    int integer::compare(const integer &op) const {
        if (length < op.length) {
            return LESS;
        } else if (length > op.length) {
            return GREAT;
        }

        for (size_t i = 0; i < length; ++i) {
            if (limbs[length - 1 - i] < op.limbs[length - 1 - i]) {
                return LESS;
            } else if (limbs[length - 1 - i] > op.limbs[length - 1 - i]) {
                return GREAT;
            }
        }

        return EQUAL;
    }

    // Logical Operators

    bool integer::operator<(const integer &op) const {
        return compare(op) == LESS;
    }

    bool integer::operator>(const integer &op) const {
        return compare(op) == GREAT;
    }

    bool integer::operator==(const integer &op) const {
        return compare(op) == EQUAL;
    }

    bool integer::operator!=(const integer &op) const {
        return !(*this == op);
    }

    bool integer::operator<=(const integer &op) const {
        return compare(op) <= EQUAL;
    }

    bool integer::operator>=(const integer &op) const {
        return compare(op) >= EQUAL;
    }

    // Bit-Wise Logical Operators

    void integer::bit_realloc(const integer &op) {
        size_t zero_set = length * LIMB_BYTES;
        capacity = op.capacity;
        limbs = (limb_t *) std::realloc(limbs, capacity * LIMB_BYTES);
        std::memset(limbs + length, 0x00, (op.length * LIMB_BYTES) - zero_set);
        length = op.length;
    }

    void integer::remove_leading_zeros() {
        for (size_t i = 0; i < length; ++i) {
            if (limbs[length - 1 - i]) {
                length -= i;
                return;
            }
        }
        length = 1;
    }

    void integer::bit_and(const integer &op) {
        for (size_t i = 0; i < op.length; ++i) {
            limbs[i] &= op.limbs[i];
        }

        for (size_t i = op.length; i < length; ++i) {
            limbs[i] &= 0;
        }
    }

    integer &integer::operator&=(const integer &op) {
        if (length < op.length) {
            bit_realloc(op);
        }

        bit_and(op);
        remove_leading_zeros();
        return *this;
    }

    integer integer::operator&(const integer &op) const {
        integer bitwise_and = *this;
        return bitwise_and &= op;
    }

    void integer::bit_or(const integer &op) {
        for (size_t i = 0; i < op.length; ++i) {
            limbs[i] |= op.limbs[i];
        }

        for (size_t i = op.length; i < length; ++i) {
            limbs[i] |= 0;
        }
    }

    integer &integer::operator|=(const integer &op) {
        if (length < op.length) {
            bit_realloc(op);
        }

        bit_or(op);
        remove_leading_zeros();
        return *this;
    }

    integer integer::operator|(const integer &op) const {
        integer bitwise_and = *this;
        return bitwise_and |= op;
    }

    void integer::bit_xor(const integer &op) {
        for (size_t i = 0; i < op.length; ++i) {
            limbs[i] ^= op.limbs[i];
        }

        for (size_t i = op.length; i < length; ++i) {
            limbs[i] ^= 0;
        }
    }

    integer &integer::operator^=(const integer &op) {
        if (length < op.length) {
            bit_realloc(op);
        }

        bit_xor(op);
        remove_leading_zeros();
        return *this;
    }

    integer integer::operator^(const integer &op) const {
        integer bitwise_and = *this;
        bitwise_and ^= op;
        return bitwise_and;
    }

    integer integer::operator~() const {
        // ------------------------------------------------------
        // flip all the bits of the limbs except the most significant.
        integer bwn(length, length);
        for (size_t i = 0; i < length - 1; ++i) {
            bwn.limbs[i] = (~limbs[i]);
        }

        // ------------------------------------------------------
        // flip the bits of the most significant limb, from it's
        // least significant bit to it's most significant bit
        // the flip will stop if it reach the last 1 bit value.
        limb_t mslimb = limbs[length - 1];
        limb_t bitmask = mslimb | (mslimb >> 1);
        for (size_t i = 2; i < BASE_BITS; i *= 2) {
            bitmask |= bitmask >> i;
        }

        bwn.limbs[bwn.length - 1] = bitmask ^ mslimb;
        bwn.remove_leading_zeros();
        return bwn;
    }

    void integer::bit_flip(size_t padding) {
        size_t prev_length = length;
        length += padding;

        if (capacity < length + padding) {
            capacity = length + padding + LIMB_GROWTH;
            limbs = (limb_t *) std::realloc(limbs, capacity * LIMB_BYTES);
        }

        for (size_t i = 0; i < prev_length; ++i) {
            limbs[i] = (~limbs[i]);
        }

        for (size_t i = prev_length; i < length; ++i) {
            limbs[i] = BASE_MAX;
        }
    }

    // Logical Operators
    integer::operator bool() const noexcept {
        return !(length == 1 && !limbs[0]);
    }

    // Arithmetic Operators

    integer &integer::operator+=(const integer &op) {
        if (capacity <= op.length + 1) {
            capacity = op.length + LIMB_GROWTH;
            limbs = (limb_t *) std::realloc(limbs, capacity * LIMB_BYTES);
        }

        if (length == capacity) {
            capacity = length + LIMB_GROWTH;
            limbs = (limb_t *) std::realloc(limbs, capacity * LIMB_BYTES);
        }

        if (length <= op.length) {
            std::memset(limbs + length, 0x00, ((op.length + 1) - length) * LIMB_BYTES);
            length = op.length + 1;
        }

        char carry = 0;
        size_t blocks = op.length / 4;
        size_t i = 0;
        for ( ; i < blocks; i += 4) {
#if defined(_BASE2_64)
            carry = _addcarry_u64(
                _addcarry_u64(
                    _addcarry_u64(
                        _addcarry_u64(carry, limbs[i], op.limbs[i], (unsigned long long*) &limbs[i])
                    , limbs[i + 1], op.limbs[i + 1], (unsigned long long*) &limbs[i + 1])
                , limbs[i + 2], op.limbs[i + 2], (unsigned long long*) &limbs[i + 2])
            , limbs[i + 3], op.limbs[i + 3], (unsigned long long*) &limbs[i + 3]);
#elif defined(_BASE2_32)
            carry = _addcarry_u32(carry, limbs[i], op.limbs[i], (unsigned int*) &limbs[i]);
            carry = _addcarry_u32(carry, limbs[i + 1], op.limbs[i + 1], (unsigned int*) &limbs[i + 1]);
            carry = _addcarry_u32(carry, limbs[i + 2], op.limbs[i + 2], (unsigned int*) &limbs[i + 2]);
            carry = _addcarry_u32(carry, limbs[i + 3], op.limbs[i + 3], (unsigned int*) &limbs[i + 3]);
#else
            cast_t sum = (cast_t) limbs[i] + op.limbs[i] + carry;
            limbs[i] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 1] + op.limbs[i + 1] + carry;
            limbs[i + 1] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 2] + op.limbs[i + 2] + carry;
            limbs[i + 2] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 3] + op.limbs[i + 3] + carry;
            limbs[i + 3] = sum;
            carry = sum >> BASE_BITS;
#endif
        }

        for ( ; i < op.length; ++i) {
            cast_t sum = (cast_t) limbs[i] + op.limbs[i] + carry;
            limbs[i] = sum;
            carry = sum >> BASE_BITS;
        }

        blocks = (length - op.length) / 4;

        for ( ; i < blocks; i += 4) {
#if defined(_BASE2_64)
            carry = _addcarry_u64(
                _addcarry_u64(
                    _addcarry_u64(
                        _addcarry_u64(carry, limbs[i], 0, (unsigned long long*) &limbs[i])
                    , limbs[i + 1], 0, (unsigned long long*) &limbs[i + 1])
                , limbs[i + 2], 0, (unsigned long long*) &limbs[i + 2])
            , limbs[i + 3], 0, (unsigned long long*) &limbs[i + 3]);
#elif defined(_BASE2_32)
            carry = _addcarry_u32(
                _addcarry_u32(
                    _addcarry_u32(
                        _addcarry_u32(carry, limbs[i], 0, (unsigned int*) &limbs[i])
                    , limbs[i + 1], 0, (unsigned int*) &limbs[i + 1])
                , limbs[i + 2], 0, (unsigned int*) &limbs[i + 2])
            , limbs[i + 3], 0, (unsigned int*) &limbs[i + 3]);
#else
            cast_t sum = (cast_t) limbs[i] + carry;
            limbs[i] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 1] + carry;
            limbs[i + 1] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 2] + carry;
            limbs[i + 2] = sum;
            carry = sum >> BASE_BITS;

            sum = (cast_t) limbs[i + 3] + carry;
            limbs[i + 3] = sum;
            carry = sum >> BASE_BITS;
#endif
        }

        for ( ; i < length; ++i) {
            cast_t sum = (cast_t) limbs[i] + carry;
            limbs[i] = sum;
            carry = sum >> BASE_BITS;
        }

        remove_leading_zeros();
        return *this;
    }

    integer integer::operator+(const integer &op) const {
        integer sum = *this;
        return sum += op;
    }

    integer &integer::operator-=(const integer &op) {
        limb_t carry = 0;

        for (size_t i = 0; i < op.length; ++i) {
            cast_t diff_index = (cast_t) limbs[i] - op.limbs[i] - carry;
            limbs[i] = diff_index;
            carry = (diff_index >> BASE_BITS);
            carry &= 0x01;
        }

        for (size_t i = op.length; i < length; ++i) {
            cast_t diff_index = (cast_t) limbs[i] - carry;
            limbs[i] = diff_index;
            carry = (diff_index >> BASE_BITS);
            carry &= 0x01;
        }

        remove_leading_zeros();
        return *this;
    }

    integer integer::operator-(const integer &op) const {
        integer dif = *this;
        return dif -= op;
    }

    integer &integer::operator*=(const integer &op) {
        integer product = *this * op;
        swap(product, *this);
        return *this;
    }

    integer integer::operator*(const integer &op) const {
        if (!(*this && op)) {
            return __INTEGER_ZERO;
        }

        limb_t *arr = (limb_t *) std::calloc(length + op.length, sizeof(limb_t));
        integer product(arr, length + op.length, length + op.length);

        cast_t index_product;
        limb_t carry;

        for (size_t i = 0; i < op.length; ++i) {
            carry = 0;
            for (size_t j = 0; j < length; ++j) {
                index_product = (cast_t) limbs[j] * op.limbs[i] + product.limbs[i + j] + carry;
                product.limbs[i + j] = index_product;
                carry = (index_product >> BASE_BITS);
            }
            product.limbs[i + length] += carry;
        }

        product.length -= !product.limbs[product.length - 1];
        return product;
    }

    integer &integer::operator/=(const integer &op) {
        integer quotient = *this / op;
        swap(quotient, *this);
        return *this;
    }

    integer integer::operator/(const integer &op) const {
        if (!op) {
            throw std::domain_error("apa::integer - Division By Zero");
        }

        int special_case = compare(op);
        switch (special_case) {
            case EQUAL:
                return __INTEGER_ONE;
            case LESS:
                return __INTEGER_ZERO;
        }

        if (op.length == 1 && op.limbs[0] == 1) {
            return *this;
        }

        return bit_division(op);
    }

    integer &integer::operator%=(const integer &op) {
        integer remainder = *this % op;
        swap(remainder, *this);
        return *this;
    }

    integer integer::operator%(const integer &op) const {
        if (!op) {
            throw std::domain_error("apa::integer - Division By Zero");
        }

        int special_case = compare(op);
        switch (special_case) {
            case EQUAL:
                return __INTEGER_ZERO;
            case LESS:
                return *this;
        }

        if (op.length == 1 && op.limbs[0] == 1) {
            return __INTEGER_ZERO;
        }

        return bit_modulo(op);
    }

    integer integer::bit_division(const integer &op) const {
        limb_t *arr = (limb_t *) std::calloc(length, sizeof(limb_t));
        integer quotient(arr, length, length), remainder(length, length);
        remainder.length = 1;
        remainder.limbs[0] = 0;
        limb_t bit = 0, current_index, current_shift_val, onebit = 1;
        size_t total_bits = length * BASE_BITS, ms_limb = length - 1;

        if (op.length == 1) {
            for (size_t i = 0; i < total_bits; ++i) {
                current_index = ms_limb - i / BASE_BITS;
                current_shift_val = i % BASE_BITS;

                remainder <<= 1;

                bit = limbs[current_index] << current_shift_val;
                bit >>= BASE_BITS_MINUS1;

                remainder.limbs[0] |= bit;

                if (remainder >= op) {
                    remainder -= op;
                    quotient.limbs[current_index] |= (onebit << (BASE_BITS_MINUS1 - current_shift_val));
                }
            }
        } else {
            for (size_t h = 0; h < total_bits; h += BASE_BITS) {
                current_index = ms_limb - h / BASE_BITS;
                remainder <<= BASE_BITS;
                remainder.limbs[0] |= limbs[current_index];

                if (remainder >= op) {
                    remainder >>= BASE_BITS;

                    for (size_t i = 0; i < BASE_BITS; ++i) {
                        current_index = ms_limb - (h + i) / BASE_BITS;
                        current_shift_val = (h + i) % BASE_BITS;

                        remainder <<= 1;

                        bit = limbs[current_index] << current_shift_val;
                        bit >>= BASE_BITS_MINUS1;

                        remainder.limbs[0] |= bit;

                        if (remainder >= op) {
                            remainder -= op;
                            quotient.limbs[current_index] |= (onebit << (BASE_BITS_MINUS1 - current_shift_val));
                        }
                    }
                }
            }
        }

        quotient.remove_leading_zeros();
        return quotient;
    }

    integer integer::bit_modulo(const integer &op) const {
        integer remainder(length, length);
        remainder.length = 1;
        remainder.limbs[0] = 0;

        limb_t bit = 0, current_index, current_shift_val;
        size_t total_bits = length * BASE_BITS, ms_limb = length - 1;

        if (op.length == 1) {
            for (size_t i = 0; i < total_bits; ++i) {
                current_index = ms_limb - i / BASE_BITS;
                current_shift_val = i % BASE_BITS;

                remainder <<= 1;

                bit = limbs[current_index] << current_shift_val;
                bit >>= BASE_BITS_MINUS1;

                remainder.limbs[0] |= bit;

                if (remainder >= op) {
                    remainder -= op;
                }
            }
        } else {
            for (size_t h = 0; h < total_bits; h += BASE_BITS) {
                current_index = ms_limb - h / BASE_BITS;
                remainder <<= BASE_BITS;
                remainder.limbs[0] |= limbs[current_index];

                if (remainder >= op) {
                    remainder >>= BASE_BITS;

                    for (size_t i = 0; i < BASE_BITS; ++i) {
                        current_index = ms_limb - (h + i) / BASE_BITS;
                        current_shift_val = (h + i) % BASE_BITS;

                        remainder <<= 1;

                        bit = limbs[current_index] << current_shift_val;
                        bit >>= BASE_BITS_MINUS1;

                        remainder.limbs[0] |= bit;

                        if (remainder >= op) {
                            remainder -= op;
                        }
                    }
                }
            }
        }

        return remainder;
    }

    // pre-fix increment/decrement
    integer &integer::operator++() {
        return *this += __INTEGER_ONE;
    }

    integer &integer::operator--() {
        return *this -= __INTEGER_ONE;
    }

    // post-fix increment/decrement
    integer integer::operator++(int) {
        integer prev = *this;
        ++*this;
        return prev;
    }

    integer integer::operator--(int) {
        integer prev = *this;
        --*this;
        return prev;
    }

    // Shift Operators
    integer &integer::operator<<=(size_t bits) {
        if (*this && bits) {
            cast_t old_msl;
            size_t limb_shifts = bits / BASE_BITS, bit_shifts = bits % BASE_BITS, new_length = length + limb_shifts + 1,
                   zero_limbs = new_length - length - 1;

            if (new_length > capacity) {
                capacity = new_length + LIMB_GROWTH;
                limbs = (limb_t *) std::realloc(limbs, capacity * LIMB_BYTES);
            }

            limbs[new_length - 1] = 0;

            for (size_t i = 0; i < length; ++i) {
                old_msl = limbs[length - 1 - i];
                old_msl <<= bit_shifts;
                limbs[new_length - 1 - i] |= old_msl >> BASE_BITS;
                limbs[new_length - 2 - i] = old_msl;
            }

            if (zero_limbs) {
                std::memset(limbs, 0x00, zero_limbs * LIMB_BYTES);
            }

            length = new_length;
            length -= !limbs[length - 1];
        }
        return *this;
    }

    integer &integer::operator>>=(size_t bits) {
        if (*this && bits) {
            size_t limb_shifts = bits / BASE_BITS;
            if (limb_shifts >= length) {
                length = 1;
                limbs[0] = 0;
            } else {
                size_t bit_shifts = bits % BASE_BITS;
                size_t new_length = length - limb_shifts;

                // initial limb shift
                limbs[0] = limbs[limb_shifts] >> bit_shifts;

                // looped shifts
                for (size_t i = 1; i < new_length; ++i) {
                    limb_t bit_catch = ((bit_shifts) ? (limbs[i + limb_shifts] << (BASE_BITS - bit_shifts)) : 0);
                    limbs[i] = limbs[i + limb_shifts] >> bit_shifts;
                    limbs[i - 1] |= bit_catch;
                }

                length = new_length;
                length -= !limbs[length - 1] && length != 1;
            }
        }
        return *this;
    }

    integer integer::operator<<(size_t bits) const {
        integer shifted = *this;
        return shifted <<= bits;
    }

    integer integer::operator>>(size_t bits) const {
        integer shifted = *this;
        return shifted >>= bits;
    }

    void integer::printHex() const {
        std::cout << "0x";
        printf(PRINT_LIMBHEX_NOPAD, (limb_t) limbs[length - 1]);
        for (size_t i = 1; i < length; ++i) {
            printf(PRINT_LIMBHEX, (limb_t) limbs[length - 1 - i]);
        }
        std::cout << "\n";
    }

    void integer::printHex_spaced_out() const {
        printf(PRINT_LIMBHEX, (limb_t) limbs[length - 1]);
        for (size_t i = 1; i < length; ++i) {
            printf(PRINT_LIMBHEX_SPACED, (limb_t) limbs[length - 1 - i]);
        }
        std::cout << "\n";
    }

    void integer::printBin_spaced_out() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << std::bitset<BASE_BITS>(limbs[length - 1 - i]) << " ";
        }
        std::cout << "\n";
    }

    void integer::printStatus(std::string printIdentifier) const {
        std::cout << "\n-----\n";
        std::cout << printIdentifier << "\n";
        std::cout << "capacity : " << capacity << "\n";
        std::cout << "length   : " << length << "\n";
        printHex_spaced_out();
    }

    std::string integer::to_base10_string() const {
        std::string Base10 = "";
        integer ten(10), quotient = *this;
        if (quotient) {
            while (quotient) {
                integer remainder = quotient % ten;
                quotient = quotient / ten;
                Base10.push_back('0' + remainder.limbs[0]);
            }

            std::reverse(Base10.begin(), Base10.end());
        } else {
            Base10 = "0";
        }
        return Base10;
    }

    std::string integer::to_base16_string() const {
        char buffer[17];
        std::string hexform = "";
        sprintf(buffer, PRINT_LIMBHEX_NOPAD, (limb_t) limbs[length - 1]);
        hexform.append(buffer);
        for (size_t i = 1; i < length; ++i) {
            sprintf(buffer, PRINT_LIMBHEX, (limb_t) limbs[length - 1 - i]);
            hexform.append(buffer);
        }
        return hexform;
    }

    // Methods

    size_t integer::byte_size() const {
        limb_t ms_limb = limbs[length - 1];
        size_t cnt = 0;
        while (ms_limb) {
            ms_limb >>= 8;
            cnt++;
        }
        return (length - 1) * BASE_BYTES + cnt;
    }

    size_t integer::bit_size() const {
        limb_t ms_limb = limbs[length - 1];
        size_t cnt = 0;
        while (ms_limb) {
            ms_limb >>= 1;
            cnt++;
        }
        return (length - 1) * BASE_BITS + cnt;
    }

    limb_t *integer::detach() {
        limb_t *detached = limbs;
        limbs = NULL;
        capacity = 0;
        length = 0;
        return detached;
    }

    void swap(integer &a, integer &b) {
        integer temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    // IO Operators
    std::ostream &operator<<(std::ostream &out, const integer &num) {
        out << num.to_base16_string();
        return out;
    }

    std::istream &operator>>(std::istream &in, integer &num) {
        std::string input;
        in >> input;
        num = integer(input, 16);
        return in;
    }
} // namespace apa

#endif