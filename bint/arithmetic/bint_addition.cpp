#ifndef BINT_ADDITION_HPP
#define BINT_ADDITION_HPP

#include <iostream>
#include "../bint.hpp"

namespace apa
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

        // same sign both positive
        this->intlimbs += rhs.intlimbs;
        this->sign = 1;
        return *this;
    }

    // inline bint bint::p_add(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len)
    // {
    //     bool same_sign = a.sign==b.sign;
    //     bool adden1isMax = a.intlimbs>b.intlimbs;

    //     bint sum;

    //     // different sign
    //     if(!same_sign && adden1isMax)
    //     {
    //         sum.intlimbs = backend_bigint::limb::p_sub(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //         if(a.sign>=0)
    //         {
    //             sum.sign = 1;
    //             return sum;
    //         }
    //         sum.sign = -1;
    //         return sum;
    //     }
    //     else if(!same_sign && !adden1isMax)
    //     {
    //         sum.intlimbs = backend_bigint::limb::p_sub(b.intlimbs,b_start,b_len,a.intlimbs,a_start,a_len);
    //         if(b.sign>=0)
    //         {
    //             sum.sign = 1;
    //             return sum;
    //         }
    //         sum.sign = -1;
    //         return sum;
    //     }

    //     // same sign both negative
    //     if(same_sign && (a.sign)<0 && b.sign<0)
    //     {
    //         sum.intlimbs = backend_bigint::limb::p_add(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //         sum.sign = -1;
    //         return sum;
    //     }

    //     // same sign both positive
    //     sum.intlimbs = backend_bigint::limb::p_add(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //     sum.sign = 1;
    //     return sum;
    // }
}

#endif