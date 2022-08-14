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

        apa::integer num1_backup = num1;
        apa::integer num2_backup = num2;

        apa::swap(num1, num2);

        ASSERT_EQUALITY(num1, num2_backup, "SWAP 0:1");
        ASSERT_EQUALITY(num2, num1_backup, "SWAP 1:0");

        RESULT("INTEGER BASE 2^16 SWAP");
    }
#elif defined(_BASE2_32)
    {
        // test variables
        apa::integer num1 = {0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0x00000bee, 0xd777deed};
        apa::integer num2 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

        apa::integer num1_backup = num1;
        apa::integer num2_backup = num2;

        apa::swap(num1, num2);

        ASSERT_EQUALITY(num1, num2_backup, "SWAP 0:1");
        ASSERT_EQUALITY(num2, num1_backup, "SWAP 1:0");

        RESULT("INTEGER BASE 2^32 SWAP");
    }
#elif defined(_BASE2_64)
    {
        // test variables
        apa::integer num1 = {0xffffffffffffffff, 0x00000000ffffffff, 0x00000beed777deed};
        apa::integer num2 = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

        apa::integer num1_backup = num1;
        apa::integer num2_backup = num2;

        apa::swap(num1, num2);

        ASSERT_EQUALITY(num1, num2_backup, "SWAP 0:1");
        ASSERT_EQUALITY(num2, num1_backup, "SWAP 1:0");

        RESULT("INTEGER BASE 2^64 SWAP");
    }
#endif
}