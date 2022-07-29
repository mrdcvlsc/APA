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

    bint bint::add_partial(
        const bint& l, size_t l_len, size_t l_index,
        const bint& r, size_t r_len, size_t r_index
    ) {

        std::cout << "add_partial : call\n";

        size_t len = std::max(l_len, r_len) + 1;
        bint sum(len + 1, len);
        std::memset(sum.number.limbs, 0x00, LIMB_BYTES*sum.number.capacity);

        std::cout << "\n\nadd_partial : raw display start\n";
        for(size_t i=0; i<sum.number.length;++i) {
            std::cout << (base_t) sum.number[sum.number.length-1-i] << " ";
        }

        std::cout << "\nadd_partial : left addition\n";
        for(size_t i=0; i<l_len; ++i) {
            sum.number.limbs[i] += l.number.limbs[l_index+i];
            std::cout << (base_t)l.number.limbs[l_index+i] << " ";
        }

        std::cout << "\n\nadd_partial : display first add\n";
        for(size_t i=0; i<sum.number.length;++i) {
            std::cout << (base_t) sum.number[sum.number.length-1-i] << " ";
        }

        std::cout << "\nadd_partial : right addition\n";
        for(size_t i=0; i<r_len; ++i) {
            sum.number.limbs[i] += r.number.limbs[r_index+i];
            std::cout << (base_t)r.number.limbs[r_index+i] << " ";
        }

        std::cout << "\n\nadd_partial : display second add\n";
        for(size_t i=0; i<sum.number.length;++i) {
            std::cout << (base_t) sum.number[sum.number.length-1-i] << " ";
        }

        std::cout << "\nadd_partial : carry\n";
        // carry
        for(size_t i=0; i<sum.number.length; ++i) {
            sum.number.limbs[i+1] += (sum.number.limbs[i] >> BASE_BITS);
            sum.number.limbs[i] = (base_t) sum.number.limbs[i];
        }

        std::cout << "\n\nadd_partial : raw display before leading\n";
        for(size_t i=0; i<sum.number.length;++i) {
            std::cout << (base_t) sum.number[sum.number.length-1-i] << " ";
        }

        std::cout << "add_partial : remove leading\n";
        sum.number.remove_leading_zeros();

        std::cout << "\n\nadd_partial : raw display end\n";
        for(size_t i=0; i<sum.number.length;++i) {
            std::cout << (base_t) sum.number[sum.number.length-1-i] << " ";
        }

        std::cout << "\n\nadd partial : return\n";
        return sum;
    }

    bint bint::mul_karatsuba(
        const bint& l, size_t l_len, size_t l_index,
        const bint& r, size_t r_len, size_t r_index
    ) {
        std::cout << "mul_karatsuba call\n";
        if(r_len < KARATSUBA_SIZE || l_len < KARATSUBA_SIZE) {

            std::cout << "mul_karatsuba : naive case\n";

            bint product(l_len + r_len + 1, l_len + r_len);
            memset(product.number.limbs,0x00,product.number.capacity*LIMB_BYTES);
            
            std::cout << "mul_karatsuba : naive case - multiply\n";
            for(size_t i=0; i<r_len; ++i) {
                for(size_t j=0; j<l_len; ++j) {
                    product.number.limbs[i+j] += l.number.limbs[j+l_index] * r.number.limbs[i+r_index];
                    limb_t carry = product.number.limbs[i+j] >> BASE_BITS;

                    if(carry) {
                        product.number.limbs[i+j] = (base_t) product.number.limbs[i+j];
                        product.number.limbs[i+j+1] += carry;
                    }
                }
            }

            std::cout << "mul_karatsuba : naive case - remove leading\n";
            if(!product.number.limbs[product.number.length-1]) {
                product.number.length--;
            }

            return product;
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

        std::cout << "mul_karatsuba : z0\n";
        bint z0 = (a_len && c_len) ? mul_karatsuba(l, a_len, split_len, r, c_len, split_len) : __BINT_ZERO;

        std::cout << "mul_karatsuba : z1\n";
        bint z1 = mul_karatsuba(l, b_len, l_index, r, d_len, r_index);

        bint lsplit_add, rsplit_add;

        std::cout << "mul_karatsuba : split add a+b\n";
        if(a_len) {
            lsplit_add = add_partial(l, a_len, split_len, l, b_len, l_index);
        } else {
            lsplit_add = add_partial(__BINT_ZERO, 1, 0, l, b_len, l_index);
        }

        std::cout << "mul_karatsuba : split add c+d\n";
        if(c_len) {
            rsplit_add = add_partial(r, c_len, split_len, r, d_len, r_index);
        } else {
            rsplit_add = add_partial(__BINT_ZERO, 1, 0, r, d_len, r_index);
        }
    
        std::cout << "mul_karatsuba : z2\n";
        bint z2 = mul_karatsuba(
            lsplit_add, lsplit_add.number.length, 0,
            rsplit_add, rsplit_add.number.length, 0
        );

        std::cout << "\n\na_len | a_index = " << a_len << " | " << split_len << "\n";
        std::cout << "b_len | b_index = " << b_len << " | " << l_index << "\n";
        std::cout << "\nc_len | c_index = " << c_len << " | " << split_len << "\n";
        std::cout << "d_len | d_index = " << d_len << " | " << r_index << "\n\n";
        std::cout << "add_partial : a+b = " << lsplit_add.to_base16_string() << "\n";
        std::cout << "add_partial : c+d = " << rsplit_add.to_base16_string() << "\n";

        lsplit_add.printHex_spaced_out();
        rsplit_add.printHex_spaced_out();
        std::cout << "lsa * rsa = " << lsplit_add.mul_naive(rsplit_add) << "\n\n";

        std::cout << "\n\nmul_karatsuba : z3\n";
        bint z3 = z2 - z1 - z0;

        // z4 addition
        
        std::cout << "mul_karatsuba : z4\n";
        size_t z4_len = l_len + r_len;
        bint z4(z4_len + 1, z4_len);
        std::memset(z4.number.limbs, 0x00, LIMB_BYTES*z4.number.capacity);

        std::cout << "mul_karatsuba : z4 + z1\n";
        for(size_t i=0; i<z1.number.length; ++i) {
            z4.number.limbs[i] = z1.number.limbs[i];
        }

        std::cout << "mul_karatsuba : z4 + z3\n";
        for(size_t i=0; i<z3.number.length; ++i) {
            z4.number.limbs[i+split_len] += z3.number.limbs[i];
            z4.number.limbs[i+1+split_len] += (z4.number.limbs[i+split_len] >> BASE_BITS);
            z4.number.limbs[i+split_len] = (base_t) z4.number.limbs[i+split_len];
        }

        std::cout << "mul_karatsuba : z4 + z0\n";
        size_t z3_padding = split_len*2;
        for(size_t i=0; i<z0.number.length; ++i) {
            z4.number.limbs[i+z3_padding] += z0.number.limbs[i];
            z4.number.limbs[i+1+z3_padding] += (z4.number.limbs[i+z3_padding] >> BASE_BITS);
            z4.number.limbs[i+z3_padding] = (base_t) z4.number.limbs[i+z3_padding];
        }

        std::cout << "mul_karatsuba : z4 remove leading\n";
        z4.number.remove_leading_zeros();

        std::cout << "\nz0 = " << z0.to_base16_string() << "\n";
        std::cout << "z1 = " << z1.to_base16_string() << "\n";
        std::cout << "z2 = " << z2.to_base16_string() << "\n";
        std::cout << "z3 = " << z3.to_base16_string() << "\n";
        std::cout << "z4 = " << z4.to_base16_string() << "\n";

        std::cout << "mul_karatsuba : return\n";

        std::cout << "\nmax_len   = " << max_len << "\n";
        std::cout << "split_len = " << split_len << "\n";
        return z4;
    }

    bint bint::operator*(const bint& op) const {

        if(number.length < KARATSUBA_SIZE || op.number.length < KARATSUBA_SIZE) {
            return mul_naive(op);
        }

        return mul_karatsuba(
            *this, number.length, 0,
            op, op.number.length, 0
        );
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
