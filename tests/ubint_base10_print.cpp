#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

apa::ubint fac(size_t n) {
    apa::ubint factorial(1);
    apa::ubint iter = factorial;
    apa::ubint one = 1;

    for(size_t i=1; i<=n; ++i) {
        factorial *= iter;
        iter = iter + one;
    }

    return factorial;
}

int main() { START_TEST;

    // test variables
    apa::ubint fac246 = fac(246), fac531 = fac(531);
    std::string fac246_base10(
        "8478097477828534281623856145554841728137163300383932666143068885474833243264585597158958"
        "1923646740532744232968263007178950382481022666893846537522142147850161951901643121125830"
        "6843984600018680684699129200342991286010101141191392319487892821710751341634617090843411"
        "6647467024783403133383473092162970369088223992057355126790671309657612172941416384285875"
        "1552923051156662764134059373320637473277918272494142222867664537208750080000000000000000"
        "0000000000000000000000000000000000000000000");

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
        "000000000000000000000000000000000000000000000000000000000000000000000000000");

    ASSERT_EQUALITY(fac246.to_base10_string(),fac246_base10,"factorial(246) in base 10");
    ASSERT_EQUALITY(fac531.to_base10_string(),fac531_base10,"factorial(531) in base 10");

    #if defined(_BASE2_16)
        RESULT("UBINT BASE 2^16 Base10 Print");
    #elif defined(_BASE2_32)
        RESULT("UBINT BASE 2^32 Base10 Print");
    #elif defined(_BASE2_64)
        RESULT("UBINT BASE 2^64 Base10 Print");
    #endif
}