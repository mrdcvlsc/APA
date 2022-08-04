#ifndef APA_MATH_HPP
#define APA_MATH_HPP

#include "bint.hpp"

namespace apa {
        
    integer fibonacci_integer(size_t nth, integer b0 = 0, integer b1 = 1);
    bint fibonacci(size_t nth, bint b0 = 0, bint b1 = 1);

    integer factorial_integer(size_t n);
    bint factorial(size_t n);

    integer power_integer(const integer& base, const integer& exponent);
    bint power(const bint& base, const bint& exponent);
}

#endif