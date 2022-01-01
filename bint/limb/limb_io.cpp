#ifndef LIMB_IO_HPP
#define LIMB_IO_HPP

#include <iostream>
#include "limb.hpp"

namespace backend_bigint
{
    std::istream& operator>>(std::istream& in, limb& value)
    {
        std::string input_stream(std::istreambuf_iterator<char>(in), {});
        value = limb(input_stream);
        return in;
    }

    std::ostream& operator<<(std::ostream &out, const limb& value)
    {
        if(value.limbs.size()==1 && value.limbs[0]==0)
        {
            out << "0";
            return out;
        }
        
        for(size_t i=0; i<value.limbs.size(); ++i)
        {
            #ifdef SHOW_LIMB_SPACE
            out << ' ';
            #endif

            size_t real_digits = value.limb_length;
            dtype current_index = value.limbs[i];
            if(current_index==0)
            {
                out << std::string(real_digits-1,'0');
            }
            else
            {
                while(current_index)
                {
                    current_index/=10;
                    real_digits--;
                }
                if(i!=0) out << std::string(real_digits,'0');
            }
            out << value.limbs[i];
        }
        return out;
    }
}

#endif