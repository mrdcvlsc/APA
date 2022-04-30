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
            "0x339e0a8ded47f83d27b1b7b4bd45112aa396e491"
        );

        apa::ubint RS34567_FAC3375_C(
            "0x14804f42e1dfdce53ca870ef78db19711"
        );

        apa::ubint
            num1("0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef"),
            num2("0xabcd54321ffff789000cccedede00124323ffff");

        apa::ubint
            LS1872_num1_C(
                "0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "000000000000000000000000000000000000000"
            ),

            LS752_num2_C(
                "0xabcd54321ffff789000cccedede00124323ffff000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "00000000000000000000000000000000000000000000000000000000000000000000000"
                "0000000000000000"
            ),
            numTest("1234567890abcdef12345"),
            LS75_numTest_C("0x91a2b3c4855e6f7891a28000000000000000000");

        apa::ubint A("bacdef1234567890"),
        LS331_A("0x5d66f7891a2b3c4800000000000000000000000000000000000000000000000000000000000000000000000000000000000");
        apa::ubint LS320_TWO_C("0x200000000000000000000000000000000000000000000000000000000000000000000000000000000");
        apa::ubint LS0_DEADBEEF_C("deadbeef");
        apa::ubint RANDNUM("abcdef0123456789caffae0feed0dead0beef0cab0bafe80ffff");
        apa::ubint LS1_RANDNUM_C("0x1579bde02468acf1395ff5c1fdda1bd5a17dde1956175fd01fffe");

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
            "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        );

        apa::ubint NUM2POW4096MIN1_RS4095_C = 1;
        apa::ubint NUM2POW4096MIN1_RS4096_C = 0;
        apa::ubint NUM2POW4096MIN1_RS4097_C = 0;
        
        // answers
        apa::ubint
            RS8123_FAC975 = fac(975) >> 8123,
            RS34567_FAC3375 = fac(3375) >> 34567,
            LS1872_num1 = num1 << 1872,
            LS752_num2 = num2 << 752,
            LS320_TWO = apa::ubint(2) << 320,
            LS0_DEADBEEF("deadbeef"),
            LS1_RANDNUM = RANDNUM << 1;
        
        apa::ubint
            RS1_ONE = ONE >> 1,
            RS2_ONE = ONE >> 2,
            RS16_ONE = ONE >> 16,
            RS32_ONE = ONE >> 32,
            RS320_ONE = ONE >> 320;

        apa::ubint NUM2POW4096MIN1_RS4095 = NUM2POW4096MIN1 >> 4095;
        apa::ubint NUM2POW4096MIN1_RS4096 = NUM2POW4096MIN1 >> 4096;
        apa::ubint NUM2POW4096MIN1_RS4097 = NUM2POW4096MIN1 >> 4097;
        
        numTest = numTest << 75;
        A = A << 331;

        ASSERT_EQUALITY(NUM2POW4096MIN1_RS4095,NUM2POW4096MIN1_RS4095_C,"NUM2POW4096MIN1_RS4095,NUM2POW4096MIN1_RS4095_C");
        ASSERT_EQUALITY(NUM2POW4096MIN1_RS4096,NUM2POW4096MIN1_RS4096_C,"NUM2POW4096MIN1_RS4096,NUM2POW4096MIN1_RS4096_C");
        ASSERT_EQUALITY(NUM2POW4096MIN1_RS4097,NUM2POW4096MIN1_RS4097_C,"NUM2POW4096MIN1_RS4097,NUM2POW4096MIN1_RS4097_C");
        ASSERT_EQUALITY(RS1_ONE,RS1_ONE_C,"RS1_ONE,RS1_ONE_C");
        ASSERT_EQUALITY(RS2_ONE,RS2_ONE_C,"RS2_ONE,RS2_ONE_C");
        ASSERT_EQUALITY(RS16_ONE,RS16_ONE_C,"RS16_ONE,RS16_ONE_C");
        ASSERT_EQUALITY(RS32_ONE,RS32_ONE_C,"RS32_ONE,RS32_ONE_C");
        ASSERT_EQUALITY(RS320_ONE,RS320_ONE_C,"RS320_ONE,RS320_ONE_C");
        ASSERT_EQUALITY(LS1_RANDNUM,LS1_RANDNUM_C,"LS1_RANDNUM << 1");
        ASSERT_EQUALITY(LS0_DEADBEEF,LS0_DEADBEEF_C,"0xdeadbeef << 0");
        ASSERT_EQUALITY(LS320_TWO,LS320_TWO_C,"apa::ubint(2) << 320");
        ASSERT_EQUALITY(A,LS331_A,"A = A << 75");
        ASSERT_EQUALITY(numTest,LS75_numTest_C,"numTest = numTest << 75");
        ASSERT_EQUALITY(RS8123_FAC975,RS8123_FAC975_C,"fac(975) >> 8123");
        ASSERT_EQUALITY(RS34567_FAC3375,RS34567_FAC3375_C,"fac(3375) >> 34567");
        ASSERT_EQUALITY(LS1872_num1,LS1872_num1_C,"num1 << 1872");
        ASSERT_EQUALITY(LS752_num2,LS752_num2_C,"num2 << 752");

    #if defined(_BASE2_16)
        RESULT("UBINT BASE 2^16 SHIFT OPERATORS");
    #elif defined(_BASE2_32)
        RESULT("UBINT BASE 2^32 SHIFT OPERATORS");
    #elif defined(_BASE2_64)
        RESULT("UBINT BASE 2^64 SHIFT OPERATORS");
    #endif
}