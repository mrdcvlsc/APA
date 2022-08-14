#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() {
    START_TEST;

    // test variables
    apa::bint subject0 = -254;
    apa::bint subject1 = "0x182379807482704987138971389471980478123748657105182347086873"; // hex
    apa::bint subject2 =
        "-0xabcdeffedabbdeffccfeddeccddeeeeeffffeeeeeccffeeeeeeeeeeeeefffeddaaacccccccddfabcdef";       // hex
    apa::bint subject3 = "-77271637711129192000019281928989382938298198818273712893712881728378818923"; // base 10 - dec
    apa::bint subject4 =
        "-0b1100100101000010101010001000001111101010001010100100010011110100010011001000111"; // base 2 - binary
    apa::bint subject5 = -subject3;
    apa::bint subject6 = -subject5;

    // base 10 equivalent
    std::string subject0_C = "-254";
    std::string subject1_C = "166598306086985122623632610372590116747460098712794938672585117710968947";
    std::string subject2_C =
        "-5871553017334163673795699804665701567810085652896428049300386755762121833992949000512414889605320175";
    std::string subject3_C = "-77271637711129192000019281928989382938298198818273712893712881728378818923";
    std::string subject4_C = "-475212645486075552867911";
    std::string subject5_C = "77271637711129192000019281928989382938298198818273712893712881728378818923";

    ASSERT_EQUALITY(subject0.to_base10_string(), subject0_C, "integral assignment     ");
    ASSERT_EQUALITY(subject1.to_base10_string(), subject1_C, "positive hex constructor");
    ASSERT_EQUALITY(subject2.to_base10_string(), subject2_C, "negative hex constructor");
    ASSERT_EQUALITY(subject3.to_base10_string(), subject3_C, "negative dec constructor");
    ASSERT_EQUALITY(subject4.to_base10_string(), subject4_C, "negative bin constructor");
    ASSERT_EQUALITY(subject5.to_base10_string(), subject5_C, "negate value 1st time   ");
    ASSERT_EQUALITY(subject6.to_base10_string(), subject3_C, "negate value 2nd time   ");

#if defined(_BASE2_16)
    RESULT("BINT BASE 2^16 constructor");
#elif defined(_BASE2_32)
    RESULT("BINT BASE 2^32 constructor");
#elif defined(_BASE2_64)
    RESULT("BINT BASE 2^64 constructor");
#endif
}