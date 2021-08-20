#ifndef BINT_IO_HPP
#define BINT_IO_HPP

#include <iostream>
#include "bint.hpp"

namespace apa
{
    // temporary fix this later

    //// IO Operators
    std::ostream& operator<<(std::ostream &out, const bint &num)
    {
        std::string output = "";
        if(num.sign<0) std::cout<<"-";

        std::cout<<num.intlimbs;
        out<<output;
        return out;
    }

    std::istream& operator>>(std::istream &in, bint &num)
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
        num.intlimbs = backend_bigint::limb(input);
        return in;
    }

    std::string bint::string_form() const
    {
        std::string strform;
        strform.reserve(intlimbs.limb_count()*intlimbs.limb_length);
        if(sign<0)
        {
            strform.push_back('-');
        }
        strform.append(intlimbs.string_form());
        return strform;
    }
}

#endif