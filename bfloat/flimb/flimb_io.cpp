#ifndef FLIMB_IO_HPP
#define FLIMB_IO_HPP

#include <iostream>
#include "flimb.hpp"

namespace backend_bigfloat
{
    std::istream& operator>>(std::istream& in, flimb& value)
    {
        std::string input_stream(std::istreambuf_iterator<char>(in), {});
        value = flimb(input_stream);
        return in;
    }

    std::ostream& operator<<(std::ostream &out, const flimb& value)
    {
        if(value.limbs.size()==2 && value.limbs[0]==0 && value.limbs[1]==0)
        {
            out << "0.0";
            return out;
        }
        
        for(size_t i=0; i<value.limbs.size(); ++i)
        {
            if(i==value.decimal_point)
            {
                out << '.';
            }
                    
            size_t real_digits = value.limb_length;
            dtype current_index = value.limbs[i];
            if(current_index==0 && current_index!=0 && i!=value.limbs.size()-1)
            {
                out << std::string(real_digits-1,'0');
            }
            else if(i!=value.limbs.size()-1)
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
                    out << std::string(real_digits,'0');
                }
            }
            #ifndef SHOW_LIMB_SPACE
            if(i==value.limbs.size()-1)
            {
                if(value.limbs[i]==0)
                {
                    out << 0;
                }
                else
                {
                    std::string last_limb = std::to_string(value.limbs[i]);
                    size_t zero_remove_rear = 0;
                    for(size_t i=0; i<last_limb.size(); ++i)
                    {
                        if(last_limb[last_limb.size()-1-i]!='0')
                        {
                            break;
                        }
                        zero_remove_rear++;
                    }
                    out << last_limb.substr(0,last_limb.size()-zero_remove_rear);
                }
            }
            else
            {
                out << value.limbs[i];
            }
            #else
            out << value.limbs[i];
            out << ' ';
            #endif
        }
        return out;
    }
}

#endif