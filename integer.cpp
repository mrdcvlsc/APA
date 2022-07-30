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

    unsigned char HEX_TO_CHAR[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f',};

    unsigned char CHAR_TO_HEX(unsigned char c) {

        switch (c) {
            case '0': return 0x0;
            case '1': return 0x1;
            case '2': return 0x2;
            case '3': return 0x3;
            case '4': return 0x4;
            case '5': return 0x5;
            case '6': return 0x6;
            case '7': return 0x7;
            case '8': return 0x8;
            case '9': return 0x9;
            case 'a': return 0xa;
            case 'b': return 0xb;
            case 'c': return 0xc;
            case 'd': return 0xd;
            case 'e': return 0xe;
            case 'f': return 0xf;
        }

        return 0xff;
    }

    integer::integer() {

        capacity = INITIAL_LIMB_CAPACITY;
        length = INITIAL_LIMB_LENGTH;
        limbs = (limb_t*) std::malloc(INITIAL_LIMB_CAPACITY*LIMB_BYTES);
    }

    integer::integer(base_t num) {

        capacity = INITIAL_LIMB_CAPACITY;
        length = INITIAL_LIMB_LENGTH;
        limbs = (limb_t*) std::malloc(INITIAL_LIMB_CAPACITY*LIMB_BYTES);
        limbs[0] = num;
    }

    integer::integer(size_t capacity, size_t length, bool AllocateSpace) {

        this->capacity = capacity;
        this->length = length;

        if(AllocateSpace) {
            limbs = (limb_t*) std::malloc(capacity*LIMB_BYTES);
        } else {
            limbs = NULL;
        }
    }

    // constructor for conveniece
    integer::integer(std::string text, size_t base) {

        if(base>1 && base<16) {
            std::vector<uint8_t> output(text.size(),0);

            for(size_t i=0; i<text.size(); ++i) {
                uint8_t carry = text[i] - '0';
                size_t j=text.size();
                while(j--) {
                    uint8_t tmp = output[j] * base + carry;
                    output[j] = tmp % 16;
                    carry = tmp / 16;
                }
            }

            size_t leading_zeros = 0;
            while(output.size()>1 && !output[leading_zeros]) {
                leading_zeros++;
            }

            output.erase(output.begin(),output.begin()+leading_zeros);

            std::string stringForm(output.size(),'0');
            for(size_t i=0; i<stringForm.size(); ++i) {
                stringForm[i] = HEX_TO_CHAR[output[i]];
            }

            text = stringForm;

        } else if(base!=16) {
            throw std::domain_error(
                "integer - string contructor : supported number base range is only from 2 to 16"
            );
        }

        size_t blocks = text.size()/(LIMB_BYTES);
        size_t remain = text.size()%(LIMB_BYTES);

        length = blocks;
        if(remain) {
            length++;
        }

        capacity = length+LIMB_GROWTH;
        limbs = (limb_t*) std::malloc(capacity*LIMB_BYTES);
        memset(limbs,0x00,capacity*LIMB_BYTES);

        for(size_t i=0; i<text.size(); ++i) {

            unsigned char CharByte = CHAR_TO_HEX((unsigned char)text[text.size()-1-i]);
            if(CharByte==0xff)
                break;

            size_t multiplier = std::pow(0x10,i%LIMB_BYTES);
            limbs[i/LIMB_BYTES] |= CharByte * multiplier;
        }

        size_t cut_length = 0;

        while(!limbs[length-1-cut_length]) {
            cut_length++;
        }

        length -= cut_length;
    }

    /// copy constructor.
    integer::integer(const integer& src) {

        capacity = src.capacity;
        length   = src.length;
        limbs = (limb_t*) std::malloc(capacity*LIMB_BYTES);
        memcpy(limbs,src.limbs,length*LIMB_BYTES);
    }

    /// move constructor.
    integer::integer(integer&& src) noexcept {

        capacity = src.capacity;
        length   = src.length;
        limbs    = src.limbs;
        src.limbs = NULL;
    }

    /// copy assignment.
    integer& integer::operator=(const integer& src) {

        if(this != &src) {
            if(capacity < src.capacity) {
                limbs = (limb_t*) std::realloc(limbs,src.capacity*LIMB_BYTES);
                capacity = src.capacity;
            }

            length = src.length;
            memcpy(limbs,src.limbs,src.length*LIMB_BYTES);
        }

        return *this;
    }

    /// move assignment.
    integer& integer::operator=(integer&& src) noexcept {

        if(this != &src) {
            std::free(limbs);

            capacity = src.capacity;
            length   = src.length;
            limbs    = src.limbs;
            src.limbs = NULL;
        }

        return *this;
    }

    integer::integer(std::initializer_list<base_t> limbs) {

        capacity = limbs.size()+LIMB_GROWTH;
        length = limbs.size();
        this->limbs = (limb_t*) std::malloc(capacity*LIMB_BYTES);
        size_t i = 0;

        for(auto limb : limbs) {
            this->limbs[length-1-i++] = limb;
        }
    }

    integer::~integer() {
        std::free(limbs);
    }

    // Index Operator
    limb_t& integer::operator[](size_t i) {
        return limbs[i];
    }

    limb_t& integer::operator[](size_t i) const {
        return limbs[i];
    }


    /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
    int integer::compare(const integer& op) const {

        if(length<op.length) {
            return LESS;
        }
        
        if(length>op.length) {
            return GREAT;
        }

        for(size_t i=0; i<length; ++i) {

            if(limbs[length-1-i]<op.limbs[length-1-i]) {
                return LESS;
            } else if(limbs[length-1-i]>op.limbs[length-1-i]) {
                return GREAT;
            }
        }

        return 0;
    }

    // Logical Operators

    bool integer::operator<(const integer& op) const {
        return this->compare(op)==LESS ? true : false;
    }

    bool integer::operator>(const integer& op) const {
        return this->compare(op)==GREAT ? true : false;
    }

    bool integer::operator==(const integer& op) const {
        return this->compare(op)==EQUAL ? true : false;
    }

    bool integer::operator!=(const integer& op) const {
        return !(*this==op);
    }

    bool integer::operator<=(const integer& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==LESS) ? true : false;
    }

    bool integer::operator>=(const integer& op) const {

        int cmp = this->compare(op);
        return (cmp==EQUAL || cmp==GREAT) ? true : false;
    }

    // Bit-Wise Logical Operators

    void integer::bit_realloc(const integer& op) {
        capacity = op.capacity;
        limbs = (limb_t*) std::realloc(limbs,capacity*LIMB_BYTES);
        size_t zero_set = length*LIMB_BYTES;
        memset(limbs+length,0x00,(op.length*LIMB_BYTES)-zero_set);
        length = op.length;
    }

    void integer::remove_leading_zeros() {

        for(size_t i=0; i<length; ++i) {
            if(limbs[length-1-i]) {
                length -= i;
                return;
            }
        }
        length = 1;
    }

    void integer::bit_and(const integer& op) {

        for(size_t i=0; i<op.length; ++i) {
            limbs[i] &= op.limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limbs[i] &= 0;
        }
    }

    integer& integer::operator&=(const integer& op) {

        if(length<op.length) {
            bit_realloc(op);
        }

        bit_and(op);
        remove_leading_zeros();
        
        return *this;
    }

    integer integer::operator&(const integer& op) const {

        integer bitwise_and = *this;
        return bitwise_and &= op;
    }

    void integer::bit_or(const integer& op) {
        
        for(size_t i=0; i<op.length; ++i) {
            limbs[i] |= op.limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limbs[i] |= 0;
        }
    }

    integer& integer::operator|=(const integer& op) {

        if(length<op.length) {
            bit_realloc(op);
        }

        bit_or(op);
        remove_leading_zeros();
        
        return *this;
    }

    integer integer::operator|(const integer& op) const {

        integer bitwise_and = *this;
        return bitwise_and |= op;
    }

    void integer::bit_xor(const integer& op) {
        
        for(size_t i=0; i<op.length; ++i) {
            limbs[i] ^= op.limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limbs[i] ^= 0;
        }
    }

    integer& integer::operator^=(const integer& op) {

        if(length<op.length) {
            bit_realloc(op);
        }

        bit_xor(op);
        remove_leading_zeros();
        
        return *this;
    }

    integer integer::operator^(const integer& op) const {

        integer bitwise_and = *this;
        bitwise_and ^= op;
        return bitwise_and;
    }

    integer integer::operator~() const {

        // ------------------------------------------------------
        // flip all the bits of the limbs.
        integer bwn(length,length);
        for(size_t i=0; i<length-1; ++i) {
            bwn.limbs[i] = (base_t)(~limbs[i]);
        }

        // ------------------------------------------------------
        // flip the bits of the most significant limb, from it's
        // least significant bit to it's most significant bit
        // the flip will stop if it reach the last 1 bit value.
        base_t mslimb = limbs[length-1];
        base_t bitmask = mslimb | (mslimb >> 1);
        for(size_t i=2; i<BASE_BITS; i*=2) {
            bitmask |= bitmask >> i;
        }
        
        bwn.limbs[bwn.length-1] = bitmask ^ mslimb;
        bwn.remove_leading_zeros();

        return bwn;
    }

    void integer::bit_flip(size_t padding) {

        if(capacity<length+padding) {
            capacity = length+padding+LIMB_GROWTH;
            limbs = (limb_t*) std::realloc(limbs,capacity*LIMB_BYTES);
        }

        size_t prev_length = length;
        length = length + padding;

        for(size_t i=0; i<prev_length; ++i) {
            limbs[i] = (base_t)(~limbs[i]);
        }

        for(size_t i=prev_length; i<length; ++i) {
            limbs[i] = BASE_MAX;
        }
    }

    // Logical Operators
    integer::operator bool() const noexcept {
        return !(length==1 && !limbs[0]);
    }

    // Arithmetic Operators

    integer& integer::operator+=(const integer& op) {
        
        if(capacity<=op.length+1) {
            capacity = op.length+LIMB_GROWTH;
            limbs = (limb_t*) std::realloc(limbs,capacity*LIMB_BYTES);
        }
        
        if(length==capacity) {
            capacity = length+LIMB_GROWTH;
            limbs = (limb_t*) std::realloc(limbs,capacity*LIMB_BYTES);
        }

        if(length<=op.length) {
            memset(limbs+length, 0x00, ((op.length+1)-length)*LIMB_BYTES);
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

        remove_leading_zeros();

        return *this;
    }

    integer integer::operator+(const integer& op) const {
        integer sum = *this;
        return sum += op;
    }
    
    integer& integer::operator-=(const integer& op) {
        
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

    integer integer::operator-(const integer& op) const {
        integer dif = *this;
        return dif -= op;
    }
    
    integer& integer::operator*=(const integer& op) {

        integer product = *this * op;
        swap(product,*this);

        return *this;
    }

    integer integer::operator*(const integer& op) const {

        if(!(*this && op)) {
            return __INTEGER_ZERO;
        }

        integer product(length+op.length,length+op.length);
        memset(product.limbs,0x00,product.length*LIMB_BYTES);
        
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

        if(!product.limbs[product.length-1]) {
            product.length--;
        }

        return product;
    }
    
    integer& integer::operator/=(const integer& op) {

        integer quotient = *this / op;
        swap(quotient,*this);

        return *this;
    }

    integer integer::operator/(const integer& op) const {

        if(!op) {
            throw std::domain_error("apa::integer - Division By Zero");
        }
            
        int special_case = this->compare(op);
        switch (special_case) {
            case EQUAL: return integer(1);
            case LESS : return integer(0);
        }

        if(op.length==1 && op.limbs[0]==1) {
            return *this;
        }

        return bit_division(op);
    }

    integer& integer::operator%=(const integer& op) {

        integer remainder = *this % op;
        swap(remainder,*this);

        return *this;
    }

    integer integer::operator%(const integer& op) const {

        if(!op) {
            throw std::domain_error("apa::integer - Division By Zero");
        }
            
        int special_case = this->compare(op);
        switch (special_case) {
            case EQUAL: return integer(0);
            case LESS : return *this;
        }

        if(op.length==1 && op.limbs[0]==1) {
            return integer(0);
        }
        
        return bit_modulo(op);
    }

    integer integer::bit_division(const integer& op) const {

        integer quotient(length,length), remainder(length,length);
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

        quotient.remove_leading_zeros();
        return quotient;
    }

    integer integer::bit_modulo(const integer& op) const {
        
        integer remainder(length,length);
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
    integer& integer::operator++() {
        return *this += __INTEGER_ONE;
    }

    integer& integer::operator--() {
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
    integer& integer::operator<<=(size_t bits) {

        if(*this) {
            size_t limb_shifts = bits / BASE_BITS;
            size_t bit_shifts = bits % BASE_BITS;

            size_t new_length = length + limb_shifts + 1;
            if(new_length>capacity) {
                capacity = new_length+LIMB_GROWTH;
                limbs = (limb_t*) std::realloc(limbs,capacity*LIMB_BYTES);
            }

            limbs[new_length-1] = 0;

            for(size_t i=0; i<length; ++i) {
                limbs[length-1-i] <<= bit_shifts;
                limbs[new_length-1-i] |= limbs[length-1-i] >> BASE_BITS;
                limbs[new_length-2-i] = (base_t) limbs[length-1-i];
            }

            size_t zero_limbs = new_length-length-1;
            if(zero_limbs) {
                memset(limbs,0x00,zero_limbs*LIMB_BYTES);
            }

            length = new_length;
            if(!limbs[length-1]) {
                length--;
            }
        }

        return *this;
    }

    integer& integer::operator>>=(size_t bits) {

        if(*this) {
            size_t limb_shifts = bits / BASE_BITS;
            
            if(limb_shifts>=length) {
                length = 1;
                limbs[0] = 0;
            } else {
                size_t bit_shifts = bits % BASE_BITS;
                size_t new_length = length - limb_shifts;
                
                base_t prev = 0;
                base_t next = 0;

                for(size_t i=0; i<new_length; ++i) {
                    next = limbs[length-1-i] << (BASE_BITS - bit_shifts);
                    limbs[new_length-1-i] = limbs[length-1-i] >> bit_shifts;
                    limbs[new_length-1-i] |= prev;
                    prev = next;
                }

                length = new_length;
                if(!limbs[length-1] && length!=1) {
                    length--;
                }
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
        printf(PRINT_LIMBHEX_NOPAD, (base_t) limbs[length-1]);

        for(size_t i=1; i<length; ++i) {
            printf(PRINT_LIMBHEX, (base_t) limbs[length-1-i]);
        }

        std::cout << "\n";
    }

    void integer::printHex_spaced_out() const {

        printf(PRINT_LIMBHEX, (base_t) limbs[length-1]);

        for(size_t i=1; i<length; ++i) {
            printf(PRINT_LIMBHEX_SPACED, (base_t) limbs[length-1-i]);
        }

        std::cout << "\n";
    }

    void integer::printBin_spaced_out() const {

        for(size_t i=0; i<length; ++i) {
            std::cout << std::bitset<BASE_BITS>(limbs[length-1-i]) << " "; 
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

        if(quotient) {
            while(quotient) {
                integer remainder = quotient % ten;
                quotient = quotient / ten;
                Base10.push_back('0'+remainder.limbs[0]);
            }

            std::reverse(Base10.begin(),Base10.end());    
        } else {
            Base10 = "0";
        }
        
        return Base10;
    }

    std::string integer::to_base16_string() const {

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

    // Methods

    size_t integer::byte_size() const {

        base_t ms_limb = limbs[length-1];
        size_t cnt = 0;

        while(ms_limb) {
            ms_limb >>= 8;
            cnt++;
        }

        return (length-1)*BASE_BYTES + cnt;
    }

    size_t integer::bit_size() const {

        base_t ms_limb = limbs[length-1];
        size_t cnt = 0;

        while(ms_limb) {
            ms_limb >>= 1;
            cnt++;
        }

        return (length-1)*BASE_BITS + cnt;
    }

    void swap(integer& a, integer& b) {

        integer temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    // IO Operators
    std::ostream& operator<<(std::ostream &out, const integer &num) {

        out << num.to_base16_string();
        return out;
    }

    std::istream& operator>>(std::istream &in, integer &num) {
        
        std::string input;
        in >> input;
        num = integer(input,16);

        return in;
    }
}

#endif