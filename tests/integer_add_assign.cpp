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

#if defined(_BASE2_16)
    {
        apa::integer fib250C = {0x151a, 0xe2a8, 0x207e, 0xf442, 0x5d98, 0x671d, 0xe203, 0xbfb8, 0x94e8, 0xf601, 0xe617};
        apa::integer fib250 = apa::fibonacci_integer(250);

        apa::integer fib1000C = {0x0021, 0xd8cb, 0x07b5, 0x72c2, 0x5732, 0xbb11, 0x6f2c, 0x33ba, 0xb0e8,
                                 0x3d0c, 0x699b, 0xad1a, 0x727a, 0x736a, 0x7e42, 0xca93, 0xb697, 0xad22,
                                 0x4d55, 0x3983, 0x7306, 0x2f18, 0xff62, 0xb99c, 0x2806, 0x8131, 0xa3fa,
                                 0xb0c1, 0x2e35, 0x1028, 0x3c1d, 0x60b0, 0x0930, 0xb7e8, 0x803c, 0x312b,
                                 0x4c8e, 0x6d52, 0x8680, 0x5fc7, 0x0b59, 0x4dc7, 0x5cc0, 0x604b};

        apa::integer fib1000 = apa::fibonacci_integer(1000);

        apa::integer fib1000_b9_9C = {0x01ec, 0xe35e, 0x12b8, 0xf7fd, 0x9e08, 0x4739, 0xb608, 0x8668, 0x08ac,
                                      0xe0dc, 0x4c10, 0x6578, 0x20ca, 0xa252, 0xe2fa, 0x0002, 0x1d82, 0x3420,
                                      0x41f1, 0x1620, 0xb67c, 0xf41c, 0xfdef, 0xdd9d, 0x0a54, 0x345f, 0x2538,
                                      0xb61f, 0xf4ed, 0x143f, 0xbc6a, 0xc884, 0x4f99, 0x801d, 0xe4b9, 0xb936,
                                      0x9b38, 0x754e, 0x700b, 0x129b, 0x6e09, 0xdae4, 0xc340, 0x6855};

        apa::integer fib1000_1_99927737 = apa::fibonacci_integer(1000, 1, apa::integer("99927737", 10));
        apa::integer fib1000_1_99927737_C = {0xc998, 0xdee1, 0x8201, 0x1030, 0x7276, 0x9e7e, 0xe803, 0xca11, 0x3a44,
                                             0x6de2, 0x7f3c, 0x67e4, 0xdd91, 0x6c39, 0x09d9, 0x95b4, 0xd857, 0x794c,
                                             0x412a, 0xcd27, 0xa845, 0x782f, 0x308f, 0x6e20, 0xaafc, 0x5b0a, 0x5a45,
                                             0xe69c, 0x8045, 0x1998, 0x4738, 0x2904, 0xaad4, 0x42a7, 0x5a69, 0xddcd,
                                             0xe1af, 0xd690, 0xb6d3, 0xbdf4, 0x3f19, 0xbf2d, 0x5a97, 0x01d0, 0x98d5};

        apa::integer fib1000_b9_9 = apa::fibonacci_integer(1000, 9, 9);

        ASSERT_EQUALITY(fib250, fib250C, "FIB(250)            ");
        ASSERT_EQUALITY(fib1000, fib1000C, "FIB(1000)           ");
        ASSERT_EQUALITY(fib1000_b9_9, fib1000_b9_9C, "FIB(1000,9,9)       ");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_1_99927737_C, "FIB(1000,1,99927737)");

        apa::integer num1 = {0x6000, 0x0712, 0x3656, 0x4fff, 0x0ef6, 0x56f3, 0x2fa4, 0xc45d,
                             0x0000, 0x777e, 0xeebb, 0xbfff, 0x0abc, 0xdef0, 0x1234, 0x5678,
                             0x9e7e, 0xe803, 0xca11, 0x3a44, 0x6de2, 0x7f3c, 0x67e4, 0xdd91};

        apa::integer num2 = {0x794c, 0x412a, 0xcd27, 0xa845, 0x782f, 0x308f,
                             0x6e20, 0xaafc, 0x5b0a, 0x5a45, 0xe69c, 0x8045};

        fib1000_1_99927737 = num1;
        fib1000_1_99927737 += num2;
        fib1000_b9_9 = num2;
        fib1000_b9_9 += num1;

        apa::integer ans1 = num1;
        ans1 += num2;
        apa::integer ans2 = num2;
        ans2 += num1;

        ASSERT_EQUALITY(ans1, ans2, "ans1==ans2              ");
        ASSERT_EQUALITY(ans2, fib1000_1_99927737, "ans2==fib1000_1_99927737");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_b9_9, "ans1==ans2              ");

        FOURWAY_ASSERT_EQUALITY(
            fib1000_1_99927737, fib1000_b9_9, ans1, ans2, "4 WAY DIFFERENT ADDITION INITIALIZATION"
        );

        RESULT("INTEGER BASE 2^16 ADDITION");
    }
#elif defined(_BASE2_32)
    {
        apa::integer fib250C = {0x151a, 0xe2a8207e, 0xf4425d98, 0x671de203, 0xbfb894e8, 0xf601e617};
        apa::integer fib250 = apa::fibonacci_integer(250);

        apa::integer fib1000C = {0x21d8cb,   0x07b572c2, 0x5732bb11, 0x6f2c33ba, 0xb0e83d0c, 0x699bad1a,
                                 0x727a736a, 0x7e42ca93, 0xb697ad22, 0x4d553983, 0x73062f18, 0xff62b99c,
                                 0x28068131, 0xa3fab0c1, 0x2e351028, 0x3c1d60b0, 0x0930b7e8, 0x803c312b,
                                 0x4c8e6d52, 0x86805fc7, 0x0b594dc7, 0x5cc0604b};

        apa::integer fib1000 = apa::fibonacci_integer(1000);

        apa::integer fib1000_b9_9C = {0x1ece35e,  0x12b8f7fd, 0x9e084739, 0xb6088668, 0x08ace0dc, 0x4c106578,
                                      0x20caa252, 0xe2fa0002, 0x1d823420, 0x41f11620, 0xb67cf41c, 0xfdefdd9d,
                                      0x0a54345f, 0x2538b61f, 0xf4ed143f, 0xbc6ac884, 0x4f99801d, 0xe4b9b936,
                                      0x9b38754e, 0x700b129b, 0x6e09dae4, 0xc3406855};

        apa::integer fib1000_1_99927737 = apa::fibonacci_integer(1000, 1, 99927737);
        apa::integer fib1000_1_99927737_C = {0xc998,     0xdee18201, 0x10307276, 0x9e7ee803, 0xca113a44, 0x6de27f3c,
                                             0x67e4dd91, 0x6c3909d9, 0x95b4d857, 0x794c412a, 0xcd27a845, 0x782f308f,
                                             0x6e20aafc, 0x5b0a5a45, 0xe69c8045, 0x19984738, 0x2904aad4, 0x42a75a69,
                                             0xddcde1af, 0xd690b6d3, 0xbdf43f19, 0xbf2d5a97, 0x01d098d5};

        apa::integer fib1000_b9_9 = apa::fibonacci_integer(1000, 9, 9);

        ASSERT_EQUALITY(fib250, fib250C, "FIB(250)            ");
        ASSERT_EQUALITY(fib1000, fib1000C, "FIB(1000)           ");
        ASSERT_EQUALITY(fib1000_b9_9, fib1000_b9_9C, "FIB(1000,9,9)       ");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_1_99927737_C, "FIB(1000,1,99927737)");

        apa::integer num1 = {0x60000712, 0x36564fff, 0x0ef656f3, 0x2fa4c45d, 0x0000777e, 0xeebbbfff,
                             0x0abcdef0, 0x12345678, 0x9e7ee803, 0xca113a44, 0x6de27f3c, 0x67e4dd91};

        apa::integer num2 = {0x794c412a, 0xcd27a845, 0x782f308f, 0x6e20aafc, 0x5b0a5a45, 0xe69c8045};

        fib1000_1_99927737 = num1;
        fib1000_1_99927737 += num2;
        fib1000_b9_9 = num2;
        fib1000_b9_9 += num1;

        apa::integer ans1 = num1;
        ans1 += num2;
        apa::integer ans2 = num2;
        ans2 += num1;

        ASSERT_EQUALITY(ans1, ans2, "ans1==ans2              ");
        ASSERT_EQUALITY(ans2, fib1000_1_99927737, "ans2==fib1000_1_99927737");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_b9_9, "ans1==ans2              ");

        FOURWAY_ASSERT_EQUALITY(
            fib1000_1_99927737, fib1000_b9_9, ans1, ans2, "4 WAY DIFFERENT ADDITION INITIALIZATION"
        );

        RESULT("INTEGER BASE 2^32 ADDITION");
    }
#elif defined(_BASE2_64)
    {
        apa::integer fib250C = {0x151ae2a8207e, 0xf4425d98671de203, 0xbfb894e8f601e617};
        apa::integer fib250 = apa::fibonacci_integer(250);

        apa::integer fib1000C = {0x21d8cb07b572c2,   0x5732bb116f2c33ba, 0xb0e83d0c699bad1a, 0x727a736a7e42ca93,
                                 0xb697ad224d553983, 0x73062f18ff62b99c, 0x28068131a3fab0c1, 0x2e3510283c1d60b0,
                                 0x0930b7e8803c312b, 0x4c8e6d5286805fc7, 0x0b594dc75cc0604b};

        apa::integer fib1000 = apa::fibonacci_integer(1000);

        apa::integer fib1000_b9_9C = {0x1ece35e12b8f7fd,  0x9e084739b6088668, 0x08ace0dc4c106578, 0x20caa252e2fa0002,
                                      0x1d82342041f11620, 0xb67cf41cfdefdd9d, 0x0a54345f2538b61f, 0xf4ed143fbc6ac884,
                                      0x4f99801de4b9b936, 0x9b38754e700b129b, 0x6e09dae4c3406855};

        apa::integer fib1000_1_99927737 = apa::fibonacci_integer(1000, 1, 99927737);
        apa::integer fib1000_1_99927737_C = {
            0xc998,
            0xdee1820110307276,
            0x9e7ee803ca113a44,
            0x6de27f3c67e4dd91,
            0x6c3909d995b4d857,
            0x794c412acd27a845,
            0x782f308f6e20aafc,
            0x5b0a5a45e69c8045,
            0x199847382904aad4,
            0x42a75a69ddcde1af,
            0xd690b6d3bdf43f19,
            0xbf2d5a9701d098d5};

        apa::integer fib1000_b9_9 = apa::fibonacci_integer(1000, 9, 9);

        ASSERT_EQUALITY(fib250, fib250C, "FIB(250)            ");
        ASSERT_EQUALITY(fib1000, fib1000C, "FIB(1000)           ");
        ASSERT_EQUALITY(fib1000_b9_9, fib1000_b9_9C, "FIB(1000,9,9)       ");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_1_99927737_C, "FIB(1000,1,99927737)");

        apa::integer num1 = {0x6000071236564fff, 0x0ef656f32fa4c45d, 0x0000777eeebbbfff,
                             0x0abcdef012345678, 0x9e7ee803ca113a44, 0x6de27f3c67e4dd91};

        apa::integer num2 = {0x794c412acd27a845, 0x782f308f6e20aafc, 0x5b0a5a45e69c8045};

        fib1000_1_99927737 = num1;
        fib1000_1_99927737 += num2;
        fib1000_b9_9 = num2;
        fib1000_b9_9 += num1;

        apa::integer ans1 = num1;
        ans1 += num2;
        apa::integer ans2 = num2;
        ans2 += num1;

        ASSERT_EQUALITY(ans1, ans2, "ans1==ans2              ");
        ASSERT_EQUALITY(ans2, fib1000_1_99927737, "ans2==fib1000_1_99927737");
        ASSERT_EQUALITY(fib1000_1_99927737, fib1000_b9_9, "ans1==ans2              ");

        FOURWAY_ASSERT_EQUALITY(
            fib1000_1_99927737, fib1000_b9_9, ans1, ans2, "4 WAY DIFFERENT ADDITION INITIALIZATION"
        );

        RESULT("INTEGER BASE 2^64 ADDITION");
    }
#endif
}