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
        // test variables
        apa::integer num1 = {0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
                             0xffff, 0xffff, 0x0000, 0x0bee, 0xd777, 0xdeed};
        apa::integer num2 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
                             0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};
        apa::integer num3 = {0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
                             0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
        apa::integer num4 = {0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000,
                             0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};

        apa::integer dif1 = {0xffff, 0xffff, 0xffff, 0xffff};
        apa::integer dif2 = 1;

        // test correct answers
        apa::integer num1dif1_C = {0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
                                   0xffff, 0xfffe, 0x0000, 0x0bee, 0xd777, 0xdeee};
        apa::integer num2dif1_C = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
                                   0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000};
        apa::integer num3dif1_C = {0xffff, 0xffff, 0xffff, 0xfffe, 0xffff, 0xffff,
                                   0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0001};
        apa::integer num4dif1_C = {0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0001};

        apa::integer num1dif2_C = {0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
                                   0xffff, 0xffff, 0x0000, 0x0bee, 0xd777, 0xdeec};
        apa::integer num2dif2_C = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
                                   0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xfffe};
        apa::integer num3dif2_C = {0xffff, 0xffff, 0xffff, 0xfffe, 0xffff, 0xffff,
                                   0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};
        apa::integer num4dif2_C = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};

        // solutions
        apa::integer og_num1 = num1;
        apa::integer og_num2 = num2;
        apa::integer og_num3 = num3;
        apa::integer og_num4 = num4;

        ASSERT_EQUALITY((og_num1 -= dif1), num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY((og_num2 -= dif1), num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY((og_num3 -= dif1), num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY((og_num4 -= dif1), num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY((num1 -= dif2), num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY((num2 -= dif2), num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY((num3 -= dif2), num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY((num4 -= dif2), num4dif2_C, "num4 - dif2");

        RESULT("INTEGER BASE 2^16 SUBTRACTION");
    }
#elif defined(_BASE2_32)
    {
        // test variables
        apa::integer num1 = {0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0x00000bee, 0xd777deed};
        apa::integer num2 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
        apa::integer num3 = {0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
        apa::integer num4 = {0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};

        apa::integer dif1 = {0xffffffff, 0xffffffff};
        apa::integer dif2 = 1;

        // test correct answers
        apa::integer num1dif1_C = {0xffffffff, 0xffffffff, 0x00000000, 0xfffffffe, 0x00000bee, 0xd777deee};
        apa::integer num2dif1_C = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
        apa::integer num3dif1_C = {0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000, 0x00000001};
        apa::integer num4dif1_C = {0xffffffff, 0xffffffff, 0x00000000, 0x00000001};

        apa::integer num1dif2_C = {0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0x00000bee, 0xd777deec};
        apa::integer num2dif2_C = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffe};
        apa::integer num3dif2_C = {0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
        apa::integer num4dif2_C = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

        // solutions
        apa::integer og_num1 = num1;
        apa::integer og_num2 = num2;
        apa::integer og_num3 = num3;
        apa::integer og_num4 = num4;
        
        ASSERT_EQUALITY((og_num1 -= dif1), num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY((og_num2 -= dif1), num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY((og_num3 -= dif1), num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY((og_num4 -= dif1), num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY((num1 -= dif2), num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY((num2 -= dif2), num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY((num3 -= dif2), num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY((num4 -= dif2), num4dif2_C, "num4 - dif2");

        RESULT("INTEGER BASE 2^32 SUBTRACTION");
    }
#elif defined(_BASE2_64)
    {
        // test variables
        apa::integer num1 = {0xffffffffffffffff, 0x00000000ffffffff, 0x00000beed777deed};
        apa::integer num2 = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        apa::integer num3 = {0xffffffffffffffff, 0x0000000000000000, 0x0000000000000000};
        apa::integer num4 = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000};

        apa::integer dif1 = 0xffffffffffffffff;
        apa::integer dif2 = 1;

        // test correct answers
        apa::integer num1dif1_C = {0xffffffffffffffff, 0x00000000fffffffe, 0x00000beed777deee};
        apa::integer num2dif1_C = {0xffffffffffffffff, 0xffffffffffffffff, 0x0000000000000000};
        apa::integer num3dif1_C = {0xfffffffffffffffe, 0xffffffffffffffff, 0x0000000000000001};
        apa::integer num4dif1_C = {0xffffffffffffffff, 0x0000000000000001};

        apa::integer num1dif2_C = {0xffffffffffffffff, 0x00000000ffffffff, 0x00000beed777deec};
        apa::integer num2dif2_C = {0xffffffffffffffff, 0xffffffffffffffff, 0xfffffffffffffffe};
        apa::integer num3dif2_C = {0xfffffffffffffffe, 0xffffffffffffffff, 0xffffffffffffffff};
        apa::integer num4dif2_C = {0xffffffffffffffff, 0xffffffffffffffff};

        // solutions
        apa::integer og_num1 = num1;
        apa::integer og_num2 = num2;
        apa::integer og_num3 = num3;
        apa::integer og_num4 = num4;

        ASSERT_EQUALITY((og_num1 -= dif1), num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY((og_num2 -= dif1), num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY((og_num3 -= dif1), num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY((og_num4 -= dif1), num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY((num1 -= dif2), num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY((num2 -= dif2), num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY((num3 -= dif2), num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY((num4 -= dif2), num4dif2_C, "num4 - dif2");

        RESULT("INTEGER BASE 2^64 SUBTRACTION");
    }
#endif
}