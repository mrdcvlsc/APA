#ifndef APA_MATH_CPP
#define APA_MATH_CPP

#ifdef _MAKE_LIB
#include "math.hpp"
#endif

#define DEVMODE
#ifdef DEVMODE
#include "math.hpp"
#endif

namespace apa {
    integer fibonacci_integer(size_t nth, integer b0, integer b1) {
        if(nth < 2) {
            return __INTEGER_ONE;
        }
        return fibonacci_template<integer>(nth, b0, b1);
    }

    bint fibonacci(size_t nth, bint b0, bint b1) {
        if(nth < 2) {
            return __BINT_ONE;
        }
        return fibonacci_template<bint>(nth, b0, b1);
    }

    integer factorial_integer(size_t n) {
        return factorial_template<integer>(n);
    }

    bint factorial(size_t n) {
        return factorial_template<bint>(n);
    }
}

#endif