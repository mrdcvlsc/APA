#ifndef LIMB_CONSTRUCTORS_HPP
#define LIMB_CONSTRUCTORS_HPP

#include <iostream>
#include "limb.hpp"

namespace backend_bigint
{
    limb::limb() {}

    limb::limb(const std::string& number)
    {
        #ifndef PRODUCTION
        check(number);
        #endif
        
        limbs = str_part_by(number);
    }

    limb::limb(unsigned short number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(short number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(unsigned int number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(int number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(unsigned long number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(long number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(unsigned long long number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }

    limb::limb(long long number)
    {
        std::string value = std::to_string(number);
        limbs = str_part_by(value);
    }
}

#endif