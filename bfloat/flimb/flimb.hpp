#ifndef FLIMB_HPP
#define FLIMB_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "../../bint/limb/limb.hpp"

namespace backend_bigfloat
{
    using namespace backend_bigint;

    class flimb : public limb
    {
        private:

            static size_t div_precision; 

            std::vector<dtype> dec_str_part_by(const std::string& number);
            std::pair<std::string,std::string> dec_slice(const std::string& float_number);

            inline void check(const std::string& value);

        public:

            static void set_div_precision(size_t n) { div_precision = n; }

            size_t decimal_point;

            flimb();
            flimb(const std::string& number);
            flimb(const std::vector<dtype>& limbs, size_t decimal_point);
            flimb(float number);
            flimb(double number);
            flimb(long double number);

            size_t flimb_count() const;
            size_t flimb_length() const;

            inline flimb operator+(const flimb& lower_adden) const;
            inline flimb& operator+=(const flimb& lower_adden);

            inline flimb operator-(const flimb& subtrahend) const;
            inline flimb& operator-=(const flimb& subtrahend);

            inline flimb operator*(const flimb& multiplier) const;
            inline flimb& operator*=(const flimb& multiplier);

            inline flimb operator/(const flimb& divisor) const;
            inline flimb& operator/=(const flimb& divisor);

            friend std::ostream& operator<<(std::ostream &out, const flimb& value);

            bool operator==(const flimb& right) const;
            bool operator!=(const flimb& right) const;
            bool operator>(const flimb& right) const;
            bool operator<(const flimb& right) const;
            bool operator>=(const flimb& right) const;
            bool operator<=(const flimb& right) const;

            int compare(const flimb& right) const;

            std::string string_form() const;
    };

    size_t flimb::div_precision = 1;
}

#include "helpers/fstring_formatters.cpp"
#include "flimb_comparison.cpp"
#include "flimb_io.cpp"
#include "flimb_constructor.cpp"
#include "helpers/flimb_sizes.cpp"

#include "arithmetic/flimb_addition.cpp"
#include "arithmetic/flimb_subtract.cpp"
#include "arithmetic/flimb_multiply.cpp"
#include "arithmetic/flimb_division.cpp"

#endif