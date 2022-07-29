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
        return this->compare(op)==LESS ? true : false;
    }

    bool bint::operator>(const bint& op) const {
        return this->compare(op)==GREAT ? true : false;
    }

    bool bint::operator==(const bint& op) const {
        return this->compare(op)==EQUAL ? true : false;
    }

    bool bint::operator!=(const bint& op) const {
        return !(*this==op);
    }

    bool bint::operator<=(const bint& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==LESS) ? true : false;
    }

    bool bint::operator>=(const bint& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==GREAT) ? true : false;
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

    bint bint::operator*(const bint& op) const {
        return mul_naive(op);
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
