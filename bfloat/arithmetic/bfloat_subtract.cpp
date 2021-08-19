#ifndef BFLOAT_SUBTRACT_HPP
#define BFLOAT_SUBTRACT_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace arb
{
    bfloat bfloat::operator-(const bfloat& rhs) const
    {
        bfloat difference = *this;
        difference-=rhs;
        return difference;
    }

    bfloat& bfloat::operator-=(const bfloat& rhs)
    {
        bool same_sign = this->sign==rhs.sign;
        bool pos_minuend = (this->sign)>=0;
        bool minuendIsMax = *this>rhs;

        int comp = floatlimbs.compare(rhs.floatlimbs);

        if(same_sign)
        {
            if(comp==0)
            {
                sign = 1;
                floatlimbs.limbs.clear();
                floatlimbs.limbs.push_back(0);
                floatlimbs.limbs.push_back(0);
                floatlimbs.decimal_point = 1;
                return *this;
            }

            else if(pos_minuend)
            {
                if(minuendIsMax)
                {
                    this->floatlimbs -= rhs.floatlimbs;
                    this->sign = 1;
                    return *this;
                }
                this->floatlimbs = rhs.floatlimbs-this->floatlimbs;
                this->sign = -1;
                return *this;
            }
            else if(!pos_minuend)
            {
                if(minuendIsMax)
                {
                    this->floatlimbs = rhs.floatlimbs-this->floatlimbs;
                    this->sign = 1;
                    return *this;
                }
                this->floatlimbs -= rhs.floatlimbs;
                this->sign = (-1);
                return *this;
            }
        }
        else
        {
            this->floatlimbs += rhs.floatlimbs;
            if(*this<rhs)
            {
                this->sign = -1;
                return *this;
            }
            this->sign = 1;
            return *this;
        }

        sign = 1;
        floatlimbs.limbs.clear();
        floatlimbs.limbs.push_back(0);
        return *this;
    }
}

#endif