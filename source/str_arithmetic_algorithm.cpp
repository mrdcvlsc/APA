#include "bignum.h"

string bignum::internal_addition(string a, string b) const{
	
	vector<long> upperAdden = str_partby9to_long(a);
	vector<long> lowerAdden = str_partby9to_long(b);

	size_t adden_size = upperAdden.size();
	size_t n = adden_size+1ul;
	long *placeValueSums = new long[n];
	placeValueSums[0] = 0l;									  // set the value of the first digit of the answer to zero

	for(size_t i=0ul ;i<adden_size; ++i)
		placeValueSums[i+1]=upperAdden[i]+lowerAdden[i];
	//reverse(placeValueSums,placeValueSums+n);
	// shift the index values from left to right that is greater the 9
	// shifting is subtracting the current index form 10, and adding 1 to the next index
	for(size_t i=n-1ul; i>0ul; --i)
		if(placeValueSums[i]>999999999l){
			placeValueSums[i]=placeValueSums[i]-1000000000l;
			++placeValueSums[i-1];
		}
	//reverse(placeValueSums,placeValueSums+n);
	string shiftedStringAnswer="", temp;
	for(size_t i=0ul;i<n;++i){		
		placeValueSums[i] = abs(placeValueSums[i]);
		temp = to_string(placeValueSums[i]);
		string front_zeros(9-temp.size(),'0');
		shiftedStringAnswer+=(front_zeros+temp);
	}	
	delete [] placeValueSums;
	return removeFrontZeros(shiftedStringAnswer);
}

string bignum::internal_subtraction(string a, string b) const{

	vector<long>    minuend = str_partby9to_long(a);
	vector<long> subtrahend = str_partby9to_long(b);

	size_t minuend_size = minuend.size();
	size_t n = minuend_size+1ul;
	long *placeValueDifference = new long[n];
	placeValueDifference[0] = 0l; 

	for(size_t i=0l; i<minuend_size; ++i)
		placeValueDifference[i+1]=minuend[i]-subtrahend[i];

	//reverse(placeValueDifference,placeValueDifference+n);

	// shift the index values from left to right
	for(size_t i=n-1l; i>0ul; --i)
		if(placeValueDifference[i]<0l){
			placeValueDifference[i]=placeValueDifference[i]+1000000000l;
			--placeValueDifference[i-1];
		}

	//reverse(placeValueDifference,placeValueDifference+n);

	// run absolute() value for all numbers (turn all to positives) then convert it back to string
	string shiftedStringAnswer="", temp;
	for(size_t i=0ul;i<n;++i){
		placeValueDifference[i] = abs(placeValueDifference[i]);
		temp = to_string(placeValueDifference[i]);
		string front_zeros(9-temp.size(),'0');
		shiftedStringAnswer+=(front_zeros+temp);
	}
	delete [] placeValueDifference;
	return removeFrontZeros(shiftedStringAnswer);
}

string bignum::internal_multiplication(string upperNumber, string bottomNumber) const{
	
	vector<long> multiplicand = str_partby4to_long(upperNumber);
	vector<long> multiplier   = str_partby4to_long(bottomNumber);

	// set all values of product to zero
	size_t answerMaxLen = multiplicand.size()+multiplier.size(); 
	long int *productValues = new long int[answerMaxLen];
    for(size_t i=0ul; i<answerMaxLen; ++i){
    	productValues[i] = 0l;
    }

	// add the answer of the multiplicand and multiplier to the answer array
	for(size_t i=0ul; i<multiplier.size(); ++i){
		for(size_t j=0ul;j<multiplicand.size();++j){
			productValues[answerMaxLen-1-i-j] = productValues[answerMaxLen-1-i-j]+(multiplicand[multiplicand.size()-1-j]*multiplier[multiplier.size()-1-i]);
		}
	}

	for(size_t i=0ul;i<answerMaxLen;++i){
		if(productValues[answerMaxLen-1-i]>=10000l){
			long ten = ten_thsd(productValues[answerMaxLen-1-i]);
			long one = one_thsd(productValues[answerMaxLen-1-i],ten);
			productValues[answerMaxLen-1-i]=one;
			productValues[answerMaxLen-1-i-1]=productValues[answerMaxLen-1-i-1]+ten;
		}
	}

	string finalAnswer, temp;
	for(size_t i=0;i<answerMaxLen;++i){
		temp = to_string(productValues[answerMaxLen-1-i]);
		string front_zeros(4-temp.size(),'0');
		finalAnswer= front_zeros+temp+finalAnswer;
	}
	
	finalAnswer = removeFrontZeros(finalAnswer);

	delete [] productValues;
	return finalAnswer;
}

bignum bignum::internal_division(bignum& dividen, bignum& divisor) const{

	internal_division_check(dividen,divisor); // error checker

	if(dividen==divisor) return bignum("1");
	if(dividen=="0")     return bignum("0");
	if(divisor=="1")     return dividen;

	
	string 	answer	   = "", partialDividen = "",
		strDividen = dividen.data,
		strDivisor = divisor.data;

    long long partialCnt = 0;
  	bignum 	multiplier = "1", current;

	for(size_t i=0; i<strDividen.size();++i){
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

	return answer;
}