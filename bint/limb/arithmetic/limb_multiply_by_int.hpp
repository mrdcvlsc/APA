#ifndef LIMB_MULTIPLY_BY_INT_HPP
#define LIMB_MULTIPLY_BY_INT_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{

/// the given constant should not exceed the maximum value a limb can hold
    inline limb& limb::fmulINT_self(dtype constant)
    {
        #ifndef PRODUCTION
        if(constant>max_value)
        {
            throw std::invalid_argument("limb : fmulINT_self(), the given constant is greater than the maximum value a limb can hold");
        }
        #endif

        size_t limb_cnt = limbs.size();

        for(size_t i=0; i<limb_cnt; ++i)
        {
            limbs[i] *= constant;
        }

        if(limbs[0]>max_value)
        {
            limbs.insert(limbs.begin(),1);
            limbs[0] = 0;
        }

        limb_cnt = limbs.size();

        // carry
        dtype ten;
        dtype one;
        for(size_t i=0;i<limb_cnt-1;++i) {
            if(limbs[limb_cnt-1-i]>=max_value+1) {
                ten = ten_thsd(limbs[limb_cnt-1-i]);
                one = one_thsd(limbs[limb_cnt-1-i],ten);
                limbs[limb_cnt-1-i]=one;
                limbs[limb_cnt-1-i-1]=limbs[limb_cnt-1-i-1]+ten;
            }
        }

        return *this;
    }
}

#endif