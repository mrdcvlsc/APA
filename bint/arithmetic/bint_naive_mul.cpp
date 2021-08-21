#ifndef BINT_NAIVE_MUL_CPP
#define BINT_NAIVE_MUL_CPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::naive_mul(const bint& multiplier) const
    {
        bint product;
        product.intlimbs = intlimbs*multiplier.intlimbs;
        product.sign = 1;
        return product;
    }
}

#endif