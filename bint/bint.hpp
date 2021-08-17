#ifndef BINT_HPP
#define BINT_HPP

#include <iostream>
#include "limb/limb.hpp"

/// arbitrary-precision namespace
namespace arb
{
    /// arbitrary-precision type
    class bint
    {
        private:

            backend_bigint::limb intlimbs;
            short sign;

        public:

            bint();
            bint(const std::string& numbers);
            bint(const std::vector<backend_bigint::dtype>& limbs);
            bint(short number);
            bint(unsigned short number);
            bint(int number);
            bint(unsigned int number);
            bint(long number);
            bint(unsigned long number);
            bint(long long number);
            bint(unsigned long long number);
            
            std::string string_form() const;

            //// IO Operators
            friend std::ostream& operator<<(std::ostream &out, const bint &value);
            friend std::istream& operator>>(std::istream&, bint&);

            //// Comparison Operators
            bool operator< (const bint&) const;  // base comparison operator (use to create other comparison operators)
            bool operator> (const bint&) const;
            bool operator<=(const bint&) const;
            bool operator>=(const bint&) const;
            bool operator==(const bint&) const;  // base  comparison operator (use to create other comparison operators)
            bool operator!=(const bint&) const;

            template<class N>friend bool operator< (N cn, const bint& bn){return bint(cn)< bn;}
            template<class N>friend bool operator> (N cn, const bint& bn){return bint(cn)> bn;}
            template<class N>friend bool operator<=(N cn, const bint& bn){return bint(cn)<=bn;}
            template<class N>friend bool operator>=(N cn, const bint& bn){return bint(cn)>=bn;}
            template<class N>friend bool operator==(N cn, const bint& bn){return bint(cn)==bn;}
            template<class N>friend bool operator!=(N cn, const bint& bn){return bint(cn)!=bn;}

            //// Arithmetic Operators
            bint operator+(const bint&) const;
            bint operator-(const bint&) const;
            bint operator*(const bint&) const;
            bint operator/(const bint&) const;
            bint operator%(const bint&) const;

            bint& operator+=(const bint&);
            bint& operator-=(const bint&);
            bint& operator*=(const bint&);
            bint& operator/=(const bint&);

            template<class N> bint pa(N cn,bint bn)const{return bint(cn)+bn;}
            template<class N> bint ps(N cn,bint bn)const{return bint(cn)-bn;}
            template<class N> bint pm(N cn,bint bn)const{return bint(cn)*bn;}
            template<class N> bint pd(N cn,bint bn)const{return bint(cn)/bn;}
            
            template<class N>friend bint operator+(N cn,const bint& bn){bint ra=ra.pa(cn,bn);return ra;}
            template<class N>friend bint operator-(N cn,const bint& bn){bint ra=ra.ps(cn,bn);return ra;}
            template<class N>friend bint operator*(N cn,const bint& bn){bint ra=ra.pm(cn,bn);return ra;}
            template<class N>friend bint operator/(N cn,const bint& bn){bint ra=ra.pd(cn,bn);return ra;}

            //// Increment Decrement Operators
            //pre-fix and post-fix increment/decrement
            bint& operator++();
            bint& operator--();
            bint operator++(int);
            bint operator--(int);

    };// end of bint class
}// end of arb namespace

#include "bint_constructor.hpp"
#include "bint_comparison.hpp"
#include "bint_io.hpp"

#include "arithmetic/bint_addition.hpp"
#include "arithmetic/bint_subtract.hpp"
#include "arithmetic/bint_multiply.hpp"
#include "arithmetic/bint_division.hpp"
#include "arithmetic/bint_indecrement.hpp"

#endif