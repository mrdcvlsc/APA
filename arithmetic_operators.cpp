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
	bignum result;
	size_t length1 = data.length();
	size_t length2 = bigintNumber.data.length();

	string addenA = data,
		   addenB = bigintNumber.data,
		   answerWidth;

	if(length1>length2){
		if(addenB[0]=='-'){
			addenB[0]='0';
			string pad(length1-length2,'0');
			addenB=pad+addenB;
			addenB[0]='-';
			answerWidth=addenA.size();
		}
		else{
			string pad(length1-length2,'0');
			addenB=pad+addenB;
			answerWidth=addenA.size();
		}
	}
	else if(length2>length1){
		if(addenA[0]=='-'){
			addenA[0]='0';
			string pad(length2-length1,'0');
			addenA=pad+addenA;
			addenA[0]='-';
			answerWidth=addenB.size();
		}
		else{
			string pad(length2-length1,'0');
			addenA=pad+addenA;
			answerWidth=addenB.size();
		}
	}

	string answer = internal_addition(addenA,addenB);
	result.data = answer;
	return result;
}

bignum bignum::operator-(const bignum& bigintNumber){
	bignum result;
	size_t length1 = data.length();
	size_t length2 = bigintNumber.data.length();

	string addenA = data,
		   addenB = bigintNumber.data,
		   answerWidth;

	if(length1>length2){
		if(addenB[0]=='-'){
			addenB[0]='0';
			string pad(length1-length2,'0');
			addenB=pad+addenB;
			addenB[0]='-';
			answerWidth=addenA.size();
		}
		else{
			string pad(length1-length2,'0');
			addenB=pad+addenB;
			answerWidth=addenA.size();
		}
	}
	else if(length2>length1){
		if(addenA[0]=='-'){
			addenA[0]='0';
			string pad(length2-length1,'0');
			addenA=pad+addenA;
			addenA[0]='-';
			answerWidth=addenB.size();
		}
		else{
			string pad(length2-length1,'0');
			addenA=pad+addenA;
			answerWidth=addenB.size();
		}
	}

	string answer = internal_subtraction(addenA,addenB);
	result.data = answer;
	return result;
}

bignum bignum::operator*(const bignum& bigintNumber){
	bignum result;
	size_t length1 = data.length();
	size_t length2 = bigintNumber.data.length();

	string upperNumber = data,
		   bottomNumber = bigintNumber.data,
		   answerWidth;

	if(length1>length2){
		if(bottomNumber[0]=='-'){
			bottomNumber[0]='0';
			string pad(length1-length2,'0');
			bottomNumber=pad+bottomNumber;
			bottomNumber[0]='-';
			answerWidth=upperNumber.size();
		}
		else{
			string pad(length1-length2,'0');
			bottomNumber=pad+bottomNumber;
			answerWidth=upperNumber.size();
		}
	}
	else if(length2>length1){
		if(upperNumber[0]=='-'){
			upperNumber[0]='0';
			string pad(length2-length1,'0');
			upperNumber=pad+upperNumber;
			upperNumber[0]='-';
			answerWidth=bottomNumber.size();
		}
		else{
			string pad(length2-length1,'0');
			upperNumber=pad+upperNumber;
			answerWidth=bottomNumber.size();
		}
	}

	string answer = internal_multiplication(upperNumber,bottomNumber);
	result.data = answer;
	return result;
}

bignum bignum::operator/(const bignum& input_divisor){

	bignum tempDividen = this->data,
	       tempDivisor = input_divisor.data;

	// check if they have different sign +-
	bool differentSign = false;
	if((tempDividen<"0" && tempDivisor>"0") || (tempDividen>"0" && tempDivisor<"0"))
		differentSign = true;

	// make the negatives positive
	tempDividen = absolute(tempDividen);
	tempDivisor = absolute(tempDivisor);

	// if decimal exist make it whole number
	pair<string,int> dividenPair,
					 divisorPair;

	dividenPair = removeDecimal(tempDividen.data);
	divisorPair = removeDecimal(tempDivisor.data);

	int ddenDecPlace = dividenPair.second;
	int dsorDecPlace = divisorPair.second;

	tempDividen = dividenPair.first;
	tempDivisor = divisorPair.first;

	cout<<"removed dn : "<<tempDividen<<endl;
	cout<<"removed dr : "<<tempDivisor<<endl;
	cout<<"dn : "<<ddenDecPlace<<endl;
	cout<<"dr : "<<dsorDecPlace<<endl;

	// check if dividen is less than divisor, add zero place to make it greater than divisor
	int additionalLen = 0;
	if(tempDividen<tempDivisor)
		additionalLen = 1+tempDivisor.data.size()-tempDividen.data.size();

	// add accuracy of 50 decimal palces
	string addAccuracy((25+additionalLen),'0');

	// create a temporary bignumber value where we will modify its decimal if it has
	bignum dividen = (tempDividen.data + addAccuracy);
	bignum divisor = tempDivisor;

	bignum temp = internal_division(dividen,divisor);
	
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
	
	if(!differentSign)
		return answer;
	else
		return bignum("-"+answer.data);
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

    	int partialCnt = 0;
    	bignum multiplier = "1", current;

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
