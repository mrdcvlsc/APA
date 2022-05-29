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
        apa::bint bits("11110011001110101001111",2); // 23 bits
        apa::bint bytes1("ffaabbccdd",16); // 5
        apa::bint bytes2("faabb",16); // 3
        
        // answers
        ASSERT_EQUALITY(bits.bit_size(), 23,   "bitsize   ");
        ASSERT_EQUALITY(bytes1.byte_size(), 5, "bytesize 1");
        ASSERT_EQUALITY(bytes2.byte_size(), 3, "bytesize 2");
      
    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 SHIFT OPERATORS");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 SHIFT OPERATORS");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 SHIFT OPERATORS");
    #endif
}