#ifndef LIMB_HPP
#define LIMB_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <chrono>
#include <exception>
#include <string>
#include <utility>

// -DPRODUCTION - disables the internal checking for limb arithmetics

namespace backend_bigint
{
    typedef long long int dtype;

    static size_t SET_LIMB_LENGTH()
    {
        dtype type_limit = std::numeric_limits<dtype>::max();
        std::string tmp = std::to_string(type_limit);
        size_t limb_length = tmp.size()/2;
        limb_length--;
        return limb_length;
    }

    static dtype SET_LIMB_MAX_VALUE()
    {
        dtype type_limit = std::numeric_limits<dtype>::max();
        std::string tmp = std::to_string(type_limit);
        size_t limb_length = tmp.size()/2;
        limb_length--;
        dtype max_value = 1;
        for(size_t i=1; i<=limb_length; ++i)
        {
            max_value*=10;
        }
        max_value--;
        return max_value;
    }

    class limb
    {
        private:

            inline void check(const std::string &value);

        protected:

            inline std::vector<dtype> str_part_by(const std::string& number);
            inline dtype one_thsd(dtype number, dtype tens) const;
            inline dtype ten_thsd(dtype number) const;
            inline std::string removeFrontZeros(const std::string& str) const;
            static inline limb mfind_base10(const limb& dividen, const limb& divisor);

        public:

            /// limbs - used as the representation of big integers
            std::vector<dtype> limbs;

            /// the maximum possible value a single limb can hold
            static dtype max_value;

            /// the maximum possible number of digits that can fit in a single limb
            static size_t limb_length;

            /// @returns the numbers of existing limbs in the big integer instance
            size_t limb_count() const { return limbs.size(); }

            /// this limb constructor should accept a string without it's signed symbol,
            /// the signed symbol should be addressed to the big integer class and,
            /// should be removed before passing the string into any limb constructors
            limb();
            limb(const std::string& number);
            limb(const std::vector<dtype>& limbs) : limbs(limbs) {}

            // special constructors and operators - start

            // copy constructor
            limb(const limb& other);

            // move constructor
            limb(limb&& temp) noexcept;

            // copy assignment
            limb& operator=(const limb& other);

            // move assignment
            limb& operator=(limb&& temp) noexcept;

            // special constructors and operators - end
            friend std::ostream& operator<<(std::ostream &out, const limb& value);
            friend std::istream& operator>>(std::istream& in, limb& value);
            
            /// this limb constructor should accept a possitive integers only,
            /// the signedes of the number should be addressed to the big integer class,
            /// use std::abs() before passing the number into any limb constructor
            limb(short number);
            limb(unsigned short number);
            limb(int number);
            limb(unsigned int number);
            limb(long number);
            limb(unsigned long number);
            limb(long long number);
            limb(unsigned long long number);

            std::string string_form() const;

            inline limb operator+(const limb& lower_adden) const;
            inline limb& operator+=(const limb& lower_adden);

            inline limb operator-(const limb& subtrahend) const;
            inline limb& operator-=(const limb& subtrahend);
            
            inline limb operator*(const limb& multiplier) const;
            
            // static inline limb p_add(const limb& a, const size_t a_start, const size_t a_len, const limb&b, const size_t b_start, const size_t b_len);
            // static inline limb p_sub(const limb& a, const size_t a_start, const size_t a_len, const limb&b, const size_t b_start, const size_t b_len);
            // static inline limb p_mul(const limb& a, const size_t a_start, const size_t a_len, const limb&b, const size_t b_start, const size_t b_len);

            inline limb operator/(const limb& divisor) const;

            inline limb& fmulINT_self(dtype constant);
            inline limb fmulINT(dtype constant) const;

            inline limb& fdiv10_self();
            inline limb fdiv10() const;
            inline limb fdiv1limb(dtype single_limb_divisor) const;
            inline limb fdivlong(const limb& multiple_limbed) const;
            inline std::pair<limb,limb> fdivlong_with_remainder(const limb& multiple_limbed) const;
            inline limb fdivdigit(const limb& divisor) const;
            inline limb fdivision(const limb& divisor) const;

            size_t digit_count() const;

            bool operator==(const limb& right) const;
            bool operator!=(const limb& right) const;
            bool operator>(const limb& right) const;
            bool operator<(const limb& right) const;
            bool operator>=(const limb& right) const;
            bool operator<=(const limb& right) const;

            int compare(const limb& right) const;
    };

    dtype limb::max_value = SET_LIMB_MAX_VALUE();
    size_t limb::limb_length = SET_LIMB_LENGTH();
}

#include "helpers/string_formatters.cpp"
#include "limb_comparison.cpp"
#include "limb_io.cpp"
#include "limb_constructor.cpp"
#include "arithmetic/limb_addition.cpp"
#include "arithmetic/limb_subtraction.cpp"
#include "arithmetic/limb_multiply.cpp"
#include "arithmetic/limb_multiply_by_int.cpp"
#include "arithmetic/limb_division_by_10.cpp"
#include "arithmetic/limb_division_by_1limb.cpp"
#include "arithmetic/limb_division.cpp"

#endif