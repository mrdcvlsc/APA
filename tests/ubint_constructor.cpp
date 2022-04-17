#include "../ubint.hpp"

int main() {
    
    #if defined(_BASE2_32)
    {
        std::cout << "===== Constructor Tests - Base32 =====\n";
        uint64_t value = 0xfedcab8761aff37a;

        apa::ubint a;
        apa::ubint b(value);
        apa::ubint c;
        apa::ubint d = { (uint32_t)(value>>32), (uint32_t)value};
        apa::ubint x = { 0xfeed, 0xfaf, 0xbeef};
        apa::ubint y = x;
        apa::ubint z;
        z = x;
        
        a.limbs[0] = (uint32_t) value;
        a.limbs[1] = value >> 32;
        c = a;

        if(a==b && a==c && a==d && x==y && x==z) {
            std::cout << "test 1 : PASSED\n";
            return 0;
        }
        else {
            std::cout << "test 1 : FAILED\n";
            return 0;
        }
    }
    #elif defined(_BASE2_64)
    {
        std::cout << "===== Constructor Tests - Base64 =====\n";
        uint64_t value = 0xfedcab8761aff37a;

        apa::ubint a;
        apa::ubint b((apa::limb_t)value);
        apa::ubint c;
        apa::ubint d = { 0 , value };
        apa::ubint x = { 0xfeed, 0xfaf0000beef};
        apa::ubint y = x;
        apa::ubint z;
        z = x;
        
        a.limbs[0] = value;
        a.limbs[1] = 0;
        c = a;

        if(a==b && a==c && a==d && x==y && x==z) {
            std::cout << "test 1 : PASSED\n";
            return 0;
        }
        else {
            std::cout << "test 1 : FAILED\n";
            return 0;
        }
    }
    #endif
}