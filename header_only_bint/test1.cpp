#include <iostream>
#include "bint.hpp"

// initialization, string_form(), and operator<< test

int main()
{
    arb::bint a("-28374627648723648234335683745674368999928374782364862784685637865834687648756347563845673465345742"),
              b("982738472978990000000000923498234862347626723648623746237434723746823472383643786583465734658734657"),
              c(-88267433),
              d(9398476827642l),
              e(-376786232323213ll);

    std::cout<<"a = "<<a<<"\n\n";
    std::cout<<"b = "<<b<<"\n\n";
    std::cout<<"c = "<<c<<"\n\n";
    std::cout<<"d = "<<d<<"\n\n";
    std::cout<<"e = "<<e<<"\n\n";

    if(a.string_form()!="-28374627648723648234335683745674368999928374782364862784685637865834687648756347563845673465345742")
    {
        throw std::logic_error("a's values is incorrect\n");
    }

    if(b.string_form()!="982738472978990000000000923498234862347626723648623746237434723746823472383643786583465734658734657")
    {
        throw std::logic_error("b's values is incorrect\n");
    }

    if(c.string_form()!="-88267433")
    {
        throw std::logic_error("c's values is incorrect\n");
    }

    if(d.string_form()!="9398476827642")
    {
        throw std::logic_error("d's values is incorrect\n");
    }

    if(e.string_form()!="-376786232323213")
    {
        throw std::logic_error("e's values is incorrect\n");
    }

    std::cout<<"\n\nNO ERRORS ENCOUNTERED ALL IS CORRECT\n";

    return 0;
}