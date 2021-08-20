#ifndef LIMB_MULTIPLY_HPP
#define LIMB_MULTIPLY_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline dtype limb::one_thsd(dtype number, dtype tens) const
    {
        return number-(tens*(max_value+1));
    }

    inline dtype limb::ten_thsd(dtype number) const
    {
        return (dtype)std::floor((long double)number/(long double)(max_value+1));
    }

    inline limb limb::operator*(const limb& multiplier) const
    {
        // add the answer of the multiplicand and multiplier to the answer array
        size_t multiplicand_len = limbs.size();
        size_t multiplier_len = multiplier.limbs.size();

        // set all values of product to zero
        size_t product_length = multiplicand_len+multiplier_len; 
        std::vector<dtype> product_limb(product_length,0);

        // operation
        dtype ten;
        dtype one;
        for(size_t i=0; i<multiplier_len; ++i)
        {
            for(size_t j=0; j<multiplicand_len; ++j)
            {
                product_limb[product_length-1-i-j] += (limbs[multiplicand_len-1-j]*multiplier.limbs[multiplier_len-1-i]);
                
                // carry
                if(product_limb[product_length-1-i-j]>=max_value+1)
                {
                    ten = ten_thsd(product_limb[product_length-1-i-j]);
                    one = one_thsd(product_limb[product_length-1-i-j],ten);
                    product_limb[product_length-1-i-j]=one;
                    product_limb[product_length-1-i-j-1]=product_limb[product_length-1-i-j-1]+ten;
                }
            }
        }

        // // carry
        // dtype ten;
        // dtype one;
        // for(size_t i=0;i<product_length;++i) {
        //     if(product_limb[product_length-1-i]>=max_value+1) {
        //         ten = ten_thsd(product_limb[product_length-1-i]);
        //         one = one_thsd(product_limb[product_length-1-i],ten);
        //         product_limb[product_length-1-i]=one;
        //         product_limb[product_length-1-i-1]=product_limb[product_length-1-i-1]+ten;
        //     }
        // }

        // remove fron zero limbs
        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = product_length;
        for(size_t i=0; i<product_length; ++i){
            if(product_limb[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) product_limb.erase(product_limb.begin()+0,product_limb.begin()+limb_to_remove);

        return limb(product_limb);
    }

    inline limb limb::karatsuba_backend(const limb& x, const limb& y)
    {
        #ifdef DEBUG
        std::cout<<"\n--------------------- kratsuba backend called ---------------------\n";
        #endif

        if(x.limbs.size()<=2 && y.limbs.size()<=2 && x.limbs.size()==y.limbs.size())
        // if(x.limbs.size()==2 && y.limbs.size()==2)
        {
            // return x*y;
            return x*y;
        }

        bool AallZero = true;
        bool BallZero = true;

        for(size_t i=0; i<x.limbs.size(); ++i)
        {
            if(x.limbs[i]!=0)
            {
                AallZero = false;
                break;
            }
        }

        for(size_t i=0; i<y.limbs.size(); ++i)
        {
            if(y.limbs[i]!=0)
            {
                BallZero = false;
                break;
            }
        }

        if(AallZero || BallZero)
        {
            return limb("0");
        }


        limb X = x;
        limb Y = y;

        #ifdef DEBUG
        std::cout<<"\nX = "; for(auto e: X.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"Y = "; for(auto e: Y.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif

        size_t x_len = x.limbs.size();
        size_t y_len = y.limbs.size();

        #ifdef DEBUG
        std::cout<<"x_len = "<<x_len<<'\n';
        std::cout<<"y_len = "<<y_len<<'\n';
        #endif

        size_t max_len = std::max(x_len,y_len);

        if(max_len%2!=0)
        {
            max_len++;
        }

        size_t X_pad = max_len - x_len;
        size_t Y_pad = max_len - y_len;

        while(X_pad--)
        {
            X.limbs.insert(X.limbs.begin(),0);
            x_len++;
        }

        while(Y_pad--)
        {
            Y.limbs.insert(Y.limbs.begin(),0);
            y_len++;
        }

        #ifdef DEBUG
        std::cout<<"\nX = "; for(auto e: X.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"Y = "; for(auto e: Y.limbs) std::cout<<e<<' '; std::cout<<"\n";

        std::cout<<"x_len = "<<x_len<<'\n';
        std::cout<<"y_len = "<<y_len<<'\n';
        #endif

        std::vector<dtype>::const_iterator as = X.limbs.begin();
        std::vector<dtype>::const_iterator ae = X.limbs.begin()+(x_len/2);

        std::vector<dtype>::const_iterator bs = X.limbs.begin()+(x_len/2);
        std::vector<dtype>::const_iterator be = X.limbs.begin()+(x_len);

        std::vector<dtype>::const_iterator cs = Y.limbs.begin();
        std::vector<dtype>::const_iterator ce = Y.limbs.begin()+(y_len/2);

        std::vector<dtype>::const_iterator ds = Y.limbs.begin()+(y_len/2);
        std::vector<dtype>::const_iterator de = Y.limbs.begin()+(y_len);

        std::vector<dtype> av(as,ae);
        std::vector<dtype> bv(bs,be);
        std::vector<dtype> cv(cs,ce);
        std::vector<dtype> dv(ds,de);

        limb a(av);
        limb b(bv);
        limb c(cv);
        limb d(dv);

        #ifdef DEBUG
        std::cout<<"\na = "; for(auto e: a.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"b = "; for(auto e: b.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"c = "; for(auto e: c.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"d = "; for(auto e: d.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif

        limb z0 = karatsuba_backend(a,c);

        #ifdef DEBUG
        std::cout<<"z0 = "; for(auto e: z0.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif
        
        limb z1 = karatsuba_backend(b,d);

        limb apb = a+b,
             cpd = c+d;

        #ifdef DEBUG
        std::cout<<"\na+b = "; for(auto e: apb.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"c+d = "; for(auto e: cpd.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif

        limb z2 = karatsuba_backend(apb,cpd);

        std::cout<<"\n\ncomparison z2.compare(z1) result = "<<z2.compare(z1)<<'\n';

        // limb z3 = (z2 - z1) - z0;

        // #ifdef DEBUG
        // std::cout<<"z3 = "; for(auto e: z3.limbs) std::cout<<e<<' '; std::cout<<"\n";
        // #endif

        #ifdef DEBUG
        std::cout<<"z0 = "; for(auto e: z0.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"z1 = "; for(auto e: z1.limbs) std::cout<<e<<' '; std::cout<<"\n";
        std::cout<<"z2 = "; for(auto e: z2.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif

        z0.limbs.push_back(0);
        z0.limbs.push_back(0);
        // z3.limbs.push_back(0);
        
        // limb z4 = (z0+z1)+z3;
        z2.limbs.push_back(0);

        std::cout<<"limb z4 = (z0+z1)+z2;\n";
        limb z4 = (z0+z1)+z2;

        z1.limbs.push_back(0);

        std::cout<<"z4 -= z1;\n";
        z4 -= z1;

        z0.limbs.pop_back();

        std::cout<<"z4 -= z0;\n";
        z4 -= z0;

        #ifdef DEBUG
        std::cout<<"z4 = "; for(auto e: z4.limbs) std::cout<<e<<' '; std::cout<<"\n";
        #endif

        return z4;
    }

    inline limb limb::karatsuba(const limb& x, const limb& y)
    {
        limb X = x;
        limb Y = y;

        size_t x_len = x.limbs.size();
        size_t y_len = y.limbs.size();

        size_t max_len = std::max(x_len,y_len);

        if(max_len%2!=0)
        {
            max_len++;
        }

        size_t X_pad = max_len - x_len;
        size_t Y_pad = max_len - y_len;

        while(X_pad--)
        {
            X.limbs.insert(X.limbs.begin(),0);
        }

        while(Y_pad--)
        {
            Y.limbs.insert(Y.limbs.begin(),0);
        }

        return karatsuba_backend(X,Y);
    }
}

#endif