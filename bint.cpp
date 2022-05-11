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
        sign = 0;
    }

    bint::bint(bint_arg_t num) {
        if(num<0) {
            sign = 1;
            num = abs(num);
        }
        else {
            sign = 0;
        }
        number = ubint(num);
    }

    bint::bint(size_t capacity, size_t length, bool AllocateSpace) {
        number = ubint(capacity,length,AllocateSpace);
        sign = 0;
    }

    // constructor for conveniece
    bint::bint(std::string text, size_t base) {
        if(text[0]=='-') {
            sign = 1;
            text.erase(text.begin(),text.begin()+1);
        }
        else {
            sign = 0;
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
        return *this;
    }

    // Logical Operators
    bint::operator bool() const noexcept {
        return (number.length==1 && number.limbs[0]==0) ? false : true;
    }

    // Arithmetic Operators

    bint& bint::operator+=(const bint& op) {
        
        if(capacity<=op.length+1) {
            capacity = op.length+LIMB_GROWTH;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
        }
        
        if(length==capacity) {
            capacity = length+LIMB_GROWTH;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
        }

        if(length<=op.length) {
            memset(limbs+length, 0x0, ((op.length+1)-length)*LIMB_BYTES);
            length = op.length+1;
        }

        for(size_t i=0; i<op.length; ++i) {
            limbs[i] += op.limbs[i];
            limbs[i+1] += (limbs[i] >> BASE_BITS);
            limbs[i] = (base_t) limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limbs[i+1] += (limbs[i] >> BASE_BITS);
            limbs[i] = (base_t) limbs[i];
        }

        size_t ms_index = length-1;
        while(ms_index) {
            if(limbs[ms_index]) {
                break;
            }
            --ms_index;
        }

        length = ms_index+1;

        return *this;
    }

    bint bint::operator+(const bint& op) const {
        bint sum = *this;
        sum += op;
        return sum;
    }
    
    bint& bint::operator-=(const bint& op) {
        
        limb_t carry = 0;

        for(size_t i=0; i<op.length; ++i) {
            limbs[i] -= carry;
            limbs[i] -= op.limbs[i];

            carry = ((base_t)(limbs[i] >> BASE_BITS)) ? 1 : 0;
            limbs[i] = (base_t) limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limbs[i] -= carry;

            carry = ((base_t)(limbs[i] >> BASE_BITS)) ? 1 : 0;
            limbs[i] = (base_t) limbs[i];
        }

        size_t ms_index = length-1;
        while(ms_index) {
            if(limbs[ms_index]) {
                break;
            }
            --ms_index;
        }

        length = ms_index+1;

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

        bint product(length+op.length,length+op.length);
        memset(product.limbs,0x0,product.length*LIMB_BYTES);
        
        for(size_t i=0; i<op.length; ++i) {
            for(size_t j=0; j<length; ++j) {
                product.limbs[i+j] += limbs[j] * op.limbs[i];
                limb_t carry = product.limbs[i+j] >> BASE_BITS;

                if(carry) {
                    product.limbs[i+j] = (base_t) product.limbs[i+j];
                    product.limbs[i+j+1] += carry;
                }
            }
        }

        if(!product.limbs[product.length-1])
            product.length--;

        return product;
    }
    
    bint& bint::operator/=(const bint& op) {
        bint quotient = *this / op;
        swap(quotient,*this);
        return *this;
    }

    bint bint::operator/(const bint& op) const {

        if(!op)
            throw std::domain_error("apa::bint - Division By Zero");
            
        int special_case = this->compare(op);
        switch (special_case)
        {
            case EQUAL: return bint(1);
            case LESS : return bint(0);
        }
        if(op.length==1 && op.limbs[0]==1) return *this;
        return bit_division(op);
    }

    bint& bint::operator%=(const bint& op) {
        bint remainder = *this % op;
        swap(remainder,*this);
        return *this;
    }

    bint bint::operator%(const bint& op) const {

        if(!op)
            throw std::domain_error("apa::bint - Division By Zero");
            
        int special_case = this->compare(op);
        switch (special_case)
        {
            case EQUAL: return bint(0);
            case LESS : return *this;
        }
        if(op.length==1 && op.limbs[0]==1) return bint(0);
        return bit_modulo(op);
    }

    bint bint::bit_division(const bint& op) const {

        bint quotient(length,length), remainder(length,length);
        memset(quotient.limbs,0x00,length*LIMB_BYTES);
        remainder.length = 1; remainder.limbs[0] = 0;

        base_t bit = 0, current_index, current_shift_val, onebit = 1;
        size_t
            total_bits = length*BASE_BITS,
            ms_limb = length - 1;
        
        for(size_t i=0; i<total_bits; ++i) {
            current_index = ms_limb - i/BASE_BITS;
            current_shift_val = i % BASE_BITS;
            
            remainder <<= 1;

            bit = limbs[current_index] << current_shift_val;
            bit >>= BASE_BITS_MINUS1;

            remainder.limbs[0] |= bit;

            if(remainder >= op) {
                remainder -= op;
                quotient.limbs[current_index] |= (onebit << (BASE_BITS_MINUS1-current_shift_val));
            }
        }

        for(size_t i=0; i<length; ++i) {
            if(quotient.limbs[length-1-i]) {
                quotient.length -= i;
                break;
            }
        }

        return quotient;
    }

    bint bint::bit_modulo(const bint& op) const {
        
        bint remainder(length,length);
        remainder.length = 1; remainder.limbs[0] = 0;

        base_t bit = 0, current_index, current_shift_val;
        size_t
            total_bits = length*BASE_BITS,
            ms_limb = length - 1;
        
        for(size_t i=0; i<total_bits; ++i) {
            current_index = ms_limb - i/BASE_BITS;
            current_shift_val = i % BASE_BITS;
            
            remainder <<= 1;

            bit = limbs[current_index] << current_shift_val;
            bit >>= BASE_BITS_MINUS1;

            remainder.limbs[0] |= bit;

            if(remainder >= op) {
                remainder -= op;
            }
        }

        return remainder;
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

        if(*this) {
            size_t limb_shifts = bits / BASE_BITS;
            size_t bit_shifts = bits % BASE_BITS;

            size_t new_length = length + limb_shifts + 1;
            if(new_length>capacity) {
                capacity = new_length+LIMB_GROWTH;
                limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
            }

            limbs[new_length-1] = 0;

            for(size_t i=0; i<length; ++i) {
                limbs[length-1-i] <<= bit_shifts;
                limbs[new_length-1-i] |= limbs[length-1-i] >> BASE_BITS;
                limbs[new_length-2-i] = (base_t) limbs[length-1-i];
            }

            size_t zero_limbs = new_length-length-1;
            if(zero_limbs)
                memset(limbs,0x00,zero_limbs*LIMB_BYTES);

            length = new_length;
            if(!limbs[length-1])
                length--;
        }

        return *this;
    }

    bint& bint::operator>>=(size_t bits) {

        if(*this) {
            size_t limb_shifts = bits / BASE_BITS;
            
            if(limb_shifts>=length) {
                length = 1;
                limbs[0] = 0;
            }
            else {
                size_t bit_shifts = bits % BASE_BITS;
                size_t new_length = length - limb_shifts;

                limbs[new_length-1] = 0;
                limb_t prev = 0;

                for(size_t i=0; i<new_length; ++i) {
                    limbs[length-1-i] <<= BASE_BITS - bit_shifts;
                    limbs[new_length-1-i] = prev;
                    limbs[new_length-1-i] |= limbs[length-1-i] >> BASE_BITS;
                    prev = (base_t) limbs[length-1-i];
                }

                length = new_length;
                if(!limbs[length-1] && length!=1)
                    length--;
            }
        }

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
        
        std::cout << "0x";
        printf(PRINT_LIMBHEX_NOPAD, (base_t) limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX, (base_t) limbs[length-1-i]);
        std::cout << "\n";
    }

    void bint::printHex_spaced_out() const {

        printf(PRINT_LIMBHEX, (base_t) limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX_SPACED, (base_t) limbs[length-1-i]);
        std::cout << "\n";
    }

    void bint::printStatus(std::string printIdentifier) const {
        std::cout << "\n-----\n";
        std::cout << printIdentifier << "\n";
        std::cout << "capacity : " << capacity << "\n";
        std::cout << "length   : " << length << "\n";
        printHex_spaced_out();
    }

    void swap(bint& a, bint& b) {
        bint temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    std::string bint::to_base10_string() const {
        std::string Base10 = "";
        bint ten(10), quotient = *this;

        if(quotient) {
            while(quotient) {
                bint remainder = quotient % ten;
                quotient = quotient / ten;
                Base10.push_back('0'+remainder.limbs[0]);
            }

            std::reverse(Base10.begin(),Base10.end());    
        }
        else Base10 = "0";
        
        return Base10;
    }

    std::string bint::to_base16_string() const {

        char buffer[17];
        std::string hexform = "";

        sprintf(buffer,PRINT_LIMBHEX_NOPAD,(base_t)limbs[length-1]);
        hexform.append(buffer);

        for(size_t i=1; i<length; ++i) {
            sprintf(buffer,PRINT_LIMBHEX,(base_t)limbs[length-1-i]);
            hexform.append(buffer);
        }

        return hexform;
    }

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const bint &num)
    {
        out << num.to_base16_string();
        return out;
    }

    std::istream& operator>>(std::istream &in, bint &num)
    {
        std::string input;
        in >> input;
        num = bint(input,16);
        return in;
    }
}

#endif
