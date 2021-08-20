#ifndef BFLOAT_COMPARISON_HPP
#define BFLOAT_COMPARISON_HPP

#include <iostream>
#include "bfloat.hpp"

namespace apa
{
    bool bfloat::operator==(const bfloat& right) const
    {
        if(sign!=right.sign)
        {
            return false;
        }
        return floatlimbs==right.floatlimbs;
    }

    bool bfloat::operator!=(const bfloat& right) const
    {
        return !(*this==right);
    }

    bool bfloat::operator< (const bfloat& right) const
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
            return !(floatlimbs<right.floatlimbs);
        }
        return floatlimbs<right.floatlimbs;
    }

    bool bfloat::operator> (const bfloat& right) const
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
            return !(floatlimbs>right.floatlimbs);
        }
        return floatlimbs>right.floatlimbs;
    }

    bool bfloat::operator<=(const bfloat& right) const
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
            return !(floatlimbs<=right.floatlimbs);
        }
        return floatlimbs<=right.floatlimbs;
    }

    bool bfloat::operator>=(const bfloat& right) const
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
            return !(floatlimbs>=right.floatlimbs);
        }
        return floatlimbs>=right.floatlimbs;
    }
}

#endif