#ifndef FLIMB_DIVISION_HPP
#define FLIMB_DIVISION_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline flimb flimb::operator/(const flimb& divisor) const
    {
        return flimb("0");
    }
    
    inline flimb& flimb::operator/=(const flimb& divisor)
    {
        return *this;
    }
    
}

#endif