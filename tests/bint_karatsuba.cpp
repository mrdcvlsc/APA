#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../core.hpp"
#else
#include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    apa::bint fac250 = apa::factorial(250),
              fib500 = apa::fibonacci(500),
              fac500 = apa::factorial(500),
              fib1000 = apa::fibonacci(1000),
              fib864 = apa::fibonacci(864),
              fac162 = apa::factorial(162);

    ASSERT_EQUALITY(fac250.mul_naive(fac250), (fac250*fac250), "phase A : karatsuba test 01 ");
    ASSERT_EQUALITY(fac250.mul_naive(fib500), (fac250*fib500), "phase A : karatsuba test 02 ");
    ASSERT_EQUALITY(fac250.mul_naive(fac500), (fac250*fac500), "phase A : karatsuba test 03 ");
    ASSERT_EQUALITY(fac250.mul_naive(fib1000), (fac250*fib1000), "phase A : karatsuba test 04 ");
    ASSERT_EQUALITY(fac250.mul_naive(fib864), (fac250*fib864), "phase A : karatsuba test 05 ");
    ASSERT_EQUALITY(fac250.mul_naive(fac162), (fac250*fac162), "phase A : karatsuba test 06 ");

    ASSERT_EQUALITY(fac250.mul_naive(fac250), (fac250*fac250), "phase A : karatsuba test 07 ");
    ASSERT_EQUALITY(fib500.mul_naive(fac250), (fib500*fac250), "phase A : karatsuba test 08 ");
    ASSERT_EQUALITY(fac500.mul_naive(fac250), (fac500*fac250), "phase A : karatsuba test 09 ");
    ASSERT_EQUALITY(fib1000.mul_naive(fac250), (fib1000*fac250), "phase A : karatsuba test 10 ");
    ASSERT_EQUALITY(fib864.mul_naive(fac250), (fib864*fac250), "phase A : karatsuba test 11 ");
    ASSERT_EQUALITY(fac162.mul_naive(fac250), (fac162*fac250), "phase A : karatsuba test 12 ");

    ASSERT_EQUALITY(fib500.mul_naive(fib500), (fib500*fib500), "phase A : karatsuba test 13 ");
    ASSERT_EQUALITY(fib500.mul_naive(fac500), (fib500*fac500), "phase A : karatsuba test 14 ");
    ASSERT_EQUALITY(fib500.mul_naive(fib1000), (fib500*fib1000), "phase A : karatsuba test 15 ");
    ASSERT_EQUALITY(fib500.mul_naive(fib864), (fib500*fib864), "phase A : karatsuba test 16 ");
    ASSERT_EQUALITY(fib500.mul_naive(fac162), (fib500*fac162), "phase A : karatsuba test 17 ");

    ASSERT_EQUALITY(fib500.mul_naive(fib500), (fib500*fib500), "phase A : karatsuba test 18 ");
    ASSERT_EQUALITY(fac500.mul_naive(fib500), (fac500*fib500), "phase A : karatsuba test 19 ");
    ASSERT_EQUALITY(fib1000.mul_naive(fib500), (fib1000*fib500), "phase A : karatsuba test 20 ");
    ASSERT_EQUALITY(fib864.mul_naive(fib500), (fib864*fib500), "phase A : karatsuba test 21 ");
    ASSERT_EQUALITY(fac162.mul_naive(fib500), (fac162*fib500), "phase A : karatsuba test 22 ");

    ASSERT_EQUALITY(fac500.mul_naive(fac500), (fac500*fac500), "phase A : karatsuba test 23 ");
    ASSERT_EQUALITY(fac500.mul_naive(fib1000), (fac500*fib1000), "phase A : karatsuba test 24 ");
    ASSERT_EQUALITY(fac500.mul_naive(fib864), (fac500*fib864), "phase A : karatsuba test 25 ");
    ASSERT_EQUALITY(fac500.mul_naive(fac162), (fac500*fac162), "phase A : karatsuba test 26 ");

    ASSERT_EQUALITY(fac500.mul_naive(fac500), (fac500*fac500), "phase A : karatsuba test 27 ");
    ASSERT_EQUALITY(fib1000.mul_naive(fac500), (fib1000*fac500), "phase A : karatsuba test 28 ");
    ASSERT_EQUALITY(fib864.mul_naive(fac500), (fib864*fac500), "phase A : karatsuba test 29 ");
    ASSERT_EQUALITY(fac162.mul_naive(fac500), (fac162*fac500), "phase A : karatsuba test 30 ");

    ASSERT_EQUALITY(fib1000.mul_naive(fib1000), (fib1000*fib1000), "phase A : karatsuba test 31 ");
    ASSERT_EQUALITY(fib1000.mul_naive(fib864), (fib1000*fib864), "phase A : karatsuba test 40 ");
    ASSERT_EQUALITY(fib1000.mul_naive(fac162), (fib1000*fac162), "phase A : karatsuba test 41 ");

    ASSERT_EQUALITY(fib1000.mul_naive(fib1000), (fib1000*fib1000), "phase A : karatsuba test 42 ");
    ASSERT_EQUALITY(fib864.mul_naive(fib1000), (fib864*fib1000), "phase A : karatsuba test 43 ");
    ASSERT_EQUALITY(fac162.mul_naive(fib1000), (fac162*fib1000), "phase A : karatsuba test 44 ");

    ASSERT_EQUALITY(fib864.mul_naive(fib864), (fib864*fib864), "phase A : karatsuba test 45 ");
    ASSERT_EQUALITY(fib864.mul_naive(fac162), (fib864*fac162), "phase A : karatsuba test 46 ");

    ASSERT_EQUALITY(fib864.mul_naive(fib864), (fib864*fib864), "phase A : karatsuba test 47 ");
    ASSERT_EQUALITY(fac162.mul_naive(fib864), (fac162*fib864), "phase A : karatsuba test 48 ");

    ASSERT_EQUALITY(fac162.mul_naive(fac162), (fac162*fac162), "phase A : karatsuba test 49 ");

    ASSERT_EQUALITY(fac162.mul_naive(fac162), (fac162*fac162), "phase A : karatsuba test 50 ");

    apa::bint fac64 = apa::factorial(64),
              fib75 = apa::fibonacci(75),
              fac713 = apa::factorial(713),
              fib200 = apa::fibonacci(200),
              fib2000 = apa::fibonacci(2000),
              fac1000 = apa::factorial(1000);

    ASSERT_EQUALITY(fac64.mul_naive(fac64), (fac64*fac64), "phase B : karatsuba test 01 ");
    ASSERT_EQUALITY(fac64.mul_naive(fib75), (fac64*fib75), "phase B : karatsuba test 02 ");
    ASSERT_EQUALITY(fac64.mul_naive(fac713), (fac64*fac713), "phase B : karatsuba test 03 ");
    ASSERT_EQUALITY(fac64.mul_naive(fib200), (fac64*fib200), "phase B : karatsuba test 04 ");
    ASSERT_EQUALITY(fac64.mul_naive(fib2000), (fac64*fib2000), "phase B : karatsuba test 05 ");
    ASSERT_EQUALITY(fac64.mul_naive(fac1000), (fac64*fac1000), "phase B : karatsuba test 06 ");

    ASSERT_EQUALITY(fac64.mul_naive(fac64), (fac64*fac64), "phase B : karatsuba test 07 ");
    ASSERT_EQUALITY(fib75.mul_naive(fac64), (fib75*fac64), "phase B : karatsuba test 08 ");
    ASSERT_EQUALITY(fac713.mul_naive(fac64), (fac713*fac64), "phase B : karatsuba test 09 ");
    ASSERT_EQUALITY(fib200.mul_naive(fac64), (fib200*fac64), "phase B : karatsuba test 10 ");
    ASSERT_EQUALITY(fib2000.mul_naive(fac64), (fib2000*fac64), "phase B : karatsuba test 11 ");
    ASSERT_EQUALITY(fac1000.mul_naive(fac64), (fac1000*fac64), "phase B : karatsuba test 12 ");

    ASSERT_EQUALITY(fib75.mul_naive(fib75), (fib75*fib75), "phase B : karatsuba test 13 ");
    ASSERT_EQUALITY(fib75.mul_naive(fac713), (fib75*fac713), "phase B : karatsuba test 14 ");
    ASSERT_EQUALITY(fib75.mul_naive(fib200), (fib75*fib200), "phase B : karatsuba test 15 ");
    ASSERT_EQUALITY(fib75.mul_naive(fib2000), (fib75*fib2000), "phase B : karatsuba test 16 ");
    ASSERT_EQUALITY(fib75.mul_naive(fac1000), (fib75*fac1000), "phase B : karatsuba test 17 ");

    ASSERT_EQUALITY(fib75.mul_naive(fib75), (fib75*fib75), "phase B : karatsuba test 18 ");
    ASSERT_EQUALITY(fac713.mul_naive(fib75), (fac713*fib75), "phase B : karatsuba test 19 ");
    ASSERT_EQUALITY(fib200.mul_naive(fib75), (fib200*fib75), "phase B : karatsuba test 20 ");
    ASSERT_EQUALITY(fib2000.mul_naive(fib75), (fib2000*fib75), "phase B : karatsuba test 21 ");
    ASSERT_EQUALITY(fac1000.mul_naive(fib75), (fac1000*fib75), "phase B : karatsuba test 22 ");

    ASSERT_EQUALITY(fac713.mul_naive(fac713), (fac713*fac713), "phase B : karatsuba test 23 ");
    ASSERT_EQUALITY(fac713.mul_naive(fib200), (fac713*fib200), "phase B : karatsuba test 24 ");
    ASSERT_EQUALITY(fac713.mul_naive(fib2000), (fac713*fib2000), "phase B : karatsuba test 25 ");
    ASSERT_EQUALITY(fac713.mul_naive(fac1000), (fac713*fac1000), "phase B : karatsuba test 26 ");

    ASSERT_EQUALITY(fac713.mul_naive(fac713), (fac713*fac713), "phase B : karatsuba test 27 ");
    ASSERT_EQUALITY(fib200.mul_naive(fac713), (fib200*fac713), "phase B : karatsuba test 28 ");
    ASSERT_EQUALITY(fib2000.mul_naive(fac713), (fib2000*fac713), "phase B : karatsuba test 29 ");
    ASSERT_EQUALITY(fac1000.mul_naive(fac713), (fac1000*fac713), "phase B : karatsuba test 30 ");

    ASSERT_EQUALITY(fib200.mul_naive(fib200), (fib200*fib200), "phase B : karatsuba test 31 ");
    ASSERT_EQUALITY(fib200.mul_naive(fib2000), (fib200*fib2000), "phase B : karatsuba test 40 ");
    ASSERT_EQUALITY(fib200.mul_naive(fac1000), (fib200*fac1000), "phase B : karatsuba test 41 ");

    ASSERT_EQUALITY(fib200.mul_naive(fib200), (fib200*fib200), "phase B : karatsuba test 42 ");
    ASSERT_EQUALITY(fib2000.mul_naive(fib200), (fib2000*fib200), "phase B : karatsuba test 43 ");
    ASSERT_EQUALITY(fac1000.mul_naive(fib200), (fac1000*fib200), "phase B : karatsuba test 44 ");

    ASSERT_EQUALITY(fib2000.mul_naive(fib2000), (fib2000*fib2000), "phase B : karatsuba test 45 ");
    ASSERT_EQUALITY(fib2000.mul_naive(fac1000), (fib2000*fac1000), "phase B : karatsuba test 46 ");

    ASSERT_EQUALITY(fib2000.mul_naive(fib2000), (fib2000*fib2000), "phase B : karatsuba test 47 ");
    ASSERT_EQUALITY(fac1000.mul_naive(fib2000), (fac1000*fib2000), "phase B : karatsuba test 48 ");

    ASSERT_EQUALITY(fac1000.mul_naive(fac1000), (fac1000*fac1000), "phase B : karatsuba test 49 ");

    ASSERT_EQUALITY(fac1000.mul_naive(fac1000), (fac1000*fac1000), "phase B : karatsuba test 50 ");

    apa::bint fac66 = apa::factorial(64),
              fib55 = apa::fibonacci(75),
              fac777 = apa::factorial(713),
              fib333 = apa::fibonacci(200),
              fib2222 = apa::fibonacci(2000),
              fac1111 = apa::factorial(1000);

    ASSERT_EQUALITY(fac66.mul_naive(fac66), (fac66*fac66), "phase C : karatsuba test 01 ");
    ASSERT_EQUALITY(fac66.mul_naive(fib55), (fac66*fib55), "phase C : karatsuba test 02 ");
    ASSERT_EQUALITY(fac66.mul_naive(fac777), (fac66*fac777), "phase C : karatsuba test 03 ");
    ASSERT_EQUALITY(fac66.mul_naive(fib333), (fac66*fib333), "phase C : karatsuba test 04 ");
    ASSERT_EQUALITY(fac66.mul_naive(fib2222), (fac66*fib2222), "phase C : karatsuba test 05 ");
    ASSERT_EQUALITY(fac66.mul_naive(fac1111), (fac66*fac1111), "phase C : karatsuba test 06 ");

    ASSERT_EQUALITY(fac66.mul_naive(fac66), (fac66*fac66), "phase C : karatsuba test 07 ");
    ASSERT_EQUALITY(fib55.mul_naive(fac66), (fib55*fac66), "phase C : karatsuba test 08 ");
    ASSERT_EQUALITY(fac777.mul_naive(fac66), (fac777*fac66), "phase C : karatsuba test 09 ");
    ASSERT_EQUALITY(fib333.mul_naive(fac66), (fib333*fac66), "phase C : karatsuba test 10 ");
    ASSERT_EQUALITY(fib2222.mul_naive(fac66), (fib2222*fac66), "phase C : karatsuba test 11 ");
    ASSERT_EQUALITY(fac1111.mul_naive(fac66), (fac1111*fac66), "phase C : karatsuba test 12 ");

    ASSERT_EQUALITY(fib55.mul_naive(fib55), (fib55*fib55), "phase C : karatsuba test 13 ");
    ASSERT_EQUALITY(fib55.mul_naive(fac777), (fib55*fac777), "phase C : karatsuba test 14 ");
    ASSERT_EQUALITY(fib55.mul_naive(fib333), (fib55*fib333), "phase C : karatsuba test 15 ");
    ASSERT_EQUALITY(fib55.mul_naive(fib2222), (fib55*fib2222), "phase C : karatsuba test 16 ");
    ASSERT_EQUALITY(fib55.mul_naive(fac1111), (fib55*fac1111), "phase C : karatsuba test 17 ");

    ASSERT_EQUALITY(fib55.mul_naive(fib55), (fib55*fib55), "phase C : karatsuba test 18 ");
    ASSERT_EQUALITY(fac777.mul_naive(fib55), (fac777*fib55), "phase C : karatsuba test 19 ");
    ASSERT_EQUALITY(fib333.mul_naive(fib55), (fib333*fib55), "phase C : karatsuba test 20 ");
    ASSERT_EQUALITY(fib2222.mul_naive(fib55), (fib2222*fib55), "phase C : karatsuba test 21 ");
    ASSERT_EQUALITY(fac1111.mul_naive(fib55), (fac1111*fib55), "phase C : karatsuba test 22 ");

    ASSERT_EQUALITY(fac777.mul_naive(fac777), (fac777*fac777), "phase C : karatsuba test 23 ");
    ASSERT_EQUALITY(fac777.mul_naive(fib333), (fac777*fib333), "phase C : karatsuba test 24 ");
    ASSERT_EQUALITY(fac777.mul_naive(fib2222), (fac777*fib2222), "phase C : karatsuba test 25 ");
    ASSERT_EQUALITY(fac777.mul_naive(fac1111), (fac777*fac1111), "phase C : karatsuba test 26 ");

    ASSERT_EQUALITY(fac777.mul_naive(fac777), (fac777*fac777), "phase C : karatsuba test 27 ");
    ASSERT_EQUALITY(fib333.mul_naive(fac777), (fib333*fac777), "phase C : karatsuba test 28 ");
    ASSERT_EQUALITY(fib2222.mul_naive(fac777), (fib2222*fac777), "phase C : karatsuba test 29 ");
    ASSERT_EQUALITY(fac1111.mul_naive(fac777), (fac1111*fac777), "phase C : karatsuba test 30 ");

    ASSERT_EQUALITY(fib333.mul_naive(fib333), (fib333*fib333), "phase C : karatsuba test 31 ");
    ASSERT_EQUALITY(fib333.mul_naive(fib2222), (fib333*fib2222), "phase C : karatsuba test 40 ");
    ASSERT_EQUALITY(fib333.mul_naive(fac1111), (fib333*fac1111), "phase C : karatsuba test 41 ");

    ASSERT_EQUALITY(fib333.mul_naive(fib333), (fib333*fib333), "phase C : karatsuba test 42 ");
    ASSERT_EQUALITY(fib2222.mul_naive(fib333), (fib2222*fib333), "phase C : karatsuba test 43 ");
    ASSERT_EQUALITY(fac1111.mul_naive(fib333), (fac1111*fib333), "phase C : karatsuba test 44 ");

    ASSERT_EQUALITY(fib2222.mul_naive(fib2222), (fib2222*fib2222), "phase C : karatsuba test 45 ");
    ASSERT_EQUALITY(fib2222.mul_naive(fac1111), (fib2222*fac1111), "phase C : karatsuba test 46 ");

    ASSERT_EQUALITY(fib2222.mul_naive(fib2222), (fib2222*fib2222), "phase C : karatsuba test 47 ");
    ASSERT_EQUALITY(fac1111.mul_naive(fib2222), (fac1111*fib2222), "phase C : karatsuba test 48 ");

    ASSERT_EQUALITY(fac1111.mul_naive(fac1111), (fac1111*fac1111), "phase C : karatsuba test 49 ");

    ASSERT_EQUALITY(fac1111.mul_naive(fac1111), (fac1111*fac1111), "phase C : karatsuba test 50 ");

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 KARATSUBA");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 KARATSUBA");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 KARATSUBA");
    #endif
}