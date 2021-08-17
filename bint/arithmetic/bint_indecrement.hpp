#ifndef BINT_INDECREMENT_HPP
#define BINT_INDECREMENT_HPP

#include <iostream>
#include "../bint.hpp"

namespace arb
{
    bint& bint::operator++()
    {
        *this += bint("1");
        return *this;
    }

    bint& bint::operator--()
    {
        *this -= bint("1");
        return *this;
    }

    //post-fix increment/decrementa
    bint bint::operator++(int)
    {
        ++*this;
        return *this-bint("1"); 
    }

    bint bint::operator--(int)
    {
        --*this;
        return *this+bint("1");
    }
}

#endif