#include <iostream>
#include "../bint.hpp"

#define LOOPS 5

int main()
{
    // apa::bint A("98727367873654428774653499876542"),
    //           B("5677652388765473");


    // apa::bint A("9872736787365442877465349987654298727367877653434344323498727367"),
    //           B("40000000000000000000000000000000");
    
    apa::bint A("87267623100128736781087365310424732505713648701513058176057107348726762310012873678108736531042473250571364870151305817605710734"),
              B("398160746366014021036812603877233981607463660140210368126023");

    // apa::bint A("7829374893729847878941120312904936275603650761785608136247761230467213648740621864360468763107462375623895710947192740175809139048617263017407264892141603128937642347237846287327468264268462746467234");
    // apa::bint B("2317616657261537651276351292040132413041602460162376136017360126016247180174612764803647767324");


    apa::bint C;

    std::pair<apa::bint,apa::bint> QR;
    
    std::cout<<"long division\n";
    for(size_t i=LOOPS; i--;)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        C = A/B;
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"proccess taken "<<dur.count()<<" microseconds\n";
        #endif  
    }

    std::cout<<"\n\ndivide and conqure division\n";
    for(size_t i=LOOPS; i--;)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        // QR = apa::bint::div2by1(A,B); // EXPERIMENTAL
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout<<"proccess taken "<<dur.count()<<" microseconds\n";
        #endif  
    }

    std::cout<<"A = "<<A<<"\n\n";
    std::cout<<"B = "<<B<<"\n\n";

    std::cout<<"A/B = "<<C<<"\n\n";
    std::cout<<"A/B = "<<QR.first<<"\n\n";
    

    return 0;
}