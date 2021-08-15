#ifndef BINT_ADDITION_HPP
#define BINT_ADDITION_HPP

#include <iostream>
#include "../bint.hpp"

namespace arb
{
    bint bint::operator+(const bint& rhs) const
    {
        bint sum = *this;
        sum+=rhs;
        return sum;
    }

    bint& bint::operator+=(const bint& rhs)
    {
        bool same_sign = this->sign==rhs.sign;
        bool adden1isMax = this->intlimbs>rhs.intlimbs; 

        // different sign
        if(!same_sign && adden1isMax)
        {
            this->intlimbs -= rhs.intlimbs;
            if(this->sign>=0)
            {
                this->sign = 1;
                return *this;
            }
            this->sign = -1;
            return *this;
        }
        else if(!same_sign && !adden1isMax)
        {
            this->intlimbs = rhs.intlimbs-this->intlimbs;
            if(rhs.sign>=0)
            {
                this->sign = 1;
                return *this;
            }
            this->sign = -1;
            return *this;
        }

        // same sign both negative
        if(same_sign && (this->sign)<0 && rhs.sign<0)
        {
            this->intlimbs += rhs.intlimbs;
            this->sign = -1;
            return *this;
        }

        // same sign bot positive
        this->intlimbs += rhs.intlimbs;
        this->sign = 1;
        return *this;
    }
}

#endif