#ifndef LIMB_DIVISION_BY_10_HPP
#define LIMB_DIVISION_BY_10_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline limb limb::fdiv10() const
    {
        limb copy = *this;
        return copy.fdiv10_self();
        // limb quotient = *this;

        // dtype origin;
        // dtype carry = 0;
        // for(size_t i=0; i<quotient.limbs.size(); ++i)
        // {
        //     origin = limbs[i]; 
        //     quotient.limbs[i]/=10;
        //     quotient.limbs[i]+=(carry*((max_value+1)/10));
        //     carry = origin%10;
        // }

        // // check and remove zero limbs
        // size_t limbs_to_remove = 0;
        // size_t limb_counts = quotient.limbs.size();
        // for(size_t i=0; i<limb_counts; ++i)
        // {
        //     if(quotient.limbs[i]==0) limbs_to_remove++;
        //     else if(quotient.limbs[i]!=0) break;
        // }
        // if(limbs_to_remove==limb_counts && limb_counts) limbs_to_remove--;
        // if(limbs_to_remove) quotient.limbs.erase(quotient.limbs.begin()+0,quotient.limbs.begin()+limbs_to_remove);

        // return quotient;
    }


    inline limb& limb::fdiv10_self()
    {
        // limb quotient =  *this;

        // std::vector<T> origin = quotient.limbs;
        dtype origin;
        dtype carry = 0;
        for(size_t i=0; i<limbs.size(); ++i)
        {
            origin = limbs[i];
            limbs[i]/=10;
            limbs[i]+=(carry*((max_value+1)/10));
            carry = origin%10;
        }

        // check and remove zero limbss
        size_t limbs_to_remove = 0;
        size_t limb_counts = limbs.size();
        for(size_t i=0; i<limb_counts; ++i)
        {
            if(limbs[i]==0) limbs_to_remove++;
            else if(limbs[i]!=0) break;
        }
        if(limbs_to_remove==limb_counts && limb_counts) limbs_to_remove--;
        if(limbs_to_remove) limbs.erase(limbs.begin()+0,limbs.begin()+limbs_to_remove);

        return *this;
    }
}

#endif