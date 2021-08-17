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
        for(size_t i=0; i<multiplier.limbs.size(); ++i)
        {
            for(size_t j=0;j<limbs.size();++j)
            {
                product_flimbs[product_flimbs.size()-1-i-j] += (limbs[limbs.size()-1-j]*multiplier.limbs[multiplier.limbs.size()-1-i]);
            }
        }

        // carry
        dtype ten;
        dtype one;
        for(size_t i=0;i<product_flimbs.size();++i)
        {
            if(product_flimbs[product_flimbs.size()-1-i]>=max_value+1)
            {
                ten = ten_thsd(product_flimbs[product_flimbs.size()-1-i]);
                one = one_thsd(product_flimbs[product_flimbs.size()-1-i],ten);
                product_flimbs[product_flimbs.size()-1-i]=one;
                product_flimbs[product_flimbs.size()-1-i-1]=product_flimbs[product_flimbs.size()-1-i-1]+ten;
            }
        }

        size_t multiplicand_decimal_limb_count = limbs.size()-decimal_point;
        size_t multiplier_decimal_limb_count = multiplier.limbs.size()-multiplier.decimal_point;
        size_t product_decimal_limb_count = multiplicand_decimal_limb_count+multiplier_decimal_limb_count;
        size_t product_decimal_place = product_flimbs.size() - product_decimal_limb_count;

        // remove fron zero limbs
        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = product_flimbs.size();
        for(size_t i=0; i<product_flimbs.size(); ++i)
        {
            if(product_flimbs[i]==0 && resulting_size>1)
            {
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove)
        {
            product_flimbs.erase(product_flimbs.begin()+0,product_flimbs.begin()+limb_to_remove);
        }

        product_decimal_place -= limb_to_remove;

        return flimb(product_flimbs,product_decimal_place);
    }

    inline flimb& flimb::operator*=(const flimb& multiplier)
    {
        return *this = *this * multiplier;
    }

}

#endif