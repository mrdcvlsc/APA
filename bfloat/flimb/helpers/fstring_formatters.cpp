#ifndef FSTRING_FORMATTERS_HPP
#define FSTRING_FORMATTERS_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline void flimb::check(const std::string& value)
    {
        size_t value_size = value.size();
        
        size_t point = 0;
        
        if(value_size<=0)
        {
            throw std::length_error("limb constructor error, number has an empty value");
        }

        for(size_t i=0; i<value_size; ++i)
        {
            if(value[i]=='.')
            {
                point++;

                if(point>1)
                {
                    std::string errmsg = "limb constructor error, \"" + value + "\" is not a valid number\n";
                    throw std::invalid_argument(errmsg);
                }

                continue;
            }

            if((value[i]<'0')^(value[i]>'9'))
            {
                std::string errmsg = "limb constructor error, \"" + value + "\" is not a valid number\n";
                throw std::invalid_argument(errmsg);
            }
        }
    }

    std::vector<dtype> flimb::dec_str_part_by(const std::string& number)
    {
        std::vector<std::string> str_partition;
        std::vector<backend_bigint::dtype> long_partition;

        std::string str_temp(limb_length,'0');
        size_t num_size = number.size();

        backend_bigint::dtype memreserve = ((backend_bigint::dtype)num_size/(backend_bigint::dtype)limb_length)+1;
        str_partition.reserve(memreserve);
        long_partition.reserve(memreserve);

        for(size_t i=0, str_i; i<num_size;++i)
        {
            if(i==0 or i%limb_length==0)
            {
                str_i = limb_length;
                str_partition.push_back(str_temp);
            }
            str_partition.back()[limb_length-str_i] = number[i];
            --str_i;
        }

        size_t str_size = str_partition.size();
        for(size_t i=0; i<str_size; ++i)
        {
            long_partition.push_back(stoll(str_partition[i]));
        }

        return long_partition;
    }

    std::pair<std::string,std::string> flimb::dec_slice(const std::string& float_number)
    {
        size_t point = 0;
        size_t float_size_num = float_number.size();

        for(size_t i=0; i<float_size_num; ++i)
        {    
            if(float_number[i]=='.')
            {    
                point = i;
                break;
            }
        }

        if(!point)
        {
            std::string nopoints(limb_length,'0');
            return std::make_pair(float_number,nopoints);
        }

        return std::make_pair(float_number.substr(0,point),float_number.substr(point+1));
    }

    std::string flimb::string_form() const
    {
        size_t n = limbs.size();
        std::string carried_answer="", current_index;

        if(limbs.size()==2 && limbs[0]==0 && limbs[1]==0)
        {
            return "0.0";
        }
        
        for(size_t i=0;i<n;++i)
        {
            current_index = std::to_string(limbs[i]);
            std::string front_zeros(limb_length-current_index.size(),'0');
            // carried_answer+=(front_zeros+current_index);
            if(i==decimal_point)
            {
                carried_answer.push_back('.');
            }

            std::string whole_limb = front_zeros.append(current_index);

            if(i==limbs.size()-1)
            {
                if(limbs[i]==0)
                {
                    whole_limb = "0";
                }
                else
                {
                    std::string last_limb = whole_limb;
                    size_t zero_remove_rear = 0;
                    for(size_t i=0; i<last_limb.size(); ++i)
                    {
                        if(last_limb[last_limb.size()-1-i]!='0')
                        {
                            break;
                        }
                        zero_remove_rear++;
                    }
                    whole_limb = last_limb.substr(0,last_limb.size()-zero_remove_rear);
                }
            }

            carried_answer.append(whole_limb);

        }

        carried_answer = removeFrontZeros(carried_answer);
        if(limbs[0]==0 && decimal_point==1)
        {
            carried_answer.insert(carried_answer.begin(),'0');
        }
        return carried_answer;
    }
}

#endif