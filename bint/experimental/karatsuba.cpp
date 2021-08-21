#ifndef KARATSUBA_CPP
#define KARATSUBA_CPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    inline backend_bigint::dtype shadow_one_thsd(backend_bigint::dtype number, backend_bigint::dtype tens)
    {
        return number-(tens*(backend_bigint::limb::max_value+1));
    }

    inline backend_bigint::dtype shadow_ten_thsd(backend_bigint::dtype number)
    {
        return (backend_bigint::dtype)std::floor((long double)number/(long double)(backend_bigint::limb::max_value+1));
    }

    typedef std::vector<backend_bigint::dtype> pvec; 

    pvec shadow_product(const pvec& a, size_t a_start, size_t a_len, const pvec& b, size_t b_start, size_t b_len)
    {
        pvec product_limb(a_len+b_len,0);

        // operation
        backend_bigint::dtype ten;
        backend_bigint::dtype one;
        for(size_t i=b_start; i<b_len; ++i)
        {
            for(size_t j=a_start; j<a_len; ++j)
            {
                product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)] += (a[a_len-1-j]*b[b_len-1-i]);
                
                // carry
                if(product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)]>=backend_bigint::limb::max_value+1)
                {
                    ten = shadow_ten_thsd(product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)]);
                    one = shadow_one_thsd(product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)],ten);
                    product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)]=one;
                    product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)-1]=product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)-1]+ten;
                }
            }
        }

        // remove fron zero limbs
        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = product_limb.size();
        for(size_t i=0; i<product_limb.size(); ++i)
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

        return product_limb;
    }

    
}

#endif