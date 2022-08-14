#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() {
    START_TEST;

    // test variables
    apa::bint subject = "0xdad0deed1feed2dead3beef4ceed5";
    apa::bint negate = -subject;

    // answers
    apa::bint subject_LS15 = "0x6d686f768ff7696f569df77a6776a8000";
    apa::bint negate_LS15 = "-0x6d686f768ff7696f569df77a6776a8000";

    apa::bint subject_RS15 = "0x1b5a1bdda3fdda5bd5a77dde99";
    apa::bint negate_RS15 = "-0x1b5a1bdda3fdda5bd5a77dde9a";

    ASSERT_EQUALITY((subject << 15), subject_LS15, "subject << 15");
    ASSERT_EQUALITY((negate << 15), negate_LS15, "negate  << 15");

    ASSERT_EQUALITY((subject >> 15), subject_RS15, "subject >> 15");
    ASSERT_EQUALITY((negate >> 15), negate_RS15, "negate  >> 15");

#if defined(_BASE2_16)
    RESULT("BINT BASE 2^16 SHIFT OPERATORS");
#elif defined(_BASE2_32)
    RESULT("BINT BASE 2^32 SHIFT OPERATORS");
#elif defined(_BASE2_64)
    RESULT("BINT BASE 2^64 SHIFT OPERATORS");
#endif
}