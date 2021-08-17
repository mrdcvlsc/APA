#ifndef FLIMB_DIVISION_HPP
#define FLIMB_DIVISION_HPP

#include <iostream>
#include "../flimb.hpp"

namespace backend_bigfloat
{
    inline flimb flimb::operator/(const flimb& divisor) const
    {
        std::cout<<"-----------------------------------\n";
        limb padded_dividen, limb_divisor;
        padded_dividen.limbs = limbs;
        limb_divisor.limbs = divisor.limbs;

        long long pad_limb_count = divisor.limbs.size() - limbs.size();

        std::cout<<"\ndivisor.limbs.size() = "<<divisor.limbs.size()<<"\n";
        std::cout<<"limbs.size()             = "<<limbs.size()<<"\n";
        std::cout<<"pad_limb_count           = "<<pad_limb_count<<"\n";

        if(pad_limb_count>0)
        {
            std::vector<dtype> pad_zeros(pad_limb_count+div_precision,0);
            padded_dividen.limbs.insert(padded_dividen.limbs.end(),pad_zeros.begin(),pad_zeros.end());
        }

        std::cout<<"limb dividen = "<<padded_dividen<<"\n";

        size_t quotient_decimal_place = decimal_point + (divisor.limbs.size()-divisor.decimal_point);
        limb quotient = padded_dividen/limb_divisor;

        std::cout<<"limb quotient = "<<quotient<<"\n";

        // create a division algorithm for bfloats where it does not remove the zeros in back and rear yet,
        // because the division in limbs do remove the zeros right away

        flimb fquotient(quotient.limbs,quotient_decimal_place);

        // // check and remove zero limbs in front
        // size_t front_remove_limit = fquotient.decimal_point-1;
        // size_t front_limb_to_remove = 0;
        // size_t resulting_size = fquotient.limbs.size();
        // for(size_t i=0; i<fquotient.limbs.size(); ++i)
        // {
        //     if(limbs[i]==0 && resulting_size>2 && front_remove_limit--)
        //     {
        //         front_limb_to_remove++;
        //         resulting_size--;
        //     }
        //     else break;
        // }
        // if(front_limb_to_remove)
        // {
        //     fquotient.limbs.erase(fquotient.limbs.begin()+0,fquotient.limbs.begin()+front_limb_to_remove);
        // }

        // // check and remove zero limbs in rear
        // size_t rear_remove_limit = fquotient.limbs.size()-fquotient.decimal_point-1;
        // size_t rear_limb_to_remove = 0;
        // for(size_t i=limbs.size()-1; i<limbs.size(); ++i)
        // {
        //     if(limbs[i]==0 && resulting_size>1 && rear_remove_limit--)
        //     {
        //         rear_limb_to_remove++;
        //         resulting_size--;
        //     }
        //     else break;
        // }
        // if(rear_limb_to_remove)
        // {
        //     fquotient.limbs.erase(fquotient.limbs.begin()+(fquotient.limbs.size()-1-rear_limb_to_remove),fquotient.limbs.end());
        // }

        return fquotient;
    }
    
    inline flimb& flimb::operator/=(const flimb& divisor)
    {
        return *this;
    }
    
}

#endif