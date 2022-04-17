#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

#define _BASE2_64

int main() { START_TEST;

    #if defined(_BASE2_16)
    {
        apa::ubint fib250C = {0x151a, 0xe2a8, 0x207e, 0xf442, 0x5d98, 0x671d, 0xe203, 0xbfb8, 0x94e8, 0xf601, 0xe617};
        apa::ubint fib250 = fib(250);

        apa::ubint fib1000C = {
            0x0021, 0xd8cb, 0x07b5, 0x72c2, 0x5732, 0xbb11, 0x6f2c, 0x33ba,
            0xb0e8, 0x3d0c, 0x699b, 0xad1a, 0x727a, 0x736a, 0x7e42, 0xca93,
            0xb697, 0xad22, 0x4d55, 0x3983, 0x7306, 0x2f18, 0xff62, 0xb99c,
            0x2806, 0x8131, 0xa3fa, 0xb0c1, 0x2e35, 0x1028, 0x3c1d, 0x60b0,
            0x0930, 0xb7e8, 0x803c, 0x312b, 0x4c8e, 0x6d52, 0x8680, 0x5fc7,
            0x0b59, 0x4dc7, 0x5cc0, 0x604b
        };

        apa::ubint fib1000 = fib(1000);

        apa::ubint fib1000_b9_9C = {
            0x01ec, 0xe35e, 0x12b8, 0xf7fd, 0x9e08, 0x4739, 0xb608, 0x8668, 0x08ac, 0xe0dc, 0x4c10, 0x6578, 0x20ca, 0xa252,
            0xe2fa, 0x0002, 0x1d82, 0x3420, 0x41f1, 0x1620, 0xb67c, 0xf41c, 0xfdef, 0xdd9d, 0x0a54, 0x345f, 0x2538, 0xb61f,
            0xf4ed, 0x143f, 0xbc6a, 0xc884, 0x4f99, 0x801d, 0xe4b9, 0xb936, 0x9b38, 0x754e, 0x700b, 0x129b, 0x6e09, 0xdae4,
            0xc340, 0x6855
        };

        apa::ubint fib1000_1_99927737 = fib(1000,1,99927737);
        apa::ubint fib1000_1_99927737_C = {
            0xc998, 0xdee1, 0x8201, 0x1030, 0x7276, 0x9e7e, 0xe803, 0xca11, 0x3a44, 0x6de2, 0x7f3c,
            0x67e4, 0xdd91, 0x6c39, 0x09d9, 0x95b4, 0xd857, 0x794c, 0x412a, 0xcd27, 0xa845, 0x782f, 0x308f,
            0x6e20, 0xaafc, 0x5b0a, 0x5a45, 0xe69c, 0x8045, 0x1998, 0x4738, 0x2904, 0xaad4, 0x42a7, 0x5a69,
            0xddcd, 0xe1af, 0xd690, 0xb6d3, 0xbdf4, 0x3f19, 0xbf2d, 0x5a97, 0x01d0, 0x98d5
        };

        apa::ubint fib1000_b9_9 = fib(1000,9,9);

        ASSERT_UBINT(fib250,fib250C,"FIB(250)");
        ASSERT_UBINT(fib1000,fib1000C,"FIB(1000)");
        ASSERT_UBINT(fib1000_b9_9,fib1000_b9_9C,"FIB(1000,9,9)");
        ASSERT_UBINT(fib1000_1_99927737,fib1000_1_99927737_C,"FIB(1000,1,99927737)");

        RESULT("UBINT BASE 2^16 ADDITION");
    }
    #elif defined(_BASE2_32)
    {
        apa::ubint fib250C = {0x151a, 0xe2a8207e, 0xf4425d98, 0x671de203, 0xbfb894e8, 0xf601e617};
        apa::ubint fib250 = fib(250);

        apa::ubint fib1000C = {
            0x21d8cb, 0x07b572c2, 0x5732bb11, 0x6f2c33ba,
            0xb0e83d0c, 0x699bad1a, 0x727a736a, 0x7e42ca93,
            0xb697ad22, 0x4d553983, 0x73062f18, 0xff62b99c,
            0x28068131, 0xa3fab0c1, 0x2e351028, 0x3c1d60b0,
            0x0930b7e8, 0x803c312b, 0x4c8e6d52, 0x86805fc7,
            0x0b594dc7, 0x5cc0604b
        };

        apa::ubint fib1000 = fib(1000);

        apa::ubint fib1000_b9_9C = {
            0x1ece35e, 0x12b8f7fd, 0x9e084739, 0xb6088668, 0x08ace0dc, 0x4c106578, 0x20caa252,
            0xe2fa0002, 0x1d823420, 0x41f11620, 0xb67cf41c, 0xfdefdd9d, 0x0a54345f, 0x2538b61f,
            0xf4ed143f, 0xbc6ac884, 0x4f99801d, 0xe4b9b936, 0x9b38754e, 0x700b129b, 0x6e09dae4,
            0xc3406855
        };

        apa::ubint fib1000_1_99927737 = fib(1000,1,99927737);
        apa::ubint fib1000_1_99927737_C = {
                0xc998, 0xdee18201, 0x10307276, 0x9e7ee803, 0xca113a44, 0x6de27f3c,
            0x67e4dd91, 0x6c3909d9, 0x95b4d857, 0x794c412a, 0xcd27a845, 0x782f308f,
            0x6e20aafc, 0x5b0a5a45, 0xe69c8045, 0x19984738, 0x2904aad4, 0x42a75a69,
            0xddcde1af, 0xd690b6d3, 0xbdf43f19, 0xbf2d5a97, 0x01d098d5
        };

        apa::ubint fib1000_b9_9 = fib(1000,9,9);

        ASSERT_UBINT(fib250,fib250C,"FIB(250)");
        ASSERT_UBINT(fib1000,fib1000C,"FIB(1000)");
        ASSERT_UBINT(fib1000_b9_9,fib1000_b9_9C,"FIB(1000,9,9)");
        ASSERT_UBINT(fib1000_1_99927737,fib1000_1_99927737_C,"FIB(1000,1,99927737)");

        RESULT("UBINT BASE 2^32 ADDITION");
    }
    #elif defined(_BASE2_64)
    {
        // test variables
        apa::ubint num1 = { 0xffffffffffffffff, 0x00000000ffffffff, 0x00000beed777deed };
        apa::ubint num2 = { 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff };
        apa::ubint num3 = { 0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000 };
        apa::ubint num4 = { 0x0000000000000001, 0x0000000000000000, 0x0000000000000000 };

        apa::ubint dif1 = 0xffffffffffffffff;
        apa::ubint dif2 = 1;
        
        // test correct answers
        apa::ubint num1dif1_C = { 0xffffffffffffffff, 0x00000000fffffffe, 0x00000beed777deee };
        apa::ubint num2dif1_C = { 0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000 };
        apa::ubint num3dif1_C = { 0xfffffffffffffffe, 0xffffffffffffffff, 0x0000000000000001 };
        apa::ubint num4dif1_C = { 0xffffffffffffffff, 0x0000000000000001 };

        apa::ubint num1dif2_C = { 0xffffffffffffffff, 0x00000000ffffffff, 0x00000beed777deec };
        apa::ubint num2dif2_C = { 0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe };
        apa::ubint num3dif2_C = { 0xfffffffffffffffe, 0xffffffffffffffff, 0xffffffffffffffff };
        apa::ubint num4dif2_C = { 0xffffffffffffffff, 0xffffffffffffffff };

        // solutions
        apa::ubint num1dif1 = num1 - dif1;
        apa::ubint num2dif1 = num2 - dif1;
        apa::ubint num3dif1 = num3 - dif1;
        apa::ubint num4dif1 = num4 - dif1;

        apa::ubint num1dif2 = num1 - dif2;
        apa::ubint num2dif2 = num2 - dif2;
        apa::ubint num3dif2 = num3 - dif2;
        apa::ubint num4dif2 = num4 - dif2;

        ASSERT_UBINT(num1dif1,num1dif1_C, "num1 - dif1");
        ASSERT_UBINT(num2dif1,num2dif1_C, "num2 - dif1");
        ASSERT_UBINT(num3dif1,num3dif1_C, "num3 - dif1");
        ASSERT_UBINT(num4dif1,num4dif1_C, "num4 - dif1");

        ASSERT_UBINT(num1dif2,num1dif2_C, "num1 - dif2");
        ASSERT_UBINT(num2dif2,num2dif2_C, "num2 - dif2");
        ASSERT_UBINT(num3dif2,num3dif2_C, "num3 - dif2");
        ASSERT_UBINT(num4dif2,num4dif2_C, "num4 - dif2");

        RESULT("UBINT BASE 2^64 SUBTRACTION");
    }
    #endif
}