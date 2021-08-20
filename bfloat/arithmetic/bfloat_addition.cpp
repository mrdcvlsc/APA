#ifndef BFLOAT_ADDITION_HPP
#define BFLOAT_ADDITION_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace apa
{
    bfloat bfloat::operator+(const bfloat& rhs) const
    {
        bfloat sum = *this;
        sum+=rhs;
        return sum;
    }

    bfloat& bfloat::operator+=(const bfloat& rhs)
    {
        bool same_sign = this->sign==rhs.sign;
        bool adden1isMax = this->floatlimbs>rhs.floatlimbs; 

        // different sign
        if(!same_sign && adden1isMax)
        {
            this->floatlimbs -= rhs.floatlimbs;
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
            this->floatlimbs = rhs.floatlimbs-this->floatlimbs;
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
            this->floatlimbs += rhs.floatlimbs;
            this->sign = -1;
            return *this;
        }

        // same sign both positive
        this->floatlimbs += rhs.floatlimbs;
        this->sign = 1;
        return *this;
    }
}

#endif