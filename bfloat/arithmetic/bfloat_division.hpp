#ifndef BFLOAT_DIVISION_HPP
#define BFLOAT_DIVISION_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace arb
{
    bfloat bfloat::operator/(const bfloat& rhs) const
    {
        bfloat quotient;

        bool same_sign = (this->sign==rhs.sign);

        // divisor is greater than dividen
        if(rhs.floatlimbs>this->floatlimbs)
        {
            quotient.floatlimbs = backend_bigfloat::flimb({0,0},1);
            quotient.sign = 1;
            return quotient;
        }

        quotient.floatlimbs = this->floatlimbs/rhs.floatlimbs;
        if(same_sign) quotient.sign = 1;
        else quotient.sign = -1;
        return quotient;
    }

    bfloat& bfloat::operator/=(const bfloat& rhs)
    {
        *this = *this/rhs;
        return *this;
    }

    bfloat bfloat::operator%(const bfloat& rhs) const
    {
        int comp = floatlimbs.compare(rhs.floatlimbs);

        if(comp<0)
        {
            bfloat mod;
            mod.floatlimbs = backend_bigfloat::flimb({0,0},1);
            mod.sign = 1;
            return mod;
        }
        else if(comp==0)
        {
            bfloat mod;
            mod.floatlimbs = backend_bigfloat::flimb({1,0},1);
            mod.sign = 1;
            return mod;
        }

        return *this-(rhs*(*this/rhs));
    }
}

#endif