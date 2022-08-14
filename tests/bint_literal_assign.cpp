#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <bint.hpp>
#endif

template <class T>
std::string cots(const T &input) {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    std::cout << input;
    std::cout.rdbuf(old);
    return buffer.str();
}

#include "mini-test.hpp"

int main() {
    START_TEST;

    // validators
    apa::bint sc_C = cots((int) std::numeric_limits<char>::min());
    apa::bint uc_C = cots((unsigned int) std::numeric_limits<unsigned char>::max());

    apa::bint ss_C = cots((short) std::numeric_limits<short>::min());
    apa::bint us_C = cots((unsigned short) std::numeric_limits<unsigned short>::max());

    apa::bint si_C = cots((int) std::numeric_limits<int>::min());
    apa::bint ui_C = cots((unsigned int) std::numeric_limits<unsigned int>::max());

    apa::bint sl_C = cots((long) std::numeric_limits<long>::min());
    apa::bint ul_C = cots((unsigned long) std::numeric_limits<unsigned long>::max());

    apa::bint sll_C = cots((long long) std::numeric_limits<long long>::min());
    apa::bint ull_C = cots((unsigned long long) std::numeric_limits<unsigned long long>::max());

    // tests subjects

    apa::bint sc_bint = ((char) std::numeric_limits<char>::min());
    apa::bint uc_bint = ((unsigned char) std::numeric_limits<unsigned char>::max());
    ASSERT_EQUALITY(sc_bint, sc_C, "       signed char ");
    ASSERT_EQUALITY(uc_bint, uc_C, "     unsigned char ");

    apa::bint ss_bint = ((short) std::numeric_limits<short>::min());
    apa::bint us_bint = ((unsigned short) std::numeric_limits<unsigned short>::max());
    ASSERT_EQUALITY(ss_bint, ss_C, "      signed short ");
    ASSERT_EQUALITY(us_bint, us_C, "    unsigned short ");

    apa::bint si_bint = ((int) std::numeric_limits<int>::min());
    apa::bint ui_bint = ((unsigned int) std::numeric_limits<unsigned int>::max());
    ASSERT_EQUALITY(si_bint, si_C, "        signed int ");
    ASSERT_EQUALITY(ui_bint, ui_C, "      unsigned int ");

    apa::bint sl_bint = ((long) std::numeric_limits<long>::min());
    apa::bint ul_bint = ((unsigned long) std::numeric_limits<unsigned long>::max());
    ASSERT_EQUALITY(sl_bint, sl_C, "       signed long ");
    ASSERT_EQUALITY(ul_bint, ul_C, "     unsigned long ");

    apa::bint sll_bint = ((long long) std::numeric_limits<long long>::min());
    apa::bint ull_bint = ((unsigned long long) std::numeric_limits<unsigned long long>::max());
    ASSERT_EQUALITY(sll_bint, sll_C, "  signed long long ");
    ASSERT_EQUALITY(ull_bint, ull_C, "unsigned long long ");

#if defined(_BASE2_16)
    RESULT("BINT BASE 2^16 LITERAL ASSIGNMENT");
#elif defined(_BASE2_32)
    RESULT("BINT BASE 2^32 LITERAL ASSIGNMENT");
#elif defined(_BASE2_64)
    RESULT("BINT BASE 2^64 LITERAL ASSIGNMENT");
#endif
}