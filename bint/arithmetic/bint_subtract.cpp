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

    // inline bint bint::p_sub(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len)
    // {
    //     bool same_sign = a.sign==b.sign;
    //     bool pos_minuend = (a.sign)>=0;
    //     bool minuendIsMax = a>b;

    //     bint dif;

    //     int comp = a.intlimbs.compare(b.intlimbs);

    //     if(same_sign)
    //     {
    //         if(comp==0)
    //         {
    //             dif.sign = 1;
    //             dif.intlimbs.limbs.push_back(0);
    //             return dif;
    //         }

    //         else if(pos_minuend)
    //         {
    //             if(minuendIsMax)
    //             {
    //                 dif.intlimbs = backend_bigint::limb::p_sub(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //                 dif.sign = 1;
    //                 return dif;
    //             }
    //             dif.intlimbs = backend_bigint::limb::p_sub(b.intlimbs,b_start,b_len,a.intlimbs,a_start,a_len);
    //             dif.sign = -1;
    //             return dif;
    //         }
    //         else if(!pos_minuend)
    //         {
    //             if(minuendIsMax)
    //             {
    //                 dif.intlimbs = backend_bigint::limb::p_sub(b.intlimbs,b_start,b_len,a.intlimbs,a_start,a_len);
    //                 dif.sign = 1;
    //                 return dif;
    //             }
    //             dif.intlimbs = backend_bigint::limb::p_sub(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //             dif.sign = (-1);
    //             return a;
    //         }
    //     }
    //     else
    //     {
    //         dif.intlimbs = backend_bigint::limb::p_add(a.intlimbs,a_start,a_len,b.intlimbs,b_start,b_len);
    //         if(a<b)
    //         {
    //             dif.sign = -1;
    //             return dif;
    //         }
    //         dif.sign = 1;
    //         return dif;
    //     }

    //     dif.sign = 1;
    //     dif.intlimbs.limbs.push_back(0);
    //     return dif;
    // }
}

#endif