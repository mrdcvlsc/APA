#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../core.hpp"
#else
#include <bint.hpp>
#endif

#include "mini-test.hpp"

int main() { START_TEST;

    // test variables
    apa::bint num1("182379807482704987138971389471980478123748657105182347086873",16);
    apa::bint num2("-abcdeffedabbdeffccfeddeccddeeeeeffffeeeeeccffeeeeeeeeeeeeefffeddaaacccccccddfabcdef",16);
    apa::bint num3 = -num1;

    apa::bint num4(
        "a1b2c3d4e5f60007700000000000000000000000000000000000000000"
        "000000000fffffffffffffffffffffffffffffffffffffffffffffffff"
    ,16);

    apa::bint num5(
        // negative sign
        "-fffffffffffffffffffffffffffff0000000000000000"
        "00000000000000000000000000000000000fffffffffff"
    ,16);

    apa::bint num6(
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"  
        ,16
    );

    // correct answers
    std::string num1num2_C =
        "-10331d323ff1d4166e6f2d589f7f53154b22284bdeeffee637515175be13860f93a4f92"
        "bbb50c459d91fd101a870a7e46f51822ab5431928ea7365e7cd1c9cae721d681fe4e9a5d";

    std::string num1num3_C =
        "-246abb288a2ff50830adc8d395f164e132c16b9b6bfc82f6ec8d6ff744abe62bf8aaea7"
        "ea3d6a437b0715cefc599b50ed29ef75ae15c9a87bcda3a9";

    apa::bint num4num5_C(
        "-a1b2c3d4e5f600076ffffffffffff5e4d3c2b1a09fff89000000000000000000001000000"
        "0000000a1b2c3d4e5ebe4da32b1a09fff88ffffffff0000000000000000000000000000100"
        "ffffffffffeffffffffffffffffffffffffffffffffffffff00000000001",16
    );

    apa::bint num6_one_C(
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",16
    );

    apa::bint num1_M_NEGATIVE_num6_C(
        "-182379807482704987138971389471980478123748657105182347086872fffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe7dc867f8b7d8fb678ec76"
        "8ec76b8e67fb87edc8b79a8efae7dcb8f7978d",16
    );

    apa::bint num7(
        "fabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcde"
        "987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210"
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "1111111111111111111111eeeeeeeeeeeeeeeeeeaaaaaaaaaaaaaaaa7777777777777777777777777777777777"
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccc"
        "122333444455555666666777777788888888999999999000000000000000000000000000000000000000000000"
        "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
        "abcdef1234567890fedcba09876543210abcdef1234567890fedcba09876543210abcdef1234567890fedcba09",
        apa::HEX
    );

    apa::bint num8(
        "991ab2c6eff89ffeef8715ecbadd21007ab756dffbeff6251aee00019918f8a98d8e9eef77bbeed76aab6c45c9"
        "aaa7a7f7bcd512def27abfe56fe89bcd3da2a4d5e7f8c7b000f8f9e019aaabbbcccdddeeefff00000000000000"
        "00000000000000009918f0a80a09f7f7f6f5f4f3f2f1f2f3f4f5f6f7f8f9f0c7c7c7c7cc6c8c8c4c1c2c3c4c5c"
        "a7c789ac7ac98c7a8c7c8f9c8f7a9c8f7a8c9f87c7c7f89f8c7a8f8f8ff7c8887f9a99c8f7a9c8f7c8a9f8f7f8"
        "bd5e6dbe5d44d5e4d5ebd6ebd5e4db7d7d6e6d5ebd5dbbe5d4ebdbd666e5dbe88ebdbd6ee5deff5f4dbbedbd6e"
        "009109871787401874872983437563456437568672163712638716238162387673954658465784658745647572"
        "877981797782783151235123767368712637812639128371293871897482374823804000420000000000000000"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        apa::HEX
    );

    apa::bint num7num8_C(
        "95f5078cac81179a90f880e565d95c10502ba435b17fccc496cd24bac1d4eeb1ad52f661939380aa50fd36714f"
        "10f0d5b2f0b8366dd6f4db77a41733c70f0c1215b49df0b37773056b1b2bd5c2e9164c3736ae75f54063b54f37"
        "0001d8c2dc473a6d8e58bdab956d6a4cc5926ba69b753fc69cbc7f0260540d7821d7007e281d8d545a74c0ac5e"
        "d7fc22d8abf3fd41232fbb3be42de61a8195cf7ac2727e73bfff8db602dcb45a1f4091987bf67fb131e2a9014a"
        "53630b8b621ca430fdc21c801b0e7286b9dca4b379bc0b1b58bd943ddc2e5484f34454e0e0eaa9b4775330c160"
        "b2ca277303c007a80aa835a193c6f400684f8bc95942edd001818046884926ec3c5b401dc07642f96f835a3b6b"
        "3b0915f664d25d5e09b0b26150bb8a1902ab2f7de4777319ca8d8b156fb0d1829bf1cf714da19687b4a7ca4a8c"
        "b008af592c30f1f2635429e7b0f572aaa2990503f40d18eff1116697e6792987e6b4ba81e0656bc0149b144093"
        "64807c01a6d48f2b49b776aba77942bd8d41cc7997943d766813a43cfbdf83412c09c2cf1e9289c45313efa88e"
        "c7209d833fad568e8ef5c6f1745cd2fdcda32f51895a77892ed0f2a510cc4c86e6293fc7dc251804c3fbb83885"
        "e2020e259c4ab90069c3fd1c99847997e4cfba7812053f645a5cec99752a9552cbe587c9b509a5e8b956cc03d6"
        "4d2a2eec3e2f030312e917248b87eebd29307633728c6a78b56e89055fa191fffab98a7987f68e9c1e72e0210d"
        "67afcb9bf124109fbe6887f7594a8c014b63240b2cc718e610d90832633485be2cda1b9345d1f043bd874af360"
        "36ef37435e31fb081f91d34c751c3f6eb9e7f9ca98cfdd020ad4ac45443fb76e500ce114f0cc5b1a35e7688eda"
        "820440507f98cef50d036ad80575ef0ab2daf0844c395be96ea78e534eebc487a6bc78f3660576c1076bd7c39a"
        "67cad4774034f890aa52ccdd20837bab98088d6a5f0757be3782435f9f6ca653a251e1466f950c8066bb5aa436"
        "27104e8d815ff3d9dc642bced6a930f8cf3dd1c04ee2cc0a753d0f89ba4209dc59c0b492d1baf9981e209dc572"
        "543210edcba9876f012345f6789abcdef543210edcba9876f012345f6789abcdef543210edcba9876f012345f7",
        apa::HEX
    );

    // solution
    apa::bint num1num2 = num1 * num2;
    apa::bint num2num1 = num2 * num1;
    apa::bint num1num3 = num1 * num3;
    apa::bint num3num1 = num3 * num1;
    apa::bint num4num5 = num4 * num5;
    apa::bint num5num4 = num5 * num4;
    apa::bint num6_one = num6 * apa::__BINT_ONE;
    apa::bint num1_P_NEGATIVE_num1 = num1 * (-num6);
    apa::bint num1zero = num1 * apa::__BINT_ZERO;
    apa::bint zeronum1 = apa::__BINT_ZERO * num1;
    apa::bint num2zero = num2 * apa::__BINT_ZERO;
    apa::bint zeronum2 = apa::__BINT_ZERO * num2;
    apa::bint num7num8 = num7 * num8;
    apa::bint num8num7 = num8 * num7;

    // checks
    ASSERT_EQUALITY(num1num2.to_base16_string(),num1num2_C,"num1 * num2 ");
    ASSERT_EQUALITY(num2num1.to_base16_string(),num1num2_C,"num2 * num1 ");
    ASSERT_EQUALITY(num1num3.to_base16_string(),num1num3_C,"num1 * num3 ");
    ASSERT_EQUALITY(num3num1.to_base16_string(),num1num3_C,"num3 * num1 ");
    ASSERT_EQUALITY(num4num5,num4num5_C,                   "num4 * num5 ");
    ASSERT_EQUALITY(num5num4,num4num5_C,                   "num5 * num4 ");
    ASSERT_EQUALITY(num6_one,num6_one_C,                   "num6 * one  ");
    ASSERT_EQUALITY(
        num1_P_NEGATIVE_num1,num1_M_NEGATIVE_num6_C,       "num1*(-num6)");
    ASSERT_EQUALITY(num1zero,apa::__BINT_ZERO,             "num1 * zero ");
    ASSERT_EQUALITY(zeronum1,apa::__BINT_ZERO,             "zero * num1 ");
    ASSERT_EQUALITY(num2zero,apa::__BINT_ZERO,             "num2 * zero ");
    ASSERT_EQUALITY(zeronum2,apa::__BINT_ZERO,             "zero * num2 ");
    ASSERT_EQUALITY(num7num8,num7num8_C,                   "num7 * num8 ");
    ASSERT_EQUALITY(num8num7,num7num8_C,                   "num8 * num7 ");

    std::cout << "karatsuba size treshold : " << apa::KARATSUBA_SIZE << "\n\n";

    std::cout << "\nnum4num5 = " << num4num5 << "\n\n";
    std::cout << "\nnum5num4 = " << num5num4 << "\n\n";
    std::cout << "\nnum4num5_C = " << num4num5_C << "\n\n";

    #if defined(_BASE2_16)
        RESULT("BINT BASE 2^16 MULTIPLICATION");
    #elif defined(_BASE2_32)
        RESULT("BINT BASE 2^32 MULTIPLICATION");
    #elif defined(_BASE2_64)
        RESULT("BINT BASE 2^64 MULTIPLICATION");
    #endif
}