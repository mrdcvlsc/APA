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
    apa::bint num1 = "0x182379807482704987138971389471980478123748657105182347086873";
    apa::bint num2 = "-0xabcdeffedabbdeffccfeddeccddeeeeeffffeeeeeccffeeeeeeeeeeeeefffeddaaacccccccddfabcdef";
    apa::bint num3 = -num1;

    apa::bint num4 =
        "0xa1b2c3d4e5f60007700000000000000000000000000000000000000000"
        "000000000fffffffffffffffffffffffffffffffffffffffffffffffff";

    apa::bint num5 =
        // negative sign
        "-0xfffffffffffffffffffffffffffff0000000000000000"
        "00000000000000000000000000000000000fffffffffff";

    apa::bint num6 =
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";

    // correct answers
    std::string sumnum12 = "-abcdeffedabbdeffccfeddeb4ba756e7b7d8ea567b9767db65a7d56ea77edb692455bc7b4aa98a3657c";
    apa::bint num4num5_C =
        "0xa1b2c3d4e5f600076ffffffff000000000000000000000000000010000"
        "000000000ffffffffffffffffffffffffffffffffffffff00000000000";

    apa::bint num6_one_C =
        "0x100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    apa::bint num1_P_NEGATIVE_num1_C =
        "-0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7dc867f8b7d8fb678ec768ec76b8e67fb87edc"
        "8b79a8efae7dcb8f7978c";

    size_t hypo_cap_len = 3;
    apa::limb_t *arr = (apa::limb_t *) std::malloc(sizeof(apa::limb_t) * hypo_cap_len);
    arr[0] = std::numeric_limits<apa::limb_t>::max();
    arr[1] = std::numeric_limits<apa::limb_t>::max();
    arr[2] = std::numeric_limits<apa::limb_t>::max();
    apa::bint hypo(arr, hypo_cap_len, hypo_cap_len, apa::POSITIVE);

    std::cout << "hypo len = " << hypo.limb_size() << "\n";
    std::cout << "hypo cap = " << hypo.capacity_size() << "\n";

    hypo += apa::__BINT_ONE;
    apa::bint hypo_C = {1, 0, 0, 0};

    // solution
    apa::bint num1num2 = num1;
    num1num2 += num2;
    apa::bint num2num1 = num2;
    num2num1 += num1;
    apa::bint num1num3 = num1;
    num1num3 += num3;
    apa::bint num3num1 = num3;
    num3num1 += num1;
    apa::bint num4num5 = num4;
    num4num5 += num5;
    apa::bint num5num4 = num5;
    num5num4 += num4;
    apa::bint num6_one = num6;
    num6_one += apa::__BINT_ONE;
    apa::bint num1_P_NEGATIVE_num1 = num1;
    num1_P_NEGATIVE_num1 += (-num6);

    // checks
    ASSERT_EQUALITY(num1num2.to_base16_string(), sumnum12, "num1 + num2 ");
    ASSERT_EQUALITY(num2num1.to_base16_string(), sumnum12, "num2 + num1 ");
    ASSERT_EQUALITY(num1num3, apa::__BINT_ZERO, "num1 + num3 ");
    ASSERT_EQUALITY(num3num1, apa::__BINT_ZERO, "num3 + num1 ");
    ASSERT_EQUALITY(num4num5, num4num5_C, "num4 + num5 ");
    ASSERT_EQUALITY(num5num4, num4num5_C, "num5 + num4 ");
    ASSERT_EQUALITY(num6_one, num6_one_C, "num6 + one  ");
    ASSERT_EQUALITY(num1_P_NEGATIVE_num1, num1_P_NEGATIVE_num1_C, "num1+(-num6)");
    ASSERT_EQUALITY(hypo, hypo_C, "hypo + 1");

#if defined(_BASE2_16)
    RESULT("BINT BASE 2^16 ADDITION");
#elif defined(_BASE2_32)
    RESULT("BINT BASE 2^32 ADDITION");
#elif defined(_BASE2_64)
    RESULT("BINT BASE 2^64 ADDITION");
#endif
}