#ifndef LIMB_CONSTRUCTORS_HPP
#define LIMB_CONSTRUCTORS_HPP

#include <iostream>
#include "limb.hpp"

namespace backend_bigint
{
    limb::limb() {}

    // copy constructor
    limb::limb(const limb& other)
    {
        limbs.reserve(other.limbs.size());
        limbs.insert(limbs.begin(),other.limbs.begin(),other.limbs.end());
    }

    // move constructor
    limb::limb(limb&& temp) noexcept
    {
        limbs = std::move(temp.limbs);
    }

    // copy assignment
    limb& limb::operator=(const limb& other)
    {
        limbs = other.limbs;
        return *this;
    }

    // move assignment
    limb& limb::operator=(limb&& temp) noexcept
    {
        limbs = std::move(temp.limbs);
        return *this;
    }

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