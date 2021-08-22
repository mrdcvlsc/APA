#include <iostream>
#include "../bfloat.hpp"

int main()
{
    apa::bfloat a("-1872389662847623.234872634876734"),
                b = -8923.23,
                c = 0.37f,
                d = 8734.000324L,
                e("0"),
                f("0.0"),
                g("0.1");

    std::cout<<"a     : "<<a<<"\n";
    if(a.string_form()!="-1872389662847623.234872634876734") throw std::logic_error("error in constructor a");
    
    std::cout<<"b     : "<<b<<"\n";
    if(b.string_form()!="-8923.23") throw std::logic_error("error in constructor b");
    
    std::cout<<"c     : "<<c<<"\n";
    if(c.string_form()!="0.37") throw std::logic_error("error in constructor c");
    
    std::cout<<"d     : "<<d<<"\n";
    if(d.string_form()!="8734.0003239999999999909618964") throw std::logic_error("error in constructor d");
    
    std::cout<<"e     : "<<e<<"\n";
    if(e.string_form()!="0.0") throw std::logic_error("error in constructor e");
    
    std::cout<<"f     : "<<f<<"\n";
    if(f.string_form()!="0.0") throw std::logic_error("error in constructor f");
    
    std::cout<<"g     : "<<g<<"\n";
    if(g.string_form()!="0.1") throw std::logic_error("error in constructor g");
    
    

    std::cout<<"\nTEST 1 - bfloat class : all constructors are correct\n";

    return 0;
}