#ifndef LIMB_DIVISION_HPP
#define LIMB_DIVISION_HPP

#include <iostream>
#include "../limb.hpp"
#include "../helpers/limb_one.hpp"

namespace backend_bigint
{

/// LONG DIVISION FOR MULTI-LIMB DIVISOR

    size_t limb::digit_count() const
    {
        dtype first_index = limbs[0];
        size_t maxtotal_digit_cnt = limbs.size()*limb_length;
        maxtotal_digit_cnt-=limb_length;
        size_t front_limb_digit_cnt = 0;    

        while(first_index)
        {
            first_index/=10;
            front_limb_digit_cnt++;
        }

        return maxtotal_digit_cnt+front_limb_digit_cnt;
    }

    inline limb limb::mfind_base10(const limb& dividen, const limb& divisor)
    {
        dtype tmp_default_val = 0;
        long long int add_limb_len = dividen.limbs.size() - divisor.limbs.size();

        add_limb_len--;

        if(add_limb_len<=0)
        {
            add_limb_len = 1;
            tmp_default_val = 10;
        }

        std::vector<dtype> tmp(add_limb_len,tmp_default_val);
        tmp[0] = 1;

        limb base(tmp), quotient;

//
        while((divisor*base)<dividen)
        {
            base.fmulINT_self(10);
        }

        return base.fdiv10_self();
    }

    /// long division - turns out it is slower than my older implementation
    limb limb::fdivlong(const limb& divisor) const
    {
        // std::cout<<"fdivlong()\n";
        // division special cases
        #ifndef PRODUCTION
        if(divisor.limbs.size()==1 && divisor.limbs[0]==0)
        {
            throw std::domain_error("ERROR in fdivlong() : division by zero detected");
        }
        #endif

        int comp = compare(divisor);

        switch(comp)
        {
            case -1:
            {
                std::vector<dtype> zero;
                zero.push_back(0);
                return limb(zero);
            }
            case  0:
            {
                std::vector<dtype> one;
                one.push_back(1);
                return limb(one);
            }
        }

        if(divisor.limbs.size()==1)
        {
            return fdiv1limb(divisor.limbs[0]);
        }
        // end of special cases

        // std::cout<<"special case end\n";

        limb original_base = mfind_base10(*this,divisor); // this function can be optimized

        // std::cout<<"base found\n";

        limb current_base = original_base;
        limb quotient = original_base;
        limb partial_product;
        
        bool not_found = true;

        while(not_found)
        // here
        {
            while((partial_product = quotient*divisor)<*this)
            {
                quotient += original_base;

                if(original_base.limbs.size()==1 && original_base.limbs[0]==0)
                {
                    not_found = false;
                    break;
                }
            }

            quotient -= original_base;
            original_base.fdiv10_self();
        }

        return quotient;
    }

    inline std::pair<limb,limb> limb::fdivlong_with_remainder(const limb& divisor) const
    {
        // std::cout<<"fdivlong()\n";
        // division special cases
        #ifndef PRODUCTION
        if(divisor.limbs.size()==1 && divisor.limbs[0]==0)
        {
            throw std::domain_error("ERROR in fdivlong() : division by zero detected");
        }
        #endif

        int comp = compare(divisor);

        switch(comp)
        {
            case -1:
            {
                std::vector<dtype> zero;
                zero.push_back(0);
                return {limb(zero),*this};
            }
            case  0:
            {
                std::vector<dtype> one;
                one.push_back(1);
                return {limb(one),limb({0})};
            }
        }

        if(divisor.limbs.size()==1)
        {
            limb quotient = fdiv1limb(divisor.limbs[0]);
            limb remainder = (*this)-(quotient*divisor);
            return {quotient,remainder};
        }
        // end of special cases

        // std::cout<<"special case end\n";

        limb original_base = mfind_base10(*this,divisor); // this function can be optimized

        // std::cout<<"base found\n";

        limb current_base = original_base;
        limb quotient = original_base;
        limb partial_product;
        
        bool not_found = true;

        while(not_found)
        {
            while((partial_product = quotient*divisor)<*this)
            {
                quotient += original_base;

                if(original_base.limbs.size()==1 && original_base.limbs[0]==0)
                {
                    not_found = false;
                    break;
                }
            }

            quotient -= original_base;
            original_base.fdiv10_self();
        }

        return {quotient,*this-partial_product};
    }

    inline limb limb::fdivision(const limb& divisor) const
    {
        // division special cases
        #ifndef PRODUCTION
        if(divisor.limbs.size()==1 && divisor.limbs[0]==0)
        {
            throw std::domain_error("ERROR in fdivision() : division by zero detected");
        }
        #endif

        int comp = compare(divisor);

        switch(comp)
        {
            case -1:
            {
                std::vector<dtype> zero;
                zero.push_back(0);
                return limb(zero);
            }
            case  0:
            {
                std::vector<dtype> one;
                one.push_back(1);
                return limb(one);
            }
        }

        if(divisor.limbs.size()==1)
        {
            return fdiv1limb(divisor.limbs[0]);
        }
        // end of special cases      

        limb accumulator;
        limb remainders;

        accumulator.limbs.reserve(limbs.size());

        for(size_t i=0; i<limbs.size(); ++i)
        {
            limb partial_dividen;
            partial_dividen.limbs.reserve(remainders.limbs.size()+1);
            partial_dividen.limbs.insert(partial_dividen.limbs.end(),remainders.limbs.begin(),remainders.limbs.end());
            partial_dividen.limbs.push_back(limbs[i]);

            std::pair<limb,limb> partial_quotient = partial_dividen.fdivlong_with_remainder(divisor);

            remainders = partial_quotient.second;

            if(remainders.limbs.size()==1 && remainders.limbs[0]==0) remainders.limbs.clear();
            accumulator.limbs.insert(accumulator.limbs.end(),partial_quotient.first.limbs.begin(),partial_quotient.first.limbs.end());
        }

        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        size_t resulting_size = accumulator.limbs.size();
     
        for(size_t i=0; i<accumulator.limbs.size(); ++i){
            if(accumulator.limbs[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else
            {
                break;
            }
        }

        if(limb_to_remove) accumulator.limbs.erase(accumulator.limbs.begin()+0,accumulator.limbs.begin()+limb_to_remove);

        return accumulator;
    }

    inline limb limb::fdivdigit(const limb& divisor) const
    {
        // division special cases
        #ifndef PRODUCTION
        if(divisor.limbs.size()==1 && divisor.limbs[0]==0)
        {
            throw std::domain_error("ERROR in operator/() : division by zero detected");
        }
        #endif

        int comp = compare(divisor);

        switch(comp)
        {
            case -1:
            {
                std::vector<dtype> zero;
                zero.push_back(0);
                return limb(zero);
            }
            case  0:
            {
                std::vector<dtype> one;
                one.push_back(1);
                return limb(one);
            }
        }

        if(divisor.limbs.size()==1)
        {
            return fdiv1limb(divisor.limbs[0]);
        }
        // end of special cases

        limb_one::num arr_dividen;
        limb_one::num arr_divisor;

        arr_dividen = limb_one::create(limb_one::limb_to_str(limbs,limb_length));
        arr_divisor = limb_one::create(limb_one::limb_to_str(divisor.limbs,limb_length));

        size_t dividen_size = arr_dividen.size();

        std::string accumulator;
        limb_one::num remainders;

        accumulator.reserve(dividen_size);
        
        for(size_t i=0; i<dividen_size; ++i)
        {
            limb_one::num part_dividen;
            part_dividen.reserve(remainders.size()+1);
            part_dividen.insert(part_dividen.end(),remainders.begin(),remainders.end());
            part_dividen.push_back(arr_dividen[i]);

            int counts = 0;

            while(limb_one::is_less_equal(arr_divisor,part_dividen))
            {
                counts++;
                part_dividen = limb_one::sub(part_dividen,arr_divisor);
            }
            remainders = part_dividen;
            if(remainders.size()==1 && remainders[0]=='0') remainders.clear();
            accumulator.push_back('0'+counts);
        }
        
        // check and remove zero limbs in front
        size_t limb_to_remove = 0;
        size_t resulting_size = accumulator.size();
     
        for(size_t i=0; i<accumulator.size(); ++i)
        {
            if(accumulator[i]=='0' && resulting_size>1)
            {
                limb_to_remove++;
                resulting_size--;
            }
            else
            {
                break;
            }
        }

        if(limb_to_remove)
        {
            accumulator.erase(accumulator.begin()+0,accumulator.begin()+limb_to_remove);
        }
        
        return accumulator;
    }

    inline limb limb::operator/(const limb& divisor) const
    {
        long long limb_count_difference = limbs.size()-divisor.limbs.size();
        if(limb_count_difference<0)
        {
            return limb("0");
        }
        else if(limb_count_difference<3)
        {
            return fdivlong(divisor);
        }
        else if(limb_count_difference<7)
        {
            return fdivision(divisor);
        }
        
        return fdivdigit(divisor);
    }
}
#endif