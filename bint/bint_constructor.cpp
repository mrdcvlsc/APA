#ifndef BINT_CONSTRUCTOR_HPP
#define BINT_CONSTRUCTOR_HPP

#include <iostream>
#include "bint.hpp"

namespace apa
{
    bint::bint() {}
    
    bint::bint(const std::string& number)
    {
        std::string num = number;
        if(num[0]=='-'){
            sign = -1;
            num = num.substr(1,num.size()-1);
        }
        else sign = 1;
        intlimbs = backend_bigint::limb(num);
    }

    bint::bint(const std::vector<backend_bigint::dtype>& limbs)
    {
        intlimbs = backend_bigint::limb(limbs);
    }

    bint::bint(short number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(unsigned short number)
    {
        sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(int number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(unsigned int number)
    {
        sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(long number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(unsigned long number)
    {
        sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(long long number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        intlimbs = backend_bigint::limb(number);
    }

    bint::bint(unsigned long long number)
    {
        sign = 1;
        intlimbs = backend_bigint::limb(number);
    }
}

#endif