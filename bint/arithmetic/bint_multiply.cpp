#ifndef BINT_MULTIPLY_HPP
#define BINT_MULTIPLY_HPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::operator*(const bint& rhs) const
    {
        bint product;
        bool same_sign = this->sign==rhs.sign;

        if(intlimbs.limb_count()<=KARATSUBA_TRESHOLD || rhs.intlimbs.limb_count()<=KARATSUBA_TRESHOLD)
        {
            // use naive at a certain treshold
            product = naive_mul(rhs);
        }
        else
        {
            // karatsuba
            product = karatsuba(rhs);
        }

        if(!same_sign)
        {
            product.sign = -1;
            return product;
        }
        product.sign = 1;
        return product;
    }

    bint& bint::operator*=(const bint& rhs)
    {
        bool same_sign = this->sign==rhs.sign;

        this->intlimbs = this->intlimbs * rhs.intlimbs;
        if(!same_sign)
        {
            this->sign = -1;
            return *this;
        }
        this->sign = 1;
        return *this;
    }

    inline bint bint::p_mul(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len)
    {
        return bint({1},1);
    }
}

#endif