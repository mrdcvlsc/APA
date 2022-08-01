#include <iostream>
#include <chrono>
#include "../core.hpp"

#define RUNS 300

int main() {
    apa::bint a = apa::factorial(3246);
    apa::bint b = apa::fibonacci(37531);

    size_t case1_total = 0, case2_total = 0, case3_total = 0, case4_total = 0;

    for(size_t i=0; i<RUNS; ++i) {
        auto add_start = std::chrono::high_resolution_clock::now();
        a + b;
        auto add_end = std::chrono::high_resolution_clock::now();
        auto add_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(add_end-add_start);
        case1_total += add_dur.count();

        auto sub_start = std::chrono::high_resolution_clock::now();
        a - b;
        auto sub_end = std::chrono::high_resolution_clock::now();
        auto sub_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(sub_end-sub_start);
        case2_total += sub_dur.count();

        auto mul_start = std::chrono::high_resolution_clock::now();
        a * b;
        auto mul_end = std::chrono::high_resolution_clock::now();
        auto mul_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(mul_end-mul_start);
        case3_total += mul_dur.count();

        auto div_start = std::chrono::high_resolution_clock::now();
        a / b;
        auto div_end = std::chrono::high_resolution_clock::now();
        auto div_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(div_end-div_start);
        case4_total += div_dur.count();
    }

    std::cout <<
    "### Using base 2<sup>" << sizeof(apa::base_t)*8 << "</sup> number system representation.\n\n"
    "- a limb size = " << a.limb_size() << "\n"
    "- b limb size = " << b.limb_size() << "\n\n"
    "| cases | nanoseconds |\n"
    "| ----- | ----------- |\n"
    "| add (a + b) | " << case1_total/RUNS << " ns |\n"
    "| sub (a - b) | " << case2_total/RUNS << " ns |\n"
    "| mul (a * b) | " << case3_total/RUNS << " ns |\n"
    "| div (a / b) | " << case4_total/RUNS << " ns |\n"
    "\n";

    return 0;
}