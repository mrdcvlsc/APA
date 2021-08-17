#include <iostream>
#include "../flimb.hpp"

using namespace backend_bigfloat;

int main()
{
    flimb a("826248234.763254723253467343"),
          b("77672364567672377253"),
          c("0.672346362758267723872364"),
          d("1.5"),
          e("23.0002366928323");

    flimb ta = a-a,
          tb = b-a,
          tc = a-c,
          td = d-c,
          te = e-d,
          tf = e-c;

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n";
    std::cout<<"c = "<<c<<"\n";
    std::cout<<"d = "<<d<<"\n";
    std::cout<<"e = "<<e<<"\n";

    std::cout<<"\n\nta = "<<ta<<"\n";
    std::cout<<"tb = "<<tb<<"\n";
    std::cout<<"tc = "<<tc<<"\n";
    std::cout<<"td = "<<td<<"\n";
    std::cout<<"te = "<<te<<"\n";
    std::cout<<"tf = "<<tf<<"\n";

    if(a.string_form()!="826248234.763254723253467343000000") throw std::logic_error("wrong values in a");
    if(b.string_form()!="77672364567672377253.00000000") throw std::logic_error("wrong vblues in b");
    if(c.string_form()!="0.672346362758267723872364") throw std::logic_error("wrong vclues in c");
    if(d.string_form()!="1.50000000") throw std::logic_error("wrong vdlues in d");
    if(e.string_form()!="23.0002366928323000") throw std::logic_error("wrong values in e");

    if(ta.string_form()!="0.0") throw std::logic_error("wrong values in ta");
    if(tb.string_form()!="77672364566846129018.236745276746532657000000") throw std::logic_error("wrong values in tb");
    if(tc.string_form()!="826248234.090908360495199619127636") throw std::logic_error("wrong values in tc");
    if(td.string_form()!="0.827653637241732276127636") throw std::logic_error("wrong values in td");
    if(te.string_form()!="21.5002366928323000") throw std::logic_error("wrong values in te");
    if(tf.string_form()!="22.327890330074032276127636") throw std::logic_error("wrong values in tf");

    std::cout<<"\n\nall answers are correct\n";

    return 0;
}