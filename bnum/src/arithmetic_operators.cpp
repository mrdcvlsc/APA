#include "bnum.hpp"

bnum bnum::operator++(){ return *this = *this+bnum("1"); }
bnum bnum::operator--(){ return *this = *this-bnum("1"); }

//post-fix increment/decrementa
bnum bnum::operator++(int){
    ++*this;
    return *this-bnum("1"); 
}
bnum bnum::operator--(int){
    --*this;
    return *this+bnum("1");
} 

bnum bnum::operator+(const bnum& that) const{

    bnum answer;

    // added and changed : start
    bnum adden1 = *this;
    bnum adden2 = that;

    size_t addn1_csize = adden1.integer.size();
    size_t addn2_csize = adden2.integer.size();

    size_t add1pp = adden1.point_place;
    size_t add2pp = adden2.point_place;

    size_t d1chunk_size = addn1_csize-add1pp;
    size_t d2chunk_size = addn2_csize-add2pp;

    size_t to_sub_ans_pp = max(d1chunk_size,d2chunk_size);

    if(d1chunk_size!=d2chunk_size)
    {
        if(d1chunk_size<d2chunk_size){
            long long int dif = (long long int)d2chunk_size - (long long int)d1chunk_size;
            bnumfield rpad(dif,0ll);
            // bnumfield newval = adden1.get_bnum_field();

            //* reserve upgrade
            
            // replace "bnumfield newval = adden1.get_bnum_field();""

            bnumfield newval;
            size_t memreserve = adden1.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),adden1.integer.begin(),adden1.integer.end());
            
            //*/

            newval.insert(newval.end(),rpad.begin(),rpad.end());
            adden1.integer = newval;
        }
        else{
            long long int dif = (long long int)d1chunk_size - (long long int)d2chunk_size;
            bnumfield rpad(dif,0ll);
            // bnumfield newval = adden2.get_bnum_field();

            //* reserve upgrade
            
            // replace "bnumfield newval = adden2.get_bnum_field();""

            bnumfield newval;
            size_t memreserve = adden2.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),adden2.integer.begin(),adden2.integer.end());
            
            //*/

            newval.insert(newval.end(),rpad.begin(),rpad.end());
            adden2.integer = newval;
            //.integer = newval
        }
    }
 
    bool same_sign = adden1.sign==adden2.sign;
    bool adden1isMax = adden1.point_place>adden2.point_place;

    // added and changed : end

    // different sign
   
	if(!same_sign && adden1isMax){
        answer.set_bnum_field(subnum(adden1.integer,adden2.integer,to_sub_ans_pp));
		if(adden1.sign>=0){
            answer.sign = 1;
            answer.point_place = answer.integer.size()-to_sub_ans_pp;
            // .point_place = answer.integer.size()-to_sub_ans_pp
            return answer;
        }
        answer.sign = -1;
        answer.point_place = answer.integer.size()-to_sub_ans_pp;
        return answer;
	}
	else if(!same_sign && !adden1isMax){
        
        answer.set_bnum_field(subnum(adden2.integer,adden1.integer,to_sub_ans_pp));
		if(adden2.sign>=0){
            answer.sign = 1;
            answer.point_place = answer.integer.size()-to_sub_ans_pp;
            return answer;
        }
        answer.sign = -1;
        answer.point_place = answer.integer.size()-to_sub_ans_pp;
        return answer;
	}

	// same sign both negative
	if(same_sign && adden1.sign<0 && adden2.sign<0){
        answer.set_bnum_field(addint(adden1.integer,adden2.integer));
        answer.sign = -1;
        answer.point_place = answer.integer.size()-to_sub_ans_pp;
        return answer;
    }

	// same sign bot positive
    answer.integer = addint(adden1.integer,adden2.integer);
    answer.sign = 1;
    answer.point_place = answer.integer.size()-to_sub_ans_pp;
    return answer;
}

bnum bnum::operator-(const bnum& that) const{

    bnum answer;

    // added : start
    
    bnum minu = *this;
    bnum subt = that;

    size_t minu_csize = minu.integer.size();
    size_t subt_csize = subt.integer.size();

    size_t minupp = minu.point_place;
    size_t subtpp = subt.point_place;

    size_t d1chunk_size = minu_csize-minupp;
    size_t d2chunk_size = subt_csize-subtpp;

    size_t to_sub_ans_pp = max(d1chunk_size,d2chunk_size);

    if(d1chunk_size!=d2chunk_size){

        if(d1chunk_size<d2chunk_size){
            long long int dif = (long long int)d2chunk_size - (long long int)d1chunk_size;
            bnumfield rpad(dif,0ll);
            // bnumfield newval = minu.get_bnum_field();

            //* reserve upgrade
            
            //replace "bnumfield newval = minu.get_bnum_field();""

            bnumfield newval;
            size_t memreserve = minu.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),minu.integer.begin(),minu.integer.end());
            
            //*/

            newval.insert(newval.end(),rpad.begin(),rpad.end());
            minu.integer = newval;
        }
        else{
            long long int dif = (long long int)d1chunk_size - (long long int)d2chunk_size;
            bnumfield rpad(dif,0ll);
            // bnumfield newval = subt.get_bnum_field();

            //* reserve upgrade
            
            //replace "bnumfield newval = subt.get_bnum_field();""

            bnumfield newval;
            size_t memreserve = subt.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),subt.integer.begin(),subt.integer.end());
            
            //*/

            newval.insert(newval.end(),rpad.begin(),rpad.end());
            subt.integer = newval;
        }
    }
 
    bool same_sign = minu.sign==subt.sign;

    // added : end
    bool pos_minuend = (minu.sign)>=0;
	bool minuendIsMax = minu>subt;

    if(same_sign)
	{
		if(minu==subt){
            answer.set_bnum_field({0,0});
            answer.sign = 1;
            return "0";
        }
		else if(pos_minuend){

			if(minuendIsMax){
                answer.set_bnum_field(subnum(minu.integer,subt.integer,to_sub_ans_pp));
                answer.sign = 1;
                answer.point_place = answer.integer.size()-to_sub_ans_pp;
                return answer;
            }
            answer.set_bnum_field(subnum(subt.integer,minu.integer,to_sub_ans_pp));
            answer.sign = -1;
            answer.point_place = answer.integer.size()-to_sub_ans_pp;
            return answer;
		}
		else if(!pos_minuend){
			if(minuendIsMax){
                answer.set_bnum_field(subnum(subt.integer,minu.integer,to_sub_ans_pp));
                answer.sign = 1;
                answer.point_place = answer.integer.size()-to_sub_ans_pp;
                return answer;
            }
            answer.set_bnum_field(subnum(minu.integer,subt.integer,to_sub_ans_pp));
            answer.sign = -1;
            answer.point_place = answer.integer.size()-to_sub_ans_pp;
            return answer;
		}
	}
	else
	{
        answer.set_bnum_field(addint(minu.integer,subt.integer));
		if(minu<subt){
            answer.sign = -1;
            answer.point_place = answer.integer.size()-to_sub_ans_pp;
            return answer;
        }
        answer.sign = 1;
        answer.point_place = answer.integer.size()-to_sub_ans_pp;
        return answer;
	}
	return bnum("0");
}

bnum bnum::operator*(const bnum& that) const{

    bnum answer;

    // added and changed : start
    bnum multiplicand = *this;
    bnum multiplier = that;

    size_t multiplicand_chunk_size = multiplicand.integer.size();
    size_t multiplier_chunk_size = multiplier.integer.size();

    if((multiplicand_chunk_size==2 && integer[0]==0ll && integer[1]==0ll) || 
       (multiplier_chunk_size==2 && that.integer[0]==0ll && that.integer[1]==0ll)){
        answer.set_bnum_field({0,0});
        answer.set_sign(1);
        answer.set_point_place(1);
        return answer;
    }

    size_t multiplicand_pp = multiplicand.point_place;
    size_t multiplier_pp = multiplier.point_place;

    size_t multiplicand_dec_chunk_size = multiplicand_chunk_size-multiplicand_pp;
    size_t multiplier_dec_chunk_size = multiplier_chunk_size-multiplier_pp;
    
    if(multiplicand_dec_chunk_size!=multiplier_dec_chunk_size){

        if(multiplicand_dec_chunk_size<multiplier_dec_chunk_size)
        {
            long long int dif = (long long int)multiplier_dec_chunk_size - (long long int)multiplicand_dec_chunk_size;
            bnumfield rpad(dif,0ll);
            bnumfield newval;
            size_t memreserve = multiplicand.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),multiplicand.integer.begin(),multiplicand.integer.end());
            newval.insert(newval.end(),rpad.begin(),rpad.end());
            multiplicand.integer = newval;
        }
        else
        {
            long long int dif = (long long int)multiplicand_dec_chunk_size - (long long int)multiplier_dec_chunk_size;
            bnumfield rpad(dif,0ll);
            bnumfield newval;
            size_t memreserve = multiplier.integer.size() + rpad.size();
            newval.reserve(memreserve);
            newval.insert(newval.end(),multiplier.integer.begin(),multiplier.integer.end());
            newval.insert(newval.end(),rpad.begin(),rpad.end());
            multiplier.integer = newval;
        }
    }
 
    bool same_sign = multiplicand.sign==multiplier.sign;

    size_t new_multiplicand_dec_chunk_size = multiplicand.integer.size() - multiplicand_pp;
    size_t new_multiplier_dec_chunk_size = multiplier.integer.size() - multiplier_pp;

    answer.integer = mulint(multiplicand.integer,multiplier.integer);
    answer.point_place = (answer.integer.size()-(new_multiplicand_dec_chunk_size+new_multiplier_dec_chunk_size));

	if(!same_sign){
        answer.sign = -1;
        return answer;
    }
    answer.sign = 1;
    return answer;
}


size_t bnum::div_precision = 1;
bnumfield bnum::precision_chunk(1,0);
bnum bnum::operator/(const bnum& that) const
{
    bnum answer;
    bnum dividen = *this;
    bnum divisor = that;

    size_t dividen_chunk_size = dividen.integer.size();
    size_t divisor_chunk_size = divisor.integer.size();

    bool same_sign = dividen.sign==divisor.sign;

    bnumfield dividen_rpad_equalizer;

    if(dividen_chunk_size==2 && dividen.integer[0]==0 && dividen.integer[1]==0){
        answer.set_bnum_field({0,0});
        answer.set_sign(1);
        answer.set_point_place(1);
        return answer;
    }
    else
    {
        bnumfield set_pad_value(div_precision,0);
        dividen_rpad_equalizer = set_pad_value;
    }

    if(divisor_chunk_size==2 && divisor.integer[0]==0 && divisor.integer[1]==0){
        cerr<<"\n\x1B[31mMath Error\033[0m : Cannot Divide Number by '0' (Zero)\n";
        exit(1);
    }
    
    // if pad zero chunks to dividen if its chunks is lessthan or equal divisor chunks
    if(dividen_chunk_size<=divisor_chunk_size)
    {
        long long int dif = (long long int)divisor_chunk_size - (long long int)dividen_chunk_size + 1;
        bnumfield rpad(dif,0ll);
        bnumfield newval;
        newval.reserve(dividen.integer.size()+dif+dividen_rpad_equalizer.size());
        newval.insert(newval.end(),dividen.integer.begin(),dividen.integer.end());
        newval.insert(newval.end(),rpad.begin(),rpad.end());
        newval.insert(newval.end(),dividen_rpad_equalizer.begin(),dividen_rpad_equalizer.end());
        dividen.integer = newval;
    }

    // add more chunks to dividen if decimal length of divisor is greater than or equal than the dividen's decimal len
    size_t dividen_dec_len = dividen.integer.size() - dividen.point_place;
    size_t divisor_dec_len = divisor.integer.size() - divisor.point_place;
    if(dividen_dec_len<=divisor_dec_len)
    {
        size_t dividen_rpad_dec_len = divisor_dec_len - dividen_dec_len;
        bnumfield dividen_rpad_dec(dividen_rpad_dec_len,0);
        dividen.integer.insert(dividen.integer.end(),dividen_rpad_dec.begin(),dividen_rpad_dec.end());
    }
  
    // add precision level
    dividen.integer.insert(dividen.integer.end(),precision_chunk.begin(),precision_chunk.end());

    try{
        if(that==bnum("0")) throw "\n\x1B[31mMath Error\033[0m : Cannot Divide Number by '0' (Zero)";

        size_t decimal_point_place = ((dividen.point_place*8)+((divisor.integer.size()-divisor.point_place)*8));
        size_t raw_dividen_len = dividen.integer.size()*8;
      
        string quotient_str = divint(dividen.integer,divisor.integer);
    
        // add zeroes in rear
        size_t len_add = raw_dividen_len-quotient_str.size();
        size_t dppp = decimal_point_place-len_add;
        size_t quotient_size = quotient_str.size();
        if(dppp>=quotient_size){
            size_t qstr_rpad_len = (dppp-quotient_size)+1;
            string qstr_rpad(qstr_rpad_len,'0');
            quotient_str = quotient_str + qstr_rpad;
        }

        quotient_str.insert(quotient_str.begin()+(decimal_point_place-len_add),'.');
       
        bnum answerf(quotient_str);
        if(same_sign) answerf.sign = 1;
        else answerf.sign = -1;
        return answerf;
    }
    catch(const char* err){
        cerr<<err<<'\n';
        exit(4);
    }
    return bnum("0");
}

bnum bnum::operator%(const bnum& that) const{
    bnum answer = (*this)-(((*this)/that)*that);
    answer.sign = 1;
    return answer;
}

bnum& bnum::operator+=(const bnum a){
	*this = *this + a;
	return *this;
}

bnum& bnum::operator-=(const bnum a){
	*this = *this - a;
	return *this;
}

bnum& bnum::operator*=(const bnum a){
	*this = *this * a;
	return *this;
}

bnum& bnum::operator/=(const bnum a){
	*this = *this / a;
	return *this;
}