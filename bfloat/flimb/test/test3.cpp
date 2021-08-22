#include <iostream>
#include "../flimb.hpp"

using namespace backend_bigfloat;

int main()
{
    flimb a("826732433683248234.763254723253467343"),
          b("77672364567672377253"),
          c("0.672346362758267723872364"),
          d("1.5"),
          e("23.0002366928323");

    flimb ta = a+a,
          tb = a+b,
          tc = a+c,
          td = c+d,
          te = d+c,
          tf = e+c;

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

    if(a.string_form()!="826732433683248234.763254723253467343") throw std::logic_error("wrong values in a");
    if(b.string_form()!="77672364567672377253.0") throw std::logic_error("wrong vblues in b");
    if(c.string_form()!="0.672346362758267723872364") throw std::logic_error("wrong vclues in c");
    if(d.string_form()!="1.5") throw std::logic_error("wrong vdlues in d");
    if(e.string_form()!="23.0002366928323") throw std::logic_error("wrong values in e");

    if(ta.string_form()!="1653464867366496469.526509446506934686") throw std::logic_error("wrong values in ta");
    if(tb.string_form()!="78499097001355625487.763254723253467343") throw std::logic_error("wrong values in tb");
    if(tc.string_form()!="826732433683248235.435601086011735066872364") throw std::logic_error("wrong values in tc");
    if(td.string_form()!="2.172346362758267723872364") throw std::logic_error("wrong values in td");
    if(te.string_form()!="2.172346362758267723872364") throw std::logic_error("wrong values in te");
    if(tf.string_form()!="23.672583055590567723872364") throw std::logic_error("wrong values in tf");

    std::cout<<"\n\nTEST 3 - flimb : all answers are correct\n";

    return 0;
}