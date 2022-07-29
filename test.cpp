#include <iostream>
#include <chrono>
#include "core.hpp"

apa::bint bintFactorial(size_t n) {
    apa::bint factorial(1);
    apa::bint iter = factorial;

    apa::bint N = n;
    for(apa::bint i=1; i<=N; ++i) {
        factorial *= iter;
        iter++;
    }

    return factorial;
}

apa::integer integerFactorial(size_t n) {
    apa::integer factorial(1);
    apa::integer iter = factorial;

    for(size_t i=1; i<=n; ++i) {
        factorial *= iter;
        iter++;
    }

    return factorial;
}

int main() {

    apa::bint a("f0000", apa::HEX);

    apa::bint b("f0000000000000000000000000000", apa::HEX);

    apa::bint c("e100000000000000000000000000000000", apa::HEX);

    apa::bint prod = a * b;

    std::cout << "c    = " << c << "\n";
    std::cout << "prod = " << prod << "\n";

    // #########

    // size_t fac_level = 50000;

    // size_t sums = 0;
    // for(size_t i=0; i<100000; ++i) {
    //     sums += (i*0.01);
    // }

    // apa::bint bintFactorial_ans;
    // for(size_t i=0; i<10; ++i) {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     bintFactorial_ans = bintFactorial(fac_level);
    //     auto ends = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(ends-start);
    //     std::cout << "bintFactorial took " << duration.count() << " milliseconds\n";
    // }

    // apa::integer integerFactorial_ans;
    // for(size_t i=0; i<10; ++i) {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     integerFactorial_ans = integerFactorial(fac_level);
    //     auto ends = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(ends-start);
    //     std::cout << "integerFactorial took " << duration.count() << " milliseconds\n";
    // }

    return 0;
}