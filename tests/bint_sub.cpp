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
    std::string num1num2_C =  "abcdeffedabbdeffccfeddee501686f64826f3875e0896027836086f368122523103dd1e4f126b43662";
    std::string num2num1_C = "-abcdeffedabbdeffccfeddee501686f64826f3875e0896027836086f368122523103dd1e4f126b43662";

    std::string num1num3_C = "3046f300e904e0930e2712e27128e33008f0246e90cae20a30468e10d0e6";
    apa::bint   num3num1_C("-3046f300e904e0930e2712e27128e33008f0246e90cae20a30468e10d0e6",16);

    apa::bint num4num5_C(
        "a1b2c3d4e5f60007700000000fffffffffffffffffffffffffffff000000"
        "000000100000000000000000000000000000000000000ffffffffffe",16
    );

    apa::bint num5num4_C = -num4num5_C;

    apa::bint num6_one_C(
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe",16
    );

    apa::bint num1_P_NEGATIVE_num6_C(
        "10000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000001823798074827049871389713894719804781237486571051823"
        "47086872",16
    );

    // solution
    apa::bint num1num2 = num1 - num2;
    apa::bint num2num1 = num2 - num1;
    apa::bint num1num3 = num1 - num3;
    apa::bint num3num1 = num3 - num1;
    apa::bint num4num5 = num4 - num5;
    apa::bint num5num4 = num5 - num4;
    apa::bint num6_one = num6 - apa::__bint_ONE;
    apa::bint num1_P_NEGATIVE_num1 = num1 - (-num6);

    // checks
    ASSERT_EQUALITY(num1num2.to_base16_string(),num1num2_C,"num1 - num2 ");
    ASSERT_EQUALITY(num2num1.to_base16_string(),num2num1_C,"num2 - num1 ");
    ASSERT_EQUALITY(num1num3.to_base16_string(),num1num3_C,"num1 - num3 ");
    ASSERT_EQUALITY(num3num1,num3num1_C,                   "num3 - num1 ");
    ASSERT_EQUALITY(num4num5,num4num5_C,                   "num4 - num5 ");
    ASSERT_EQUALITY(num5num4,num5num4_C,                   "num5 - num4 ");
    ASSERT_EQUALITY(num6_one,num6_one_C,                   "num6 - one  ");
    ASSERT_EQUALITY(
        num1_P_NEGATIVE_num1,num1_P_NEGATIVE_num6_C,       "num1-(-num6)");

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 SUBTRACTION");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 SUBTRACTION");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 SUBTRACTION");
    #endif
}