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

    // correct answers
    std::string sumnum12 = "-abcdeffedabbdeffccfeddeb4ba756e7b7d8ea567b9767db65a7d56ea77edb692455bc7b4aa98a3657c";

    // solution
    apa::bint num1num2 = num1 + num2;
    apa::bint num2num1 = num2 + num1;
    apa::bint num1num3 = num1 + num3;
    apa::bint num3num1 = num3 + num1;

    // checks
    ASSERT_EQUALITY(num1num2.to_base16_string(),sumnum12,  "num1 + num2");
    ASSERT_EQUALITY(num2num1.to_base16_string(),sumnum12,  "num2 + num1");
    ASSERT_EQUALITY(num1num3,apa::__bint_ZERO,             "num1 + num3");
    ASSERT_EQUALITY(num3num1,apa::__bint_ZERO,             "num3 + num1");

    #if defined(_BASE2_16)
        RESULT("bINT BASE 2^16 access methods");
    #elif defined(_BASE2_32)
        RESULT("bINT BASE 2^32 access methods");
    #elif defined(_BASE2_64)
        RESULT("bINT BASE 2^64 access methods");
    #endif
}