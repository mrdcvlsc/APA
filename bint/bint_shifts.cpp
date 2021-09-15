#ifndef BINT_SHIFTS_CPP
#define BINT_SHIFTS_CPP

#include <iostream>
#include "bint.hpp"

namespace apa
{
    bint bint::operator<<(const bint& k) const
    {
        return (*this) * apa::pow(BINTTWO,k);
    }

    bint bint::operator>>(const bint& k) const
    {
        return (*this) / apa::pow(BINTTWO,k);
    }
}

#endif