#include "bignum.h"

// ----------------- INCREMENT/DECREMENT OPERATORS ---------------------------
  //pre-fix
	bignum bignum::operator++(){
		this->data = (bignum(this->data)+bignum("1")).data;
		return bignum(data);
	}
	bignum bignum::operator--(){
		this->data = (bignum(this->data)-bignum("1")).data;
		return bignum(data);
	}

  //post-fix
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

	string answer = addstrn(addenA,addenB);
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

	string answer = substrn(addenA,addenB);
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

	string answer = mltpstrn(upperNumber,bottomNumber);
	result.data = answer;
	return result;
}
// --------------------------------------------------------------
