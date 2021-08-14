// Karatsuba

#include <iostream>
#include "limb.hpp"

limb<long long int> karatsuba(limb<long long int> multiplicand, limb<long long int> multiplier)
{
    size_t limb_len = multiplicand.limb_length;

    limb<long long int> product({0,0,0,0},multiplicand.max_value,multiplicand.limb_length);

    long long int
        a = multiplicand.limbs[0],
        b = multiplicand.limbs[1],
        c = multiplier.limbs[0],
        d = multiplier.limbs[1];

    std::cout<<"karatsuba\n";
    std::cout<<"a="<<a<<'\n';
    std::cout<<"b="<<b<<'\n';
    std::cout<<"c="<<c<<'\n';
    std::cout<<"d="<<d<<'\n';

    long long int
        z0 = a*c,
        z1 = b*d,
        z2 = (a+b)*(c+d);

    long long int z3 = z2 - z1 - z0;

    long long int z4 = (z0*std::pow(10,2*limb_len)) + z1 + (z3*std::pow(10,limb_len));

    std::cout<<"z0="<<z0<<'\n';
    std::cout<<"z1="<<z1<<'\n';
    std::cout<<"z2="<<z2<<'\n';
    std::cout<<"z3="<<z3<<'\n';
    std::cout<<"z4="<<z4<<'\n';

    std::cout<<"karatsuba product : "<<z4<<'\n';

    return product;
}

int main()
{
    limb<long long int>
        a("898763765651524009"),
        b("993723767265846234");

    std::cout<<"a="<<a.string_form()<<'\n';
    std::cout<<"b="<<b.string_form()<<'\n';

    std::cout<<"a*b=";
    karatsuba(a,b);

    return 0;
}