#ifndef FLIMB_COMPARISON_HPP
#define FLIMB_COMPARISON_HPP

#include <iostream>
#include "flimb.hpp"

namespace backend_bigfloat
{
    bool flimb::operator==(const flimb& right) const
    {
        return compare(right)==0;
    }

    bool flimb::operator!=(const flimb& right) const
    {
        return !(*this==right);
    }

    bool flimb::operator<(const flimb& right) const
    {
        return compare(right)<0;
    }

    bool flimb::operator>(const flimb& right) const
    {
        return compare(right)>0;
    }

    bool flimb::operator<=(const flimb& right) const
    {
        return compare(right)<=0;
    }

    bool flimb::operator>=(const flimb& right) const
    {
        return compare(right)>=0;
    }

    int flimb::compare(const flimb& right) const
    {
        size_t left_int_size = decimal_point;
        size_t right_int_size = right.decimal_point;

        if(left_int_size<right_int_size)
        {
            return -1;
        }
        else if(left_int_size>right_int_size)
        {
            return 1;
        }
        else
        {
            size_t min_limb_cnt = std::min(limbs.size(),right.limbs.size());

            for(size_t i=0; i<min_limb_cnt; ++i)
            {
                if(limbs[i]<right.limbs[i])
                {
                    // if first index is lessthan return true
                    return -1;
                }
                else if(limbs[i]>right.limbs[i])
                {
                    // if first index is greater than return false
                    return 1;
                }
            }
        }

        size_t left_limb_cnts = limbs.size();
        size_t right_limb_cnts = right.limbs.size();

        if(left_limb_cnts<right_limb_cnts)
        {
            return -1;
        }
        else if(left_limb_cnts>right_limb_cnts)
        {
            return 1;
        }

        return 0;
    }

}

#endif