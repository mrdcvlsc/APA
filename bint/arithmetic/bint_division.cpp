#ifndef BINT_DIVISION_HPP
#define BINT_DIVISION_HPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::operator/(const bint& rhs) const
    {
        bint quotient;

        bool same_sign = (this->sign==rhs.sign);

        // divisor is greater than dividen
        if(rhs.intlimbs>this->intlimbs)
        {
            quotient.intlimbs = {0};
            quotient.sign = 1;
            return quotient;
        }

        quotient.intlimbs = this->intlimbs/rhs.intlimbs;
        if(same_sign) quotient.sign = 1;
        else quotient.sign = -1;
        return quotient;
    }

    bint& bint::operator/=(const bint& rhs)
    {
        *this = *this/rhs;
        return *this;
    }

    bint bint::operator%(const bint& rhs) const
    {
        int comp = intlimbs.compare(rhs.intlimbs);

        if(*this<rhs)
        {
            return *this;
        }
        else if(*this==rhs)
        {
            return bint("0");
        }

        return *this-(rhs*(*this/rhs));
    }
}

#endif