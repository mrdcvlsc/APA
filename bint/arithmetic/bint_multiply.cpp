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

        product.intlimbs = this->intlimbs*rhs.intlimbs;
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
}

#endif