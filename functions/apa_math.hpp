#ifndef APA_MATH_HPP
#define APA_MATH_HPP

#include <iostream>
#include "../bint/bint.hpp"
#include "../bfloat/bfloat.hpp"

namespace apa
{    
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