#ifndef BINT_COMPARISON_HPP
#define BINT_COMPARISON_HPP

#include <iostream>
#include "bint.hpp"

namespace apa
{
    bool bint::operator==(const bint& right) const
    {
        if(sign!=right.sign)
        {
            return false;
        }
        return intlimbs==right.intlimbs;
    }

    bool bint::operator!=(const bint& right) const
    {
        return !(*this==right);
    }

    bool bint::operator< (const bint& right) const
    {
        if(sign<right.sign)
        {
            return true;
        }
        else if(sign>right.sign)
        {
            return false;
        }
        if(sign<0)
        {
            return !(intlimbs<right.intlimbs);
        }
        return intlimbs<right.intlimbs;
    }

    bool bint::operator> (const bint& right) const
    {
        if(sign>right.sign)
        {
            return true;
        }
        else if(sign<right.sign)
        {
            return false;
        }
        if(sign<0)
        {
            return !(intlimbs>right.intlimbs);
        }
        return intlimbs>right.intlimbs;
    }

    bool bint::operator<=(const bint& right) const
    {
        if(sign<right.sign)
        {
            return true;
        }
        else if(sign>right.sign)
        {
            return false;
        }
        if(sign<0)
        {
            return !(intlimbs<=right.intlimbs);
        }
        return intlimbs<=right.intlimbs;
    }

    bool bint::operator>=(const bint& right) const
    {
        if(sign>right.sign)
        {
            return true;
        }
        else if(sign<right.sign)
        {
            return false;
        }
        if(sign<0)
        {
            return !(intlimbs>=right.intlimbs);
        }
        return intlimbs>=right.intlimbs;
    }
}

#endif