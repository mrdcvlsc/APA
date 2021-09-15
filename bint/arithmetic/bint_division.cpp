#ifndef BINT_DIVISION_HPP
#define BINT_DIVISION_HPP

#include <iostream>
#include "../bint.hpp"

namespace apa
{
    bint bint::operator/(const bint& rhs) const
    {
        bint quotient;

        bool same_sign = (this->sign==rhs.sign);

        // divisor is greater than dividen
        if(rhs.intlimbs>this->intlimbs)
        {
            quotient.intlimbs = {0};
            quotient.sign = 1;
            return quotient;
        }

        quotient.intlimbs = this->intlimbs/rhs.intlimbs;
        if(same_sign) quotient.sign = 1;
        else quotient.sign = -1;
        return quotient;
    }

    bint& bint::operator/=(const bint& rhs)
    {
        *this = *this/rhs;
        return *this;
    }

    bint bint::operator%(const bint& rhs) const
    {
        int comp = intlimbs.compare(rhs.intlimbs);

        if(*this<rhs)
        {
            return *this;
        }
        else if(*this==rhs)
        {
            return bint("0");
        }

        return *this-(rhs*(*this/rhs));
    }

    std::pair<bint,bint> bint::div2by1(const bint& A, const bint& B)
    {
        // std::cout<<"-------------- upper -----------------------\n";

        // backend_bigint::dtype
        //     a1 = A.intlimbs.limbs[0],
        //     a2 = A.intlimbs.limbs[1],
        //     a3 = A.intlimbs.limbs[2],
        //     a4 = A.intlimbs.limbs[3],
        //     b1 = B.intlimbs.limbs[0],
        //     b2 = B.intlimbs.limbs[1];
        // std::pair<bint,bint> q1R = bint::div3by2(bint(a1),bint(a2),bint(a3),bint(b1),bint(b2));
        
        size_t N = B.limb_count()/2;
        bint a1,a2,a3,a4,b1,b2;
        a1.sign = a2.sign = a3.sign = a4.sign = b1.sign = b2.sign = 1;
        a1.intlimbs.limbs.insert(a1.intlimbs.limbs.end(),A.intlimbs.limbs.begin()+(0*N),A.intlimbs.limbs.begin()+(1*N));
        a2.intlimbs.limbs.insert(a2.intlimbs.limbs.end(),A.intlimbs.limbs.begin()+(1*N),A.intlimbs.limbs.begin()+(2*N));
        a3.intlimbs.limbs.insert(a3.intlimbs.limbs.end(),A.intlimbs.limbs.begin()+(2*N),A.intlimbs.limbs.begin()+(3*N));
        a4.intlimbs.limbs.insert(a4.intlimbs.limbs.end(),A.intlimbs.limbs.begin()+(3*N),A.intlimbs.limbs.begin()+(4*N));
        b1.intlimbs.limbs.insert(b1.intlimbs.limbs.end(),B.intlimbs.limbs.begin()+(0*N),B.intlimbs.limbs.begin()+(1*N));
        b2.intlimbs.limbs.insert(b2.intlimbs.limbs.end(),B.intlimbs.limbs.begin()+(1*N),B.intlimbs.limbs.begin()+(2*N));
        std::pair<bint,bint> q1R = bint::div3by2(a1,a2,a3,b1,b2);

        // std::cout<<"upper Q = "<<q1R.first<<"\n";
        // std::cout<<"upper R = "<<q1R.second<<"\n\n";
        
        // std::cout<<"-------------- lower -----------------------\n";

        size_t RPLEN = q1R.second.limb_count()/2;
        bint Ra1, Ra2; Ra1.sign = Ra2.sign = 1;
        Ra1.intlimbs.limbs.insert(Ra1.intlimbs.limbs.end(),q1R.second.intlimbs.limbs.begin(),q1R.second.intlimbs.limbs.begin()+RPLEN);
        Ra2.intlimbs.limbs.insert(Ra2.intlimbs.limbs.end(),q1R.second.intlimbs.limbs.begin()+RPLEN,q1R.second.intlimbs.limbs.end());

        std::pair<bint,bint> q2R = bint::div3by2(Ra1,Ra2,a4,b1,b2);

        // std::cout<<"lower Q = "<<q2R.first<<"\n";
        // std::cout<<"lower R = "<<q2R.second<<"\n\n";

        std::vector<backend_bigint::dtype> Q;
        Q.insert(Q.end(),q1R.first.intlimbs.limbs.begin(),q1R.first.intlimbs.limbs.end());
        Q.insert(Q.end(),q2R.first.intlimbs.limbs.begin(),q2R.first.intlimbs.limbs.end());
        return {bint(Q,1),q2R.second};
    }

    std::pair<bint,bint> bint::div3by2(const bint& a1, const bint& a2, const bint& a3, const bint& b1, const bint& b2)
    {  
        std::cout<<"------------------------------------\n";
        std::cout<<"a1 = "<<a1<<"\n";
        std::cout<<"a2 = "<<a2<<"\n";
        std::cout<<"a3 = "<<a3<<"\n";
        std::cout<<"b1 = "<<b1<<"\n";
        std::cout<<"b2 = "<<b2<<"\n\n";

        std::vector<backend_bigint::dtype> tmpB;
        tmpB.insert(tmpB.end(),b1.intlimbs.limbs.begin(),b1.intlimbs.limbs.end());
        tmpB.insert(tmpB.end(),b2.intlimbs.limbs.begin(),b2.intlimbs.limbs.end());
        bint B(tmpB,1);

        std::vector<backend_bigint::dtype> dividen;

        dividen.insert(dividen.end(),a1.intlimbs.limbs.begin(),a1.intlimbs.limbs.end());
        dividen.insert(dividen.end(),a2.intlimbs.limbs.begin(),a2.intlimbs.limbs.end());

        bint q(dividen,1), c(dividen,1);

        // std::cout<<"q = "<<q<<"\n";
        // std::cout<<"b1 = "<<b1<<"\n\n";

        if(q.limb_count()>2)
        {
            std::pair<bint,bint> quotient_remainder = div2by1(q,b1);
            q = quotient_remainder.first;
        }
        else
        {
            q = q/b1;
        }

        c = c-(q*b1);

        bint D = q*b2;

        std::vector<backend_bigint::dtype> tmpR;
        tmpR.insert(tmpR.end(),c.intlimbs.limbs.begin(),c.intlimbs.limbs.end());
        tmpR.insert(tmpR.end(),a3.intlimbs.limbs.begin(),a3.intlimbs.limbs.end());
        bint R(tmpR,1);

        R -= D;
  
        std::cout<<"remainder?\n";
        std::cout<<"B = "<<B<<"\n";
        while(R.sign<0)
        {
            std::cout<<"q = "<<q<<"\n";
            std::cout<<"R = "<<R<<"\n";
            q--;
            R = R + B;
        }
        std::cout<<"done\n";

        // std::cout<<"q = "<<q<<"\n";
        // std::cout<<"R = "<<R<<"\n\n";

        return {q,R};
    }

    /*
        backend_bigint::dtype front_limb = B.intlimbs.limbs[0];

        size_t cnt = 0;
        size_t one_limb_value = std::pow(10,backend_bigint::limb::limb_length-1);
        while(front_limb<one_limb_value)
        {
            cnt++;
            front_limb*=10;
        }

        bint tempA = A;
        bint tempB = B;

        while(cnt--)
        {
            tempA.intlimbs.fmulINT_self(10);
            tempB.intlimbs.fmulINT_self(10);
        }

        std::cout<<"\nB     = "<<B<<"\n";
        std::cout<<"tempB = "<<tempB<<"\n\n";
    */

}

#endif