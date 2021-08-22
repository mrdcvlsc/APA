#include <iostream>
#include "../bint.hpp"

apa::bint euclid_gcd(apa::bint a, apa::bint b)
{
    apa::bint R;
    while((a%b)>0)
    {
        R = a % b;
        a = b;
        b = R;
    }

    return b;
}

int main()
{
    apa::bint a("286428886421086240088866425686688228484884411288664422288818828"
                "806861028640866108264861826408126408126480264061284610284610284"),
              b("100020002042402640620640626460606026048284260462806806802640862"
                "806802604826482664802648620886886862486204680");

    apa::bint gcd = euclid_gcd(a,b); // 4

    std::cout<<"a = "<<a<<"\n\n";
    std::cout<<"b = "<<b<<"\n\n";
    
    apa::bint quotient = a/b,
              mod = a%b;

    std::cout<<"div = "<<quotient<<"\n\n";
    std::cout<<"mod = "<<mod<<"\n\n";
    std::cout<<"gcd of a & b = "<<gcd<<"\n";

    if(quotient.string_form()!="2863716062509747970")
    {
        throw std::logic_error("incorrect quotient");
    }

    if(mod.string_form()!="71813614982697441998600180311652992291298295699653635881012848103943170008859229727560490753702461650110684")
    {
        throw std::logic_error("incorrect mod");
    }
    
    if(gcd.string_form()!="4")
    {
        throw std::logic_error("incorrect gcd");
    }

    std::cout<<"\n\n\nTEST 4 - bint class :all outputs are correct\n\n";

    return 0;
}