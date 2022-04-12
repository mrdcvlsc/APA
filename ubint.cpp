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
        length = 1;
        limbs = (uint64_t*) malloc(UBINT_INITIAL_LIMB_CAPACITY*LIMB_BYTES);
    }

    ubint::ubint(uint64_t num) {
        capacity = UBINT_INITIAL_LIMB_CAPACITY;
        length = 1;
        limbs = (uint64_t*) malloc(UBINT_INITIAL_LIMB_CAPACITY*LIMB_BYTES);
        limbs[0] = num;
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


    ubint::~ubint() {
        if(limbs != NULL)
            free(limbs);
    }

    /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
    int ubint::compare(const ubint& op) const {

        for(size_t i=0; i<length; ++i) {

            if(limbs[length-1-i]<op.limbs[length-1-i]) {
                return -1;
            }
            else if(limbs[length-1-i]>op.limbs[length-1-i]) {
                return 1;
            }
        }
        return 0;
    }

    bool ubint::operator==(const ubint& op) const {
        return compare(op)==EQUAL ? true : false;
    }

    ubint& ubint::operator+=(const ubint& op) {
        *this = op;
        return *this;
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