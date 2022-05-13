#ifndef UNSIGNED_BIG_INTEGER_CPP
#define UNSIGNED_BIG_INTEGER_CPP

#ifdef _MAKE_LIB
#include "bint.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
#include "bint.hpp"
#endif

namespace apa {

    bint::bint() {
        number = ubint();
        sign = POSITIVE;
    }

    bint::bint(bint_arg_t num) {
        if(num<0) {
            sign = NEGATIVE;
            num = abs(num);
        }
        else {
            sign = POSITIVE;
        }
        number = ubint(num);
    }

    bint::bint(size_t capacity, size_t length, bool AllocateSpace) {
        number = ubint(capacity,length,AllocateSpace);
        sign = POSITIVE;
    }

    // constructor for conveniece
    bint::bint(std::string text, size_t base) {
        if(text[0]=='-') {
            sign = NEGATIVE;
            text.erase(text.begin(),text.begin()+1);
        }
        else {
            sign = POSITIVE;
        }
        number = ubint(text);
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
        number = src.number;
        sign = src.sign;

        return *this;
    }

    /// move assignment.
    bint& bint::operator=(bint&& src) noexcept {
        number = std::move(src.number);
        sign = src.sign;

        return *this;
    }

    bint::bint(std::initializer_list<base_t> limbs, uint8_t sign) {
        number = ubint(limbs);
        this->sign = sign;
    }

    bint::~bint() {}

    /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
    int bint::compare(const bint& op) const {
        if(LPOS_RNEG(sign,op.sign))      return  1;
        else if(LNEG_RPOS(sign,op.sign)) return -1;
        else if(SIGN_NEGATIVE(sign)) {
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

    bint& bint::operator&=(const bint& op) {
        return *this;
    }

    bint bint::operator&(const bint& op) const {
        return *this;
    }

    bint& bint::operator|=(const bint& op) {
        return *this;
    }

    bint bint::operator|(const bint& op) const {
        return *this;
    }

    bint& bint::operator^=(const bint& op) {
        return *this;
    }

    bint bint::operator^(const bint& op) const {
        return *this;
    }

    bint bint::operator~() const {
        bint bwn = *this;
        if(SIGN_NEGATIVE(sign)) {
            bwn -= 1;
        } else {
            bwn += 1;
        }
        bwn.sign = !bwn.sign;
        return *this;
    }

    // Logical Operators
    bint::operator bool() const noexcept {
        return(number.limb_size()==1 && number[0]==0) ? false : true;
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
            }
        }
        else {
            number += op.number;
        }
        return *this;
    }

    bint bint::operator+(const bint& op) const {
        bint sum = *this;
        sum += op;
        return sum;
    }
    
    bint& bint::operator-=(const bint& op) {
        int cmp = compare(op);
        if(sign!=op.sign) {
            number += op.number; // correct - final
        }
        else {
            if(cmp==EQUAL) {
                number.set_length(1);
                number[0] = 0;
            }
            else if(SIGN_NEGATIVE(sign)) {
                switch (cmp)
                {
                    case GREAT: {
                        number = op.number - number;
                        sign = POSITIVE;
                    } break;
                    case LESS: {
                        number -= op.number;
                        sign = NEGATIVE;
                    } break;
                }
            }
            else {
                switch (cmp)
                {
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
        dif -= op;
        return dif;
    }
    
    bint& bint::operator*=(const bint& op) {
        bint product = *this * op;
        swap(product,*this);
        return *this;
    }

    bint bint::operator*(const bint& op) const {
        bint product = 0;
        product.number = number * op.number;
        product.sign = (sign==op.sign) ? 0 : 1;
        return product;
    }
    
    bint& bint::operator/=(const bint& op) {
        bint quotient = *this / op;
        swap(quotient,*this);
        return *this;
    }

    bint bint::operator/(const bint& op) const {
        bint quotient = 0;
        quotient.number = number / op.number;
        quotient.sign = (sign==op.sign) ? 0 : 1;
        return quotient;
    }

    bint& bint::operator%=(const bint& op) {
        bint remainder = *this % op;
        swap(remainder,*this);
        return *this;
    }

    bint bint::operator%(const bint& op) const {
        bint modulo = 0;
        modulo.number = number % op.number;
        modulo.sign = (sign==op.sign) ? sign : !sign;
        return modulo;
    }

    // pre-fix increment/decrement
    bint& bint::operator++() {
        *this += __bint_ONE;
        return *this;
    }

    bint& bint::operator--() {
        *this -= __bint_ONE;
        return *this;
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
        if(number) number <<= bits;
        return *this;
    }

    bint& bint::operator>>=(size_t bits) {
        if(number) number >>= bits;
        return *this;
    }

    bint bint::operator<<(size_t bits) const {
        bint shifted = *this;
        shifted <<= bits;
        return shifted;
    }

    bint bint::operator>>(size_t bits) const {
        bint shifted = *this;
        shifted >>= bits;
        return shifted;
    }

    void bint::printHex() const {
        if(SIGN_NEGATIVE(sign)) std::cout << "-";
        number.printHex();
    }

    void bint::printHex_spaced_out() const {
        number.printHex_spaced_out();
        std::cout << (SIGN_NEGATIVE(sign)) ? "\nNegative:" : "\nPositive\n";
    }

    void bint::printStatus(std::string printIdentifier) const {
        number.printStatus();
        std::cout << (SIGN_NEGATIVE(sign)) ? "\nNegative:" : "\nPositive\n";
    }

    std::string bint::to_base10_string() const {
        std::string Base10 = "";
        if(SIGN_NEGATIVE(sign)) Base10.push_back('-');
        Base10.append(number.to_base10_string());
        return Base10;
    }

    std::string bint::to_base16_string() const {
        std::string Base16 = "";
        if(SIGN_NEGATIVE(sign)) Base16.push_back('-');
        Base16.append(number.to_base16_string());
        return Base16;
    }

    // Member Access Methods
    size_t bint::capacity_size() const {
        return number.capacity_size();
    }

    size_t bint::limb_size() const {
        return number.limb_size();
    }

    size_t bint::byte_size() const {
        return number.byte_size();
    }

    size_t bint::bit_size() const {
        return number.bit_size();
    }

    const limb_t *bint::limb_view() const {
        return number.limb_view();
    }

    const uint8_t *bint::byte_view() const {
        return number.byte_view();
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
