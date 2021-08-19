#ifndef BFLOAT_INDECREMENT_HPP
#define BFLOAT_INDECREMENT_HPP

#include <iostream>
#include "../bfloat.hpp"

namespace arb
{
    // all of these can be optimized more by directly adding or subtractiong instead of passing to constructor the 1 value

    bfloat& bfloat::operator++()
    {
        bfloat one;
        one.floatlimbs = backend_bigfloat::flimb({1,0},1);
        one.sign = 1;
        *this += one;
        return *this;
    }

    bfloat& bfloat::operator--()
    {
        bfloat one;
        one.floatlimbs = backend_bigfloat::flimb({1,0},1);
        one.sign = 1;
        *this -= one;
        return *this;
    }

    //post-fix increment/decrementa
    bfloat bfloat::operator++(int)
    {
        bfloat one;
        one.floatlimbs = backend_bigfloat::flimb({1,0},1);
        one.sign = 1;
        ++*this;
        return *this-one;
    }

    bfloat bfloat::operator--(int)
    {
        bfloat one;
        one.floatlimbs = backend_bigfloat::flimb({1,0},1);
        one.sign = 1;
        --*this;
        return *this+one;
    }
}

#endif