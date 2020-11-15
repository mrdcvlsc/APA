#include "bignum.h"

string bignum::internal_addition(string a, string b){
	
	vector<long> upperAdden = str_partby9to_long(a);
	vector<long> lowerAdden = str_partby9to_long(b);

	long placeValueSums[upperAdden.size()+1];
	size_t n = sizeof(placeValueSums)/sizeof(placeValueSums[0]);
	placeValueSums[0] = 0;									  // set the value of the first digit of the answer to zero

	for(unsigned int i=0;i<upperAdden.size();++i)
		placeValueSums[i+1]=upperAdden[i]+lowerAdden[i];

	reverse(placeValueSums,placeValueSums+n);

	// shift the index values from left to right that is greater the 9
	// shifting is subtracting the current index form 10, and adding 1 to the next index
	for(int i=0;i<n-1;++i)
		if(placeValueSums[i]>999999999l){
			placeValueSums[i]=placeValueSums[i]-1000000000l;
			++placeValueSums[i+1];
		}

	reverse(placeValueSums,placeValueSums+n);

	string shiftedStringAnswer="", temp;
	for(int i=0;i<n;++i){		
		placeValueSums[i] = abs(placeValueSums[i]);
		temp = to_string(placeValueSums[i]);
		string front_zeros(9-temp.size(),'0');
		shiftedStringAnswer+=(front_zeros+temp);
	}	

	shiftedStringAnswer = removeFrontZeros(shiftedStringAnswer);
	
	return shiftedStringAnswer;
}

string bignum::internal_subtraction(string a, string b){

	vector<long>    minuend = str_partby9to_long(a);
	vector<long> subtrahend = str_partby9to_long(b);

	long placeValueDifference[minuend.size()+1];
	size_t n = sizeof(placeValueDifference)/sizeof(placeValueDifference[0]);
	placeValueDifference[0] = 0; 


	for(unsigned int i=0;i<minuend.size();++i)
		placeValueDifference[i+1]=minuend[i]-subtrahend[i];

	reverse(placeValueDifference,placeValueDifference+n);

	// shift the index values from left to right
	for(int i=0;i<n-1;++i)
		if(placeValueDifference[i]<0l){
			placeValueDifference[i]=placeValueDifference[i]+1000000000l;
			--placeValueDifference[i+1];
		}

	reverse(placeValueDifference,placeValueDifference+n);

	// run absolute() value for all numbers (turn all to positives) then convert it back to string
	string shiftedStringAnswer="", temp;
	for(int i=0;i<n;++i){
		placeValueDifference[i] = abs(placeValueDifference[i]);
		temp = to_string(placeValueDifference[i]);
		string front_zeros(9-temp.size(),'0');
		shiftedStringAnswer+=(front_zeros+temp);
	}

	shiftedStringAnswer = removeFrontZeros(shiftedStringAnswer);
	
	return shiftedStringAnswer;
}

string bignum::internal_multiplication(string upperNumber, string bottomNumber){
	
	vector<long> multiplicand = str_partby9to_long(upperNumber);
	vector<long> multiplier   = str_partby9to_long(bottomNumber);

	// set all values of product to zero
	size_t answerMaxLen = multiplicand.size()+multiplier.size(); 
	long productValues[answerMaxLen];
	for(auto& e: productValues) e=0l;

	// add the answer of the multiplicand and multiplier to the answer array
	for(size_t i=0;i<multiplier.size();++i){
		for(size_t j=0;j<multiplicand.size();++j){
			productValues[answerMaxLen-1-i-j] = productValues[answerMaxLen-1-i-j]+
							   (multiplicand[multiplicand.size()-1-j]*
				 			    multiplier[multiplier.size()-1-i]);
		}
	}

	for(size_t i=0;i<answerMaxLen;++i){
		if(productValues[answerMaxLen-1-i]>=1000000000l){
			long ten = tens(productValues[answerMaxLen-1-i]);
			long one = ones(productValues[answerMaxLen-1-i],ten);
			productValues[answerMaxLen-1-i]=one;
			productValues[answerMaxLen-1-i-1]=productValues[answerMaxLen-1-i-1]+ten;
		}
	}

	string finalAnswer, temp;
	for(size_t i=0;i<answerMaxLen;++i){
		temp = to_string(productValues[answerMaxLen-1-i]);
		string front_zeros(9-temp.size(),'0');
		finalAnswer= front_zeros+temp+finalAnswer;
	}

	finalAnswer = removeFrontZeros(finalAnswer);

	return finalAnswer;
}

bignum bignum::internal_division(bignum& dividen, bignum& divisor){

	internal_division_check(dividen,divisor); // error checker

	if(dividen==divisor) return bignum("1");
	if(dividen=="0")     return bignum("0");
	if(divisor=="1")     return dividen;

	string 	answer	   = "", partialDividen = "",
		strDividen = dividen.data,
		strDivisor = divisor.data;

    	int 	partialCnt = 0;
  	bignum 	multiplier = "1",
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

	return bignum(answer);
}