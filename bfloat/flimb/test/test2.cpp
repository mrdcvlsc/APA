#include <iostream>
#include "../flimb.hpp"

using namespace backend_bigfloat;

int main()
{
    int buff;

    flimb a("0.736473634328743");
    flimb b = 0.736473634328743;

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"a = "<<a.string_form()<<"\n";

    std::cout<<"\nb = "<<b<<"\n";
    std::cout<<"b = "<<b.string_form()<<"\n";

    buff = a.compare(b);
    std::cout<<"\ncomp a.compare(b) = "<<buff<<"\n"; // = 0
    if(buff!=0) throw std::logic_error("comparision error\n");

    b = 0.736473634328743887343877483747L;
    buff = a.compare(b);
    std::cout<<"\ncomp a.compare(b) = "<<buff<<"\n"; // = -1
    if(buff!=-1) throw std::logic_error("comparision error\n");

    buff = b.compare(a);
    std::cout<<"\ncomp b.compare(a) = "<<buff<<"\n"; // = 1
    if(buff!=1) throw std::logic_error("comparision error\n");

    a = 1.234f;
    buff = a.compare(b);
    std::cout<<"\ncomp a.compare(b) = "<<buff<<"\n"; // = 1
    if(buff!=1) throw std::logic_error("comparision error\n");

    std::cout<<"\n\na = "<<a<<"\n";
    std::cout<<"a = "<<a.string_form()<<"\n";

    std::cout<<"\nb = "<<b<<"\n";
    std::cout<<"b = "<<b.string_form()<<"\n";

    std::cout<<"\n\ncomparisions are correct\n";

    return 0;
}