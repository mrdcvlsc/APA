#ifndef UNSIGNED_BIG_INTEGER_CPP
#define UNSIGNED_BIG_INTEGER_CPP

#ifdef _MAKE_LIB
#include "ubint.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
#include "ubint.hpp"
#endif

namespace apa {

    unsigned char CHAR_TO_HEX(unsigned char c) {
        switch (c)
        {
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

    ubint::ubint() {
        capacity = INITIAL_LIMB_CAPACITY;
        length = INITIAL_LIMB_LENGTH;
        limbs = (limb_t*) malloc(INITIAL_LIMB_CAPACITY*LIMB_BYTES);
    }

    ubint::ubint(limb_t num) {
        capacity = INITIAL_LIMB_CAPACITY;
        length = INITIAL_LIMB_LENGTH;
        limbs = (limb_t*) malloc(INITIAL_LIMB_CAPACITY*LIMB_BYTES);
        limbs[0] = (base_t) num;
        limb_t high = num >> BASE_BITS;
        if((base_t)high) {
            limbs[1] = high;
            length++;
        }
    }

    ubint::ubint(size_t capacity, size_t length, bool AllocateSpace) {
        this->capacity = capacity;
        this->length = length;
        if(AllocateSpace)
            limbs = (limb_t*) malloc(capacity*LIMB_BYTES);
        else
            limbs = NULL;
    }

    ubint::ubint(std::string text, bool isHex) {

        if(isHex) {
            std::reverse(text.begin(),text.end());

            size_t blocks = text.size()/(LIMB_BYTES);
            size_t remain = text.size()%(LIMB_BYTES);

            length = blocks;
            if(remain) length++;
            capacity = length+LIMB_GROWTH;
            limbs = (limb_t*) malloc(capacity*LIMB_BYTES);
            memset(limbs,0x0,capacity*LIMB_BYTES);

            for(size_t i=0; i<text.size(); ++i) {

                unsigned char CharByte = CHAR_TO_HEX((unsigned char)text[i]);
                if(CharByte==0xff)
                    break;

                size_t multiplier = std::pow(0x10,i%LIMB_BYTES);
                limbs[i/LIMB_BYTES] |= CharByte * multiplier;
            }

            size_t cut_length = 0;

            while(!limbs[length-1-cut_length])
                cut_length++;

            length -= cut_length;
        }
        else {
            // base 10
        }
    }

    /// copy constructor.
    ubint::ubint(const ubint& src) {
        capacity = src.capacity;
        length   = src.length;
        limbs = (limb_t*) malloc(capacity*LIMB_BYTES);
        memcpy(limbs,src.limbs,length*LIMB_BYTES);
    }

    /// move constructor.
    ubint::ubint(ubint&& src) noexcept {
        capacity = src.capacity;
        length   = src.length;
        limbs    = src.limbs;
        src.limbs = NULL;
    }

    /// copy assignment.
    ubint& ubint::operator=(const ubint& src) {
        if(capacity < src.capacity) {
            limbs = (limb_t*) realloc(limbs,src.capacity*LIMB_BYTES);
            capacity = src.capacity;
        }

        length = src.length;
        memcpy(limbs,src.limbs,src.length*LIMB_BYTES);

        return *this;
    }

    /// move assignment.
    ubint& ubint::operator=(ubint&& src) noexcept {
        if(limbs != NULL)
            free(limbs);

        capacity = src.capacity;
        length   = src.length;
        limbs    = src.limbs;
        src.limbs = NULL;

        return *this;
    }

    ubint::ubint(std::initializer_list<base_t> limbs) {
        capacity = limbs.size()+LIMB_GROWTH;
        length = limbs.size();
        this->limbs = (limb_t*) malloc(capacity*LIMB_BYTES);
        size_t i = 0;
        for(auto limb : limbs) {
            this->limbs[length-1-i++] = limb;
        }
    }

    ubint::~ubint() {
        if(limbs != NULL)
            free(limbs);
    }

    /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
    int ubint::compare(const ubint& op) const {

        if(length<op.length)
            return -1;
        
        if(length>op.length)
            return 1;

        for(size_t i=0; i<length; ++i) {

            if(limbs[length-1-i]<op.limbs[length-1-i])
                return -1;
                
            else if(limbs[length-1-i]>op.limbs[length-1-i])
                return 1;
        }

        return 0;
    }

    // Logical Operators

    bool ubint::operator<(const ubint& op) const {
        return compare(op)==LESS ? true : false;
    }

    bool ubint::operator>(const ubint& op) const {
        return compare(op)==GREAT ? true : false;
    }

    bool ubint::operator==(const ubint& op) const {
        return compare(op)==EQUAL ? true : false;
    }

    bool ubint::operator!=(const ubint& op) const {
        return !(*this==op);
    }

    bool ubint::operator<=(const ubint& op) const {
        int cmp = compare(op);
        return (cmp==EQUAL || cmp==LESS) ? true : false;
    }

    bool ubint::operator>=(const ubint& op) const {
        int cmp = compare(op);
        return (cmp==EQUAL || cmp==GREAT) ? true : false;
    }

    // Bit-Wise Logical Operators

    ubint& ubint::operator&=(const ubint& op) {

        if(length<op.length) {
            capacity = op.capacity;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
            size_t zero_set = length*LIMB_BYTES;
            memset(limbs+length,0x00,(op.length*LIMB_BYTES)-zero_set);
            length = op.length;
        }

        for(size_t i=0; i<op.length; ++i)
            limbs[i] &= op.limbs[i];

        for(size_t i=op.length; i<length; ++i)
            limbs[i] &= 0;

        for(size_t i=0; i<length; ++i) {
            if(limbs[length-1-i]) {
                length -= i;
                break;
            }
        }
        
        return *this;
    }

    ubint ubint::operator&(const ubint& op) const {

        ubint bitwise_and = *this;
        bitwise_and &= op;
        return bitwise_and;
    }

    ubint& ubint::operator|=(const ubint& op) {

        if(length<op.length) {
            capacity = op.capacity;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
            size_t zero_set = length*LIMB_BYTES;
            memset(limbs+length,0x00,(op.length*LIMB_BYTES)-zero_set);
            length = op.length;
        }

        for(size_t i=0; i<op.length; ++i)
            limbs[i] |= op.limbs[i];

        for(size_t i=op.length; i<length; ++i)
            limbs[i] |= 0;

        for(size_t i=0; i<length; ++i) {
            if(limbs[length-1-i]) {
                length -= i;
                break;
            }
        }
        
        return *this;
    }

    ubint ubint::operator|(const ubint& op) const {

        ubint bitwise_and = *this;
        bitwise_and |= op;
        return bitwise_and;
    }

    ubint& ubint::operator^=(const ubint& op) {

        if(length<op.length) {
            capacity = op.capacity;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
            size_t zero_set = length*LIMB_BYTES;
            memset(limbs+length,0x00,(op.length*LIMB_BYTES)-zero_set);
            length = op.length;
        }

        for(size_t i=0; i<op.length; ++i)
            limbs[i] ^= op.limbs[i];

        for(size_t i=op.length; i<length; ++i)
            limbs[i] ^= 0;

        for(size_t i=0; i<length; ++i) {
            if(limbs[length-1-i]) {
                length -= i;
                break;
            }
        }
        
        return *this;
    }

    ubint ubint::operator^(const ubint& op) const {

        ubint bitwise_and = *this;
        bitwise_and ^= op;
        return bitwise_and;
    }

    ubint ubint::operator~() const {

        ubint bwn = *this;
        for(size_t i=0; i<bwn.length-1; ++i)
            bwn.limbs[i] = (base_t)(~bwn.limbs[i]);

        base_t mslimb = bwn.limbs[bwn.length-1];
        base_t bitmask = mslimb | (mslimb >> 1);
        for(size_t i=2; i<BASE_BITS; i*=2)
            bitmask |= bitmask >> i;
        
        bwn.limbs[bwn.length-1] = bitmask ^ mslimb;

        for(size_t i=0; i<bwn.length; ++i) {
            if(bwn.limbs[bwn.length-1-i]) {
                bwn.length -= i;
                break;
            }
        }

        return bwn;
    }

    // Logical Operators
    ubint::operator bool() const noexcept {
        return (length==1 && limbs[0]==0) ? false : true;
    }

    // Arithmetic Operators

    ubint& ubint::operator+=(const ubint& op) {
        
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
        }

        for(size_t i=0; i<op.length; ++i) {
            limbs[i] += op.limbs[i];
            limbs[i+1] += (limbs[i] >> BASE_BITS);
            limbs[i] = (base_t) limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            limb_t carry = limbs[i] >> BASE_BITS;
            if(carry) {
                limbs[i] = (base_t) limbs[i];
                limbs[i+1] += carry;
            }
            else {
                break;
            }
        }

        length = std::max(length,op.length);

        if(limbs[length]==1) length++;

        return *this;
    }

    ubint ubint::operator+(const ubint& op) const {
        ubint sum = *this;
        sum += op;
        return sum;
    }
    
    ubint& ubint::operator-=(const ubint& op) {
        
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

    ubint ubint::operator-(const ubint& op) const {
        ubint dif = *this;
        dif -= op;
        return dif;
    }
    
    ubint& ubint::operator*=(const ubint& op) {
        ubint product = *this * op;
        swap(product,*this);
        return *this;
    }

    ubint ubint::operator*(const ubint& op) const {

        ubint product(length+op.length,length+op.length);
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
    
    ubint& ubint::operator/=(const ubint& op) {
        ubint quotient = *this / op;
        swap(quotient,*this);
        return *this;
    }

    ubint ubint::operator/(const ubint& op) const {

        if(!op)
            throw std::domain_error("apa::ubint - Division By Zero");
            
        int special_case = compare(op);
        switch (special_case)
        {
            case EQUAL: return ubint(1);
            case LESS : return ubint(0);
        }
        if(op.length==1 && op.limbs[0]==1) return *this;
        return bit_division(op);
    }

    ubint& ubint::operator%=(const ubint& op) {
        ubint remainder = *this % op;
        swap(remainder,*this);
        return *this;
    }

    ubint ubint::operator%(const ubint& op) const {

        if(!op)
            throw std::domain_error("apa::ubint - Division By Zero");
            
        int special_case = compare(op);
        switch (special_case)
        {
            case EQUAL: return ubint(0);
            case LESS : return *this;
        }
        if(op.length==1 && op.limbs[0]==1) return ubint(0);
        return bit_modulo(op);
    }

    ubint ubint::bit_division(const ubint& op) const {

        ubint quotient(length,length), remainder(length,length);
        remainder.limbs[0] = 0, remainder.length = 1;
        memset(quotient.limbs,0x00,length*LIMB_BYTES);

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

    ubint ubint::bit_modulo(const ubint& op) const {
        
        ubint remainder(length,length);
        remainder.limbs[0] = 0, remainder.length = 1;

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

        for(size_t i=0; i<length; ++i) {
            if(remainder.limbs[length-1-i]) {
                remainder.length -= i;
                break;
            }
        }

        return remainder;
    }


    // Shift Operators
    ubint& ubint::operator<<=(size_t bits) {

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

    ubint& ubint::operator>>=(size_t bits) {

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

    ubint ubint::operator<<(size_t bits) const {
        ubint shifted = *this;
        shifted <<= bits;
        return shifted;
    }

    ubint ubint::operator>>(size_t bits) const {
        ubint shifted = *this;
        shifted >>= bits;
        return shifted;
    }


    void ubint::printHex() const {
#ifdef _BASE2_64
        std::cout << "0x";
        printf(PRINT_LIMBHEX_NOPAD, (base_t) limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX, (base_t) limbs[length-1-i]);
        std::cout << "\n";
#else
        std::cout << "0x";
        printf(PRINT_LIMBHEX_NOPAD,limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX,limbs[length-1-i]);
        std::cout << "\n";
#endif
    }

    void ubint::printHex_spaced_out() const {
#ifdef _BASE2_64
        printf(PRINT_LIMBHEX, (base_t) limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX_SPACED, (base_t) limbs[length-1-i]);
        std::cout << "\n";
#else
        printf(PRINT_LIMBHEX,limbs[length-1]);
        for(size_t i=1; i<length; ++i)
            printf(PRINT_LIMBHEX_SPACED,limbs[length-1-i]);
        std::cout << "\n";
#endif
    }

    void ubint::printStatus(std::string printIdentifier) const {
        std::cout << "\n-----\n";
        std::cout << printIdentifier << "\n";
        std::cout << "capacity : " << capacity << "\n";
        std::cout << "length   : " << length << "\n";
        printHex_spaced_out();
    }

    void swap(ubint& a, ubint& b) {
        ubint temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }
}

#endif