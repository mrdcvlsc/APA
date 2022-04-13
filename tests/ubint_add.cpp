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

    std::cout << "\n===== Addition Tests =====\n";

    apa::ubint fib250C = {0x151a, 0xe2a8207e, 0xf4425d98, 0x671de203, 0xbfb894e8, 0xf601e617};
    apa::ubint fib250 = fib(250);

    apa::ubint fib1000C = {
          0x21d8cb, 0x07b572c2, 0x5732bb11, 0x6f2c33ba,
        0xb0e83d0c, 0x699bad1a, 0x727a736a, 0x7e42ca93,
        0xb697ad22, 0x4d553983, 0x73062f18, 0xff62b99c,
        0x28068131, 0xa3fab0c1, 0x2e351028, 0x3c1d60b0,
        0x0930b7e8, 0x803c312b, 0x4c8e6d52, 0x86805fc7,
        0x0b594dc7, 0x5cc0604b
    };

    apa::ubint fib1000 = fib(1000);

    if(fib250==fib250C) {
        std::cout << "FIB(250) : PASSED\n";
    }
    else {
        std::cout << "FIB(250) : FAILED\n";
    }

    if(fib1000==fib1000C) {
        std::cout << "FIB(1000) : PASSED\n";
    }
    else {
        std::cout << "FIB(1000) : FAILED\n";
    }

    fib1000C.printHex();
    fib1000.printHex();

    return 0;
}