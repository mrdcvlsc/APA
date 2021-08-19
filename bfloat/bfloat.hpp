#ifndef BFLOAT_HPP
#define BFLOAT_HPP

#include <iostream>
#include "flimb/flimb.hpp"
#include "../bint/limb/limb.hpp"

/// arbitrary-precision namespace
namespace arb
{
    /// arbitrary-precision type
    class bfloat
    {
        private:

            backend_bigfloat::flimb floatlimbs;
            short sign;

        public:

            bfloat();
            bfloat(const std::string& numbers);
            bfloat(const std::vector<backend_bigint::dtype>& flimbs, size_t decimal_point);
            bfloat(float number);
            bfloat(double number);
            bfloat(long double number);
            
            std::string string_form() const;

            //// IO Operators
            friend std::ostream& operator<<(std::ostream &out, const bfloat &value);
            friend std::istream& operator>>(std::istream&, bfloat&);

            //// Comparison Operators
            bool operator< (const bfloat&) const;  // base comparison operator (use to create other comparison operators)
            bool operator> (const bfloat&) const;
            bool operator<=(const bfloat&) const;
            bool operator>=(const bfloat&) const;
            bool operator==(const bfloat&) const;  // base  comparison operator (use to create other comparison operators)
            bool operator!=(const bfloat&) const;

            template<class N>friend bool operator< (N cn, const bfloat& bn){return bfloat(cn)< bn;}
            template<class N>friend bool operator> (N cn, const bfloat& bn){return bfloat(cn)> bn;}
            template<class N>friend bool operator<=(N cn, const bfloat& bn){return bfloat(cn)<=bn;}
            template<class N>friend bool operator>=(N cn, const bfloat& bn){return bfloat(cn)>=bn;}
            template<class N>friend bool operator==(N cn, const bfloat& bn){return bfloat(cn)==bn;}
            template<class N>friend bool operator!=(N cn, const bfloat& bn){return bfloat(cn)!=bn;}

            //// Arithmetic Operators
            bfloat operator+(const bfloat&) const;
            bfloat operator-(const bfloat&) const;
            bfloat operator*(const bfloat&) const;
            bfloat operator/(const bfloat&) const;
            bfloat operator%(const bfloat&) const;

            bfloat& operator+=(const bfloat&);
            bfloat& operator-=(const bfloat&);
            bfloat& operator*=(const bfloat&);
            bfloat& operator/=(const bfloat&);

            template<class N> bfloat pa(N cn,bfloat bn)const{return bfloat(cn)+bn;}
            template<class N> bfloat ps(N cn,bfloat bn)const{return bfloat(cn)-bn;}
            template<class N> bfloat pm(N cn,bfloat bn)const{return bfloat(cn)*bn;}
            template<class N> bfloat pd(N cn,bfloat bn)const{return bfloat(cn)/bn;}
            
            template<class N>friend bfloat operator+(N cn,const bfloat& bn){bfloat ra=ra.pa(cn,bn);return ra;}
            template<class N>friend bfloat operator-(N cn,const bfloat& bn){bfloat ra=ra.ps(cn,bn);return ra;}
            template<class N>friend bfloat operator*(N cn,const bfloat& bn){bfloat ra=ra.pm(cn,bn);return ra;}
            template<class N>friend bfloat operator/(N cn,const bfloat& bn){bfloat ra=ra.pd(cn,bn);return ra;}

            //// Increment Decrement Operators
            //pre-fix and post-fix increment/decrement
            bfloat& operator++();
            bfloat& operator--();
            bfloat operator++(int);
            bfloat operator--(int);

    };// end of bfloat class
}// end of arb namespace

#include "bfloat_constructor.hpp"
#include "bfloat_comparison.hpp"
#include "bfloat_io.hpp"

#include "arithmetic/bfloat_addition.hpp"
#include "arithmetic/bfloat_subtract.hpp"
#include "arithmetic/bfloat_multiply.hpp"
#include "arithmetic/bfloat_division.hpp"
#include "arithmetic/bfloat_indecrement.hpp"

#endif