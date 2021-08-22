#include <iostream>
#include <chrono>
#include "../flimb.hpp"

using namespace backend_bigfloat;

/*

-D flag

FAST_FLOAT_CONSTRUCTOR - disables flimb constructor's higher precision assignment of values when,
                         constructing from floating-point types to increase speed, but will result
                         to a much lower accuracy of values

*/

int main()
{
    flimb a;

    size_t loops = 10;
    while(loops--)
    {
        #ifdef BENCHMARK
        auto start = std::chrono::high_resolution_clock::now();
        #endif
        a = 0.892374982388734873L;
        #ifdef BENCHMARK
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        std::cout<<"proccess taken "<<dur.count()<<" nanoseconds\n";
        #endif
    }
    
    flimb b("892784723462347234324234.27656757600000002394");
    flimb c("0.78126");

    std::cout<<"a = \n";
    std::cout<<a<<"\n";
    std::cout<<a.string_form()<<"\n\n";

    std::cout<<"b = \n";
    std::cout<<b<<"\n";
    std::cout<<b.string_form()<<"\n\n";

    std::cout<<"c = \n";
    std::cout<<c<<"\n";
    std::cout<<c.string_form()<<"\n\nTEST 1 - flimb : ";

    

    return 0;
}