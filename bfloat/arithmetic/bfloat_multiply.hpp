#ifndef BFLOAT_MULTIPLY_HPP
#define BFLOAT_MULTIPLY_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace arb
{
    bfloat bfloat::operator*(const bfloat& rhs) const
    {
        bfloat product;
        bool same_sign = this->sign==rhs.sign;

        product.floatlimbs = this->floatlimbs*rhs.floatlimbs;
        if(!same_sign)
        {
            product.sign = -1;
            return product;
        }
        product.sign = 1;
        return product;
    }

    bfloat& bfloat::operator*=(const bfloat& rhs)
    {
        bool same_sign = this->sign==rhs.sign;

        this->floatlimbs = this->floatlimbs * rhs.floatlimbs;
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