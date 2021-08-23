#ifndef BINT_KARATSUBA2_CPP
#define BINT_KARATSUBA2_CPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    // bint bint::karatsuba2(size_t a_start, size_t a_len, const bint& y, size_t y_start, size_t y_len) const
    // {
    //     // std::cout<<"\n--------------------- karatsuba call 2 ----------------------\n";
    //     // for(size_t i=a_start; i<a_start+a_len; ++i) std::cout<<intlimbs.limbs[i]<<' ';
    //     // std::cout<<"\n";
    //     // for(size_t i=y_start; i<y_start+y_len; ++i) std::cout<<y.intlimbs.limbs[i]<<' ';
    //     // std::cout<<"\n.\n";


    //     // std::cout<<"a_len = "<<a_len<<"\n";
    //     // std::cout<<"y_len = "<<y_len<<"\n";

    //     if(a_len<=KARATSUBA_TRESHOLD || y_len<=KARATSUBA_TRESHOLD)
    //     // if(a_len<=2 || y_len<=2)
    //     {
    //         // std::cout<<"wat?\n";
    //         // std::cout<<"base case return = ";
    //         // std::cout<<"excuse me?\n";
    //         // std::cout<<bint::p_mul(*this,a_start,a_len,y,y_start,y_len)<<"\n";
            
    //         // use naive at a certain treshold
    //         return bint::p_mul(*this,a_start,a_len,y,y_start,y_len);
    //     }
    //     else if(*this==BINTZERO || y==BINTZERO)
    //     {
    //         // std::cout<<"return zero\n";
    //         return BINTZERO;
    //     }
    //     else if(*this==BINTONE)
    //     {
    //         // std::cout<<"return 1\n";
    //         return y;
    //     }
    //     else if(y==BINTONE)
    //     {
    //         // std::cout<<"return 1\n";
    //         return *this;
    //     }

    //     bint z0,z1,z2,z3,z4;

    //     // std::cout<<"////\n";

    //     // ---- //

    //     size_t mcand_len = a_len;
    //     size_t mlier_len = y_len;
    //     size_t split, P;

    //     if(mcand_len==mlier_len)
    //     {
    //         // std::cout<<"equal case\n";

    //         split = mcand_len/2;
    //         P = mcand_len-split;

    //         z0 = this->karatsuba2(a_start,a_len-P,y,y_start,y_len-P);
    //         z1 = this->karatsuba2((a_start+a_len)-P,P,y,(y_start+y_len)-P,P);

    //         bint ab = bint::p_add(*this,a_start,a_len-P,*this,(a_start+a_len)-P,P);
    //         bint cd = bint::p_add(y,y_start,y_len-P,y,(y_start+y_len)-P,P);

    //         z2 = ab.karatsuba2(0,ab.limb_count(),cd,0,cd.limb_count());
    //     }
    //     else if(mcand_len>mlier_len)
    //     {
    //         // throw std::logic_error("not equal detected\n");
    //         // std::cout<<"multiplicand is longer\n";
    //         // std::cout<<"multiplicand len = "<<mcand_len<<"\n";
    //         // std::cout<<"multiplier len   = "<<mlier_len<<"\n\n";
    //         split = mcand_len/2;
    //         P = mcand_len-split;
    //         // std::cout<<"P = "<<P<<"\n";

    //         if(mlier_len>P)
    //         {
    //             z0 = this->karatsuba2(a_start,a_len-P,y,y_start,y_len-P);
    //             z1 = this->karatsuba2((a_start+a_len)-P,P,y,(y_start+y_len)-P,P);

    //             bint ab = bint::p_add(*this,a_start,a_len-P,*this,(a_start+a_len)-P,P);
    //             bint cd = bint::p_add(y,y_start,y_len-P,y,(y_start+y_len)-P,P);

    //             z2 = ab.karatsuba2(0,ab.limb_count(),cd,0,cd.limb_count());
    //         }
    //         else if(mlier_len<=P)
    //         {
    //             z0 = this->karatsuba2(a_start,a_len-P,BINTZERO,0,1);
    //             z1 = this->karatsuba2((a_start+a_len)-P,P,y,y_start,y_len);

    //             bint ab = bint::p_add(*this,a_start,a_len-P,*this,(a_start+a_len)-P,P);
    //             bint cd = bint::p_add(BINTZERO,0,1,y,y_start,y_len);

    //             z2 = ab.karatsuba2(0,ab.limb_count(),cd,0,cd.limb_count());
    //         }
    //     }
    //     else
    //     {
    //         // throw std::logic_error("not equal detected\n");
    //         // std::cout<<"multiplier is longer\n";
            
    //         split = mlier_len/2;
    //         P = mlier_len-split;

    //         if(mcand_len>P)
    //         {
    //             z0 = this->karatsuba2(a_start,a_len-P,y,y_start,y_len-P);
    //             z1 = this->karatsuba2((a_start+a_len)-P,P,y,(y_start+y_len)-P,P);

    //             bint ab = bint::p_add(*this,a_start,a_len-P,*this,(a_start+a_len)-P,P);
    //             bint cd = bint::p_add(y,y_start,y_len-P,y,(y_start+y_len)-P,P);

    //             z2 = ab.karatsuba2(0,ab.limb_count(),cd,0,cd.limb_count());
    //         }
    //         else if(mcand_len<=P)
    //         {
    //             z0 = BINTZERO.karatsuba2(0,1,y,0,y_len-P);
    //             z1 = this->karatsuba2(a_start,a_len,y,(y_start+y_len)-P,P);

    //             bint ab = bint::p_add(BINTZERO,0,1,*this,a_start,a_len);
    //             bint cd = bint::p_add(y,y_start,y_len-P,y,(y_start+y_len)-P,P);

    //             z2 = ab.karatsuba2(0,ab.limb_count(),cd,0,cd.limb_count());
    //         }
    //     }

    //     // std::cout<<"z0 = "<<z0<<"\n";
    //     // std::cout<<"z1 = "<<z1<<"\n";
    //     // std::cout<<"z2 = "<<z2<<"\n";

    //     // z0 = this->karatsuba2(0,half,y,0,half);
    //     // z1 = this->karatsuba2(half,end,y,half,end);
    //     // z2 = this->p_add(0,half,*this,half,end).karatsuba2(y.p_add(0,half,y,half,end));

    //     // z0 = a.karatsuba(c);
    //     // z1 = b.karatsuba(d);
    //     // z2 = (a+b).karatsuba(c+d);

    //     z3 = z2-z1-z0;
        
    //     for(size_t i=P; i--; )
    //     {
    //         z0.intlimbs.limbs.push_back(0);
    //         z0.intlimbs.limbs.push_back(0);
    //     }

    //     for(size_t i=P; i--; )
    //     {
    //         z3.intlimbs.limbs.push_back(0);
    //     }
        
    //     z4 = z0+z1+z3;

    //     return z4;
    // }
}

#endif