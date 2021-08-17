#ifndef FLIMB_ADDITION_HPP
#define FLIMB_ADDITION_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline flimb flimb::operator+(const flimb& lower_adden) const
    {
        flimb sum = *this;
        return sum+=lower_adden;
    }

    inline flimb& flimb::operator+=(const flimb& lower_adden)
    {
        size_t left_rational_limb_cnt = limbs.size()-decimal_point;
        size_t right_rational_limb_cnt = lower_adden.limbs.size()-lower_adden.decimal_point;

        size_t int_sum_limb_cnt = std::max(decimal_point,lower_adden.decimal_point);
        size_t rational_sum_limb_cnt = std::max(left_rational_limb_cnt,right_rational_limb_cnt);

        size_t sum_limb_cnt = int_sum_limb_cnt+rational_sum_limb_cnt;

        size_t front_inserts = int_sum_limb_cnt-decimal_point;
        if(front_inserts)
        {
            std::vector<dtype> front_zeros(front_inserts,0);
            limbs.insert(limbs.begin(),front_zeros.begin(),front_zeros.end());
        }

        size_t rear_inserts = rational_sum_limb_cnt - left_rational_limb_cnt;
        if(rear_inserts)
        {
            std::vector<dtype> rear_zeros(rear_inserts,0);
            limbs.insert(limbs.end(),rear_zeros.begin(),rear_zeros.end());
        }

        size_t start_index = int_sum_limb_cnt-lower_adden.decimal_point;
        for(size_t i=0; i<lower_adden.limbs.size(); ++i)
        {
            limbs[start_index+i] += lower_adden.limbs[i];
        }

        // carry
        for(size_t i=sum_limb_cnt-1; i>0; i--)
        {
            if(limbs[i]>max_value)
            {	
                limbs[i]=limbs[i]-(max_value+1);
                ++limbs[i-1];
            }
        }

        // add new limb if needed
        if(limbs[0]>max_value)
        {
            limbs[0]=limbs[0]-(max_value+1);
            limbs.insert(limbs.begin(),1);
        }

        return *this;
    }

}

#endif