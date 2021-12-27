#include <iostream>
#include <random>
#include <chrono>
#include "../bint/bint.hpp"

#define ITERATIONS 5

int main()
{
    apa::bint a(
        "32750879526546289498442939676535478677728526823164537273512101804878005623761455219020471"
        "64787577658930691989938986835444518626482425493453059082558884879233357060752003639216878"
        "4858854172939754110712"
    );

    apa::bint b(
        "77481082352307402063005652609529360269636842535076451045987483604520473788200955229395842"
        "65066279144994824018379591585585315157804386355888214387556397592430967459882849516522076"
        "0892451831894760733340"
    );

    apa::bint add, sub, mul, kar, div;


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
        std::cout<<"bint : add proccess taken "<<dur1.count()<<" nanoseconds\n";
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
        std::cout<<"bint : sub proccess taken "<<dur1.count()<<" nanoseconds\n";
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
        std::cout<<"bint : mul proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    for(size_t i=ITERATIONS; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        kar = a.karatsuba(b);
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
        std::cout<<"bint : kar proccess taken "<<dur1.count()<<" nanoseconds\n";
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
        std::cout<<"bint : div proccess taken "<<dur1.count()<<" nanoseconds\n";
        #endif
    }
    std::cout<<"\n";

    #ifndef BENCHMARK
    std::cout<<"add = "<<add<<"\n\n";
    std::cout<<"sub = "<<sub<<"\n\n";
    std::cout<<"mul = "<<mul<<"\n\n";
    std::cout<<"kar = "<<kar<<"\n\n";
    std::cout<<"div = "<<div<<"\n\n";
    #endif

    /* OLD BENCH:
    bint : add proccess taken    977 - 3,232  nanoseconds
    bint : sub proccess taken  1,353 - 10,537 nanoseconds
    bint : mul proccess taken 26,700 - 32,688 nanoseconds
    bint : kar proccess taken 27,389 - 27,789 nanoseconds
    bint : div proccess taken  3,295 - 5,877  nanoseconds
    */

    return 0;
}