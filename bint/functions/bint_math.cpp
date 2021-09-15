#ifndef BINT_MATH_CPP
#define BINT_MATH_CPP

#include "../bint.hpp"

namespace apa
{
    bint pow(const bint& base, const bint& exponent)
    {    
        if(exponent==BINTZERO)
        {
            return BINTONE;
        }
        else if(exponent==BINTONE)
        {
            return base;
        }

        bint sub_pow = apa::pow(base,exponent/BINTTWO);

        if((exponent%BINTTWO)==BINTZERO)
        {
            return sub_pow*sub_pow;
        }
        else
        {
            return base*sub_pow*sub_pow;
        }
    }
}

#endif