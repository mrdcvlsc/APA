#ifndef LIMB_MULTIPLY_HPP
#define LIMB_MULTIPLY_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline dtype limb::one_thsd(dtype number, dtype tens) const
    {
        return number-(tens*(max_value+1));
    }

    inline dtype limb::ten_thsd(dtype number) const
    {
        return number/(max_value+1);
    }

    inline limb limb::operator*(const limb& multiplier) const
    {
        // add the answer of the multiplicand and multiplier to the answer array
        size_t multiplicand_len = limbs.size();
        size_t multiplier_len = multiplier.limbs.size();

        // set all values of product to zero
        size_t product_length = multiplicand_len+multiplier_len; 
        std::vector<dtype> product_limb(product_length,0);

        // operation
        dtype ten;
        dtype one;
        for(size_t i=0; i<multiplier_len; ++i)
        {
            for(size_t j=0; j<multiplicand_len; ++j)
            {
                product_limb[product_length-1-i-j] += (limbs[multiplicand_len-1-j]*multiplier.limbs[multiplier_len-1-i]);
                
                // carry - can be optimized by scanning first the max values of multiplicand and multiplier then setting the threshold if we can
                // continue to just add the product in the product index, or to carry immidietely
                if(product_limb[product_length-1-i-j]>=max_value+1)
                {
                    ten = ten_thsd(product_limb[product_length-1-i-j]);
                    one = one_thsd(product_limb[product_length-1-i-j],ten);
                    product_limb[product_length-1-i-j]=one;
                    product_limb[product_length-1-i-j-1]=product_limb[product_length-1-i-j-1]+ten;
                }
            }
        }

        // remove fron zero limbs
        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = product_length;

        for(size_t i=0; i<product_length; ++i)
        {
            if(product_limb[i]==0 && resulting_size>1)
            {
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }

        if(limb_to_remove)
        {
            product_limb.erase(product_limb.begin()+0,product_limb.begin()+limb_to_remove);
        }

        return limb(product_limb);
    }

    // /// partial limb multiplication
    // inline limb limb::p_mul(const limb& a, const size_t a_start, const size_t a_len, const limb&b, const size_t b_start, const size_t b_len)
    // {
    //     // set all values of product to zero
    //     size_t product_length = a_len+b_len; 
    //     std::vector<dtype> product_limb(product_length,0);

    //     // operation
    //     dtype ten;
    //     dtype one;

    //     size_t a_end = a_start+a_len;
    //     size_t b_end = b_start+b_len;

    //     for(size_t i=0; i<b_len; ++i)
    //     {
    //         for(size_t j=0; j<a_len; ++j)
    //         {
    //             product_limb[product_length-1-i-j] += (a.limbs[a_end-1-j]*b.limbs[b_end-1-i]);
    //             // carry - can be optimized by scanning first the max values of multiplicand and multiplier then setting the threshold if we can
    //             // continue to just add the product in the product index, or to carry immidietely
    //             if(product_limb[product_length-1-i-j]>=max_value+1)
    //             {
    //                 ten = product_limb[product_length-1-i-j]/(max_value+1);
    //                 one = product_limb[product_length-1-i-j]-(ten*(max_value+1));
    //                 product_limb[product_length-1-i-j]=one;
    //                 product_limb[product_length-1-i-j-1]=product_limb[product_length-1-i-j-1]+ten;
    //             }
    //         }
    //     }

    //     // for(auto e: product_limb) std::cout<<e<<' ';
    //     // std::cout<<"\n";

    //     // remove fron zero limbs
    //     // check and remove zero limbs
    //     size_t limb_to_remove = 0;
    //     size_t resulting_size = product_length;

    //     for(size_t i=0; i<product_length; ++i)
    //     {
    //         if(product_limb[i]==0 && resulting_size>1)
    //         {
    //             limb_to_remove++;
    //             resulting_size--;
    //         }
    //         else break;
    //     }

    //     if(limb_to_remove)
    //     {
    //         product_limb.erase(product_limb.begin(),product_limb.begin()+limb_to_remove);
    //     }

    //     return limb(product_limb);
    // }
}

#endif