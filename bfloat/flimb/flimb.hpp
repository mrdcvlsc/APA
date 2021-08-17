#ifndef FLIMB_HPP
#define FLIMB_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "../../bint/limb/limb.hpp"

namespace backend_bigfloat
{
    using namespace backend_bigint;

    class flimb : private limb
    {
        private:

            std::vector<dtype> dec_str_part_by(const std::string& number);
            std::pair<std::string,std::string> dec_slice(const std::string& float_number);

            inline void check(const std::string& value);

        public:

            size_t decimal_point;

            flimb();
            flimb(const std::vector<dtype>& limbs, size_t decimal_point);
            flimb(const std::string& number);
            flimb(float number);
            flimb(double number);
            flimb(long double number);

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
}

#include "helpers/fstring_formatters.hpp"
#include "flimb_comparison.hpp"
#include "flimb_io.hpp"
#include "flimb_constructor.hpp"

#include "arithmetic/flimb_addition.hpp"
#include "arithmetic/flimb_subtract.hpp"
#include "arithmetic/flimb_multiply.hpp"
#include "arithmetic/flimb_division.hpp"

#endif