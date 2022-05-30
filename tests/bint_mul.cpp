#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../core.hpp"
#else
#include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    // test variables
    apa::bint num1("182379807482704987138971389471980478123748657105182347086873",16);
    apa::bint num2("-abcdeffedabbdeffccfeddeccddeeeeeffffeeeeeccffeeeeeeeeeeeeefffeddaaacccccccddfabcdef",16);
    apa::bint num3 = -num1;

    apa::bint num4(
        "a1b2c3d4e5f60007700000000000000000000000000000000000000000"
        "000000000fffffffffffffffffffffffffffffffffffffffffffffffff"
    ,16);

    apa::bint num5(
        // negative sign
        "-fffffffffffffffffffffffffffff0000000000000000"
        "00000000000000000000000000000000000fffffffffff"
    ,16);

    apa::bint num6(
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"  
        ,16
    );

    // correct answers
    std::string num1num2_C =
        "-10331d323ff1d4166e6f2d589f7f53154b22284bdeeffee637515175be13860f93a4f92"
        "bbb50c459d91fd101a870a7e46f51822ab5431928ea7365e7cd1c9cae721d681fe4e9a5d";

    std::string num1num3_C =
        "-246abb288a2ff50830adc8d395f164e132c16b9b6bfc82f6ec8d6ff744abe62bf8aaea7"
        "ea3d6a437b0715cefc599b50ed29ef75ae15c9a87bcda3a9";

    apa::bint num4num5_C(
        "-a1b2c3d4e5f600076ffffffffffff5e4d3c2b1a09fff89000000000000000000001000000"
        "0000000a1b2c3d4e5ebe4da32b1a09fff88ffffffff0000000000000000000000000000100"
        "ffffffffffeffffffffffffffffffffffffffffffffffffff00000000001",16
    );

    apa::bint num6_one_C(
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",16
    );

    apa::bint num1_M_NEGATIVE_num6_C(
        "-182379807482704987138971389471980478123748657105182347086872fffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7dc867f8b7d8fb678ec76"
        "8ec76b8e67fb87edc8b79a8efae7dcb8f7978d",16
    );

    // solution
    apa::bint num1num2 = num1 * num2;
    apa::bint num2num1 = num2 * num1;
    apa::bint num1num3 = num1 * num3;
    apa::bint num3num1 = num3 * num1;
    apa::bint num4num5 = num4 * num5;
    apa::bint num5num4 = num5 * num4;
    apa::bint num6_one = num6 * apa::__BINT_ONE;
    apa::bint num1_P_NEGATIVE_num1 = num1 * (-num6);
    apa::bint num1zero = num1 * apa::__BINT_ZERO;
    apa::bint zeronum1 = apa::__BINT_ZERO * num1;
    apa::bint num2zero = num2 * apa::__BINT_ZERO;
    apa::bint zeronum2 = apa::__BINT_ZERO * num2;

    // checks
    ASSERT_EQUALITY(num1num2.to_base16_string(),num1num2_C,"num1 * num2 ");
    ASSERT_EQUALITY(num2num1.to_base16_string(),num1num2_C,"num2 * num1 ");
    ASSERT_EQUALITY(num1num3.to_base16_string(),num1num3_C,"num1 * num3 ");
    ASSERT_EQUALITY(num3num1.to_base16_string(),num1num3_C,"num3 * num1 ");
    ASSERT_EQUALITY(num4num5,num4num5_C,                   "num4 * num5 ");
    ASSERT_EQUALITY(num5num4,num4num5_C,                   "num5 * num4 ");
    ASSERT_EQUALITY(num6_one,num6_one_C,                   "num6 * one  ");
    ASSERT_EQUALITY(
        num1_P_NEGATIVE_num1,num1_M_NEGATIVE_num6_C,       "num1*(-num6)");
    ASSERT_EQUALITY(num1zero,apa::__BINT_ZERO,             "num1 * zero ");
    ASSERT_EQUALITY(zeronum1,apa::__BINT_ZERO,             "zero * num1 ");
    ASSERT_EQUALITY(num2zero,apa::__BINT_ZERO,             "num2 * zero ");
    ASSERT_EQUALITY(zeronum2,apa::__BINT_ZERO,             "zero * num2 ");

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 MULTIPLICATION");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 MULTIPLICATION");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 MULTIPLICATION");
    #endif
}