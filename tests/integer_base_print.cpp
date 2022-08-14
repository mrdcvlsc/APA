#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
    #include "../core.hpp"
#else
    #include <integer.hpp>
#endif

#include "mini-test.hpp"

apa::integer fac(size_t n) {
    apa::integer factorial(1);
    apa::integer iter = factorial;

    for (size_t i = 1; i <= n; ++i) {
        factorial *= iter;
        iter++;
    }

    return factorial;
}

int main() {
    START_TEST;

    // test variables

    apa::integer zero = 0;
    std::string zero_str = "0";

    apa::integer fac246 = fac(246), fac531 = fac(531);

    std::string fac246_base10(
        "8478097477828534281623856145554841728137163300383932666143068885474833243264585597158958"
        "1923646740532744232968263007178950382481022666893846537522142147850161951901643121125830"
        "6843984600018680684699129200342991286010101141191392319487892821710751341634617090843411"
        "6647467024783403133383473092162970369088223992057355126790671309657612172941416384285875"
        "1552923051156662764134059373320637473277918272494142222867664537208750080000000000000000"
        "0000000000000000000000000000000000000000000"
    );

    std::string fac531_base10(
        "1501502829857694554256081515897044819321219706314646909443769783106149612080281449756595"
        "6437767369719977629432786070105768095750435305550855613767967150445096008648547124344604"
        "3068616988014865602340341053872072940557114514884277181836080195915779266963156856904682"
        "2966327370414656696706602597932734542608722194129650258442856038867571509088897710246259"
        "7859769734628678945218577160381786243877910873734207044229451861666254757445006447208363"
        "7290284049798149180182748542841827732901886878520074660767944664430933694144688782973281"
        "8275163399024599093348145009249088293898913756266466923503914248067207671238533534311905"
        "6264409995171246426774053296184191003989818724853004015523089290024077311123449626233798"
        "9502554440906233431894271840844627273170914683849185271292927638237892369345171350344348"
        "6459567397807653050166888113472017262884860367241141668018686981076941220803431100415957"
        "1133139590436110062451513142745577703823417877427560230984390974467062660363906544541062"
        "9859723673072443013271548590525167725752466877753868330589638531664462889626174782538764"
        "2789877564214044648610492265267200000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000000000000000000000000000000000000000000000"
    );

    std::string fac246_base16(
        "13116905ffa446bf668c5de5019ae55b1d6d502b3b1372a4a7a9566c67c860ad93ff973c09228e7a36e15bea"
        "af596e8613d7ddc2ad41d9f3ee68dd09cab22752c3252634a71eefb4065ef0e8c258eec1c38c9c09d345d972"
        "60b93180e5a27043f5c674575611f0b28aad60586f800f4d1425ce0df6b8b5dd6e4b39e0ad62fd85aea6705f"
        "8db952c3582cff0b3006b8baa3fac50c7ef5f146a88e8f8792eb09063578cf8ca797f5b9fd2df70000000000"
        "00000000000000000000000000000000000000000000000000"
    );

    std::string fac531_base16(
        "67989e2c857298226ef0d9e4968a084c12b117bfa96c746387c5d38a371603b45fac676e06860341bb96221eb"
        "175fb6ded6c2df2d734e13b3da682c02e7e75cc71fe8400e94e70d4162701c6a1281274fc30052deb32497693"
        "efc00f35ab77d13a024e6e65f4e9154f554b6abed12c75d7eb70f1e31e862c3a40d0ed928cd49ac02c208f96b"
        "54726766d899446061773c27b32de9bb2a1b3dc87d1c28c431774f2096876090b1193d12bfb1be9945300c464"
        "783242ca3555259004ffef9f4aad8eb43e35d919f5d500db604b7ebe33767911ae62bdcacf693972e516dd5e3"
        "04c84530628bc1e683cde0381a43dde6501d8edae27e4f2058ab457ea93ed781f730b35dc5a97aad854362ae2"
        "d0f1aab99f54e78196cfc4e92ea0e9d62df0a51ae56513c29e1cc76a8bcc48b27b8f5908dab79efbd04567573"
        "ccdb0ae1d971627dc8a5802068241d75baf811c4e3e268efa650e05130662e6b68d02547705a1d0fad27791c7"
        "8b51cc38e9c71aaac006033b2112a9f0886175bd510c43f87f99d3f69e3dc670af195377166209e1e178a087e"
        "ec98488476f18050a61f0cc8a98a17c67f9bc8239052e99a3e0b349ef65b9df0b499e10fa5720418000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000000000000000000000000"
    );

    ASSERT_EQUALITY(zero.to_base10_string(), zero_str, "integer zero in base 10    ");
    ASSERT_EQUALITY(zero.to_base16_string(), zero_str, "integer zero in base 16    ");
    ASSERT_EQUALITY(fac246.to_base10_string(), fac246_base10, "factorial(246) in base 10");
    ASSERT_EQUALITY(fac531.to_base10_string(), fac531_base10, "factorial(531) in base 10");
    ASSERT_EQUALITY(fac246.to_base16_string(), fac246_base16, "factorial(246) in base 16");
    ASSERT_EQUALITY(fac531.to_base16_string(), fac531_base16, "factorial(531) in base 16");

#if defined(_BASE2_16)
    RESULT("INTEGER BASE 2^16 Base10 Print");
#elif defined(_BASE2_32)
    RESULT("INTEGER BASE 2^32 Base10 Print");
#elif defined(_BASE2_64)
    RESULT("INTEGER BASE 2^64 Base10 Print");
#endif
}