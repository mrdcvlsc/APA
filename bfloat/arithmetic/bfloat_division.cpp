#ifndef BFLOAT_DIVISION_HPP
#define BFLOAT_DIVISION_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace apa
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

        if(*this<rhs)
        {
            return *this;
        }
        else if(*this==rhs)
        {
            return bfloat("0.0");
        }

        return *this-(rhs*(*this/rhs));
    }
}

#endif