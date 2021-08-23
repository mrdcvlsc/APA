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

        // you can implement the functions below if you want

        bint gcd(const bint& a, const bint& b); // not defined
        bint lcm(const bint&a, const bint& b); // not defined

        bint factorial(const bint& n); // not defined

        bfloat sqrt(const bint& a); // not defined
        bfloat sqrt(const bfloat& a); // not defined

        bfloat ln(const bint& n); // not defined
        bfloat ln(const bfloat& n); // not defined

        bfloat log2(const bint& n); // not defined
        bfloat log2(const bfloat& n); // not defined

        bfloat log10(const bint& n); // not defined
        bfloat log10(const bfloat& n); // not defined

        bfloat log(const bint& b, const bint& n);
        bfloat log(const bfloat& b, const bfloat& n);

        /// round up values
        bfloat ceil(const bfloat& n); // not defined

        /// round down values
        bfloat roof(const bfloat& n); // not defined

        /// round-off values
        bfloat round(const bfloat& n); // not defined
    }
}

#include "pow.cpp"

#endif