#ifndef BFLOAT_IO_HPP
#define BFLOAT_IO_HPP

#include <iostream>
#include "bfloat.hpp"

namespace apa
{
    // temporary fix this later

    //// IO Operators
    std::ostream& operator<<(std::ostream &out, const bfloat &num)
    {
        if(num.sign<0) out << "-";
        out << num.floatlimbs;
        return out;
    }

    std::istream& operator>>(std::istream &in, bfloat &num)
    {
        std::string input;
        in >> input;
        if(input[0]=='-')
        {
            num.sign = -1;
            input.erase(0,1);
        }
        else
        {
            num.sign = 1;
        }
        num.floatlimbs = backend_bigfloat::flimb(input);
        return in;
    }

    std::string bfloat::string_form() const
    {
        std::string strform;
        strform.reserve(floatlimbs.flimb_count()*floatlimbs.flimb_length());
        if(sign<0)
        {
            strform.push_back('-');
        }
        strform.append(floatlimbs.string_form());
        return strform;
    }
}

#endif