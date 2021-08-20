#ifndef BINT_SUBTRACT_HPP
#define BINT_SUBTRACT_HPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::operator-(const bint& rhs) const
    {
        bint difference = *this;
        difference-=rhs;
        return difference;
    }

    bint& bint::operator-=(const bint& rhs)
    {
        bool same_sign = this->sign==rhs.sign;
        bool pos_minuend = (this->sign)>=0;
        bool minuendIsMax = *this>rhs;

        int comp = intlimbs.compare(rhs.intlimbs);

        if(same_sign)
        {
            if(comp==0)
            {
                sign = 1;
                intlimbs.limbs.clear();
                intlimbs.limbs.push_back(0);
                return *this;
            }

            else if(pos_minuend)
            {
                if(minuendIsMax)
                {
                    this->intlimbs -= rhs.intlimbs;
                    this->sign = 1;
                    return *this;
                }
                this->intlimbs = rhs.intlimbs-this->intlimbs;
                this->sign = -1;
                return *this;
            }
            else if(!pos_minuend)
            {
                if(minuendIsMax)
                {
                    this->intlimbs = rhs.intlimbs-this->intlimbs;
                    this->sign = 1;
                    return *this;
                }
                this->intlimbs -= rhs.intlimbs;
                this->sign = (-1);
                return *this;
            }
        }
        else
        {
            this->intlimbs += rhs.intlimbs;
            if(*this<rhs)
            {
                this->sign = -1;
                return *this;
            }
            this->sign = 1;
            return *this;
        }

        sign = 1;
        intlimbs.limbs.clear();
        intlimbs.limbs.push_back(0);
        return *this;
    }
}

#endif