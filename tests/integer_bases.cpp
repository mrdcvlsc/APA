#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <integer.hpp>
#endif

#include "mini-test.hpp"

int main() {
    START_TEST;

    // test variables
    apa::integer base2(
        "111000010100101111001000100000011111111111110001001010001001"
        "100001010101110000000011010111111111111111110000000101010101"
        "001111111111111111111111111111111111111111111111111111111101"
        "000001001010101001010100011100100101111001010110101011100111"
        "000000000000000000000000000000000000000000000000000000000000",
        2
    );

    apa::integer base8(
        "70245710403777611211412560032777776005251777777777"
        "77777777750112512434457126534700000000000000000000",
        8
    );

    apa::integer base10(
        "1792719198763919877864491671917284253530489706249053429919273492850310328205362535189184512", 10
    );

    apa::integer base10_default(
        "1792719198763919877864491671917284253530489706249053429919273492850310328205362535189184512"
    );

    apa::integer base16("e14bc881fff1289855c035ffff01553fffffffffffffd04aa54725e56ae7000000000000000", 16);

    ASSERT_EQUALITY(base10, base10_default, "base10==base10_default");
    ASSERT_EQUALITY(base2, base8, "base2==base8          ");
    ASSERT_EQUALITY(base2, base10, "base2==base10         ");
    ASSERT_EQUALITY(base2, base16, "base2==base16         ");
    ASSERT_EQUALITY(base8, base2, "base8==base2          ");
    ASSERT_EQUALITY(base8, base10, "base8==base10         ");
    ASSERT_EQUALITY(base8, base16, "base8==base16         ");
    ASSERT_EQUALITY(base10, base2, "base10==base2         ");
    ASSERT_EQUALITY(base10, base8, "base10==base8         ");
    ASSERT_EQUALITY(base10, base16, "base10==base16        ");
    ASSERT_EQUALITY(base16, base2, "base16==base2         ");
    ASSERT_EQUALITY(base16, base8, "base16==base8         ");
    ASSERT_EQUALITY(base16, base10, "base16==base10        ");

#if defined(_BASE2_16)
    RESULT("INTEGER BASE 2^16 base2, base8, base10, base16 constructor");
#elif defined(_BASE2_32)
    RESULT("INTEGER BASE 2^32 base2, base8, base10, base16 constructor");
#elif defined(_BASE2_64)
    RESULT("INTEGER BASE 2^64 base2, base8, base10, base16 constructor");
#endif
}