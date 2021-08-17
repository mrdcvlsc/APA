#ifndef FLIMB_SUBTRACT_HPP
#define FLIMB_SUBTRACT_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline flimb flimb::operator-(const flimb& subtrahend) const
    {
        flimb difference = *this;
        return difference-=subtrahend;
    }

    inline flimb& flimb::operator-=(const flimb& subtrahend)
    {
        size_t left_rational_limb_cnt = limbs.size()-decimal_point;
        size_t right_rational_limb_cnt = subtrahend.limbs.size()-subtrahend.decimal_point;

        size_t int_diff_limb_cnt = std::max(decimal_point,subtrahend.decimal_point);
        size_t rational_diff_limb_cnt = std::max(left_rational_limb_cnt,right_rational_limb_cnt);

        size_t diff_limb_cnt = int_diff_limb_cnt+rational_diff_limb_cnt;
        size_t rear_inserts = rational_diff_limb_cnt - left_rational_limb_cnt;

        if(rear_inserts)
        {
            std::vector<dtype> rear_zeros(rear_inserts,0);
            limbs.insert(limbs.end(),rear_zeros.begin(),rear_zeros.end());
        }

        // subtraction operation
        size_t start_index = decimal_point-subtrahend.decimal_point;
        for(size_t i=0; i<subtrahend.limbs.size(); ++i)
        {
            limbs[start_index+i] -= subtrahend.limbs[i];
        }
        
        // carry
        for(size_t i=diff_limb_cnt-1; i>0; --i){
            if(limbs[i]<0)
            {
                limbs[i]=limbs[i]+(max_value+1);
                --limbs[i-1];
            }
        }

        // check and remove zero limbs in front
        size_t front_remove_limit = decimal_point-1;
        size_t front_limb_to_remove = 0;
        size_t resulting_size = diff_limb_cnt;
        for(size_t i=0; i<diff_limb_cnt; ++i)
        {
            if(limbs[i]==0 && resulting_size>1 && front_remove_limit--)
            {
                front_limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(front_limb_to_remove)
        {
            limbs.erase(limbs.begin()+0,limbs.begin()+front_limb_to_remove);
        }

        // check and remove zero limbs in rear
        size_t rear_remove_limit = rational_diff_limb_cnt-1;
        size_t rear_limb_to_remove = 0;
        for(size_t i=limbs.size()-1; i<limbs.size(); ++i)
        {
            if(limbs[i]==0 && resulting_size>1 && rear_remove_limit--)
            {
                rear_limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(rear_limb_to_remove)
        {
            limbs.erase(limbs.begin()+(limbs.size()-1-rear_limb_to_remove),limbs.end());
        }

        return *this;
    }

}

#endif