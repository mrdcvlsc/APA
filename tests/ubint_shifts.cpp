#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

apa::ubint fac(size_t n) {
    apa::ubint factorial(1);
    apa::ubint iter = factorial;
    apa::ubint one = 1;

    for(size_t i=1; i<=n; ++i) {
        factorial *= iter;
        iter = iter + one;
    }

    return factorial;
}

int main() { START_TEST;

        // test variables
        apa::ubint RS8123_FAC975_C(
            "0x339e0a8ded47f83d27b1b7b4bd45112aa396e491",16
        );

        apa::ubint RS34567_FAC3375_C(
            "0x14804f42e1dfdce53ca870ef78db19711",16
        );

        apa::ubint
            num1("0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef",16),
            num2("0xabcd54321ffff789000cccedede00124323ffff",16);

        apa::ubint
            LS1872_num1_C(
                "0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "000000000000000000000000000000000000000",16
            ),

            LS752_num2_C(
                "0xabcd54321ffff789000cccedede00124323ffff000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "0000000000000000",16
            ),
            numTest("1234567890abcdef12345",16),
            LS75_numTest_C("0x91a2b3c4855e6f7891a28000000000000000000",16);

        apa::ubint A("bacdef1234567890",16),
        LS331_A("0x5d66f7891a2b3c4800000000000000000000000000000000000000000000000000000000000000000000000000000000000",16);
        apa::ubint LS320_TWO_C("0x200000000000000000000000000000000000000000000000000000000000000000000000000000000",16);
        apa::ubint LS0_DEADBEEF_C("deadbeef",16);
        apa::ubint RANDNUM("abcdef0123456789caffae0feed0dead0beef0cab0bafe80ffff",16);
        apa::ubint LS1_RANDNUM_C("0x1579bde02468acf1395ff5c1fdda1bd5a17dde1956175fd01fffe",16);

        apa::ubint ONE = 1, RS1_ONE_C = 0, RS2_ONE_C = 0, RS16_ONE_C = 0, RS32_ONE_C = 0, RS320_ONE_C = 0;
        apa::ubint NUM2POW4096MIN1(
            "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",16
        );

        apa::ubint LS0_DEADBEEF("deadbeef",16);

        apa::ubint NUM2POW4096MIN1_RS4095_C = 1;
        apa::ubint NUM2POW4096MIN1_RS4096_C = 0;
        apa::ubint NUM2POW4096MIN1_RS4097_C = 0;
        
        // answers

        ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4095,NUM2POW4096MIN1_RS4095_C,"(NUM2POW4096MIN1 >> 4095");
        ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4096,NUM2POW4096MIN1_RS4096_C,"(NUM2POW4096MIN1 >> 4096");
        ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4097,NUM2POW4096MIN1_RS4097_C,"(NUM2POW4096MIN1 >> 4097");
        ASSERT_EQUALITY(ONE >> 1,RS1_ONE_C,"(ONE >> 1");
        ASSERT_EQUALITY(ONE >> 2,RS2_ONE_C,"(ONE >> 2");
        ASSERT_EQUALITY(ONE >> 16,RS16_ONE_C,"(ONE >> 16");
        ASSERT_EQUALITY(ONE >> 32,RS32_ONE_C,"(ONE >> 32");
        ASSERT_EQUALITY(ONE >> 320,RS320_ONE_C,"(ONE >> 320");
        ASSERT_EQUALITY(RANDNUM << 1,LS1_RANDNUM_C,"(RANDNUM << 1");
        ASSERT_EQUALITY(LS0_DEADBEEF << 0,LS0_DEADBEEF_C,"(LS0_DEADBEEF << 0");
        ASSERT_EQUALITY(A << 331,LS331_A,"(A << 331");
        ASSERT_EQUALITY(numTest << 75,LS75_numTest_C,"(numTest << 75");
        ASSERT_EQUALITY(num1 << 1872,LS1872_num1_C,"(num1 << 1872");
        ASSERT_EQUALITY(num2 << 752,LS752_num2_C,"(num2 << 752");

        ASSERT_EQUALITY(apa::ubint(2) << 320,LS320_TWO_C,"2 << 320");
        ASSERT_EQUALITY(fac(975) >> 8123,RS8123_FAC975_C,"fac(975) >> 8123");
        ASSERT_EQUALITY(fac(3375) >> 34567,RS34567_FAC3375_C,"fac(3375) >> 34567");

    #if defined(_BASE2_16)
        RESULT("UBINT BASE 2^16 SHIFT OPERATORS");
    #elif defined(_BASE2_32)
        RESULT("UBINT BASE 2^32 SHIFT OPERATORS");
    #elif defined(_BASE2_64)
        RESULT("UBINT BASE 2^64 SHIFT OPERATORS");
    #endif
}