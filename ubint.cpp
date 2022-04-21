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
        limbs[1] = num >> BASE_BITS;
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
            capacity = length*LIMB_GROWTH_FACTOR;
            limbs = (limb_t*) malloc(capacity*LIMB_BYTES);
            memset(limbs,0x0,capacity*LIMB_BYTES);

            for(size_t i=0; i<text.size(); ++i) {
                
                unsigned char CharByte = CHAR_TO_HEX((unsigned char)text[i]);
                if(CharByte==0xff)
                    break;

                size_t multiplier = std::pow(0x10,i%LIMB_BYTES);
                limbs[i/LIMB_BYTES] |= CharByte * multiplier;
            }
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
        capacity = limbs.size()*LIMB_GROWTH_FACTOR;
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

    bool ubint::operator==(const ubint& op) const {
        return compare(op)==EQUAL ? true : false;
    }

    ubint& ubint::operator+=(const ubint& op) {
        
        if(capacity<=op.length+1) {
            capacity = op.length*LIMB_GROWTH_FACTOR;
            limbs = (limb_t*) realloc(limbs,capacity*LIMB_BYTES);
        }
        
        if(length==capacity) {
            capacity = length*LIMB_GROWTH_FACTOR;
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
        memset(product.limbs,0x0,product.capacity*LIMB_BYTES);
        
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
    
    ubint ubint::operator/(const ubint& op) const {
        return op;
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