#ifndef APA_MATH_HPP
#define APA_MATH_HPP

#include <iostream>
#include "../bint/bint.hpp"
#include "../bfloat/bfloat.hpp"

namespace apa
{
    apa::bint BINTZERO = 0;
    apa::bint BINTONE = 1;
    apa::bint BINTTWO = 2;

    apa::bfloat BFLOATZERO("0.0");
    apa::bfloat BFLOATONE("1.0");
    apa::bfloat BFLOATTWO("2.0");
    
    namespace math
    {
        bint pow(const bint& base, const bint& exponent);
        bfloat pow(const bfloat& base, const bint& exponent);

        bint gcd(const bint& a, const bint& b); // not defined

        bfloat sqrt(const bint& a); // not defined
        bfloat sqrt(const bfloat& a); // not defined

        bint factorial(const bint& n); // not defined
    }
}

#include "power.cpp"

#endif