#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    #if defined(_BASE2_16)
    {
        // test variables
        apa::ubint num1 = { 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0bee, 0xd777, 0xdeed };
        apa::ubint num2 = { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff };
        apa::ubint num3 = { 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
        apa::ubint num4 = { 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };

        apa::ubint dif1 = { 0xffff, 0xffff, 0xffff, 0xffff };
        apa::ubint dif2 = 1;
        
        // test correct answers
        apa::ubint num1dif1_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xfffe, 0x0000, 0x0bee, 0xd777, 0xdeee };
        apa::ubint num2dif1_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000 };
        apa::ubint num3dif1_C = { 0xffff, 0xffff, 0xffff, 0xfffe, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0001 };
        apa::ubint num4dif1_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0001 };

        apa::ubint num1dif2_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0bee, 0xd777, 0xdeec };
        apa::ubint num2dif2_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xfffe };
        apa::ubint num3dif2_C = { 0xffff, 0xffff, 0xffff, 0xfffe, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff };
        apa::ubint num4dif2_C = { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff };

        // solutions

        ASSERT_EQUALITY(num1 - dif1,num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY(num2 - dif1,num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY(num3 - dif1,num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY(num4 - dif1,num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY(num1 - dif2,num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY(num2 - dif2,num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY(num3 - dif2,num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY(num4 - dif2,num4dif2_C, "num4 - dif2");

        RESULT("UBINT BASE 2^16 SUBTRACTION");
    }
    #elif defined(_BASE2_32)
    {
        // test variables
        apa::ubint num1 = { 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0x00000bee, 0xd777deed };
        apa::ubint num2 = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff };
        apa::ubint num3 = { 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
        apa::ubint num4 = { 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

        apa::ubint dif1 = { 0xffffffff, 0xffffffff };
        apa::ubint dif2 = 1;
        
        // test correct answers
        apa::ubint num1dif1_C = { 0xffffffff, 0xffffffff, 0x00000000, 0xfffffffe, 0x00000bee, 0xd777deee };
        apa::ubint num2dif1_C = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000 };
        apa::ubint num3dif1_C = { 0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000, 0x00000001 };
        apa::ubint num4dif1_C = { 0xffffffff, 0xffffffff, 0x00000000, 0x00000001 };

        apa::ubint num1dif2_C = { 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0x00000bee, 0xd777deec };
        apa::ubint num2dif2_C = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffe };
        apa::ubint num3dif2_C = { 0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff };
        apa::ubint num4dif2_C = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff };

        // solutions
        ASSERT_EQUALITY(num1 - dif1,num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY(num2 - dif1,num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY(num3 - dif1,num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY(num4 - dif1,num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY(num1 - dif2,num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY(num2 - dif2,num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY(num3 - dif2,num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY(num4 - dif2,num4dif2_C, "num4 - dif2");

        RESULT("UBINT BASE 2^32 SUBTRACTION");
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
        ASSERT_EQUALITY(num1 - dif1,num1dif1_C, "num1 - dif1");
        ASSERT_EQUALITY(num2 - dif1,num2dif1_C, "num2 - dif1");
        ASSERT_EQUALITY(num3 - dif1,num3dif1_C, "num3 - dif1");
        ASSERT_EQUALITY(num4 - dif1,num4dif1_C, "num4 - dif1");

        ASSERT_EQUALITY(num1 - dif2,num1dif2_C, "num1 - dif2");
        ASSERT_EQUALITY(num2 - dif2,num2dif2_C, "num2 - dif2");
        ASSERT_EQUALITY(num3 - dif2,num3dif2_C, "num3 - dif2");
        ASSERT_EQUALITY(num4 - dif2,num4dif2_C, "num4 - dif2");

        RESULT("UBINT BASE 2^64 SUBTRACTION");
    }
    #endif
}