#ifndef LIMB_IO_HPP
#define LIMB_IO_HPP

#include <iostream>
#include "limb.hpp"

namespace backend_bigint
{
    std::ostream& operator<<(std::ostream &out, const limb& value)
    {
        std::string outputstring = "";
        if(value.limbs.size()==1 && value.limbs[0]==0)
        {
            outputstring = "0";
            out << outputstring;
            return out;
        }
        
        for(size_t i=0; i<value.limbs.size(); ++i)
        {
            #ifdef SHOW_LIMB_SPACE
            std::cout<<' ';
            #endif

            size_t real_digits = value.limb_length;
            dtype current_index = value.limbs[i];
            if(current_index==0)
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
                if(i!=0) std::cout<<std::string(real_digits,'0');
            }
            std::cout<<value.limbs[i];
        }
        out << outputstring;
        return out;
    }
}

#endif