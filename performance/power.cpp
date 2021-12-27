#include <iostream>
#include "../bfloat/bfloat.hpp"

#define ITERATIONS 10

int main()
{
    apa::bfloat b("2.2");
    apa::bint e = 321;
    apa::bfloat power;

    #ifdef BENCHMARK
    auto start1 = std::chrono::high_resolution_clock::now();
    for(size_t i=0; i<ITERATIONS; ++i)
    #endif
        power = apa::pow(b,e);
    #ifdef BENCHMARK
    auto end1 = std::chrono::high_resolution_clock::now();
    auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1);
    std::cout<< ITERATIONS <<" iterations of power toot "<<dur1.count()<<" nanoseconds\n";
    #endif

    #ifndef BENCHMARK
    std::cout<<power<<"\n";
    #endif
    
    /* output

    82733337426266713526325852808546470983403982888124144770331506094928027938777139065229084725716751315911897210.74543221264142915
    75696707119831328517886660461460858728136256844778637653193470359856043666862962857819245746193505881242508583105869039144390543
    43119594612138707164329955150317078286139488995582660335248028665245492930295727471626133973850977966242139290346266904810277993
    046638156865321497984580207663602337611169923072

    505,233 - 795,668 nanoseconds : old
    */
}