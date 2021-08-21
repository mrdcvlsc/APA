#include <iostream>
#include <random>
#include "../bint/bint.hpp"

int main()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_engine(seed);
    std::uniform_int_distribution<long long> random_number(0,99999999);

    size_t digits = 20000;
    size_t numlimb = digits/8;

    std::vector<long long> num1, num2;
    num1.reserve(numlimb);
    num2.reserve(numlimb);

    size_t f = numlimb;
    while(f--)
    {
        num1.push_back(random_number(rand_engine));
        num1.push_back(random_number(rand_engine));
        num2.push_back(random_number(rand_engine));
    }

    apa::bint
        a(num1,1),
        b(num2,1),
        c, k, m;


    std::cout<<"benchmark started\n";

    size_t L = 5;

    for(size_t i=L; i--;)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        c=a.naive_mul(b);
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"naive     proccess taken "<<dur.count()<<" microseconds\n";
        #endif
    }
    std::cout<<"\n";

    for(size_t i=L; i--;)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        k=a.karatsuba(b);
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"karatsuba proccess taken "<<dur.count()<<" microseconds\n";
        #endif
    }

    std::cout<<"\n";

    for(size_t i=L; i--;)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        m=a*b;
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"optimized proccess taken "<<dur.count()<<" microseconds\n";
        #endif
    }

    // std::cout<<"\n\na = "<<a<<"\n";
    // std::cout<<"b = "<<b<<"\n\n";
    // std::cout<<"c = "<<c<<"\n";
    // std::cout<<"k = "<<k<<"\n";
    if(k!=c) throw std::logic_error("wrong karatsuba product\n");
    if(m!=c) throw std::logic_error("wrong karatsuba product\n");
    if(k!=m) throw std::logic_error("wrong karatsuba product\n");
    
    std::cout<<"correct answer\n";

    return 0;
}