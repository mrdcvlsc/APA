#include <iostream>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

apa::ubint fib(size_t nth) {
    apa::ubint base0 = 0, base1 = 1;
    apa::ubint nthfib = 0;
    for(size_t i=2; i<=nth; ++i) {
        nthfib = base0 + base1;
        base0 = base1;
        base1 = nthfib;
    }
    return nthfib;
}

int main() {

    apa::ubint fib250C = {0x151a, 0xe2a8207e, 0xf4425d98, 0x671de203, 0xbfb894e8, 0xf601e617};
    apa::ubint fib250 = fib(250);
    fib250C.printStatus();
    fib250.printStatus();

    return 0;
}