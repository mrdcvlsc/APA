#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../core.hpp"
#else
#include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    try {
        apa::bint bin = "0b1100012j228263";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::BIN,     "HANDLING WRONG ASSIGNMENT | bin     ");    
    }

    try {
        apa::bint dec = "1100012j228263";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::DEC,     "HANDLING WRONG ASSIGNMENT | dec     ");    
    }

    try {
        apa::bint oct = "0o1100012j228263";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::OCT,     "HANDLING WRONG ASSIGNMENT | oct     ");    
    }

    try {
        apa::bint hex = "0x1100012j228263";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::HEX,     "HANDLING WRONG ASSIGNMENT | hex     ");    
    }

    try {
        apa::bint empty = "";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::EMPTY,   "HANDLING WRONG ASSIGNMENT | empty   ");    
    }

    try {
        apa::bint invalid = "0ffffffff";
    } catch (const apa::bint_error& e) {
        ASSERT_EQUALITY(e.get_error_code(), apa::INVALID, "HANDLING WRONG ASSIGNMENT | invalid ");    
    }

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 ERROR HANDLING");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 ERROR HANDLING");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 ERROR HANDLING");
    #endif
}