#ifndef FLIMB_SIZES
#define FLIMB_SIZES

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    size_t flimb::flimb_count() const
    {
        return limbs.size();
    }

    size_t flimb::flimb_length() const
    {
        return limb_length;
    }
}

#endif