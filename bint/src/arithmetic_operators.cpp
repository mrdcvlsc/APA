#include "bint.hpp"

bint bint::operator++(){ return *this = *this+bint("1"); }
bint bint::operator--(){ return *this = *this-bint("1"); }

//post-fix increment/decrementa
bint bint::operator++(int){
    ++*this;
    return *this-bint("1"); 
}
bint bint::operator--(int){
    --*this;
    return *this+bint("1");
} 

bint bint::operator+(const bint& that) const{

    bint answer;

    bool same_sign = this->sign==that.sign;
    bool adden1isMax = chunk_is_great(this->integer,that.integer);

    // different sign
	if(!same_sign && adden1isMax){
        answer.set_bint_field(subint(this->integer,that.integer));
		if(this->sign>=0){
            answer.set_sign(1);
            return answer;
        }
        answer.set_sign(-1);
        return answer;
	}
	else if(!same_sign && !adden1isMax){
        answer.set_bint_field(subint(that.integer,this->integer));
		if(that.sign>=0){
            answer.set_sign(1);
            return answer;
        }
        answer.set_sign(-1);
        return answer;
	}

	// same sign both negative
	if(same_sign && (this->sign)<0 && that.sign<0){
        answer.set_bint_field(addint(this->integer,that.integer));
        answer.set_sign(-1);
        return answer;
    }

	// same sign bot positive
    answer.set_bint_field(addint(this->integer,that.integer));
    answer.set_sign(1);
    return answer;
}

bint bint::operator-(const bint& that) const{

    bint answer;

    bool same_sign = this->sign==that.sign;
    bool pos_minuend = (this->sign)>=0;
	bool minuendIsMax = *this>that;

    if(same_sign)
	{
		if(*this==that) return "0";

		else if(pos_minuend){

			if(minuendIsMax){
                answer.set_bint_field(subint(this->integer,that.integer));
                answer.set_sign(1);
                return answer;
            }
            answer.set_bint_field(subint(that.integer,this->integer));
            answer.set_sign(-1);
            return answer;
		}
		else if(!pos_minuend){
			if(minuendIsMax){
                answer.set_bint_field(subint(that.integer,this->integer));
                answer.set_sign(1);
                return answer;
            }
            answer.set_bint_field(subint(this->integer,that.integer));
            answer.set_sign(-1);
            return answer;
		}
	}
	else
	{
        answer.set_bint_field(addint(this->integer,that.integer));
		if(*this<that){
            answer.set_sign(-1);
            return answer;
        }
        answer.set_sign(1);
        return answer;
	}
	return bint("0");
}

bint bint::operator*(const bint& that) const{

    bint answer;
    bool same_sign = this->sign==that.sign;

    answer.set_bint_field(mulint(this->integer,that.integer));
	if(!same_sign){
        answer.set_sign(-1);
        return answer;
    }
    answer.set_sign(1);
    return answer;
}

bint bint::operator/(const bint& that) const{

    try{
        if(that==bint("0")) throw "\n\x1B[31mMath Error\033[0m : Cannot Divide Number by '0' (Zero)";
        bint answer;

        bool same_sign = (this->sign==that.sign);

        // divisor is greater than dividen
        if(chunk_is_great(that.get_bint_field(),this->get_bint_field())){
            answer.set_bint_field({0});
            answer.set_sign(1);
            return answer;
        }

        answer.set_bint_field(divint(this->integer,that.integer));
        if(same_sign) answer.set_sign(1);
        else answer.set_sign(-1);
        return answer;
    }
    catch(const char* err){
        cerr<<err<<'\n';
        exit(4);
    }
    return bint("0");
}

bint bint::operator%(const bint& that) const{
    bint answer = (*this)-(((*this)/that)*that);
    answer.set_sign(1);
    return answer;
}

bint& bint::operator+=(const bint a){
	*this = *this + a;
	return *this;
}

bint& bint::operator-=(const bint a){
	*this = *this - a;
	return *this;
}

bint& bint::operator*=(const bint a){
	*this = *this * a;
	return *this;
}

bint& bint::operator/=(const bint a){
	*this = *this / a;
	return *this;
}