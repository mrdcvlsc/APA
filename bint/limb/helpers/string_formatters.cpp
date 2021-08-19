#ifndef STRING_FORMATTERS_HPP
#define STRING_FORMATTERS_HPP

#include <iostream>
#include "../limb.hpp"

namespace backend_bigint
{
    inline void limb::check(const std::string &value)
    {    
        size_t value_size = value.size();
        
        if(value_size<=0)
        {
            throw std::length_error("limb constructor error, number has an empty value");
        }

        for(size_t i=0; i<value_size; ++i)
        {
            if((value[i]<'0')^(value[i]>'9'))
            {
                std::string errmsg = "limb constructor error, \"" + value + "\" is not a valid number\n";
                throw std::invalid_argument(errmsg);
            }
        }
    }

    inline std::vector<dtype> limb::str_part_by(const std::string& number)
    {	
        std::vector<std::string> str_partition;
        std::vector<dtype> long_partition;

        std::string str_temp(this->limb_length,'0');
        size_t num_size = number.size();

        dtype memreserve = ((dtype)num_size/(dtype)this->limb_length)+1;
        str_partition.reserve(memreserve);
        long_partition.reserve(memreserve);

        for(size_t i=0, str_i; i<num_size;++i) {
            
            if(i==0 or i%this->limb_length==0){
                str_i = this->limb_length;
                str_partition.push_back(str_temp);
            }
            str_partition.back()[str_i-1] = number[num_size-1-i];
            --str_i;
        }

        size_t str_size = str_partition.size();
        for(size_t i=0; i<str_size; ++i)	
            long_partition.push_back(stoll(str_partition[str_size-1-i]));
            
        return long_partition;
    }

    inline std::string limb::removeFrontZeros(const std::string& str) const
    {	
        size_t str_len = str.size();
        size_t zero_indecies = 0;

        if(str_len==1) return str;

        for(size_t i=0; i<str_len-1; ++i)
        {
            if(str[i]!='0')
            {
                break;
            }
            ++zero_indecies;
        }

        return str.substr(zero_indecies,str_len-zero_indecies);
    }

    std::string limb::string_form() const
    {
        size_t n = limbs.size();
        std::string carried_answer="", current_index;

        if(limbs.size()==1 && limbs[0]==0)
        {
            return "0";
        }
        
        for(size_t i=0;i<n;++i) {
            current_index = std::to_string(limbs[i]);
            std::string front_zeros(limb_length-current_index.size(),'0');
            // carried_answer+=(front_zeros+current_index);
            carried_answer.append(front_zeros);
            carried_answer.append(current_index);

        }
        return removeFrontZeros(carried_answer);
    }
}

#endif