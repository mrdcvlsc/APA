#include <iostream>
#include "../limb.hpp"

using namespace backend_bigint;

int main()
{
    limb a("8879273489273498237947238947928374892374972398472384786171293761273612837612312");
    limb b("78872364762384767846872674623746867623847623846236478");

    limb asub("374892374972398472384786171293761273612837612312"); // 4 , 5
    limb bsub("78872364762384767846872674623"); // 0 , 4

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n\n";

    limb
        c = a*b,
        d = limb::p_mul(a,0,a.limb_count(),b,0,b.limb_count());

    if(c!=d) throw std::logic_error("wrong partial answer");


    limb csub = asub*bsub;
    std::cout<<"\n\nasub = "<<asub<<"\n";    
    std::cout<<"bsub = "<<bsub<<"\n";
    std::cout<<"csub = "<<csub<<"\n";

    limb cpproc = limb::p_mul(a,4,6,b,0,4);

    std::cout<<"cproc = "<<cpproc<<"\n";

    if(csub!=cpproc) throw std::logic_error("2nd partial answer is wrong");

    std::cout<<"TEST 2 - limb : CORRECT\n";

    return 0;
}