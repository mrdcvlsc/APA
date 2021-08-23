#ifndef LIMB_SUBTRACTION_HPP
#define LIMB_SUBTRACTION_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline limb limb::operator-(const limb& subtrahend) const
    {
        #ifndef PRODUCTION
        int cases = compare(subtrahend);
        switch(cases)
        {
            case -1 :
                throw std::length_error(
                    "ERROR : limb operator-() : cannot subtract limbs with subtrahend("+subtrahend.string_form()+") greater than the minuend"
                    "("+string_form()+")"
                );
            case 0 :
                return limb("0");
            default:
                break;
        }
        #endif

        size_t minuend_len = limbs.size();
        size_t subtrah_len = subtrahend.limbs.size();

        size_t longest_len = std::max(minuend_len,subtrah_len);
        size_t ans_len = longest_len;
        std::vector<dtype> diff_limbs(ans_len,0);								

        // operation
        for(size_t i=0 ;i<minuend_len; ++i)
        {
            diff_limbs[ans_len-1-i]=limbs[minuend_len-1-i];
        }
        
        for(size_t i=0 ;i<subtrah_len; ++i)
        {
            diff_limbs[ans_len-1-i]-=subtrahend.limbs[subtrah_len-1-i];
        }

        // carry
        for(size_t i=ans_len-1; i>0; --i)
        {
            if(diff_limbs[i]<0)
            {
                diff_limbs[i]=diff_limbs[i]+(max_value+1);
                diff_limbs[i-1]--;
            }
        }

        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        size_t resulting_size = ans_len;
        for(size_t i=0; i<ans_len; ++i)
        {
            if(diff_limbs[i]==0 && resulting_size>1)
            {
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) diff_limbs.erase(diff_limbs.begin()+0,diff_limbs.begin()+limb_to_remove);

        return limb(diff_limbs);
    }

    inline limb& limb::operator-=(const limb& subtrahend)
    {
        #ifndef PRODUCTION
        int cases = compare(subtrahend);
        switch(cases)
        {
            case -1 :
                throw std::length_error(
                    "ERROR : limb operator-() : cannot subtract limbs with subtrahend("+subtrahend.string_form()+") greater than the minuend"
                    "("+string_form()+")"
                );
            case 0 :
                limbs.clear();
                limbs.push_back(0);
                return *this;
            default:
                break;
        }
        #endif

        size_t minuend_len = limbs.size();
        size_t subtrah_len = subtrahend.limbs.size();							

        // operation    
        for(size_t i=0 ;i<subtrah_len; ++i)
        {
            limbs[minuend_len-1-i]-=subtrahend.limbs[subtrah_len-1-i];
        }

        // carry
        for(size_t i=minuend_len-1; i>0; --i)
        {
            if(limbs[i]<0)
            {
                limbs[i]=limbs[i]+(max_value+1);
                limbs[i-1]--;
            }
        }

        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = minuend_len;
        for(size_t i=0; i<minuend_len; ++i)
        {
            if(limbs[i]==0 && resulting_size>1)
            {
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) limbs.erase(limbs.begin()+0,limbs.begin()+limb_to_remove);

        return *this;
    }

    // /// partial limb subtraction
    // inline limb limb::p_sub(const limb& a, const size_t a_start, const size_t a_len, const limb&b, const size_t b_start, const size_t b_len)
    // {
    //     #ifndef PRODUCTION
    //     int cases = a.compare(b);
    //     switch(cases)
    //     {
    //         case -1 :
    //             throw std::length_error(
    //                 "ERROR : limb operator-() : cannot subtract limbs with subtrahend("+b.string_form()+") greater than the minuend"
    //                 "("+a.string_form()+")"
    //             );
    //         case 0 :
    //             return limb("0");
    //         default:
    //             break;
    //     }
    //     #endif

    //     size_t longest_len = std::max(a_len,b_len);
    //     size_t ans_len = longest_len;
    //     std::vector<dtype> diff_limbs(ans_len,0);	

    //     size_t a_end = a_start+a_len;
    //     size_t b_end = b_start+b_len;

    //     // operation
    //     for(size_t i=0 ;i<a_len; ++i)
    //     {
    //         diff_limbs[ans_len-1-i]=a.limbs[a_end-1-i];
    //     }
        
    //     for(size_t i=0 ;i<b_len; ++i)
    //     {
    //         diff_limbs[ans_len-1-i]-=b.limbs[b_end-1-i];
    //     }

    //     // carry
    //     for(size_t i=ans_len-1; i>0; --i)
    //     {
    //         if(diff_limbs[i]<0)
    //         {
    //             diff_limbs[i]=diff_limbs[i]+(max_value+1);
    //             diff_limbs[i-1]--;
    //         }
    //     }

    //     // check and remove zero limbs in front
    //     size_t limb_to_remove = 0;
    //     size_t resulting_size = ans_len;
    //     for(size_t i=0; i<ans_len; ++i)
    //     {
    //         if(diff_limbs[i]==0 && resulting_size>1)
    //         {
    //             limb_to_remove++;
    //             resulting_size--;
    //         }
    //         else break;
    //     }
        
    //     if(limb_to_remove)
    //     {
    //         diff_limbs.erase(diff_limbs.begin()+0,diff_limbs.begin()+limb_to_remove);
    //     }

    //     return limb(diff_limbs);
    // }
}

#endif