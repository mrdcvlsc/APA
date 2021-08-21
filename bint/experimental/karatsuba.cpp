#ifndef KARATSUBA_CPP
#define KARATSUBA_CPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    #define KARATSUBA_TRESHOLD 17
    // bint bint::karatsuba_backend(const bint& multiplier)
    // {

    // }

    inline backend_bigint::dtype one_thsd(backend_bigint::dtype number, backend_bigint::dtype tens)
    {
        return number-(tens*(backend_bigint::limb::max_value+1));
    }

    inline backend_bigint::dtype ten_thsd(backend_bigint::dtype number)
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
                    ten = ten_thsd(product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)]);
                    one = one_thsd(product_limb[product_limb.size()-1-(b_len-i)-(a_len-j)],ten);
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

    apa::bint BINTZERO = 0;
    apa::bint BINTONE = 1;
    apa::bint BINTTWO = 2;

    bint bint::karatsuba(const bint& multiplier)
    {
        // std::cout<<"karatsuba() - called\n";
        // base case

        if(intlimbs.limb_count()<=KARATSUBA_TRESHOLD || multiplier.intlimbs.limb_count()<=KARATSUBA_TRESHOLD)
        {
            // std::cout<<"base case karatsuba\n";
            return *this*multiplier;
        }
        // else if(*this==BINTZERO || multiplier==BINTZERO)
        // {
        //     return BINTZERO;
        // }
        // else if(*this==BINTONE)
        // {
        //     return multiplier;
        // }
        // else if(multiplier==BINTONE)
        // {
        //     return *this;
        // }

        bint a,b,c,d,z0,z1,z2,z3,z4;

        a.sign = 1;
        b.sign = 1;
        c.sign = 1;
        d.sign = 1;

        // ---- //

        // partition mmultiplicand and multiplier

        size_t mcand_len = intlimbs.limb_count();
        size_t mlier_len = multiplier.intlimbs.limb_count();
        size_t split, P;

        if(mcand_len==mlier_len)
        {
            // std::cout<<"pad case 0\n";
            split = mcand_len/2;
            P = mcand_len-split;

            // correct
            std::vector<backend_bigint::dtype> av(intlimbs.limbs.begin(),intlimbs.limbs.end()-P);
            std::vector<backend_bigint::dtype> bv(intlimbs.limbs.end()-P,intlimbs.limbs.end());

            // correct
            std::vector<backend_bigint::dtype> cv(multiplier.intlimbs.limbs.begin(),multiplier.intlimbs.limbs.end()-P);
            std::vector<backend_bigint::dtype> dv(multiplier.intlimbs.limbs.end()-P,multiplier.intlimbs.limbs.end());

            a.intlimbs = av;
            b.intlimbs = bv;
            c.intlimbs = cv;
            d.intlimbs = dv;
        }
        else if(mcand_len>mlier_len)
        {
            // std::cout<<"pad case 1\n";
            split = mcand_len/2;
            P = mcand_len-split;

            // correct
            std::vector<backend_bigint::dtype> av(intlimbs.limbs.begin(),intlimbs.limbs.end()-P);
            std::vector<backend_bigint::dtype> bv(intlimbs.limbs.end()-P,intlimbs.limbs.end());

            a.intlimbs = av;
            b.intlimbs = bv;

            if(mlier_len>P)
            {// correct
                std::vector<backend_bigint::dtype> cv(multiplier.intlimbs.limbs.begin(),multiplier.intlimbs.limbs.end()-P);
                std::vector<backend_bigint::dtype> dv(multiplier.intlimbs.limbs.end()-P,multiplier.intlimbs.limbs.end());

                c.intlimbs = cv;
                d.intlimbs = dv;
            }
            else if(mlier_len<=P)
            {
                c.intlimbs = {0};
                d.intlimbs = multiplier.intlimbs;
            }
        }
        else
        {
            // std::cout<<"pad case 2\n";
            split = mlier_len/2;
            P = mlier_len-split;

            // correct
            std::vector<backend_bigint::dtype> cv(multiplier.intlimbs.limbs.begin(),multiplier.intlimbs.limbs.end()-P);
            std::vector<backend_bigint::dtype> dv(multiplier.intlimbs.limbs.end()-P,multiplier.intlimbs.limbs.end());

            c.intlimbs = cv;
            d.intlimbs = dv;

            if(mcand_len>P)
            {
                // correct
                std::vector<backend_bigint::dtype> av(intlimbs.limbs.begin(),intlimbs.limbs.end()-P);
                std::vector<backend_bigint::dtype> bv(intlimbs.limbs.end()-P,intlimbs.limbs.end());

                a.intlimbs = av;
                b.intlimbs = bv;
            }
            else if(mcand_len<=P)
            {
                a.intlimbs = {0};
                b.intlimbs = intlimbs;
            }
        }

        // std::cout<<"split size = "<<split<<"\n";
        // std::cout<<"P size = "<<P<<"\n";

        // std::cout<<"\nx = "<<*this<<"\n";
        // std::cout<<"y = "<<multiplier<<"\n";

        // std::cout<<"\na = "<<a<<"\n";
        // std::cout<<"b = "<<b<<"\n";
        // std::cout<<"c = "<<c<<"\n";
        // std::cout<<"d = "<<d<<"\n";

        // ---- //
        z0 = a.karatsuba(c);
        // std::cout<<"z0 = "<<z0<<"\n";

        z1 = b.karatsuba(d);
        // std::cout<<"z1 = "<<z1<<"\n";

        z2 = (a+b).karatsuba(c+d);
        // std::cout<<"z2 = "<<z2<<"\n";

        z3 = z2-z1-z0;
        // std::cout<<"z3 = "<<z3<<"\n";
        
        for(size_t i=P; i--; )
        {
            z0.intlimbs.limbs.push_back(0);
            z0.intlimbs.limbs.push_back(0);
        }

        // std::cout<<"z0 after = "<<z0<<"\n";

        for(size_t i=P; i--; )
        {
            z3.intlimbs.limbs.push_back(0);
        }

        // std::cout<<"z3 after = "<<z3<<"\n";

        z4 = z0+z1+z3;

        // std::cout<<"z4 = "<<z4<<"\n";

        return z4;
    }
}

#endif