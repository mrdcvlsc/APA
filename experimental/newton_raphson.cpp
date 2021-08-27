#include <iostream>
#include <iomanip>
#include "../bfloat/bfloat.hpp"

#define LOOPLIMIT 8

apa::bfloat newton_raphson(const apa::bfloat& a, const apa::bfloat& b)
{
    apa::bfloat xn("0.01");

    for(size_t i=0; i<LOOPLIMIT; ++i)
    {
        xn = xn*(apa::BFLOATTWO-(b*xn));
    }
    
    return xn;
}

int main()
{
    apa::bfloat::set_div_precision(10);

    apa::bfloat a("1");
    apa::bfloat b("21");

    apa::bfloat c, d;

    size_t loops = 5;
    while(loops--)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        c = a/b;
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"bfloat division proccess taken "<<dur.count()<<" microseconds\n";
        #endif
    }

    size_t loopsnew = 5;
    while(loopsnew--)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        d = newton_raphson(a,b);
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"bfloat newton proccess taken   "<<dur.count()<<" microseconds\n";
        #endif
    }

    std::cout<<"\n\na = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n\n";
    std::cout<<"c = "<<c<<"\n\nd = "<<d<<"\n";

    return 0;
}