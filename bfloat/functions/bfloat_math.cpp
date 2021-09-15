#ifndef BFLOAT_MATH_CPP
#define BFLOAT_MATH_CPP

#include "../bfloat.hpp"

namespace apa
{
    bfloat pow(const bfloat& base, const bint& exponent)
    {
        if(exponent==BINTZERO)
        {
            return BFLOATONE;
        }
        else if(exponent==BINTONE)
        {
            return base;
        }

        bfloat sub_power = apa::pow(base,exponent/BINTTWO);

        if((exponent%BINTTWO)==BINTZERO)
        {
            return sub_power*sub_power;
        }
        else
        {
            return base*sub_power*sub_power;
        }
    }
}

#endif