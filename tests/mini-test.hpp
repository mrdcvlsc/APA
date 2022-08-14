#ifndef MINI_TEST_HPP
#define MINI_TEST_HPP

#include <iostream>
#include <vector>

#ifdef _MAKE_LIB
    #include <math.hpp>
#endif

std::vector<bool> TEST_RESULTS;

#define START_TEST std::cout << "-------------------------------\n";

#define ASSERT_EXPRESSION(LOGIC, SPECIFIC_TEST_NAME)                                                                   \
    std::cout << SPECIFIC_TEST_NAME << " : ";                                                                          \
    if (LOGIC) {                                                                                                       \
        std::cout << "PASSED\n";                                                                                       \
        TEST_RESULTS.push_back(true);                                                                                  \
    } else {                                                                                                           \
        std::cout << "FAILED < !\n";                                                                                   \
        TEST_RESULTS.push_back(false);                                                                                 \
    }

#define ASSERT_EQUALITY(A, B, SPECIFIC_TEST_NAME)                                                                      \
    std::cout << SPECIFIC_TEST_NAME << " : ";                                                                          \
    if (A == B) {                                                                                                      \
        std::cout << "PASSED\n";                                                                                       \
        TEST_RESULTS.push_back(true);                                                                                  \
    } else {                                                                                                           \
        std::cout << "FAILED < !\n";                                                                                   \
        TEST_RESULTS.push_back(false);                                                                                 \
    }

#define FOURWAY_ASSERT_EQUALITY(A, B, C, D, SPECIFIC_TEST_NAME)                                                        \
    std::cout << SPECIFIC_TEST_NAME << " : ";                                                                          \
    if (((A == B) && (C == D)) && (A == D)) {                                                                          \
        std::cout << "PASSED\n";                                                                                       \
        TEST_RESULTS.push_back(true);                                                                                  \
    } else {                                                                                                           \
        std::cout << "FAILED < !\n";                                                                                   \
        TEST_RESULTS.push_back(false);                                                                                 \
    }

#define RESULT(MAIN_TEST_NAME)                                                                                         \
    std::cout << "----------------------------------------------\n";                                                   \
    std::cout << "    " << MAIN_TEST_NAME << "(" << __FILE__ << ") : ";                                                \
    for (auto e: TEST_RESULTS) {                                                                                       \
        if (!e) {                                                                                                      \
            std::cout << "FAILED\n";                                                                                   \
            return 1;                                                                                                  \
        }                                                                                                              \
    }                                                                                                                  \
    std::cout << "PASSED\n";                                                                                           \
    std::cout << "----------------------------------------------\n\n";                                                 \
    return 0;

#endif