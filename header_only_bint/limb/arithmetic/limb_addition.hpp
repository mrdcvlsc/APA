#ifndef LIMB_ADDITION_HPP
#define LIMB_ADDITION_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline limb limb::operator+(const limb& lower_adden) const
    {
        size_t uadden_len = limbs.size();
        size_t ladden_len = lower_adden.limbs.size();

        size_t longest_len = std::max(uadden_len,ladden_len);
        size_t ans_len = longest_len;
        std::vector<dtype> sum_limbs(ans_len,0);								

        // operation
        for(size_t i=0 ;i<uadden_len; ++i){
            sum_limbs[ans_len-1-i]+=limbs[uadden_len-1-i];
        }
        
        for(size_t i=0 ;i<ladden_len; ++i){
            sum_limbs[ans_len-1-i]+=lower_adden.limbs[ladden_len-1-i];
        }

        // carry
        for(size_t i=ans_len-1; i>0; i--){
            if(sum_limbs[i]>max_value){	
                sum_limbs[i]=sum_limbs[i]-(max_value+1);
                ++sum_limbs[i-1];
            }
        }

        // add new limb if needed
        if(sum_limbs[0]>max_value){
            sum_limbs[0]=sum_limbs[0]-(max_value+1);
            sum_limbs.insert(sum_limbs.begin(),1);
        }

        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        size_t resulting_size = sum_limbs.size();
        for(size_t i=0; i<resulting_size; ++i){
            if(sum_limbs[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) sum_limbs.erase(sum_limbs.begin()+0,sum_limbs.begin()+limb_to_remove);
        
        return limb(sum_limbs);
    }


    inline limb& limb::operator+=(const limb& lower_adden)
    {
        if(limbs.size()<lower_adden.limbs.size())
        {
            *this = *this + lower_adden;
            return *this;
        }

        size_t uadden_len = limbs.size();
        size_t ladden_len = lower_adden.limbs.size();							

        // operation
        for(size_t i=0 ;i<ladden_len; ++i){
            limbs[uadden_len-1-i]+=lower_adden.limbs[ladden_len-1-i];
        }

        // add new limb if needed
        if(limbs[0]>max_value){
            limbs[0]=limbs[0]-(max_value+1);
            limbs.insert(limbs.begin(),1);
        }

        // carry
        for(size_t i=uadden_len; i>0; i--){
            if(limbs[i]>max_value){	
                limbs[i]=limbs[i]-(max_value+1);
                ++limbs[i-1];
            }
        }

        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        size_t resulting_size = limbs.size();
        for(size_t i=0; i<resulting_size; ++i){
            if(limbs[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) limbs.erase(limbs.begin()+0,limbs.begin()+limb_to_remove);
        
        return *this;
    }
}

#endif