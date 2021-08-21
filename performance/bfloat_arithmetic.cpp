#include <iostream>
#include <random>
#include <chrono>
#include "../bfloat/bfloat.hpp"

int main()
{
    // apa::bfloat::set_div_precision(50);

    // unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    // std::mt19937_64 rand_engine1(seed);
    // std::mt19937_64 rand_engine2(seed+2);
    // std::uniform_int_distribution<long long> random_number(0ll,99999999ll);

    // // 200 digits === 200 digits / 8 digits limbs = 25 times of looping
    // std::vector<long long> num1, num2;
    // num1.reserve(25);
    // num2.reserve(25);
    // for(size_t i=0; i<25; ++i)
    // {
    //     num1.push_back(random_number(rand_engine2));
    //     num2.push_back(random_number(rand_engine1));
    // }

    apa::bfloat a("32750879526546289498442939676535478677728526823164537273512101804878005623761455.219020471647875776589306919899389868354445186264824254934530590825588848792333570607520036392168784858854172939754110712");
    apa::bfloat b("77481082352307402063005652609529360269636842535076451045987483604520473788200955229395842650662791449948.24018379591585585315157804386355888214387556397592430967459882849516522076089245183189476073334");

    apa::bfloat add, sub, mul, div;


    std::cout<<"a = "<<a<<"\n\n";
    std::cout<<"b = "<<b<<"\n\n\n";


    for(size_t i=6; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        add = a+b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);
        std::cout<<"add proccess taken "<<dur1.count()<<" microseconds\n";
        #endif
    }
    std::cout<<"\n\n";

    for(size_t i=6; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        sub = a-b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);
        std::cout<<"sub proccess taken "<<dur1.count()<<" microseconds\n";
        #endif
    }
    std::cout<<"\n\n";

    for(size_t i=6; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        mul = a*b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);
        std::cout<<"mul proccess taken "<<dur1.count()<<" microseconds\n";
        #endif
    }
    std::cout<<"\n\n";

    for(size_t i=6; i>0; --i)
    {
        #ifdef BENCHMARK
        auto start1 = std::chrono::high_resolution_clock::now();
        #endif
        div = a/b;
        #ifdef BENCHMARK
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);
        std::cout<<"div proccess taken "<<dur1.count()<<" microseconds\n";
        #endif
    }
    std::cout<<"\n\n";

    std::cout<<"add = "<<add<<"\n\n";
    std::cout<<"sub = "<<sub<<"\n\n";
    std::cout<<"mul = "<<mul<<"\n\n";
    std::cout<<"div = "<<div<<"\n\n";

    return 0;
}