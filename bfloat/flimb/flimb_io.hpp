#ifndef FLIMB_IO_HPP
#define FLIMB_IO_HPP

#include <iostream>
#include "flimb.hpp"

namespace backend_bigfloat
{
    std::ostream& operator<<(std::ostream &out, const flimb& value)
    {
        std::string outputstring = "";

        if(value.limbs.size()==2 && value.limbs[0]==0 && value.limbs[1]==0)
        {
            outputstring = "0.0";
            out << outputstring;
            return out;
        }
        
        for(size_t i=0; i<value.limbs.size(); ++i)
        {
            if(i==value.decimal_point)
            {
                std::cout<<'.';
            }
                    
            size_t real_digits = value.limb_length;
            dtype current_index = value.limbs[i];
            if(current_index==0 && current_index!=0)
            {
                std::cout<<std::string(real_digits-1,'0');
            }
            else
            {
                while(current_index)
                {
                    current_index/=10;
                    real_digits--;
                }
                if(i!=0)
                {
                    if(value.limbs[i]==0)
                    {
                        real_digits--;
                    }
                    std::cout<<std::string(real_digits,'0');
                }
            }
            #ifndef SHOW_LIMB_SPACE
            std::cout<<value.limbs[i];
            #else
            std::cout<<value.limbs[i]<<' ';
            #endif
        }
        out << outputstring;
        return out;
    }
}

#endif