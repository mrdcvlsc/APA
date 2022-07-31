#ifndef SIGNED_BIG_INTEGER_CPP
#define SIGNED_BIG_INTEGER_CPP

#ifdef _MAKE_LIB
#include "bint.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
#include "bint.hpp"
#endif

namespace apa {

    bint::bint() {

        number = integer();
        sign = POSITIVE;
    }

    bint::bint(bint_arg_t num) {

        if(num<0) {
            sign = NEGATIVE;
            num = std::abs(num);
        } else {
            sign = POSITIVE;
        }
        number = integer(num);
    }

    bint::bint(size_t capacity, size_t length, bool AllocateSpace) {

        number = integer(capacity,length,AllocateSpace);
        sign = POSITIVE;
    }

    // constructor for conveniece
    bint::bint(std::string text, size_t base) {

        if(text[0]=='-') {
            sign = NEGATIVE;
            text.erase(text.begin(),text.begin()+1);
        } else {
            sign = POSITIVE;
        }
        number = integer(text,base);
    }

    // read only constuctor
    bint::bint(limb_t* arr, size_t capacity, size_t length, uint8_t sign) {
        number = integer(arr, capacity, length);
        this->sign = sign;
    }

    /// copy constructor.
    bint::bint(const bint& src) {

        number = src.number;
        sign = src.sign;
    }

    /// move constructor.
    bint::bint(bint&& src) noexcept {

        number = std::move(src.number);
        sign = src.sign;
    }

    /// copy assignment.
    bint& bint::operator=(const bint& src) {
        
        if(this != &src) {
            number = src.number;
            sign = src.sign;
        }
        return *this;
    }

    /// move assignment.
    bint& bint::operator=(bint&& src) noexcept {

        if(this != &src) {
            number = std::move(src.number);
            sign = src.sign;
        }
        return *this;
    }

    bint::bint(uint8_t sign, const integer& number) {

        this->number = number;
        this->sign = sign;
    }
    
    bint::bint(uint8_t sign, integer&& number) noexcept {

        this->number = std::move(number);
        this->sign = sign;
    }
    

    bint::bint(std::initializer_list<base_t> limbs, uint8_t sign) {

        number = integer(limbs);
        this->sign = sign;
    }

    bint::~bint() {}

    int bint::compare(const bint& op) const {

        if(LPOS_RNEG(sign,op.sign)) {
            return  GREAT;
        } else if(LNEG_RPOS(sign,op.sign)) {
            return LESS;
        } else if(SIGN_NEGATIVE(sign)) {
            return CMP_RES_FLIP(number.compare(op.number));
        }

        return number.compare(op.number);
    }

    // Logical Operators

    bool bint::operator<(const bint& op) const {
        return this->compare(op)==LESS;
    }

    bool bint::operator>(const bint& op) const {
        return this->compare(op)==GREAT;
    }

    bool bint::operator==(const bint& op) const {
        return this->compare(op)==EQUAL;
    }

    bool bint::operator!=(const bint& op) const {
        return !(*this==op);
    }

    bool bint::operator<=(const bint& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==LESS);
    }

    bool bint::operator>=(const bint& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==GREAT);
    }

    // Bit-Wise Logical Operators

    void bint::bitwise_prepare(bint& left, bint& right) {

        size_t lpadding = 0, rpadding = 0;

        if(left.limb_size() < right.limb_size()) {
            lpadding = right.limb_size() - left.limb_size();
        } else {
            rpadding = left.limb_size() - right.limb_size();
        }

        if(SIGN_NEGATIVE(left.sign)) {
            left.number.bit_flip(lpadding);
            ++left.number;
        }

        if(SIGN_NEGATIVE(right.sign)) {
            right.number.bit_flip(rpadding);
            ++right.number;
        }

        if(lpadding) {
            left.number.bit_realloc(right.number);
        }

        if(rpadding) {
            right.number.bit_realloc(left.number);
        }
    }

    bint& bint::operator&=(const bint& op) {

        if(sign | op.sign) {
            bint left = *this, right = op;
            
            bitwise_prepare(left,right);

            left.number.bit_and(right.number);
            left.sign &= right.sign;

            if(SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this,left);
            
        } else {
            number &= op.number;
        }
        return *this;
    }

    bint bint::operator&(const bint& op) const {
        bint bw = *this;
        return bw &= op;
    }

    bint& bint::operator|=(const bint& op) {
        if(sign | op.sign) {
            bint left = *this, right = op;
            
            bitwise_prepare(left,right);

            left.number.bit_or(right.number);
            left.sign |= right.sign;

            if(SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this,left);
            
        } else {
            number |= op.number;
        }
        return *this;
    }

    bint bint::operator|(const bint& op) const {
        bint bw = *this;
        return bw |= op;
    }

    bint& bint::operator^=(const bint& op) {
        if(sign | op.sign) {
            bint left = *this, right = op;
            
            bitwise_prepare(left,right);

            left.number.bit_xor(right.number);
            left.sign ^= right.sign;

            if(SIGN_NEGATIVE(left.sign)) {
                left.number.bit_flip(0);
                ++left.number;
            }

            left.number.remove_leading_zeros();
            swap(*this,left);
            
        } else {
            number ^= op.number;
        }
        return *this;
    }

    bint bint::operator^(const bint& op) const {
        bint bw = *this;
        return bw ^= op;
    }

    bint bint::operator~() const {
        
        bint bwn = *this;
        if(SIGN_NEGATIVE(sign)) {
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
    bint& bint::operator+=(const bint& op) {

        int cmp = number.compare(op.number);
        if(sign!=op.sign) {
            switch (cmp) {
                case GREAT: {
                    number -= op.number;
                } break;
                case LESS : {
                    number = op.number - number;
                    sign = op.sign;
                } break;
                default : {
                    number.length = 1;
                    number[0] = 0;
                    sign = POSITIVE;
                }
            }
        } else {
            number += op.number;
        }

        return *this;
    }

    bint bint::operator+(const bint& op) const {
        
        bint sum = *this;
        return sum += op;
    }
    
    bint& bint::operator-=(const bint& op) {

        int cmp = compare(op);
        if(sign!=op.sign) {
            number += op.number; // correct - final
        }
        else {
            if(cmp==EQUAL) {
                number.length = 1;
                number[0] = 0;
            } else if(SIGN_NEGATIVE(sign)) {
                switch(cmp) {
                    case GREAT: {
                        number = op.number - number;
                        sign = POSITIVE;
                    } break;
                    case LESS: {
                        number -= op.number;
                        sign = NEGATIVE;
                    } break;
                }
            } else {
                switch(cmp) {
                    case GREAT: {
                        number -= op.number;
                        sign = POSITIVE;
                    } break;
                    case LESS: {
                        number = op.number - number;
                        sign = NEGATIVE;
                    } break;
                }
            }
        }

        return *this;
    }

    bint bint::operator-(const bint& op) const {

        bint dif = *this;
        return dif -= op;
    }
    
    bint& bint::operator*=(const bint& op) {

        bint product = *this * op;
        swap(product,*this);
        return *this;
    }

    bint bint::mul_naive(const bint& op) const {
        
        bint product(!(sign==op.sign), number * op.number);
        
        if(!product.number){
            product.sign = 0;
        }

        return product;
    }

    bint bint::add_partial(
        const limb_t* l, size_t l_len, size_t l_index,
        const limb_t* r, size_t r_len, size_t r_index
    ) {
        size_t len = std::max(l_len, r_len) + 1;
        bint sum(len + 1, len);
        std::memset(sum.number.limbs, 0x00, LIMB_BYTES*sum.number.capacity);

        for(size_t i=0; i<l_len; ++i) {
            sum.number.limbs[i] += l[l_index+i];
        }

        for(size_t i=0; i<r_len; ++i) {
            sum.number.limbs[i] += r[r_index+i];
        }

        // carry
        for(size_t i=0; i<sum.number.length; ++i) {
            sum.number.limbs[i+1] += (sum.number.limbs[i] >> BASE_BITS);
            sum.number.limbs[i] = (base_t) sum.number.limbs[i];
        }

        sum.number.remove_leading_zeros();
        return sum;
    }

    void bint::sub_partial(
        limb_t* output, size_t out_len, size_t out_index,
        const limb_t* m, size_t m_len, size_t m_index
    ) {
        limb_t carry = 0;

        for(size_t i=0; i<m_len; ++i) {
            output[i+out_index] -= carry;
            output[i+out_index] -= m[i+m_index];

            carry = !!(base_t)(output[i+out_index] >> BASE_BITS);
            output[i+out_index] = (base_t) output[i+out_index];
        }

        for(size_t i=m_len; i<out_len; ++i) {
            output[i+out_index] -= carry;

            carry = !!(base_t)(output[i+out_index] >> BASE_BITS);
            output[i+out_index] = (base_t) output[i+out_index];
        }
    }

    void bint::mul_karatsuba(
        limb_t* output,
        const limb_t* l, size_t l_len, size_t l_index,
        const limb_t* r, size_t r_len, size_t r_index
    ) {
        if(r_len < KARATSUBA_SIZE || l_len < KARATSUBA_SIZE) {           
            for(size_t i=0; i<r_len; ++i) {
                for(size_t j=0; j<l_len; ++j) {
                    output[i+j] += l[j+l_index] * r[i+r_index];
                    limb_t carry = output[i+j] >> BASE_BITS;

                    if(carry) {
                        output[i+j] = (base_t) output[i+j];
                        output[i+j+1] += carry;
                    }
                }
            }
            return;
        }

        size_t max_len = std::max(l_len, r_len);
        size_t split_len = max_len - (max_len / 2);

        // prep logics
        size_t a_len, b_len, c_len, d_len;
        
        // left hand side split
        if(l_len > split_len) {
            a_len = l_len - split_len;
            b_len = split_len;
        } else {
            a_len = 0;
            b_len = l_len;
        }

        // right hand side split
        if(r_len > split_len) {
            c_len = r_len - split_len;
            d_len = split_len;
        } else {
            c_len = 0;
            d_len = r_len;
        }

        // karatsuba

        // z0 --------------------------------------------------------------
        size_t z0_padding = split_len*2;
        mul_karatsuba(
            output + z0_padding,
            l, a_len, split_len + l_index,
            r, c_len, split_len + r_index
        );
        bint z0;
        if (a_len && c_len) {
            z0 = bint(output + z0_padding, a_len + c_len + 1, a_len + c_len, 0);
        } else {
            z0 = bint(__BINT_ZERO.number.limbs, 1, 1, 0);
        }
        z0.number.remove_leading_zeros();

        // z1 --------------------------------------------------------------
        mul_karatsuba(output, l, b_len, l_index, r, d_len, r_index);
        bint z1 = bint(output, b_len + d_len + 1, b_len + d_len, 0);
        z1.number.remove_leading_zeros();

        // z2 --------------------------------------------------------------
        bint lsplit_add, rsplit_add;

        if(a_len) {
            lsplit_add = add_partial(l, a_len, split_len + l_index, l, b_len, l_index);
        } else {
            lsplit_add = add_partial(__BINT_ZERO.number.limbs, 1, 0, l, b_len, l_index);
        }

        if(c_len) {
            rsplit_add = add_partial(r, c_len, split_len + r_index, r, d_len, r_index);
        } else {
            rsplit_add = add_partial(__BINT_ZERO.number.limbs, 1, 0, r, d_len, r_index);
        }

        bint z2(lsplit_add.number.length + rsplit_add.number.length + 1, lsplit_add.number.length + rsplit_add.number.length);
        std::memset(z2.number.limbs, 0x00, z2.number.capacity * LIMB_BYTES);
        mul_karatsuba(
            z2.number.limbs,
            lsplit_add.number.limbs, lsplit_add.number.length, 0,
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
        for(size_t i=0; i<z3.number.length; ++i) {
            output[i+split_len] += z3.number.limbs[i];
            output[i+1+split_len] += (output[i+split_len] >> BASE_BITS);
            output[i+split_len] = (base_t) output[i+split_len];
        }
    }

    bint bint::operator*(const bint& op) const {

        if(number.length < KARATSUBA_SIZE || op.number.length < KARATSUBA_SIZE) {
            return mul_naive(op);
        }

        size_t len = number.length + op.number.length;
        bint product(len + 1, len);
        std::memset(product.number.limbs, 0x00, product.number.capacity * LIMB_BYTES);
        mul_karatsuba(
            product.number.limbs,
            number.limbs, number.length, 0,
            op.number.limbs, op.number.length, 0
        );
        product.number.remove_leading_zeros();
        product.sign = !(sign == op.sign);
        return product;
    }
    
    bint& bint::operator/=(const bint& op) {

        bint quotient = *this / op;
        swap(quotient,*this);
        return *this;
    }

    bint bint::operator/(const bint& op) const {

        bint quotient(!(sign==op.sign), number / op.number);
        
        if(!quotient.number){
            quotient.sign = 0;
        }

        return quotient;
    }

    bint& bint::operator%=(const bint& op) {

        bint remainder = *this % op;
        swap(remainder,*this);
        return *this;
    }
    
    bint bint::operator%(const bint& op) const {
        
        bint mod(sign, number % op.number);

        if(!mod.number){
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
    bint& bint::operator++() {
        return *this += __BINT_ONE;
    }

    bint& bint::operator--() {
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
    bint& bint::operator<<=(size_t bits) {

        if(number) {
            number <<= bits;
        }
        return *this;
    }

    bint& bint::operator>>=(size_t bits) {

        if(number) {
            number >>= bits;
            if(SIGN_NEGATIVE(sign)) {
                ++number;
            }
        }
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

        if(SIGN_NEGATIVE(sign)) {
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
        if(SIGN_NEGATIVE(sign)) {
            Base10.push_back('-');
        }

        Base10.append(number.to_base10_string());
        return Base10;
    }

    std::string bint::to_base16_string() const {

        std::string Base16 = "";
        if(SIGN_NEGATIVE(sign)) {
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
        return (const limb_t*) number.limbs;
    }

    const uint8_t *bint::byte_view() const {
        return (const uint8_t*) number.limbs;
    }

    limb_t* bint::detach() {
        sign = 0;
        return number.detach();
    }

    void swap(bint& a, bint& b) {

        bint temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const bint &num) {

        out << num.to_base16_string();
        return out;
    }

    std::istream& operator>>(std::istream &in, bint &num) {
        
        std::string input;
        in >> input;
        num = bint(input,16);
        return in;
    }
}

#endif
