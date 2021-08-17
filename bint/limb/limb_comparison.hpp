#ifndef LIMB_COMPARISON_HPP
#define LIMB_COMPARISON_HPP

#include <iostream>
#include "limb.hpp"

namespace backend_bigint
{
    bool limb::operator==(const limb& right) const
    {
        return compare(right)==0;
    }

    bool limb::operator!=(const limb& right) const
    {
        return !(*this==right);
    }

    bool limb::operator<(const limb& right) const
    {
        return compare(right)<0;
    }

    bool limb::operator>(const limb& right) const
    {
        return compare(right)>0;
    }

    bool limb::operator<=(const limb& right) const
    {
        return compare(right)<=0;
    }

    bool limb::operator>=(const limb& right) const
    {
        return compare(right)>=0;
    }

    /// @returns  1 : if limb is greater than the limb parameter | -1 : if limb is less than the limb parameter | 0 : if both limbs are equal
    int limb::compare(const limb& right) const
    {
        size_t left_size = limbs.size();
        size_t right_size = right.limbs.size();

        if(left_size<right_size)
        {
            return -1;
        }
        else if(left_size>right_size)
        {
            return 1;
        }
        else
        {
            for(size_t i=0; i<left_size; ++i)
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

        // if all values are equal return false
        return 0;
    }
}

#endif