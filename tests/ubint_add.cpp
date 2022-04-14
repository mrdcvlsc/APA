#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

apa::ubint fib(size_t nth, uint64_t b0 = 0, uint64_t b1 = 1) {
    apa::ubint base0 = b0, base1 = b1;
    apa::ubint nthfib = 0;
    for(size_t i=2; i<=nth; ++i) {
        nthfib = base0 + base1;
        base0 = base1;
        base1 = nthfib;
    }
    return nthfib;
}

int main() { START_TEST;

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

    apa::ubint fib1000_b9_9C = {
         0x1ece35e, 0x12b8f7fd, 0x9e084739, 0xb6088668, 0x08ace0dc, 0x4c106578, 0x20caa252,
        0xe2fa0002, 0x1d823420, 0x41f11620, 0xb67cf41c, 0xfdefdd9d, 0x0a54345f, 0x2538b61f,
        0xf4ed143f, 0xbc6ac884, 0x4f99801d, 0xe4b9b936, 0x9b38754e, 0x700b129b, 0x6e09dae4,
        0xc3406855
    };

    apa::ubint fib1000_1_99927737 = fib(1000,1,99927737);
    apa::ubint fib1000_1_99927737_C = {
            0xc998, 0xdee18201, 0x10307276, 0x9e7ee803, 0xca113a44, 0x6de27f3c,
        0x67e4dd91, 0x6c3909d9, 0x95b4d857, 0x794c412a, 0xcd27a845, 0x782f308f,
        0x6e20aafc, 0x5b0a5a45, 0xe69c8045, 0x19984738, 0x2904aad4, 0x42a75a69,
        0xddcde1af, 0xd690b6d3, 0xbdf43f19, 0xbf2d5a97, 0x01d098d5
    };

    apa::ubint fib1000_b9_9 = fib(1000,9,9);

    ASSERT_UBINT(fib250,fib250C,"FIB(250)");
    ASSERT_UBINT(fib1000,fib1000C,"FIB(1000)");
    ASSERT_UBINT(fib1000_b9_9,fib1000_b9_9C,"FIB(1000,9,9)");
    ASSERT_UBINT(fib1000_1_99927737,fib1000_1_99927737_C,"FIB(1000,1,99927737)");

    RESULT("UBINT ADDITION");
}