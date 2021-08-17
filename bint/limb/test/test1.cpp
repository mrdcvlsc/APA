#include <iostream>
#include <chrono>
#include <random>
#include <exception>
#include "../limb.hpp"

// if the two size are almost equal the fdivlong() is the fastest
// if the divisor is less than 10 limbs with the dividen fdivision() is the fastest
// if the divisor is below half of the digits of the dividen the operator/() is the fastest

// g++ test1.cpp -I"/home/lovelace/Documents/libraries/Cpp/precompiled/bignum_lin/include" -L"/home/lovelace/Documents/libraries/Cpp/precompiled/bignum_lin/lib" -lbint -o test1.o -O3 -march=native

using namespace backend_bigint;

typedef long used_type;

int main()
{
    // arithmetic operation test

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    limb a("9923948723468991236213517357657263537457235473846235465475127351283517265376152376512361253765612531316235716253"
           "3784687345634695624536985634694678346523683264723866666660000000000000000002342348672764234230472486778648712866"
           "27424837984240000000000009994237423423000000000000000000000000000000000000000000000000000000000"),
         b("7782476738873246723468236476283468273648623846826482364876234682364836762384762384682364823657348563465743658436"
           "438573686584657385634756765827638462347263847623876483647623846237467236482634876237462374636473647");

    std::cout<<"a = "<<a<<"\n\n";
    std::cout<<"b = "<<b<<"\n\n";

    std::cout<<"max limb value = "<<limb::max_value<<'\n';
    std::cout<<"limb lenght    = "<<limb::limb_length<<'\n';

    long onelimb = 9834723;
    long constmultiplier = 9737629;

    std::cout<<"\n\n-------------------------- limb operations -------------------------------\n\n";

    limb sum;
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        sum = a+b;
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a+b proccess taken "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(sum.string_form()=="9923948723468991236213517357657263537457235473846235465475127351283517265376152376512361253765612531316235724035855207607810193030690174846937741483276215152954751542900682364836762384762618917232100080771610714421523307725201111422641625634756765837632699770686847623876483647623846237467236482634876237462374636473647")
    {
        std::cout<<"\na+b is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a+b is incorrect\n");
    #endif

    limb differnce;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        differnce = a-b;
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a-b proccess taken "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(differnce.string_form()=="9923948723468991236213517357657263537457235473846235465475127351283517265376152376512361253765612531316235708470901729861316746094217222280001194186028521499990021790431317635163237615237849552502452766074483782934206434848053738253326854365243234182355775076159152376123516352376153762532763517365123762537625363526353")
    {
        std::cout<<"\na-b is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a-b is incorrect\n");
    #endif

    limb product;
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        product = a*b;
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a*b proccess taken "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(product.string_form()=="77232900098168274666793646607360996182013071348849719215575504135735107824552948733724994044464555027404117229628307111418938270391721641434472288517926842290638177422135990022435709976380528143635369429453566503768070823638332185019667470054570408858549595175707624187867062846652341900400900546538815430121485621922170156689288612653564700250343515726529925535858485058321967361791387295890136217539138827985961324229678860550520108385562372092854451794737528071920033681000000000000000000000000000000000000000000000000000000000")
    {
        std::cout<<"\na*b is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a*b is incorrect\n");
    #endif

    limb div_by_10;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        div_by_10 = a.fdiv10();
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a.fdiv10() proccess taken "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(div_by_10.string_form()=="992394872346899123621351735765726353745723547384623546547512735128351726537615237651236125376561253131623571625337846873456346956245369856346946783465236832647238666666600000000000000000023423486727642342304724867786487128662742483798424000000000000999423742342300000000000000000000000000000000000000000000000000000000")
    {
        std::cout<<"a.fdiv10() is correct\n";
    }
    else
    {
        std::cout<<"\n\na            = "<<a<<"\n";
        std::cout<<"\n div_by_10() = "<<div_by_10<<"\n";
        std::cout<<"\n div_by_10() = "<<div_by_10.string_form()<<"\n";
        std::cout<<"\n right answer= 992394872346899123621351735765726353745723547384623546547512735128351726537615237651236125376561253131623571625337846873456346956245369856346946783465236832647238666666600000002342348672764234230472486778648712866274248379842400099942374234230000000\n";
        throw std::runtime_error("ERROR wrong answer : a.fdiv10() is incorrect\n");
    }
    #endif

    limb div_by_1limb;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        div_by_1limb = a.fdiv1limb(onelimb);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a.fdiv1limb() proccess taken  : "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(div_by_1limb.string_form()=="1009072520239664221983020503745480532340080699156065246115739848624462251288231745470854771788245843966956234176944126309867951498222542573234596219400624534770566152871412850163649754039868152348294550179303194271751717998221955497677386541542654532313135552818620310912671358410399560821387648640434509441699578")
    {
        std::cout<<"a.fdiv1limb() is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a.fdiv1limb() incorrect\n");
    #endif

    limb divlong;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        divlong = a.fdivlong(b);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a.fdivlong(b) proccess taken  : "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(divlong.string_form()=="1275165870255564497664718019975789302020025029519271868382415204627447358055147684037112106489611308955843696")
    {
        std::cout<<"a.fdivlong(b) is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a.fdivlong(b) incorrect\n");
    #endif

    limb division;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        division = a.fdivision(b);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a.fdivision(b) proccess taken : "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(division.string_form()=="1275165870255564497664718019975789302020025029519271868382415204627447358055147684037112106489611308955843696")
    {
        std::cout<<"a.fdivision(b) is correct\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a.fdivision(b) incorrect\n");
    #endif

    limb bintdivision;
    std::cout<<"\n";
    for(size_t i=0; i<5; ++i){
        auto start1 = std::chrono::high_resolution_clock::now();
        bintdivision = a/b;
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"a/b proccess taken            : "<<duration1.count()<<" nanoseconds\n";
    }
    #ifndef CHECK_DISABLE
    if(bintdivision.string_form()=="1275165870255564497664718019975789302020025029519271868382415204627447358055147684037112106489611308955843696")
    {
        std::cout<<"a/b is correct\n\n";
    }
    else throw std::runtime_error("ERROR wrong answer : a/b incorrect\n");
    #endif

    size_t bloops = 5;
    while(bloops--)
    {
        auto bstart = std::chrono::high_resolution_clock::now();
        a.digit_count();
        b.digit_count();
        auto bend = std::chrono::high_resolution_clock::now();
        auto bdur = std::chrono::duration_cast<std::chrono::nanoseconds>(bend-bstart);
        std::cout<<"digit_count() proccess taken "<<bdur.count()<<" nanoseconds\n";
    }

    std::cout<<"\n\na = "<<a<<"\n";
    std::cout<<"\nb = "<<b<<"\n";

    std::cout<<"\n       a + b  = "<<sum<<"\n";
    std::cout<<"\n       a - b  = "<<differnce<<"\n";
    std::cout<<"\n       a * b  = "<<product<<"\n";
    std::cout<<"\na.fdiv10()    = "<<div_by_10<<"\n";
    std::cout<<"\na.fdiv1limb() = "<<div_by_1limb<<"\n";
    std::cout<<"\na.fdivlong()  = "<<divlong<<"\n";
    std::cout<<"\na.fdivision() = "<<division<<"\n";
    std::cout<<"\n       a / b  = "<<bintdivision<<"\n";

    return 0;
}

// arithmetic operation test

// unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    // std::mt19937_64 rand_engine(seed);
    // std::uniform_int_distribution<int> random_numberS(1,9);
    // std::uniform_int_distribution<int> random_number(0,9);
    
    // std::string num1 = std::to_string(random_numberS(rand_engine));
    // std::string num2 = std::to_string(random_numberS(rand_engine));

    // std::string bnum1 = num1;
    // std::string bnum2 = num2;

    // size_t NUM_LEN = 1000000;

    // bool testbinum1 = true, testbinum2 = true;

    // for(size_t i=0; i<NUM_LEN; ++i)
    // {
    //     int currand = random_number(rand_engine);
    //     std::string tos = std::to_string(currand);
    //     num1 = num1+tos;
    //     bnum1 = bnum1+tos;
    //     if(i/2>NUM_LEN/2 && testbinum1)
    //     {
    //         bnum1 = bnum1+".";
    //         testbinum1 = false;
    //     }
    // }

    // for(size_t i=0; i<NUM_LEN-1000; ++i)
    // {
    //     int currand = random_number(rand_engine);
    //     std::string tos = std::to_string(currand);
    //     num2 = num2+tos;
    //     bnum2 = bnum2+tos;
    //     if(i/2>(NUM_LEN-1000)/2 && testbinum2)
    //     {
    //         bnum2 = bnum2+".";
    //         testbinum2 = false;
    //     }
    // }

    // limb a(num1),
    //            b(num2);

    // bnum binta(bnum1),
    //      bintb(bnum2),
    //      bintc;