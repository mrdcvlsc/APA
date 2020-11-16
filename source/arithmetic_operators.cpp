#include "bignum.h"

// ----------------- INCREMENT/DECREMENT OPERATORS ---------------------------

//pre-fix increment/decrementa
bignum bignum::operator++(){
	this->data = (bignum(this->data)+bignum("1")).data;
	return bignum(data);
}

bignum bignum::operator--(){
	this->data = (bignum(this->data)-bignum("1")).data;
	return bignum(data);
}

//post-fix increment/decrementa
bignum bignum::operator++(int){
        this->data = (bignum(this->data)+bignum("1")).data;
        return bignum(this->data)-bignum("1"); 
}

bignum bignum::operator--(int){
        this->data = (bignum(this->data)-bignum("1")).data;
        return bignum(this->data)+bignum("1");
} 

// --------------------------------------------------------------------------

// -------------------- Arithmetic Operators --------------------

bignum bignum::operator+(const bignum& bigintNumber){

	// temporary values	
	bignum t_adden1 = bignum(this->data),
	       t_adden2 = bigintNumber;
	
	// if there is a float value
	if(t_adden1.isFloat() or t_adden2.isFloat()){

		pair<string,string> adden1_slices = dec_slice(t_adden1.data),
						    adden2_slices = dec_slice(t_adden2.data);
	    
	    // whole values
		string adden1w = adden1_slices.first,
		       adden2w = adden2_slices.first;

		// point values       
		string adden1d = adden1_slices.second,
		       adden2d = adden2_slices.second;

		pair<string,string> newWhl = strfront_fill0(adden1w,adden2w);
		pair<string,string> newDec = strback_fill0(adden1d,adden2d);

		string makeWholeAdden1 = newWhl.first + newDec.first;
		string makeWholeAdden2 = newWhl.second + newDec.second;

		bignum answerWhole = bignum(makeWholeAdden1) + bignum(makeWholeAdden2);

		string finalAnswer = answerWhole.data.insert(answerWhole.data.size()-newDec.first.size(),".");

		return bignum(finalAnswer);
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
	string adden1 = add_num.first,
		   adden2 = add_num.second;
	
	// different sign
	if(!same_sign and adden1isMax){
		if(pos_adden1)
			return bignum(internal_subtraction(adden1,adden2));
		return bignum(("-"+internal_subtraction(adden1,adden2)));
	}
	else if(!same_sign and !adden1isMax){
		if(pos_adden2)
			return bignum(internal_subtraction(adden2,adden1));
		return bignum(("-"+internal_subtraction(adden2,adden1)));
	}

	// perform internal addition
	string answer = internal_addition(adden1,adden2);

	// same sign both negative
	if(same_sign and !pos_adden1 and !pos_adden2)
		return bignum(("-"+answer));

	// same sign bot positive
	return bignum(answer);
}

bignum bignum::operator-(const bignum& bigintNumber){
	
	// temporary values	
	bignum t_minuend    = bignum(this->data),
	       t_subtrahend = bigintNumber;

	if(t_minuend == t_subtrahend)
		return bignum("0");

	// if there is a float value
	if(t_minuend.isFloat() || t_subtrahend.isFloat()){

		pair<string,string> minuend_slices    = dec_slice(t_minuend.data),
						    subtrahend_slices = dec_slice(t_subtrahend.data);
	    
	    // whole values
		string minuend_w = minuend_slices.first,
		       subtrahend_w = subtrahend_slices.first;

		// point values       
		string minuend_d    = minuend_slices.second,
		       subtrahend_d = subtrahend_slices.second;

		pair<string,string> newWhl = strfront_fill0(minuend_w,subtrahend_w);
		pair<string,string> newDec = strback_fill0(minuend_d,subtrahend_d);

		string makeWholeMinuend    = newWhl.first + newDec.first;
		string makeWholeSubtrahend = newWhl.second + newDec.second;

		bignum answerWhole = bignum(makeWholeMinuend) - bignum(makeWholeSubtrahend);

		string padzero(newDec.first.size(),'0');

		bool isNegative = false;
		if(answerWhole<"0"){
			answerWhole = absolute(answerWhole);
			isNegative = true;
		}

		string tempWhole = padzero+answerWhole.data;

		string finalAnswer = tempWhole.insert(tempWhole.size()-newDec.first.size(),".");

		if(isNegative) finalAnswer = "-" + finalAnswer;
		finalAnswer = removeRearZeros(removeFrontZeros(finalAnswer));
		
		return bignum(finalAnswer);
	}
	
	// apply rules of subtraction
	bool same_sign       = sameSign(t_minuend,t_subtrahend);
	bool pos_minuend     = t_minuend.isPositive();
	bool pos_subtrahend  = t_subtrahend.isPositive();

	t_minuend = absolute(t_minuend);
	t_subtrahend = absolute(t_subtrahend);

	bool minuendIsMax = t_minuend>t_subtrahend; 

	// add zeros to front to match the length of each other
	pair<string,string> sub_num = strfront_fill0(t_minuend.data,t_subtrahend.data);
	string    minuend = sub_num.first,
		   subtrahend = sub_num.second;


	//same sign
	if(minuendIsMax){
		if(same_sign && pos_minuend)	   
			return bignum(internal_subtraction(minuend,subtrahend));
		else if(same_sign && !pos_minuend)
			return bignum("-"+internal_subtraction(minuend,subtrahend));
	}
	else{
		if(same_sign && !pos_minuend)
			return bignum(internal_subtraction(subtrahend,minuend));
		else if(same_sign && pos_minuend)
			return bignum("-"+internal_subtraction(subtrahend,minuend));
	}

	//different sign
	if(minuendIsMax){
		if(pos_minuend)
			return bignum(internal_addition(minuend,subtrahend));
		else if(!pos_minuend)
			return bignum("-"+internal_addition(minuend,subtrahend));
	}
	else{
		if(pos_minuend)
			return bignum(internal_addition(minuend,subtrahend));
		else if(!pos_minuend)
			return bignum("-"+internal_addition(minuend,subtrahend));
	}
	return bignum(internal_subtraction(minuend,subtrahend));
}

bignum bignum::operator*(const bignum& bigintNumber){
	
	// temporary values	
	bignum t_multiplicand = bignum(this->data),
	       t_multiplier   = bigintNumber;

	if(t_multiplicand == "0" || t_multiplier == "0")
		return bignum("0");

	// if there is a float value
	if(t_multiplicand.isFloat() || t_multiplier.isFloat()){
		
		bool same_sign_float = sameSign(t_multiplicand,t_multiplier);
		
		t_multiplicand = absolute(t_multiplicand);
		t_multiplier   = absolute(t_multiplier);

		pair<string,string> multiplicand_slices = dec_slice(t_multiplicand.data),
						    multiplier_slices   = dec_slice(t_multiplier.data);
	    
	    // whole values
		string multiplicand_w = multiplicand_slices.first,
		       multiplier_w   = multiplier_slices.first;

		// point values       
		string multiplicand_d = multiplicand_slices.second,
		       multiplier_d   = multiplier_slices.second;


		pair<string,string> newWhl = strfront_fill0(multiplicand_w,multiplier_w);
		pair<string,string> newDec = make_pair(multiplicand_d,multiplier_d);

		string makeWholeAdden1 = newWhl.first + newDec.first;
		string makeWholeAdden2 = newWhl.second + newDec.second;

		bignum t1 = makeWholeAdden1;
		bignum t2 = makeWholeAdden2;
		bignum answerWhole = (t1*t2);
		
		size_t mulcand  = multiplicand_d.size(),
		       mulplier = multiplier_d.size();

		string finalAnswer = answerWhole.data.insert(answerWhole.data.size()-(mulcand+mulplier),".");

		if(same_sign_float)
			return bignum(finalAnswer);
		
		return bignum("-"+finalAnswer);
	}

	// apply rules of multiplication
	bool same_sign = sameSign(t_multiplicand,t_multiplier);

	t_multiplicand = absolute(t_multiplicand);
	t_multiplier   = absolute(t_multiplier);

	// add zeros to front to match the length of each other
	pair<string,string> mul_num = strfront_fill0(t_multiplicand.data,t_multiplier.data);
	string multiplicand = mul_num.first,
		     multiplier = mul_num.second;
	
	// perform internal multiplication
	string answer = internal_multiplication(multiplicand,multiplier);

	if(!same_sign)
		return bignum("-"+answer);

	return bignum(answer);
}

bignum bignum::operator/(const bignum& input_divisor){

	bignum tempDividen = bignum(this->data),
	       tempDivisor = input_divisor.data;

	if(tempDividen == "0")
		return bignum("0");
	
	// check if they have different sign +-
	bool differentSign = false;
	if((tempDividen<"0" && tempDivisor>"0") || (tempDividen>"0" && tempDivisor<"0"))
		differentSign = true;

	// make the negatives positive
	tempDividen = absolute(tempDividen);
	tempDivisor = absolute(tempDivisor);

	// if decimal exist make it whole number
	pair<string,int> dividenPair, divisorPair;

	dividenPair = removeDecimal(tempDividen.data);
	divisorPair = removeDecimal(tempDivisor.data);

	int ddenDecPlace = dividenPair.second;
	int dsorDecPlace = divisorPair.second;

	tempDividen = dividenPair.first;
	tempDivisor = divisorPair.first;

	// check if dividen is less than divisor, add zero place to make it greater than divisor
	int additionalLen = 0;
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
	else               return bignum("-"+answer.data);
}

// --------------------------------------------------------------


// ------------------- SPECIAL OPERATORS -------------------------

bignum bignum::operator%(bignum& divisor){

	bignum dividen(this->data);

	if(divisor=="0"){
		cout<<"bignum ERROR [modulo] : ("<<dividen<<'%'<<divisor<<") dividing by zero is not possible"<<endl;
		exit(1);
	}

	if(dividen<divisor)  return dividen;
	if(dividen==divisor) return bignum("0");
	

	string answer = "", partialDividen = "",
	       strDividen = dividen.data,
	       strDivisor = divisor.data;

    	int    partialCnt = 0;
   	bignum multiplier = "1",
               current;

	for(int i=0; i<strDividen.size();++i){
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

		// back to default values
		partialCnt = 0;
		multiplier = "1";
	}
	bignum wholeAnswer = answer;
	
	return dividen-divisor*wholeAnswer;
}