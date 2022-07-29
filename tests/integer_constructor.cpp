#include "../core.hpp"
#include "mini-test.hpp"

int main() { START_TEST;
    
    #if defined(_BASE2_16)
    {
        std::cout << "===== Constructor Tests - Base16 =====\n";

        apa::integer x = { 0xfeed, 0xfaf, 0xbeef};
        apa::integer y = x;
        apa::integer z;
        z = x;

        ASSERT_EQUALITY(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_EQUALITY(x,z,"initialize_list<base_t> equal operator= assignment    ");
        
        // additionals

        apa::integer num1 = {
            0x0761, 0x236a, 0xfccc, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
            0x0000, 0x0000, 0xffff, 0xffff, 0xabcd, 0xefab, 0xcdef, 0xabcd, 0x1a2b, 0x3c4d, 0x5e6f,
            0x89af, 0x9999, 0x9999, 0x9999, 0x9999
        };

        apa::integer num2(
            "761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        apa::integer num3(
            "0x761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        ASSERT_EQUALITY(num1,num2, "initializer_list<base_t> equal string constructor num2");
        ASSERT_EQUALITY(num1,num3, "initializer_list<base_t> equal string constructor num3");

        RESULT("INTEGER BASE 2^16 CONSTRUCTORS");
    }
    #elif defined(_BASE2_32)
    {
        std::cout << "===== Constructor Tests - Base32 =====\n";
        
        apa::integer x = { 0xfeed, 0xfaf, 0xbeef};
        apa::integer y = x;
        apa::integer z;
        z = x;
    
        ASSERT_EQUALITY(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_EQUALITY(x,z,"initialize_list<base_t> equal operator= assignment    ");
        
        // additionals

        apa::integer num1 = {
            0x00000761, 0x236afccc, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000,
            0x00000000, 0xffffffff, 0xabcdefab, 0xcdefabcd, 0x1a2b3c4d, 0x5e6f89af,
            0x99999999, 0x99999999
        };

        apa::integer num2(
            "761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        apa::integer num3(
            "0x761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        ASSERT_EQUALITY(num1,num2, "initializer_list<base_t> equal string constructor num2");
        ASSERT_EQUALITY(num1,num3, "initializer_list<base_t> equal string constructor num3");

        RESULT("INTEGER BASE 2^32 CONSTRUCTORS");
    }
    #elif defined(_BASE2_64)
    {
        std::cout << "===== Constructor Tests - Base64 =====\n";
       
        apa::integer x = { 0xfeed, 0xfaf0000beef};
        apa::integer y = x;
        apa::integer z;
        z = x;
      
        ASSERT_EQUALITY(x,y,"initialize_list<base_t> equal copy constructor        ");
        ASSERT_EQUALITY(x,z,"initialize_list<base_t> equal operator= assignment    ");

        // additionals

        apa::integer num1 = {
                                0x00000761236afccc, 0xffffffffffffffff, 0xffffffff00000000,
            0x00000000ffffffff, 0xabcdefabcdefabcd, 0x1a2b3c4d5e6f89af, 0x9999999999999999
        };

        apa::integer num2(
            "761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        apa::integer num3(
            "0x761236afcccfff"
            "fffffffffffffffffffff0000000000"
            "000000ffffffffabcdefabcdefabcd1"
            "a2b3c4d5e6f89af9999999999999999",16
        );

        ASSERT_EQUALITY(num1,num2, "initializer_list<base_t> equal string constructor num2");
        ASSERT_EQUALITY(num1,num3, "initializer_list<base_t> equal string constructor num3");
        
        RESULT("INTEGER BASE 2^64 CONSTRUCTORS");
    }
    #endif
}