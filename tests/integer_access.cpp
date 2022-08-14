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
    apa::integer subject1("4ff0dec3d875aafff", 16);
    apa::integer subject2("fffffff", 16);
    apa::integer subject3("ffffffffffffffff", 16);
    apa::integer subject4("ffffffff", 16);

    size_t sub1_byte_size = 9;
    size_t sub2_byte_size = 4;
    size_t sub3_byte_size = 8;
    size_t sub4_byte_size = 4;

    size_t sub1_bit_size = 67;
    size_t sub2_bit_size = 28;
    size_t sub3_bit_size = 64;
    size_t sub4_bit_size = 32;

    ASSERT_EQUALITY(subject1.byte_size(), sub1_byte_size, "subject1 byte size");
    ASSERT_EQUALITY(subject2.byte_size(), sub2_byte_size, "subject2 byte size");
    ASSERT_EQUALITY(subject3.byte_size(), sub3_byte_size, "subject3 byte size");
    ASSERT_EQUALITY(subject4.byte_size(), sub4_byte_size, "subject4 byte size");

    ASSERT_EQUALITY(subject1.bit_size(), sub1_bit_size, "subject1 bit size ");
    ASSERT_EQUALITY(subject2.bit_size(), sub2_bit_size, "subject2 bit size ");
    ASSERT_EQUALITY(subject3.bit_size(), sub3_bit_size, "subject3 bit size ");
    ASSERT_EQUALITY(subject4.bit_size(), sub4_bit_size, "subject4 bit size ");

#if defined(_BASE2_16)
    RESULT("INTEGER BASE 2^16 access methods");
#elif defined(_BASE2_32)
    RESULT("INTEGER BASE 2^32 access methods");
#elif defined(_BASE2_64)
    RESULT("INTEGER BASE 2^64 access methods");
#endif
}