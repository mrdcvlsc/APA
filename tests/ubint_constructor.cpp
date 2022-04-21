#include "../ubint.hpp"
#include "mini-test.hpp"

// #define _BASE2_64

int main() { START_TEST;
    
    #if defined(_BASE2_16)
    {
        std::cout << "===== Constructor Tests - Base16 =====\n";

        apa::ubint a;
        apa::ubint b(0x61aff37a);
        apa::ubint c;
        apa::ubint d = { 0xfedc, 0xab87, 0x61af, 0xf37a };
        apa::ubint x = { 0xfeed, 0xfaf, 0xbeef};
        apa::ubint y = x;
        apa::ubint z;
        z = x;

        b.length=4;
        b.limbs[2] = 0xab87;
        b.limbs[3] = 0xfedc;
        
        a.limbs[0] = 0xf37a;
        a.limbs[1] = 0x61af;
        a.limbs[2] = 0xab87;
        a.limbs[3] = 0xfedc;
        a.length = 4;

        c = a;

        ASSERT_UBINT(a,b,"manual-limb-assignments equal limb_t constructor      ");
        ASSERT_UBINT(a,c,"manual-limb-assignments equal operator= assignment    ");
        ASSERT_UBINT(a,d,"manual-limb-assignments equal initialize_list<base_t> ");
        ASSERT_UBINT(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_UBINT(x,z,"initialize_list<base_t> equal operator= assignment    ");
        
        RESULT("UBINT BASE 2^16 CONSTRUCTORS");
    }
    #elif defined(_BASE2_32)
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

        ASSERT_UBINT(a,b,"manual-limb-assignments equal limb_t constructor      ");
        ASSERT_UBINT(a,c,"manual-limb-assignments equal operator= assignment    ");
        ASSERT_UBINT(a,d,"manual-limb-assignments equal initialize_list<base_t> ");
        ASSERT_UBINT(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_UBINT(x,z,"initialize_list<base_t> equal operator= assignment    ");
        
        RESULT("UBINT BASE 2^32 CONSTRUCTORS");
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

        ASSERT_UBINT(a,b,"manual-limb-assignments equal limb_t constructor      ");
        ASSERT_UBINT(a,c,"manual-limb-assignments equal operator= assignment    ");
        ASSERT_UBINT(a,d,"manual-limb-assignments equal initialize_list<base_t> ");
        ASSERT_UBINT(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_UBINT(x,z,"initialize_list<base_t> equal operator= assignment    ");
        
        RESULT("UBINT BASE 2^64 CONSTRUCTORS");
    }
    #endif
}