#ifndef BINT_HPP
#define BINT_HPP

#include <iostream>
#include "limb/limb.hpp"

/// arbitrary-precision namespace
namespace apa
{
    #define KARATSUBA_TRESHOLD 17
    
    /// arbitrary-precision type
    class bint
    {
        private:

            short sign;

        public:

            backend_bigint::limb intlimbs;

            bint();
            bint(const std::string& numbers);
            bint(const std::vector<backend_bigint::dtype>& limbs, short signedness);
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

            // static inline bint p_add(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len);
            // static inline bint p_sub(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len);
            // static inline bint p_mul(const bint& a, const size_t a_start, const size_t a_len, const bint&b, const size_t b_start, const size_t b_len);

            bint& operator+=(const bint&);
            bint& operator-=(const bint&);
            bint& operator*=(const bint&);
            bint& operator/=(const bint&);

            // experimental
            bint karatsuba(const bint& multiplier) const;
            // bint karatsuba2(size_t a_start, size_t a_len, const bint& b, size_t b_start, size_t b_len) const;
            bint naive_mul(const bint& multiplier) const;

            static std::pair<bint,bint> div2by1(const bint& A, const bint& B);
            static std::pair<bint,bint> div3by2(const bint& a1, const bint& a2, const bint& a3, const bint& b1, const bint& b2);
            // - - - - - - -

            bint operator<<(const bint&) const;
            bint operator>>(const bint&) const;

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

            size_t limb_count() const
            {
                return intlimbs.limb_count();
            }
            
    };// end of bint class


    // CONSTANTS

    const bint BINTZERO = 0;
    const bint BINTONE = 1;
    const bint BINTTWO = 2;

    // FUNCTIONS

    bint pow(const bint& base, const bint& exponent);

}// end of arb namespace

#include "bint_constructor.cpp"
#include "bint_comparison.cpp"
#include "bint_io.cpp"
#include "bint_shifts.cpp"

#include "arithmetic/bint_addition.cpp"
#include "arithmetic/bint_subtract.cpp"
#include "arithmetic/bint_multiply.cpp"
#include "arithmetic/bint_naive_mul.cpp"
#include "arithmetic/bint_karatsuba.cpp"
#include "arithmetic/bint_karatsuba2.cpp"
#include "arithmetic/bint_division.cpp"
#include "arithmetic/bint_indecrement.cpp"

#include "functions/bint_math.cpp"

#endif