#include "bignum.h"

// -------------------- Comparison Operators --------------------

// the == operator is a base operator method used to create other comparison operators
bool bignum::operator==(const bignum& bnum_) const{
	size_t l_size = this->data.size();
	size_t r_size = bnum_.data.size();

	for(size_t i=0; i<l_size && i<r_size; ++i)
		if(this->data[i]!=bnum_.data[i])
			return false;
	return true;
}

// the < operator is another base operator method used to create other comparison operators
bool bignum::operator<(const bignum& bnum_) const{
	// new state floating point support
	bool l_IsPositive = this->data[0]!='-'?true:false;
	bool r_IsPositive = bnum_.data[0]!='-'?true:false;
	
	size_t l_size = this->data.size();
	size_t r_size = bnum_.data.size();

	//sign check
	     if( l_IsPositive && !r_IsPositive) return false;
	else if(!l_IsPositive &&  r_IsPositive) return true;
	else if( l_IsPositive ==  r_IsPositive){
		//decimal check
		for(size_t i=0; i<l_size || i<r_size; ++i){
			     if(this->data[i]=='.' && bnum_.data[i]!='.' &&  l_IsPositive) return true;
			else if(this->data[i]=='.' && bnum_.data[i]!='.' && !l_IsPositive) return false;
			else if(this->data[i]!='.' && bnum_.data[i]=='.' &&  l_IsPositive) return false;
			else if(this->data[i]!='.' && bnum_.data[i]=='.' && !l_IsPositive) return true;
			else if(this->data[i]=='.' && bnum_.data[i]=='.'){
				for(size_t j=0; j<l_size && j<r_size; ++j){
						 if(this->data[j]<bnum_.data[i] &&  l_IsPositive) return true;
					else if(this->data[j]<bnum_.data[i] && !l_IsPositive) return false;
					else if(this->data[j]>bnum_.data[i] &&  l_IsPositive) return false;
					else if(this->data[j]>bnum_.data[i] &&  l_IsPositive) return true;
				}
				return false;
			}
		}
		//length check
			 if(l_size<r_size &&  l_IsPositive) return true;
		else if(l_size<r_size && !l_IsPositive) return false;
		else if(l_size>r_size &&  l_IsPositive) return false;
		else if(l_size>r_size && !l_IsPositive) return true;
		else{
			for(size_t i=0; i<l_size && i<r_size; ++i){
				     if(this->data[i]<bnum_.data[i] and  l_IsPositive) return true;
				else if(this->data[i]<bnum_.data[i] and !l_IsPositive) return false;
				else if(this->data[i]>bnum_.data[i] and  l_IsPositive) return false;
				else if(this->data[i]>bnum_.data[i] and !l_IsPositive) return true;
			}
		}
	}
	return false;
}

bool bignum::operator!=(const bignum& bnum_) const{
	return !(*this==bnum_);
}

bool bignum::operator>(const bignum& bnum_) const{
	if((*this==bnum_))
		return false;
	return !(*this<bnum_);
}

bool bignum::operator<=(const bignum& bnum_) const{
	if(*this==bnum_)
		return true;
	return *this<bnum_;
}

bool bignum::operator>=(const bignum& bnum_) const{	
	if(*this==bnum_)
		return true;
	return *this>bnum_;
}

