#include <iostream>
#include <random>
#include <chrono>
#include "../bfloat/bfloat.hpp"

#define ITERATIONS 10

int main()
{
    apa::bfloat a(
        "32750879526546289498442939676535478677728526823164537273512101804878005623761455219020471"
        "64787577658930691989938986835444518626482425493453059082558884879233357060752003639216878"
        "4858854172939754110712"
    );

    apa::bfloat b(
        "77481082352307402063005652609529360269636842535076451045987483604520473788200955229395842"
        "65066279144994824018379591585585315157804386355888214387556397592430967459882849516522076"
        "0892451831894760733340"
    );

    apa::bfloat add, sub, mul, div;


    #ifndef BENCHMARK
    std::cout<<"a = "<<a<<"\n\n";
    std::cout<<"b = "<<b<<"\n\n\n";
    #endif

    for(size_t i=ITERATIONS; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        add = a+b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"add proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    for(size_t i=ITERATIONS; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        sub = a-b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"sub proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    for(size_t i=ITERATIONS; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        mul = a*b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"mul proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    for(size_t i=ITERATIONS; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        div = a/b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"div proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    #ifndef BENCHMARK
    std::cout<<"add = "<<add<<"\n\n";
    std::cout<<"sub = "<<sub<<"\n\n";
    std::cout<<"mul = "<<mul<<"\n\n";
    std::cout<<"div = "<<div<<"\n\n";
    #endif

    /* OLD BENCH : 

    add proccess taken     849 - 10,583  nanoseconds
    sub proccess taken     912 - 2,798   nanoseconds
    mul proccess taken  24,837 - 41,792  nanoseconds
    div proccess taken 166,480 - 176,150 nanoseconds

    */

    return 0;
}