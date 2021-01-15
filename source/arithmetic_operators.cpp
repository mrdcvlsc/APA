#include "bignum.h"

// ----------------- INCREMENT/DECREMENT OPERATORS ---------------------------

//pre-fix increment/decrementa
bignum bignum::operator++(){
	return *this = *this+"1"; 
}

bignum bignum::operator--(){
	return *this = *this-"1";
}

//post-fix increment/decrementa
bignum bignum::operator++(int){
    ++*this;
    return *this-"1"; 
}

bignum bignum::operator--(int){
    --*this;
    return *this+"1";
} 

// -------------------- Arithmetic Operators --------------------

bignum bignum::operator+(const bignum& right_bn) const{

	bignum t_adden1 = *this;
	bignum t_adden2 = right_bn;

	// if there is a float value
	if(t_adden1.isFloat() || t_adden2.isFloat()){

		pair<string,string> adden1_slices = dec_slice(t_adden1.data),
						    adden2_slices = dec_slice(t_adden2.data);

		pair<string,string> newWhl = strfront_fill0(adden1_slices.first,adden2_slices.first);
		pair<string,string> newDec = strback_fill0(adden1_slices.second,adden2_slices.second);

		bignum answerWhole = bignum(newWhl.first + newDec.first) + bignum(newWhl.second + newDec.second);
		return answerWhole.data.insert(answerWhole.data.size()-newDec.first.size(),".");
	}

	/////////// apply rules of addition ///////////
	bool same_sign   = sameSign(t_adden1,t_adden2);
	bool pos_adden1  = t_adden1.isPositive();
	bool pos_adden2  = t_adden2.isPositive();

	t_adden1 = absolute(t_adden1);
	t_adden2 = absolute(t_adden2);

	bool adden1isMax = t_adden1>t_adden2; 

	// add zeros to front to match the length of each other
	pair<string,string> add_num = strfront_fill0(t_adden1.data,t_adden2.data);
	
	// different sign
	if(!same_sign and adden1isMax){
		if(pos_adden1)
			return internal_subtraction(add_num.first,add_num.second);
		return "-"+internal_subtraction(add_num.first,add_num.second);
	}
	else if(!same_sign and !adden1isMax){
		if(pos_adden2)
			return internal_subtraction(add_num.second,add_num.first);
		return "-"+internal_subtraction(add_num.second,add_num.first);
	}

	// same sign both negative
	if(same_sign and !pos_adden1 and !pos_adden2)
		return "-"+internal_addition(add_num.first,add_num.second);

	// same sign bot positive
	return internal_addition(add_num.first,add_num.second);
}

bignum bignum::operator-(const bignum& right_bn) const{
	
	bignum t_minuend    = *this,
	       t_subtrahend = right_bn;

	// if there is a float value
	if(t_minuend.isFloat() || t_subtrahend.isFloat()){

		pair<string,string> minuend_slices    = dec_slice(t_minuend.data),
						    subtrahend_slices = dec_slice(t_subtrahend.data);

		pair<string,string> newWhl = strfront_fill0(minuend_slices.first,subtrahend_slices.first);
		pair<string,string> newDec = strback_fill0(minuend_slices.second,subtrahend_slices.second);

		bignum answerWhole = bignum(newWhl.first+newDec.first)-bignum(newWhl.second+newDec.second);

		string padzero(newDec.first.size(),'0');

		bool isNegative = false;
		if(answerWhole<"0"){
			answerWhole = absolute(answerWhole);
			isNegative = true;
		}

		string answer = padzero+answerWhole.data;
		answer = answer.insert(answer.size()-newDec.first.size(),".");

		if(isNegative) answer = "-" + answer;
		return removeRearZeros(removeFrontZeros(answer));
	}
	
	bool same_sign       = sameSign(t_minuend,t_subtrahend);
	bool pos_minuend     = t_minuend.isPositive();

	bool minuendIsMax = t_minuend>t_subtrahend;

	pair<string,string> sub_num = strfront_fill0(absolute(t_minuend).data,absolute(t_subtrahend).data);

	//apply rules of subtraction
	if(same_sign)
	{
		if(t_minuend==t_subtrahend) return "0";

		else if(pos_minuend){

			if(minuendIsMax)
				 return     internal_subtraction(sub_num.first,sub_num.second);
			else return "-"+internal_subtraction(sub_num.second,sub_num.first);
		}
		else if(!pos_minuend){

			if(minuendIsMax)
				 return     internal_subtraction(sub_num.second,sub_num.first);
			else return "-"+internal_subtraction(sub_num.first,sub_num.second);
		}
	}
	else
	{
		if(t_minuend<t_subtrahend)
			 return "-"+internal_addition(sub_num.first,sub_num.second);
		else return     internal_addition(sub_num.first,sub_num.second);
	}
	return "0";
}

bignum bignum::operator*(const bignum& right_bn) const{
	
	// temporary values	
	bignum t_multiplicand = *this,
	       t_multiplier   = right_bn;

	if(t_multiplicand == "0" || t_multiplier == "0")
		return "0";

	// if there is a float value
	if(t_multiplicand.isFloat() || t_multiplier.isFloat()){
		
		bool same_sign_float = sameSign(t_multiplicand,t_multiplier);

		t_multiplicand = absolute(t_multiplicand);
		t_multiplier   = absolute(t_multiplier);


		pair<string,string> multiplicand_slices = dec_slice(t_multiplicand.data),
						    multiplier_slices   = dec_slice(t_multiplier.data);
	    
		pair<string,string> newWhl = strfront_fill0(multiplicand_slices.first,multiplier_slices.first);
		pair<string,string> newDec = make_pair(multiplicand_slices.second,multiplier_slices.second);

		bignum t1 = newWhl.first + newDec.first;
		bignum t2 = newWhl.second + newDec.second;
		bignum answerWhole = (t1*t2);
		
		string finalAnswer = answerWhole.data.insert(answerWhole.data.size()-(multiplicand_slices.second.size()+multiplier_slices.second.size()),".");

		if(same_sign_float) return finalAnswer;
		return "-"+finalAnswer;
	}

	bool same_sign = sameSign(t_multiplicand,t_multiplier);
	pair<string,string> mul_num = strfront_fill0(absolute(t_multiplicand).data,absolute(t_multiplier).data);

	if(!same_sign)
		return "-"+internal_multiplication(mul_num.first,mul_num.second);
	return internal_multiplication(mul_num.first,mul_num.second);
}

bignum bignum::new_division_test(bignum a,bignum b) const{
	bignum tempDividen = a,
	       tempDivisor = b;

	if(tempDividen == "0") return bignum("0");
	
	bool differentSign = !sameSign(tempDividen,tempDivisor);

	// make the negatives positive
	tempDividen = absolute(tempDividen);
	tempDivisor = absolute(tempDivisor);

	// if decimal exist make it whole number
	pair<string,long long> dividenPair, divisorPair;

	dividenPair = removeDecimal(tempDividen.data);
	divisorPair = removeDecimal(tempDivisor.data);

	long long ddenDecPlace = dividenPair.second;
	long long dsorDecPlace = divisorPair.second;

	tempDividen = dividenPair.first;
	tempDivisor = divisorPair.first;

	// check if dividen is less than divisor, add zero place to make it greater than divisor
	long long additionalLen = 0;
	if(tempDividen<tempDivisor)
		additionalLen = 1+tempDivisor.data.size()-tempDividen.data.size();

	// add accuracy of 50 decimal palces
	string addAccuracy((25+additionalLen),'0');

	// create a temporary bignumber value where we will modify its decimal if it has
	bignum dividen = (tempDividen.data + addAccuracy);
	bignum divisor = tempDivisor;
	bignum temp    = internal_division(dividen,divisor);
	
	// bring back the decimal to its proper place
	string answerValue = temp.data;
	if((ddenDecPlace==0 and dsorDecPlace==0) || (ddenDecPlace>0 and dsorDecPlace>0))
		answerValue = putDecimal(answerValue,(25+additionalLen+(ddenDecPlace-dsorDecPlace)));
	else if(ddenDecPlace>0 and dsorDecPlace==0)
		answerValue = putDecimal(answerValue,(25+additionalLen+(ddenDecPlace-1)));
	else if(dsorDecPlace>0 and ddenDecPlace==0)
		answerValue = putDecimal(answerValue,(25+additionalLen-(dsorDecPlace-1)));
	
	answerValue = removeFrontZeros(answerValue);
	answerValue = removeRearZeros(answerValue);
	
	bignum answer = answerValue;
	
	if(!differentSign) return answer;
	else               return "-"+answer.data;
}

bignum bignum::operator/(const bignum& bnum_) const{

	bignum tempDividen = *this,
	       tempDivisor = bnum_.data;

	if(tempDividen == "0") return bignum("0");
	
	bool differentSign = !sameSign(tempDividen,tempDivisor);

	// make the negatives positive
	tempDividen = absolute(tempDividen);
	tempDivisor = absolute(tempDivisor);

	// if decimal exist make it whole number
	pair<string,long long> dividenPair, divisorPair;

	dividenPair = removeDecimal(tempDividen.data);
	divisorPair = removeDecimal(tempDivisor.data);

	long long ddenDecPlace = dividenPair.second;
	long long dsorDecPlace = divisorPair.second;

	tempDividen = dividenPair.first;
	tempDivisor = divisorPair.first;

	// check if dividen is less than divisor, add zero place to make it greater than divisor
	long long additionalLen = 0;
	if(tempDividen<tempDivisor)
		additionalLen = 1+tempDivisor.data.size()-tempDividen.data.size();

	// add accuracy of 50 decimal palces
	string addAccuracy((25+additionalLen),'0');

	// create a temporary bignumber value where we will modify its decimal if it has
	bignum dividen = (tempDividen.data + addAccuracy);
	bignum divisor = tempDivisor;
	bignum temp    = dev_div(dividen.data,divisor.data);
	
	// bring back the decimal to its proper place
	string answerValue = temp.data;
	if((ddenDecPlace==0 and dsorDecPlace==0) || (ddenDecPlace>0 and dsorDecPlace>0))
		answerValue = putDecimal(answerValue,(25+additionalLen+(ddenDecPlace-dsorDecPlace)));
	else if(ddenDecPlace>0 and dsorDecPlace==0)
		answerValue = putDecimal(answerValue,(25+additionalLen+(ddenDecPlace-1)));
	else if(dsorDecPlace>0 and ddenDecPlace==0)
		answerValue = putDecimal(answerValue,(25+additionalLen-(dsorDecPlace-1)));
	
	answerValue = removeFrontZeros(answerValue);
	answerValue = removeRearZeros(answerValue);
	
	bignum answer = answerValue;
	
	if(!differentSign) return answer;
	else               return "-"+answer.data;
}

// ------------------- SPECIAL OPERATORS -------------------------

bignum bignum::operator%(const bignum& divisor) const{

	bignum dividen =  *this;

	if(divisor=="0"){
		cout<<"bignum ERROR [modulo] : ("<<dividen<<'%'<<divisor<<") dividing by zero is not possible"<<endl;
		exit(1);
	}

	if(dividen<divisor)  return dividen;
	if(dividen==divisor) return bignum("0");
	
	string answer = "", partialDividen = "";
	string strDividen = dividen.data;
	string strDivisor = divisor.data;
	
	long long partialCnt = 0;
   	bignum multiplier = "1", current;
	
	size_t str_div_size = strDividen.size();
	for(size_t i=0; i<str_div_size; ++i){
		partialDividen = partialDividen + strDividen[i];
		current = partialDividen;

		if(divisor<=current){
			while((divisor*multiplier)<=current){
				++multiplier;
				++partialCnt;	
			}

			--multiplier;
			bignum longDivDividen = (divisor*multiplier);
			longDivDividen = current - longDivDividen;

			partialDividen = longDivDividen.data;

			if(partialDividen=="0") partialDividen="";
		}

		answer = answer + to_string(partialCnt);

		partialCnt = 0;
		multiplier = "1";
	}
	bignum wholeAnswer = answer;
	
	return dividen-divisor*wholeAnswer;
}
