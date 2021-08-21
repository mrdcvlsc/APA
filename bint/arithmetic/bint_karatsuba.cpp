#ifndef BINT_KARATSUBA_CPP
#define BINT_KARATSUBA_CPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::karatsuba(const bint& multiplier) const
    {
        if(intlimbs.limb_count()<=KARATSUBA_TRESHOLD || multiplier.intlimbs.limb_count()<=KARATSUBA_TRESHOLD)
        {
            // use naive at a certain treshold
            return naive_mul(multiplier);
        }
        else if(*this==BINTZERO || multiplier==BINTZERO)
        {
            return BINTZERO;
        }
        else if(*this==BINTONE)
        {
            return multiplier;
        }
        else if(multiplier==BINTONE)
        {
            return *this;
        }

        bint a,b,c,d,z0,z1,z2,z3,z4;

        a.sign = 1;
        b.sign = 1;
        c.sign = 1;
        d.sign = 1;

        // ---- //

        size_t mcand_len = intlimbs.limb_count();
        size_t mlier_len = multiplier.intlimbs.limb_count();
        size_t split, P;

        if(mcand_len==mlier_len)
        {
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

        z0 = a.karatsuba(c);
        z1 = b.karatsuba(d);
        z2 = (a+b).karatsuba(c+d);
        z3 = z2-z1-z0;
        
        for(size_t i=P; i--; )
        {
            z0.intlimbs.limbs.push_back(0);
            z0.intlimbs.limbs.push_back(0);
        }

        for(size_t i=P; i--; )
        {
            z3.intlimbs.limbs.push_back(0);
        }
        
        z4 = z0+z1+z3;

        return z4;
    }
}

#endif