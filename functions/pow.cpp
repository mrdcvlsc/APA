#ifndef POWER_CPP
#define POWER_CPP

#include <iostream>
#include "../bint/bint.hpp"
#include "../bfloat/bfloat.hpp"
#include "apa_math.hpp"

namespace apa::math
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

        bint sub_power = pow(base,exponent/BINTTWO);

        if((exponent%BINTTWO)==BINTZERO)
        {
            return sub_power*sub_power;
        }
        else
        {
            return base*sub_power*sub_power;
        }
    }

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

        bfloat sub_power = pow(base,exponent/BINTTWO);

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