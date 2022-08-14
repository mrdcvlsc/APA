#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <integer.hpp>
#endif

#include "mini-test.hpp"

apa::integer fac(size_t n) {
    apa::integer factorial(1);
    apa::integer iter = factorial;

    for (size_t i = 1; i <= n; ++i) {
        factorial *= iter;
        iter++;
    }

    return factorial;
}

int main() {
    START_TEST;

    // test variables
    apa::integer RS8123_FAC975_C("0x339e0a8ded47f83d27b1b7b4bd45112aa396e491", 16);

    apa::integer RS34567_FAC3375_C("0x14804f42e1dfdce53ca870ef78db19711", 16);

    apa::integer num1("0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef", 16),
        num2("0xabcd54321ffff789000cccedede00124323ffff", 16);

    apa::integer LS1872_num1_C(
        "0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000000",
        16
    ),

        LS752_num2_C(
            "0xabcd54321ffff789000cccedede00124323ffff000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000",
            16
        ),
        numTest("1234567890abcdef12345", 16), LS75_numTest_C("0x91a2b3c4855e6f7891a28000000000000000000", 16);

    apa::integer A("bacdef1234567890", 16),
        LS331_A(
            "0x5d66f7891a2b3c4800000000000000000000000000000000000000000000000000000000000000000000000000000000000", 16
        );
    apa::integer LS320_TWO_C("0x200000000000000000000000000000000000000000000000000000000000000000000000000000000", 16);
    apa::integer LS0_DEADBEEF_C("deadbeef", 16);
    apa::integer RANDNUM("abcdef0123456789caffae0feed0dead0beef0cab0bafe80ffff", 16);
    apa::integer LS1_RANDNUM_C("0x1579bde02468acf1395ff5c1fdda1bd5a17dde1956175fd01fffe", 16);

    apa::integer ONE = 1, RS1_ONE_C = 0, RS2_ONE_C = 0, RS16_ONE_C = 0, RS32_ONE_C = 0, RS320_ONE_C = 0;
    apa::integer NUM2POW4096MIN1(
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
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        16
    );

    apa::integer LS0_DEADBEEF("deadbeef", 16);

    apa::integer NUM2POW4096MIN1_RS4095_C = 1;
    apa::integer NUM2POW4096MIN1_RS4096_C = 0;
    apa::integer NUM2POW4096MIN1_RS4097_C = 0;

    apa::integer SUBJECT_LS1("ffff", 16);
    apa::integer LS1_C("0x1fffe", 16);

    apa::integer subject_bug("dad0deed1feed2dead3beef4ceed5", 16);
    apa::integer subject_bug_RS15("1b5a1bdda3fdda5bd5a77dde99", 16);

    apa::integer subject_bug_ans = subject_bug >> 15;

    apa::integer ver4_5test(
        "19cf0546f6a3fc1e93d8dbda5ea2889551cb7248d21125fbf60f3c622a4ab01456703c339c"
        "96f18bed4ce4fa268983f97dcb83ae847f8ecf19f81870578c41ede22ccf76553d1c38deb6",
        apa::HEX
    );

    apa::integer ver4_5bug_ras = ver4_5test >> 64;

    apa::integer ver4_5bug_ras_C(
        "19cf0546f6a3fc1e93d8dbda5ea2889551cb7248d21125fbf60f3c622a4ab01456"
        "703c339c96f18bed4ce4fa268983f97dcb83ae847f8ecf19f81870578c41ede22c",
        apa::HEX
    );

    apa::integer ver4_5_p2_test(
        "19cf0546f6a3fc1e93d8dbda5ea2889551cb7248d21125fbf60f3c622a4ab01456703c339c"
        "96f18bed4ce4fa268983f97dcb83ae847f8ecf19f81870578c41ede22ccf76553d1c38deb6",
        apa::HEX
    );

    apa::integer ver4_5_p2_bug_ras = ver4_5_p2_test << 64;

    apa::integer ver4_5_p2_bug_ras_C(
        "19cf0546f6a3fc1e93d8dbda5ea2889551cb7248d21125fbf60f3c622a4ab01456703c339c96f18bed"
        "4ce4fa268983f97dcb83ae847f8ecf19f81870578c41ede22ccf76553d1c38deb60000000000000000",
        apa::HEX
    );

    // answers

    ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4095, NUM2POW4096MIN1_RS4095_C, "(NUM2POW4096MIN1 >> 4095");
    ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4096, NUM2POW4096MIN1_RS4096_C, "(NUM2POW4096MIN1 >> 4096");
    ASSERT_EQUALITY(NUM2POW4096MIN1 >> 4097, NUM2POW4096MIN1_RS4097_C, "(NUM2POW4096MIN1 >> 4097");
    ASSERT_EQUALITY(ONE >> 1, RS1_ONE_C, "(ONE >> 1               ");
    ASSERT_EQUALITY(ONE >> 2, RS2_ONE_C, "(ONE >> 2               ");
    ASSERT_EQUALITY(ONE >> 16, RS16_ONE_C, "(ONE >> 16              ");
    ASSERT_EQUALITY(ONE >> 32, RS32_ONE_C, "(ONE >> 32              ");
    ASSERT_EQUALITY(ONE >> 320, RS320_ONE_C, "(ONE >> 320             ");
    ASSERT_EQUALITY(RANDNUM << 1, LS1_RANDNUM_C, "(RANDNUM << 1           ");
    ASSERT_EQUALITY(LS0_DEADBEEF << 0, LS0_DEADBEEF_C, "(LS0_DEADBEEF << 0      ");
    ASSERT_EQUALITY(A << 331, LS331_A, "(A << 331               ");
    ASSERT_EQUALITY(numTest << 75, LS75_numTest_C, "(numTest << 75          ");
    ASSERT_EQUALITY(num1 << 1872, LS1872_num1_C, "(num1 << 1872           ");
    ASSERT_EQUALITY(num2 << 752, LS752_num2_C, "(num2 << 752            ");
    ASSERT_EQUALITY(apa::integer(2) << 320, LS320_TWO_C, "2 << 320                ");
    ASSERT_EQUALITY(fac(975) >> 8123, RS8123_FAC975_C, "fac(975) >> 8123        ");
    ASSERT_EQUALITY(fac(3375) >> 34567, RS34567_FAC3375_C, "fac(3375) >> 34567      ");
    ASSERT_EQUALITY((SUBJECT_LS1 << 1), LS1_C, "(SUBJECT_LS1 << 1)      ");
    ASSERT_EQUALITY(subject_bug_ans, subject_bug_RS15, "subject_bug >> 15       ");
    ASSERT_EQUALITY(ver4_5bug_ras, ver4_5bug_ras_C, "ver4_5_bug >> 64        ");
    ASSERT_EQUALITY(ver4_5_p2_bug_ras, ver4_5_p2_bug_ras_C, "ver4_5_p2_bug << 64     ");

#if defined(_BASE2_16)
    RESULT("INTEGER BASE 2^16 SHIFT OPERATORS");
#elif defined(_BASE2_32)
    RESULT("INTEGER BASE 2^32 SHIFT OPERATORS");
#elif defined(_BASE2_64)
    RESULT("INTEGER BASE 2^64 SHIFT OPERATORS");
#endif
}