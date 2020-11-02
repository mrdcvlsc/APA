#include "bignum.h"

string bignum::addstrn(string a, string b){

	bool upperAddenIsPositive = true, lowerAddenIsPositive = true;
	if(a[0]=='-') { upperAddenIsPositive = false; a[0]='0'; }
	if(b[0]=='-') { lowerAddenIsPositive = false; b[0]='0'; }

	int upperAdden[a.size()],
	    lowerAdden[b.size()],
	    placeValueSums[a.size()+1];
	int n = sizeof(placeValueSums)/sizeof(placeValueSums[0]);

	placeValueSums[0]=0;

	for(unsigned int i=0;i<a.size();++i){
		if(upperAddenIsPositive) upperAdden[i]= charToInt(a[i]);
		else     				 upperAdden[i]=-charToInt(a[i]);

		if(lowerAddenIsPositive) lowerAdden[i]= charToInt(b[i]);
		else    				 lowerAdden[i]=-charToInt(b[i]);
	}

	for(unsigned int i=0;i<a.size();++i)
		placeValueSums[i+1]=upperAdden[i]+lowerAdden[i];

	bool answerIsPositive = true;
	for(int i=0;i<n;++i)	
		if(placeValueSums[i]!=0)
			if(placeValueSums[i]<0){
				answerIsPositive = false;
				break;
			}
			else break;

	reverse(placeValueSums,placeValueSums+n);

	// shift the index values from left to right that is greater the 9
	// shifting is subtracting the current index form 10, and adding 1 to the next index
	for(int i=0;i<n-1;++i)
		if(placeValueSums[i]>9){
			placeValueSums[i]=placeValueSums[i]-10;
			++placeValueSums[i+1];
		}
		else if(placeValueSums[i]<-9){
			placeValueSums[i]=placeValueSums[i]+10;
			--placeValueSums[i+1];
		}
		else if(placeValueSums[i]>0 and !answerIsPositive){
			placeValueSums[i]=placeValueSums[i]-10;
			++placeValueSums[i+1];
		}
		else if(placeValueSums[i]<0 and answerIsPositive){
			placeValueSums[i]=placeValueSums[i]+10;
			--placeValueSums[i+1];
		}

	reverse(placeValueSums,placeValueSums+n);

	// run absolute() value for all numbers (turn all to positives)
	// convert it back to string
	string shiftedStringAnswer;
	for(int i=0;i<n;++i){
		placeValueSums[i] = abs(placeValueSums[i]);
		shiftedStringAnswer.push_back(intToChar(placeValueSums[i]));
	}	

	if(!answerIsPositive)
		shiftedStringAnswer="-"+shiftedStringAnswer;

	shiftedStringAnswer = removeFrontZeros(shiftedStringAnswer);
	return shiftedStringAnswer;
}

string bignum::substrn(string a, string b){

	bool minuendIsPositive = true, subtrahendIsPositive = true;
	if(a[0]=='-') { minuendIsPositive = false; a[0]='0'; }
	if(b[0]=='-') { subtrahendIsPositive = false; b[0]='0'; }

	int minuend[a.size()],
	    subtrahend[b.size()],
	    placeValueDifference[a.size()+1];
	int n = sizeof(placeValueDifference)/sizeof(placeValueDifference[0]);

	placeValueDifference[0]=0;

	for(unsigned int i=0;i<a.size();++i){
		if(minuendIsPositive) minuend[i]= charToInt(a[i]);
		else     				 minuend[i]=-charToInt(a[i]);

		if(subtrahendIsPositive) subtrahend[i]= charToInt(b[i]);
		else    				 subtrahend[i]=-charToInt(b[i]);
	}

	for(unsigned int i=0;i<a.size();++i)
		placeValueDifference[i+1]=minuend[i]-subtrahend[i];

	bool answerIsPositive = true;
	for(int i=0;i<n;++i)	
		if(placeValueDifference[i]!=0)
			if(placeValueDifference[i]<0){
				answerIsPositive = false;
				break;
			}
			else break;

	reverse(placeValueDifference,placeValueDifference+n);

	// shift the index values from left to right
	for(int i=0;i<n-1;++i)
		if(placeValueDifference[i]>9){
			placeValueDifference[i]=placeValueDifference[i]-10;
			++placeValueDifference[i+1];
		}
		else if(placeValueDifference[i]<-9){
			placeValueDifference[i]=placeValueDifference[i]+10;
			--placeValueDifference[i+1];
		}
		else if(placeValueDifference[i]>0 and !answerIsPositive){
			placeValueDifference[i]=placeValueDifference[i]-10;
			++placeValueDifference[i+1];
		}
		else if(placeValueDifference[i]<0 and answerIsPositive){
			placeValueDifference[i]=placeValueDifference[i]+10;
			--placeValueDifference[i+1];
		}

	reverse(placeValueDifference,placeValueDifference+n);

	// run absolute() value for all numbers (turn all to positives) then convert it back to string
	string shiftedStringAnswer;
	for(int i=0;i<n;++i){
		placeValueDifference[i] = abs(placeValueDifference[i]);
		shiftedStringAnswer.push_back(intToChar(placeValueDifference[i]));
	}

	if(!answerIsPositive)
		shiftedStringAnswer="-"+shiftedStringAnswer;

	shiftedStringAnswer = removeFrontZeros(shiftedStringAnswer);
	return shiftedStringAnswer;
}


string bignum::mltpstrn(string upperNumber, string bottomNumber){
	bool upperNumberIsPosivite = true, bottomNumberIsPositive = true;
	if(upperNumber[0] == '-') { upperNumberIsPosivite = false; upperNumber[0]='0'; }
	if(bottomNumber[0] == '-') { bottomNumberIsPositive = false; bottomNumber[0]='0'; }

	int upperNumberArray[upperNumber.size()],
	    bottomNumberArray[bottomNumber.size()],
		answerMaxLen = upperNumber.size()+bottomNumber.size();

	int productValues[answerMaxLen]; for(auto& e: productValues) e=0;
	    

	for(unsigned int i=0;i<upperNumber.size();++i){
		upperNumberArray[i] = charToInt(upperNumber[i]);
		bottomNumberArray[i]= charToInt(bottomNumber[i]);
	}

	
	for(int i=0;i<bottomNumber.size();++i){
		for(int j=0;j<upperNumber.size();++j){
			productValues[answerMaxLen-1-i-j]=productValues[answerMaxLen-1-i-j]+
				(upperNumberArray[upperNumber.size()-1-j]*
				 bottomNumberArray[bottomNumber.size()-1-i]);
		}
	}

	for(int i=0;i<answerMaxLen;++i){
		if(productValues[answerMaxLen-1-i]>=10){
			int ten = tens(productValues[answerMaxLen-1-i]);
			int one = ones(productValues[answerMaxLen-1-i],ten);
			productValues[answerMaxLen-1-i]=one;
			productValues[answerMaxLen-1-i-1]=productValues[answerMaxLen-1-i-1]+ten;
		}
	}

	string finalAnswer;
	for(int i=0;i<answerMaxLen;++i){
		finalAnswer=intToChar(productValues[answerMaxLen-1-i])+finalAnswer;
	}

	finalAnswer = removeFrontZeros(finalAnswer);
	if(upperNumberIsPosivite!=bottomNumberIsPositive)
		finalAnswer='-'+finalAnswer;

	return finalAnswer;
}
