#include <iostream>
#include "../flimb.hpp"

using namespace backend_bigfloat;

int main()
{
    flimb::set_div_precision(3);

    flimb a("826732433683248234.763254723253467343"),
          b("77672364567672377253"),
          c("0.672346362758267723872364"),
          d("1.5"),
          e("23.0002366928323");

    flimb ta = a/a;
    flimb tb = a/b;
    flimb tc = a/c;
    flimb td = c/d;
    flimb te = d/c;
    flimb tf = e/c;

    std::cout<<"a = "<<a<<"\n";
    std::cout<<"b = "<<b<<"\n";
    std::cout<<"c = "<<c<<"\n";
    std::cout<<"d = "<<d<<"\n";
    std::cout<<"e = "<<e<<"\n";

    std::cout<<"\n\na/a = "<<ta<<"\n";
    std::cout<<"a/b = "<<tb<<"\n";
    std::cout<<"a/c = "<<tc<<"\n";
    std::cout<<"c/d = "<<td<<"\n";
    std::cout<<"d/c = "<<te<<"\n";
    std::cout<<"e/c = "<<tf<<"\n";

    if(a.string_form()!="826732433683248234.763254723253467343") throw std::logic_error("wrong values in a");
    if(b.string_form()!="77672364567672377253.0") throw std::logic_error("wrong vblues in b");
    if(c.string_form()!="0.672346362758267723872364") throw std::logic_error("wrong vclues in c");
    if(d.string_form()!="1.5") throw std::logic_error("wrong vdlues in d");
    if(e.string_form()!="23.0002366928323") throw std::logic_error("wrong values in e");

    if(ta.string_form()!="1.0") throw std::logic_error("wrong values in ta");
    if(tb.string_form()!="0.01064384273975532305903893784883160534243099188769256108917717315392727310330986") throw std::logic_error("wrong values in tb");
    if(tc.string_form()!="1229622824598350298.4040189796823293847324680265189341709837784952498547487261236647") throw std::logic_error("wrong values in tc");
    if(td.string_form()!="0.4482309085055118159149093333333333333333333333333333333333333333") throw std::logic_error("wrong values in td");
    if(te.string_form()!="2.23099295703233097659836763275866005135301416674522165638") throw std::logic_error("wrong values in te");
    if(tf.string_form()!="34.20891071452363586425598509740249031641948896234024469862") throw std::logic_error("wrong values in tf");

    std::cout<<"\n\nall answers are correct\n";

    return 0;
}