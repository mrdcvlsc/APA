#ifndef FLIMB_MULTIPLY_HPP
#define FLIMB_MULTIPLY_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline flimb flimb::operator*(const flimb& multiplier) const
    {
        std::vector<dtype> product_flimbs(limbs.size()+multiplier.limbs.size(),0);

        // operation
        dtype ten;
        dtype one;
        for(size_t i=0; i<multiplier.limbs.size(); ++i)
        {
            for(size_t j=0;j<limbs.size();++j)
            {
                product_flimbs[product_flimbs.size()-1-i-j] += (limbs[limbs.size()-1-j]*multiplier.limbs[multiplier.limbs.size()-1-i]);

                // carry to avoid overflow
                if(product_flimbs[product_flimbs.size()-1-i-j]>=max_value+1)
                {
                    ten = ten_thsd(product_flimbs[product_flimbs.size()-1-i-j]);
                    one = one_thsd(product_flimbs[product_flimbs.size()-1-i-j],ten);
                    product_flimbs[product_flimbs.size()-1-i-j]=one;
                    product_flimbs[product_flimbs.size()-1-i-j-1]=product_flimbs[product_flimbs.size()-1-i-j-1]+ten;
                }
            }
        }

        // // carry
        // dtype ten;
        // dtype one;
        // for(size_t i=0;i<product_flimbs.size();++i)
        // {
        //     if(product_flimbs[product_flimbs.size()-1-i]>=max_value+1)
        //     {
        //         ten = ten_thsd(product_flimbs[product_flimbs.size()-1-i]);
        //         one = one_thsd(product_flimbs[product_flimbs.size()-1-i],ten);
        //         product_flimbs[product_flimbs.size()-1-i]=one;
        //         product_flimbs[product_flimbs.size()-1-i-1]=product_flimbs[product_flimbs.size()-1-i-1]+ten;
        //     }
        // }

        size_t multiplicand_decimal_limb_count = limbs.size()-decimal_point;
        size_t multiplier_decimal_limb_count = multiplier.limbs.size()-multiplier.decimal_point;
        size_t product_decimal_limb_count = multiplicand_decimal_limb_count+multiplier_decimal_limb_count;
        size_t product_decimal_place = product_flimbs.size() - product_decimal_limb_count;

        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        for(size_t i=0; i<product_decimal_place-1; ++i)
        {
            if(product_flimbs[i]==0)
            {
                limb_to_remove++;
            }
            else break;
        }
        if(limb_to_remove)
        {
            product_flimbs.erase(product_flimbs.begin()+0,product_flimbs.begin()+limb_to_remove);
        }

        product_decimal_place -= limb_to_remove;

        // check and remove zero limbs in rear
        size_t rear_limb_to_remove = 0;
        for(size_t i=product_flimbs.size()-1; i>product_decimal_place; --i)
        {
            if(product_flimbs[i]!=0)
            {
                break;
            }
            rear_limb_to_remove++;
        }
   
        if(rear_limb_to_remove)
        {
            product_flimbs.erase(product_flimbs.end()-rear_limb_to_remove, product_flimbs.end());
        }

        return flimb(product_flimbs,product_decimal_place);
    }

    inline flimb& flimb::operator*=(const flimb& multiplier)
    {
        return *this = *this * multiplier;
    }

}

#endif