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
    template <class T>
    T fibonacci_template(size_t nth, T b0, T b1) {
        T base0 = b0, base1 = b1;
        T nthfib = 0;
        for (size_t i = 2; i < nth; ++i) {
            nthfib = base0 + base1;
            base0 = std::move(base1);
            base1 = std::move(nthfib);
        }
        return base0 + base1;
    }

    template <class T>
    T factorial_template(size_t n) {
        T factorial(1);
        T iter = factorial;

        for (size_t i = 1; i <= n; ++i) {
            factorial *= iter;
            iter++;
        }

        return factorial;
    }

    integer fibonacci_integer(size_t nth, integer b0, integer b1) {
        if (nth < 2) {
            return __INTEGER_ONE;
        }
        return fibonacci_template<integer>(nth, b0, b1);
    }

    bint fibonacci(size_t nth, bint b0, bint b1) {
        if (nth < 2) {
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

    integer power_integer(const integer &base, const integer &exponent) {
        if (exponent == __INTEGER_ZERO) {
            return __INTEGER_ONE;
        } else if (exponent == __INTEGER_ONE) {
            return base;
        }

        integer sub_power = power_integer(base, exponent / __INTEGER_TWO);

        if ((exponent % __INTEGER_TWO) == __INTEGER_ZERO) {
            return sub_power * sub_power;
        } else {
            return base * sub_power * sub_power;
        }
    }

    bint power(const bint &base, const bint &exponent) {
        if (exponent == __BINT_ZERO) {
            return __BINT_ONE;
        } else if (exponent == __BINT_ONE) {
            return base;
        }

        bint sub_power = power(base, exponent / __BINT_TWO);

        if ((exponent % __BINT_TWO) == __BINT_ZERO) {
            return sub_power * sub_power;
        } else {
            return base * sub_power * sub_power;
        }
    }

} // namespace apa

#endif