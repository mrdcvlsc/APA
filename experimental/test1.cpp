#include <iostream>
#include "../bint/bint.hpp"

int main()
{
    apa::bint a("8765463765419008376400987006735416874872782684623848236428346823643264762384623746346823648236487236472347734");
    apa::bint b("7239474798237472384878756726347236482374623742374723645726487236488623723648723648274362346832746823647236477"
                "7263423428462764823646387638764836476328746372648687234623846923649010012368123612631726371263812367263726767"
                "000000000000000000000000000000000000000000000000000000000092374723742374234000000000002374234230000000000000");
                                           //

    apa::bint k,c;

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n\n";

    k = a.karatsuba(b);
    c = a.karatsuba2(0,a.limb_count(),b,0,b.limb_count());

    std::cout<<"karatsuba = "<<k<<"\n\n";
    std::cout<<"karatsub2 = "<<c<<"\n";

    if(k!=c) throw std::logic_error("wrong answer\n");

    std::cout<<"\n\nCORRECT ANSWER\n";

    return 0;
}