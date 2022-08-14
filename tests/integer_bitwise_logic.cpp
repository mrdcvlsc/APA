#include <bitset>
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

    // test variables
    apa::integer num1("0xffeab07760ac0f014ffed979faa2555fc000a10000fffabcdeffaeeedcde5", 16),
        num2("0x4333afaafffededeadbeef5567abc1234567890bb", 16), num3("0xfffff00000000000000111", 16);

    // correct answers
    apa::integer num1_and_num2_C("0x4131aaa2555ec000a100005562a8c0230466880a1", 16),
        num1_and_num3_C("0xff00000000000000101", 16), num2_and_num3_C("0xeef5500000000000000011", 16),

        num1_or_num2_C("0xffeab07760ac0f014ffedb7bffaaffffdedeadbeefffffbfdfffefefdddff", 16),
        num1_or_num3_C("0xffeab07760ac0f014ffed979faa2555fc000a10ffffffabcdeffaeeedcdf5", 16),
        num2_or_num3_C("0x4333afaafffededeadbfffff67abc1234567891bb", 16),

        num1_xor_num2_C("0xffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d5e", 16),
        num1_xor_num3_C("0xffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf4", 16),
        num2_xor_num3_C("0x4333afaafffededeadb110aa67abc1234567891aa", 16),

        num1_not_C("0x154f889f53f0feb0012686055daaa03fff5effff000543210051112321a", 16),
        num2_not_C("0x3ccc505500012121524110aa98543edcba9876f44", 16), num3_not_C("0xffffffffffffffeee", 16);

    // answers

    ASSERT_EQUALITY((num1 & num2), num1_and_num2_C, "num1 & num2");
    ASSERT_EQUALITY((num1 & num3), num1_and_num3_C, "num1 & num3");
    ASSERT_EQUALITY((num2 & num3), num2_and_num3_C, "num2 & num3");

    ASSERT_EQUALITY((num2 & num1), num1_and_num2_C, "num2 & num1");
    ASSERT_EQUALITY((num3 & num1), num1_and_num3_C, "num3 & num1");
    ASSERT_EQUALITY((num3 & num2), num2_and_num3_C, "num3 & num2");

    ASSERT_EQUALITY((num1 | num2), num1_or_num2_C, "num1 | num2");
    ASSERT_EQUALITY((num1 | num3), num1_or_num3_C, "num1 | num3");
    ASSERT_EQUALITY((num2 | num3), num2_or_num3_C, "num2 | num3");

    ASSERT_EQUALITY((num2 | num1), num1_or_num2_C, "num2 | num1");
    ASSERT_EQUALITY((num3 | num1), num1_or_num3_C, "num3 | num1");
    ASSERT_EQUALITY((num3 | num2), num2_or_num3_C, "num3 | num2");

    ASSERT_EQUALITY((num1 ^ num2), num1_xor_num2_C, "num1 ^ num2");
    ASSERT_EQUALITY((num1 ^ num3), num1_xor_num3_C, "num1 ^ num3");
    ASSERT_EQUALITY((num2 ^ num3), num2_xor_num3_C, "num2 ^ num3");

    ASSERT_EQUALITY((num2 ^ num1), num1_xor_num2_C, "num2 ^ num1");
    ASSERT_EQUALITY((num3 ^ num1), num1_xor_num3_C, "num3 ^ num1");
    ASSERT_EQUALITY((num3 ^ num2), num2_xor_num3_C, "num3 ^ num2");

    ASSERT_EQUALITY((~num1), num1_not_C, "~num1      ");
    ASSERT_EQUALITY((~num2), num2_not_C, "~num2      ");
    ASSERT_EQUALITY((~num3), num3_not_C, "~num3      ");

#if defined(_BASE2_16)
    RESULT("INTEGER BASE 2^16 LOGICAL BITWISE OPERATOR");
#elif defined(_BASE2_32)
    RESULT("INTEGER BASE 2^32 LOGICAL BITWISE OPERATOR");
#elif defined(_BASE2_64)
    RESULT("INTEGER BASE 2^64 LOGICAL BITWISE OPERATOR");
#endif
}