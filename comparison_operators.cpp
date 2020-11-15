#include "bignum.h"

// -------------------- Comparison Operators --------------------

// the == operator is a base operator method used to create other comparison operators
bool bignum::operator==(const bignum& bintright) const{
	return (this->data==bintright.data);
}

// the < operator is another base operator method used to create other comparison operators
bool bignum::operator<(const bignum& bintright) const{
	bignum	left  = this->data,
		right = bintright;

	bool leftIsPositive  = left.data[0]  != '-' ? true : false;
	bool rightIsPositive = right.data[0] != '-' ? true : false;

	int leftLength  =  left.data.size();	
	int rightLength = right.data.size();

	if(!leftIsPositive){
		left.data.erase(0,1);
		leftLength--;
	}

	if(!rightIsPositive){
		right.data.erase(0,1);
		rightLength--;
	}

	if     (!leftIsPositive and rightIsPositive)  return true;
	else if(leftIsPositive and !rightIsPositive)  return false;
	else if(leftIsPositive and rightIsPositive){	
		if(leftLength<rightLength)
			return true;
		else if(leftLength == rightLength){
			for(int i=0;i<leftLength;++i){
				if(left.data[i] == right.data[i])
					continue;
				else if(left.data[i] < right.data[i])
					return true;
				else return false;
			}
		}
		else
			return false;
	}
	else if(!leftIsPositive and !rightIsPositive){  
		if(leftLength>rightLength)
			return true;
		else if(leftLength == rightLength){
			for(int i=0;i<leftLength;++i){
				if(left.data[i] == right.data[i])
					continue;
				else if(left.data[i] > right.data[i])
					return true;
				else return false;
			}
		}
		else
			return false;
	}
	return false;
}

bool bignum::operator!=(const bignum& bintright) const{
	
	bignum currentObjTmpCpy = this->data;
	return !(currentObjTmpCpy==bintright);
}

bool bignum::operator>(const bignum& bintright) const{
	
	bignum currentObjTmpCpy = this->data;
	
	if(currentObjTmpCpy==bintright)
		return false;
	
	return !(currentObjTmpCpy<bintright);
}

bool bignum::operator<=(const bignum& bintright) const{
	
	bignum currentObjTmpCpy = this->data;
	
	if(this->data==bintright.data)
		return true;
	
	return currentObjTmpCpy<bintright;
}

bool bignum::operator>=(const bignum& bintright) const{
	
	bignum currentObjTmpCpy = this->data;
	
	if(this->data==bintright.data)
		return true;
	
	return currentObjTmpCpy>bintright;
}


// ----- COMPARISON OPERATOR: for "const char*" (direct coded value) ex: (abignum == "723823") value not stored in bignum variable -----

// right const char * left bignum
bool operator < (const char* dQuoteStrValue, const bignum& left){
	return left<bignum(string(dQuoteStrValue));
}

bool operator > (const char* dQuoteStrValue, const bignum& left){
	return left>bignum(string(dQuoteStrValue));
}

bool operator <= (const char* dQuoteStrValue, const bignum& left){
	return left<=bignum(string(dQuoteStrValue));
}

bool operator >= (const char* dQuoteStrValue, const bignum& left){
	return left>=bignum(string(dQuoteStrValue));
}

bool operator ==(const char* dQuoteStrValue, const bignum& left){
	return left==bignum(string(dQuoteStrValue));
}

bool operator !=(const char* dQuoteStrValue, const bignum& left){
	return left!=bignum(string(dQuoteStrValue));
}