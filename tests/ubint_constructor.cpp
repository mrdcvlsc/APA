#include "../ubint.hpp"

int main() {
    std::cout << "===== Constructor Tests =====\n";
    
    apa::ubint a;
    apa::ubint b(0xbeef777);
    apa::ubint c;
    a.limbs[0] = 0xbeef777;
    c = a;

    if(a==b && a==c) {
        std::cout << "test 1 : PASSED\n";
        return 0;
    }
    else {
        std::cout << "test 1 : FAILED\n";
        return 0;
    }
}