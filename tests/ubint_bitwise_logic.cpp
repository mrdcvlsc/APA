#include <iostream>
#include <vector>
#include <bitset>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

apa::ubint fac(size_t n) {
    apa::ubint factorial(1);
    apa::ubint iter = factorial;
    apa::ubint one = 1;

    for(size_t i=1; i<=n; ++i) {
        factorial *= iter;
        iter = iter + one;
    }

    return factorial;
}

int main() { START_TEST;

    // test variables
    apa::ubint
        num1("0xffeab07760ac0f014ffed979faa2555fc000a10000fffabcdeffaeeedcde5"),
        num2("0x4333afaafffededeadbeef5567abc1234567890bb"),
        num3("0xfffff00000000000000111");

    // answers
    apa::ubint
        num1_and_num2 = num1 & num2,
        num1_and_num3 = num1 & num3,
        num2_and_num3 = num2 & num3,

        num2_and_num1 = num2 & num1,
        num3_and_num1 = num3 & num1,
        num3_and_num2 = num3 & num2,
        
        num1_or_num2 = num1 | num2,
        num1_or_num3 = num1 | num3,
        num2_or_num3 = num2 | num3,

        num2_or_num1 = num2 | num1,
        num3_or_num1 = num3 | num1,
        num3_or_num2 = num3 | num2,
        
        num1_xor_num2 = num1 ^ num2,
        num1_xor_num3 = num1 ^ num3,
        num2_xor_num3 = num2 ^ num3,

        num2_xor_num1 = num2 ^ num1,
        num3_xor_num1 = num3 ^ num1,
        num3_xor_num2 = num3 ^ num2,
        
        num1_not = ~num1,
        num2_not = ~num2,
        num3_not = ~num3;

    // correct answers
    apa::ubint
        num1_and_num2_C("0x4131aaa2555ec000a100005562a8c0230466880a1"),
        num1_and_num3_C("0xff00000000000000101"),
        num2_and_num3_C("0xeef5500000000000000011"),
        
        num1_or_num2_C("0xffeab07760ac0f014ffedb7bffaaffffdedeadbeefffffbfdfffefefdddff"),
        num1_or_num3_C("0xffeab07760ac0f014ffed979faa2555fc000a10ffffffabcdeffaeeedcdf5"),
        num2_or_num3_C("0x4333afaafffededeadbfffff67abc1234567891bb"),

        num1_xor_num2_C("0xffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d5e"),
        num1_xor_num3_C("0xffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf4"),
        num2_xor_num3_C("0x4333afaafffededeadb110aa67abc1234567891aa"),
        
        num1_not_C("0x154f889f53f0feb0012686055daaa03fff5effff000543210051112321a"),
        num2_not_C("0x3ccc505500012121524110aa98543edcba9876f44"),
        num3_not_C("0xffffffffffffffeee");

    ASSERT_UBINT(num1_and_num2,num1_and_num2_C,"num1 & num2");
    ASSERT_UBINT(num1_and_num3,num1_and_num3_C,"num1 & num3");
    ASSERT_UBINT(num2_and_num3,num2_and_num3_C,"num2 & num3");

    ASSERT_UBINT(num2_and_num1,num1_and_num2_C,"num2 & num1");
    ASSERT_UBINT(num3_and_num1,num1_and_num3_C,"num3 & num1");
    ASSERT_UBINT(num3_and_num2,num2_and_num3_C,"num3 & num2");

    ASSERT_UBINT(num1_or_num2,num1_or_num2_C,"num1 | num2");
    ASSERT_UBINT(num1_or_num3,num1_or_num3_C,"num1 | num3");
    ASSERT_UBINT(num2_or_num3,num2_or_num3_C,"num2 | num3");

    ASSERT_UBINT(num2_or_num1,num1_or_num2_C,"num2 | num1");
    ASSERT_UBINT(num3_or_num1,num1_or_num3_C,"num3 | num1");
    ASSERT_UBINT(num3_or_num2,num2_or_num3_C,"num3 | num2");

    ASSERT_UBINT(num1_xor_num2,num1_xor_num2_C,"num1 ^ num2");
    ASSERT_UBINT(num1_xor_num3,num1_xor_num3_C,"num1 ^ num3");
    ASSERT_UBINT(num2_xor_num3,num2_xor_num3_C,"num2 ^ num3");

    ASSERT_UBINT(num2_xor_num1,num1_xor_num2_C,"num2 ^ num1");
    ASSERT_UBINT(num3_xor_num1,num1_xor_num3_C,"num3 ^ num1");
    ASSERT_UBINT(num3_xor_num2,num2_xor_num3_C,"num3 ^ num2");

    ASSERT_UBINT(num1_not,num1_not_C,"~num1");
    ASSERT_UBINT(num2_not,num2_not_C,"~num2");
    ASSERT_UBINT(num3_not,num3_not_C,"~num3");

    #if defined(_BASE2_16)
        RESULT("UBINT BASE 2^16 LOGICAL BITWISE OPERATOR");
    #elif defined(_BASE2_32)
        RESULT("UBINT BASE 2^32 LOGICAL BITWISE OPERATOR");
    #elif defined(_BASE2_64)
        RESULT("UBINT BASE 2^64 LOGICAL BITWISE OPERATOR");
    #endif
}