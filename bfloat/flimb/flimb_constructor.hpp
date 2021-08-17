#ifndef FLIMB_CONSTRUCTOR_HPP
#define FLIMB_CONSTRUCTOR_HPP

#include <iostream>
#include "flimb.hpp"

namespace backend_bigfloat
{
    flimb::flimb(){}

    flimb::flimb(const std::vector<dtype>& limbs, size_t decimal_point)
    {
        this->limbs = limbs;
        this->decimal_point = decimal_point;
    }

    flimb::flimb(const std::string& number)
    {
        #ifndef PRODUCTION
        check(number);
        #endif

        std::pair<std::string,std::string> num_slice = dec_slice(number);

        std::vector<dtype> tmp_int = str_part_by(num_slice.first);
        decimal_point = tmp_int.size();

        std::vector<dtype> tmp_rational = dec_str_part_by(num_slice.second);

        limbs.reserve(decimal_point+tmp_rational.size());
        limbs.insert(limbs.end(),tmp_int.begin(),tmp_int.end());
        limbs.insert(limbs.end(),tmp_rational.begin(),tmp_rational.end());
    }

    flimb::flimb(float number)
    {
        #ifndef FAST_FLOAT_CONSTRUCTOR
        std::stringstream precision_output;
        precision_output<<std::setprecision(7);
        precision_output<<number;
        std::string value = precision_output.str();
        #else
        std::string value = std::to_string(number);
        #endif

        std::pair<std::string,std::string> num_slice = dec_slice(value);

        std::vector<dtype> tmp_int = str_part_by(num_slice.first);
        decimal_point = tmp_int.size();

        std::vector<dtype> tmp_rational = dec_str_part_by(num_slice.second);

        limbs.reserve(decimal_point+tmp_rational.size());
        limbs.insert(limbs.end(),tmp_int.begin(),tmp_int.end());
        limbs.insert(limbs.end(),tmp_rational.begin(),tmp_rational.end());
    }

    flimb::flimb(double number)
    {
        #ifndef FAST_FLOAT_CONSTRUCTOR
        std::stringstream precision_output;
        precision_output<<std::setprecision(15);
        precision_output<<number;
        std::string value = precision_output.str();
        #else
        std::string value = std::to_string(number);
        #endif

        std::pair<std::string,std::string> num_slice = dec_slice(value);

        std::vector<dtype> tmp_int = str_part_by(num_slice.first);
        decimal_point = tmp_int.size();

        std::vector<dtype> tmp_rational = dec_str_part_by(num_slice.second);

        limbs.reserve(decimal_point+tmp_rational.size());
        limbs.insert(limbs.end(),tmp_int.begin(),tmp_int.end());
        limbs.insert(limbs.end(),tmp_rational.begin(),tmp_rational.end());
    }

    flimb::flimb(long double number)
    {
        #ifndef FAST_FLOAT_CONSTRUCTOR
        std::stringstream precision_output;
        precision_output<<std::setprecision(30);
        precision_output<<number;
        std::string value = precision_output.str();
        #else
        std::string value = std::to_string(number);
        #endif

        std::pair<std::string,std::string> num_slice = dec_slice(value);

        std::vector<dtype> tmp_int = str_part_by(num_slice.first);
        decimal_point = tmp_int.size();

        std::vector<dtype> tmp_rational = dec_str_part_by(num_slice.second);

        limbs.reserve(decimal_point+tmp_rational.size());
        limbs.insert(limbs.end(),tmp_int.begin(),tmp_int.end());
        limbs.insert(limbs.end(),tmp_rational.begin(),tmp_rational.end());
    }
}

#endif