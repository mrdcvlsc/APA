#include <iostream>
#include <vector>
#include <bitset>

#ifndef _MAKE_LIB
#include "../core.hpp"
#else
#include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    // test variables
    apa::bint
        num1("ffeab07760ac0f014ffed979faa2555fc000a10000fffabcdeffaeeedcde5",16),
        num2("4333afaafffededeadbeef5567abc1234567890bb",16),
        num3("fffff00000000000000111",16);

    apa::bint
        neg_num1("-ffeab07760ac0f014ffed979faa2555fc000a10000fffabcdeffaeeedcde5",16),
        neg_num2("-4333afaafffededeadbeef5567abc1234567890bb",16),
        neg_num3("-fffff00000000000000111",16);

    // correct answers

    apa::bint
        num1_and_num2_C("4131aaa2555ec000a100005562a8c0230466880a1",16),
        num1_and_num3_C("ff00000000000000101",16),
        num2_and_num3_C("eef5500000000000000011",16),
        
        num1_or_num2_C("ffeab07760ac0f014ffedb7bffaaffffdedeadbeefffffbfdfffefefdddff",16),
        num1_or_num3_C("ffeab07760ac0f014ffed979faa2555fc000a10ffffffabcdeffaeeedcdf5",16),
        num2_or_num3_C("4333afaafffededeadbfffff67abc1234567891bb",16),

        num1_xor_num2_C("ffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d5e",16),
        num1_xor_num3_C("ffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf4",16),
        num2_xor_num3_C("4333afaafffededeadb110aa67abc1234567891aa",16);

    // answers
    ASSERT_EQUALITY((num1 & num2),num1_and_num2_C, "num1 & num2");
    ASSERT_EQUALITY((num1 & num3),num1_and_num3_C, "num1 & num3");
    ASSERT_EQUALITY((num2 & num3),num2_and_num3_C, "num2 & num3");

    ASSERT_EQUALITY((num2 & num1),num1_and_num2_C, "num2 & num1");
    ASSERT_EQUALITY((num3 & num1),num1_and_num3_C, "num3 & num1");
    ASSERT_EQUALITY((num3 & num2),num2_and_num3_C, "num3 & num2");

    ASSERT_EQUALITY((num1 | num2),num1_or_num2_C,  "num1 | num2");
    ASSERT_EQUALITY((num1 | num3),num1_or_num3_C,  "num1 | num3");
    ASSERT_EQUALITY((num2 | num3),num2_or_num3_C,  "num2 | num3");

    ASSERT_EQUALITY((num2 | num1),num1_or_num2_C,  "num2 | num1");
    ASSERT_EQUALITY((num3 | num1),num1_or_num3_C,  "num3 | num1");
    ASSERT_EQUALITY((num3 | num2),num2_or_num3_C,  "num3 | num2");

    ASSERT_EQUALITY((num1 ^ num2),num1_xor_num2_C, "num1 ^ num2");
    ASSERT_EQUALITY((num1 ^ num3),num1_xor_num3_C, "num1 ^ num3");
    ASSERT_EQUALITY((num2 ^ num3),num2_xor_num3_C, "num2 ^ num3");

    ASSERT_EQUALITY((num2 ^ num1),num1_xor_num2_C, "num2 ^ num1");
    ASSERT_EQUALITY((num3 ^ num1),num1_xor_num3_C, "num3 ^ num1");
    ASSERT_EQUALITY((num3 ^ num2),num2_xor_num3_C, "num3 ^ num2");

    ASSERT_EQUALITY((~num1),(-(num1+1)),           "~num1      ");
    ASSERT_EQUALITY((~num2),(-(num2+1)),            "~num2      ");
    ASSERT_EQUALITY((~num3),(-(num3+1)),            "~num3      ");

    // bitwise logical and negatives test

    apa::bint neg_num1_and_num2_C("2020508aaa01ede0cbeef000503010041010101b",16);
    apa::bint neg_num1_and_num3_C("fff0000000000000000011",16);
    apa::bint neg_num2_and_num3_C("110aa00000000000000101",16);
     
    apa::bint num1_and_neg_num2_C("ffeab07760ac0f014ffe9848500000010000000000aa98141edcaa8854d45",16);
    apa::bint num1_and_neg_num3_C("ffeab07760ac0f014ffed979faa2555fc000a1000000fabcdeffaeeedcce5",16);
    apa::bint num2_and_neg_num3_C("4333afaafffededeadb0000067abc1234567890ab",16);

    apa::bint neg_num1_and_neg_num2_C("-ffeab07760ac0f014ffedb7bffaaffffdedeadbeefffffbfdfffefefdddff",16);
    apa::bint neg_num1_and_neg_num3_C("-ffeab07760ac0f014ffed979faa2555fc000a10ffffffabcdeffaeeedcdf5",16);
    apa::bint neg_num2_and_neg_num3_C("-4333afaafffededeadbfffff67abc1234567891bb",16);

    ASSERT_EQUALITY((neg_num1 & num2),neg_num1_and_num2_C,"-num1 & num2");
    ASSERT_EQUALITY((neg_num1 & num3),neg_num1_and_num3_C,"-num1 & num3");
    ASSERT_EQUALITY((neg_num2 & num3),neg_num2_and_num3_C,"-num2 & num3");

    ASSERT_EQUALITY((num1 & neg_num2),num1_and_neg_num2_C,"num1 & -num2");
    ASSERT_EQUALITY((num1 & neg_num3),num1_and_neg_num3_C,"num1 & -num3");
    ASSERT_EQUALITY((num2 & neg_num3),num2_and_neg_num3_C,"num2 & -num3");

    ASSERT_EQUALITY((neg_num1 & neg_num2),neg_num1_and_neg_num2_C,"-num1 & -num2");
    ASSERT_EQUALITY((neg_num1 & neg_num3),neg_num1_and_neg_num3_C,"-num1 & -num3");
    ASSERT_EQUALITY((neg_num2 & neg_num3),neg_num2_and_neg_num3_C,"-num2 & -num3");

    // bitwise logical or negatives test

    apa::bint neg_num1_or_num2_C("-ffeab07760ac0f014ffe9848500000010000000000aa98141edcaa8854d45",16);
    apa::bint neg_num1_or_num3_C("-ffeab07760ac0f014ffed979faa2555fc000a1000000fabcdeffaeeedcce5",16);
    apa::bint neg_num2_or_num3_C("-4333afaafffededeadb0000067abc1234567890ab",16);
     
    apa::bint num1_or_neg_num2_C("-2020508aaa01ede0cbeef000503010041010101b",16);
    apa::bint num1_or_neg_num3_C("-fff0000000000000000011",16);
    apa::bint num2_or_neg_num3_C("-110aa00000000000000101",16);

    apa::bint neg_num1_or_neg_num2_C("-4131aaa2555ec000a100005562a8c0230466880a1",16);
    apa::bint neg_num1_or_neg_num3_C("-ff00000000000000101",16);
    apa::bint neg_num2_or_neg_num3_C("-eef5500000000000000011",16);

    ASSERT_EQUALITY((neg_num1 | num2),neg_num1_or_num2_C,"-num1 | num2");
    ASSERT_EQUALITY((neg_num1 | num3),neg_num1_or_num3_C,"-num1 | num3");
    ASSERT_EQUALITY((neg_num2 | num3),neg_num2_or_num3_C,"-num2 | num3");

    ASSERT_EQUALITY((num1 | neg_num2),num1_or_neg_num2_C,"num1 | -num2");
    ASSERT_EQUALITY((num1 | neg_num3),num1_or_neg_num3_C,"num1 | -num3");
    ASSERT_EQUALITY((num2 | neg_num3),num2_or_neg_num3_C,"num2 | -num3");

    ASSERT_EQUALITY((neg_num1 | neg_num2),neg_num1_or_neg_num2_C,"-num1 | -num2");
    ASSERT_EQUALITY((neg_num1 | neg_num3),neg_num1_or_neg_num3_C,"-num1 | -num3");
    ASSERT_EQUALITY((neg_num2 | neg_num3),neg_num2_or_neg_num3_C,"-num2 | -num3");

    // bitwise logical and negatives test

    apa::bint neg_num1_xor_num2_C("-ffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d60",16);
    apa::bint neg_num1_xor_num3_C("-ffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf6",16);
    apa::bint neg_num2_xor_num3_C("-4333afaafffededeadb110aa67abc1234567891ac",16);
     
    apa::bint num1_xor_neg_num2_C("-ffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d60",16);
    apa::bint num1_xor_neg_num3_C("-ffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf6",16);
    apa::bint num2_xor_neg_num3_C("-4333afaafffededeadb110aa67abc1234567891ac",16);

    apa::bint neg_num1_xor_neg_num2_C("ffeab07760ac0f014ffe9a4a5508aaa11ede0cbeefaa9d171fdceb8955d5e",16);
    apa::bint neg_num1_xor_neg_num3_C("ffeab07760ac0f014ffed979faa2555fc000a10fff00fabcdeffaeeedccf4",16);
    apa::bint neg_num2_xor_neg_num3_C("4333afaafffededeadb110aa67abc1234567891aa",16);

    ASSERT_EQUALITY((neg_num1 ^ num2),neg_num1_xor_num2_C,"-num1 ^ num2");
    ASSERT_EQUALITY((neg_num1 ^ num3),neg_num1_xor_num3_C,"-num1 ^ num3");
    ASSERT_EQUALITY((neg_num2 ^ num3),neg_num2_xor_num3_C,"-num2 ^ num3");

    ASSERT_EQUALITY((num1 ^ neg_num2),num1_xor_neg_num2_C,"num1 ^ -num2");
    ASSERT_EQUALITY((num1 ^ neg_num3),num1_xor_neg_num3_C,"num1 ^ -num3");
    ASSERT_EQUALITY((num2 ^ neg_num3),num2_xor_neg_num3_C,"num2 ^ -num3");

    ASSERT_EQUALITY((neg_num1 ^ neg_num2),neg_num1_xor_neg_num2_C,"-num1 ^ -num2");
    ASSERT_EQUALITY((neg_num1 ^ neg_num3),neg_num1_xor_neg_num3_C,"-num1 ^ -num3");
    ASSERT_EQUALITY((neg_num2 ^ neg_num3),neg_num2_xor_neg_num3_C,"-num2 ^ -num3");

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 LOGICAL BITWISE OPERATOR");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 LOGICAL BITWISE OPERATOR");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 LOGICAL BITWISE OPERATOR");
    #endif
}