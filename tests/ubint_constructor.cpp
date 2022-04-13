#include "../ubint.hpp"

int main() {
    std::cout << "===== Constructor Tests =====\n";
    
    uint64_t value = 0xfedcab8761aff37a;

    apa::ubint a;
    apa::ubint b(value);
    apa::ubint c;
    a.limbs[0] = (uint32_t) value;
    a.limbs[1] = value >> 32;
    c = a;

    a.printHex();
    b.printHex();
    c.printHex();

    if(a==b && a==c) {
        std::cout << "test 1 : PASSED\n";
        return 0;
    }
    else {
        std::cout << "test 1 : FAILED\n";
        return 0;
    }
}