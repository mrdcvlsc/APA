#include <iostream>
#include "../flimb.hpp"

using namespace backend_bigfloat;

int main()
{
    {
        flimb a("12.82"),
              b("0.6233");

        flimb c = a*b;

        std::cout<<"a = "<<a<<"\n";
        std::cout<<"b = "<<b<<"\n";
        std::cout<<"\na*b = "<<c<<"\n";

        if(c.string_form()!="7.990706") throw std::logic_error("wrong product in first example");
    }

    {
        flimb a("0.83"),
              b("1.463");

        flimb c = a*b;

        std::cout<<"\n\na = "<<a<<"\n";
        std::cout<<"b = "<<b<<"\n";
        std::cout<<"\na*b = "<<c<<"\n";

        if(c.string_form()!="1.21429") throw std::logic_error("wrong product in second example");
    }

    {
        flimb a("0.23"),
              b("99.8");

        flimb c = a*b;

        std::cout<<"\n\na = "<<a<<"\n";
        std::cout<<"b = "<<b<<"\n";
        std::cout<<"\na*b = "<<c<<"\n";

        if(c.string_form()!="22.954") throw std::logic_error("wrong product in thrid example");
    }

    std::cout<<"all output is correct\n";

    return 0;
}