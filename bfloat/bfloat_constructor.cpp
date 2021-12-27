#ifndef BFLOAT_CONSTRUCTOR_HPP
#define BFLOAT_CONSTRUCTOR_HPP

#include <iostream>
#include "bfloat.hpp"

namespace apa
{
    bfloat::bfloat() {}

    // copy constructor
    bfloat::bfloat(const bfloat& other) : floatlimbs(other.floatlimbs)
    {
        sign = other.sign;
    }

    // move constructor
    bfloat::bfloat(bfloat&& temp) noexcept : floatlimbs(std::move(temp.floatlimbs))
    {
        sign = temp.sign;
    }

    // copy assignment
    bfloat& bfloat::operator=(const bfloat& other)
    {
        floatlimbs = other.floatlimbs;
        sign = other.sign;
        return *this;
    }

    // move assignment
    bfloat& bfloat::operator=(bfloat&& temp) noexcept
    {
        floatlimbs = std::move(temp.floatlimbs);
        sign = temp.sign;
        return *this;
    }
    
    bfloat::bfloat(const std::string& number)
    {
        std::string num = number;
        if(num[0]=='-'){
            sign = -1;
            num = num.substr(1,num.size()-1);
        }
        else sign = 1;
        floatlimbs = backend_bigfloat::flimb(num);
    }

    bfloat::bfloat(const std::vector<backend_bigint::dtype>& flimbs, size_t decimal_point)
    {
        floatlimbs = backend_bigfloat::flimb(flimbs,decimal_point);
    }

    bfloat::bfloat(float number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        floatlimbs = backend_bigfloat::flimb(number);
    }

    bfloat::bfloat(double number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        floatlimbs = backend_bigfloat::flimb(number);
    }

    bfloat::bfloat(long double number)
    {
        if(number<0)
        {
            sign = -1;
            number = std::abs(number);
        }
        else sign = 1;
        floatlimbs = backend_bigfloat::flimb(number);
    }
}

#endif