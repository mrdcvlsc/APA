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
    ubint::ubint() {
        capacity = UBINT_INITIAL_LIMB_CAPACITY;
        length = UBINT_INITIAL_LIMB_LENGTH;
        limbs = (uint64_t*) malloc(UBINT_INITIAL_LIMB_CAPACITY*LIMB_BYTES);
    }

    ubint::ubint(uint64_t num) {
        capacity = UBINT_INITIAL_LIMB_CAPACITY;
        length = UBINT_INITIAL_LIMB_LENGTH;
        limbs = (uint64_t*) malloc(UBINT_INITIAL_LIMB_CAPACITY*LIMB_BYTES);
        limbs[0] = (uint32_t) num;
        limbs[1] = num >> 32;
    }

    /// copy constructor.
    ubint::ubint(const ubint& src) {
        capacity = src.capacity;
        length   = src.length;
        limbs = (uint64_t*) malloc(src.length*LIMB_BYTES);
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
        if(capacity < src.capacity)
            limbs = (uint64_t*) realloc(limbs,src.length*LIMB_BYTES);

        capacity = src.capacity;
        length   = src.length;
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

    ubint& ubint::operator=(std::initializer_list<uint32_t> limbs) {
        capacity = limbs.size()*2;
        length = limbs.size();
        this->limbs = (uint64_t*) malloc(capacity*LIMB_BYTES);
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
            capacity = op.length*LIMB_EXPANSION;
            limbs = (uint64_t*) realloc(limbs,capacity*LIMB_BYTES);
        }
        
        if(length==capacity) {
            capacity = length*LIMB_EXPANSION;
            limbs = (uint64_t*) realloc(limbs,capacity*LIMB_BYTES);
        }

        if(length<op.length) {
            memset(limbs+length, 0x0, ((op.length+1)-length)*LIMB_BYTES);
        }

        for(size_t i=0; i<op.length; ++i) {
            limbs[i] += op.limbs[i];
            limbs[i+1] += (limbs[i] >> 32);
            limbs[i] = (uint32_t) limbs[i];
        }

        for(size_t i=op.length; i<length; ++i) {
            uint64_t carry = limbs[i] >> 32;
            if(carry) {
                limbs[i+1] += carry;
                limbs[i] = (uint32_t) limbs[i];
            }
            else {
                break;
            }
        }

        length = std::max(length,op.length);

        if(limbs[length]) length++;

        return *this;
    }

    ubint ubint::operator+(const ubint& op) const {
        ubint sum = *this;
        return (sum+=op);
    }
    
    ubint& ubint::operator-=(const ubint& op) {
        *this = op;
        return *this;
    }
    
    ubint ubint::operator*(const ubint& op) const {
        return op;
    }
    
    ubint ubint::operator/(const ubint& op) const {
        return op;
    }

    void ubint::printHex() const {
        std::cout << "0x";
        for(size_t i=0; i<length; ++i)
            printf(PRINT_LIMBHEX,limbs[length-1-i]);
        std::cout << "\n";
    }
}


#endif