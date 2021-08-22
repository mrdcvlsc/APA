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

    flimb ta = a*a,
          tb = a*b,
          tc = a*c,
          td = c*d,
          te = d*c,
          tf = e*c;

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n";
    std::cout<<"c = "<<c<<"\n";
    std::cout<<"d = "<<d<<"\n";
    std::cout<<"e = "<<e<<"\n";

    std::cout<<"\n\na*a = "<<ta<<"\n";
    std::cout<<"a*b = "<<tb<<"\n";
    std::cout<<"a*c = "<<tc<<"\n";
    std::cout<<"c*d = "<<td<<"\n";
    std::cout<<"d*c = "<<te<<"\n";
    std::cout<<"e*c = "<<tf<<"\n";

    if(a.string_form()!="826732433683248234.763254723253467343") throw std::logic_error("wrong values in a");
    if(b.string_form()!="77672364567672377253.0") throw std::logic_error("wrong vblues in b");
    if(c.string_form()!="0.672346362758267723872364") throw std::logic_error("wrong vclues in c");
    if(d.string_form()!="1.5") throw std::logic_error("wrong vdlues in d");
    if(e.string_form()!="23.0002366928323") throw std::logic_error("wrong values in e");

    if(ta.string_form()!="683486516903826440404389663015265104.421609403531571546406267671967479649") throw std::logic_error("wrong values in ta");
    if(tb.string_form()!="64214262988964283574016670920235224128.485277075811548779") throw std::logic_error("wrong values in tb");
    if(tc.string_form()!="555850544761222731.726452999454141338093269943427757774208852") throw std::logic_error("wrong values in tc");
    if(td.string_form()!="1.008519544137401585808546") throw std::logic_error("wrong values in td");
    if(te.string_form()!="1.008519544137401585808546") throw std::logic_error("wrong values in te");
    if(tf.string_form()!="15.4641254830050455066921770241588565572") throw std::logic_error("wrong values in tf");

    std::cout<<"\n\nTEST 6 - flimb : all answers are correct\n";

    return 0;
}