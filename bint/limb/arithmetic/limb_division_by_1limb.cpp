#ifndef LIMB_DIVISION_BY_1LIMB_HPP
#define LIMB_DIVISION_BY_1LIMB_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline limb limb::fdiv1limb(dtype single_limb_divisor) const
    {
        #ifndef PRODUCTION
        if(single_limb_divisor>max_value)
        {
            throw std::invalid_argument("fdiv1limb() : single limb divisor's value overflow");
        }
        #endif
        // one chunk divisor division
        size_t dividen_limb_cnt = limbs.size();

        std::vector<dtype> quotient;
        quotient.reserve(dividen_limb_cnt);

        dtype tmp_pdividen;
        dtype tmp_pquotient;
        dtype tmp_dif = 0;

        for(size_t i=0; i<dividen_limb_cnt; ++i)
        {
            tmp_pdividen = (tmp_dif*(max_value+1))+limbs[i];
            tmp_pquotient = tmp_pdividen/single_limb_divisor;
            tmp_dif = tmp_pdividen%single_limb_divisor;
            quotient.push_back(tmp_pquotient);
        }

        // check and remove zero chunks
        size_t limb_to_remove = 0;
        size_t final_limb_cnt = quotient.size();

        for(size_t i=0; i<final_limb_cnt; ++i)
        {
            if(quotient[i]==0 && final_limb_cnt>1)
            {
                limb_to_remove++;
                final_limb_cnt--;
            }
            else break;
        }

        if(limb_to_remove)
        {
            quotient.erase(quotient.begin()+0,quotient.begin()+limb_to_remove);
        }
        
        return limb(quotient);
    }
}

#endif