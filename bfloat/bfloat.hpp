#ifndef BFLOAT_HPP
#define BFLOAT_HPP

#include <iostream>
#include "flimb/flimb.hpp"
#include "../bint/limb/limb.hpp"

/// arbitrary-precision namespace
namespace apa
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

            // copy constructor
            bfloat(const bfloat& other);

            // move constructor
            bfloat(bfloat&& temp) noexcept;

            // copy assignment
            bfloat& operator=(const bfloat& other);

            // move assignment
            bfloat& operator=(bfloat&& temp) noexcept;
            
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

            static void set_div_precision(size_t n)
            {
                backend_bigfloat::flimb::set_div_precision(n);
            }

    };// end of bfloat class

    // CONSTANTS

    const apa::bfloat BFLOATZERO("0.0");
    const apa::bfloat BFLOATONE("1.0");
    const apa::bfloat BFLOATTWO("2.0");

    // FUNCTIONS

    bfloat pow(const bfloat& base, const bint& exponent);

}// end of arb namespace

#include "bfloat_constructor.cpp"
#include "bfloat_comparison.cpp"
#include "bfloat_io.cpp"

#include "arithmetic/bfloat_addition.cpp"
#include "arithmetic/bfloat_subtract.cpp"
#include "arithmetic/bfloat_multiply.cpp"
#include "arithmetic/bfloat_division.cpp"
#include "arithmetic/bfloat_indecrement.cpp"

#include "functions/bfloat_math.cpp"

#endif