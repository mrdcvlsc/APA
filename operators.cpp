#include "bigint.h"

// ---------- input and output stream operators ---------- 
ostream& operator<<(ostream &out, const BIGINT &value) {
    out << value.data;
    return out;
}

istream& operator>>(istream &in, BIGINT &value) {
	in >> value.data;
	return in;
}
// -------------------------------------------------------

// -------------------- Arithmetic Operators --------------------
BIGINT BIGINT::operator+(const BIGINT& bigintNumber){
	BIGINT result;
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

BIGINT BIGINT::operator-(const BIGINT& bigintNumber){
	BIGINT result;
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

BIGINT BIGINT::operator*(const BIGINT& bigintNumber){
	BIGINT result;
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


// -------------------- Comparison Operators --------------------
bool operator<(const BIGINT& bintleft,const BIGINT& bintright){
	BIGINT left  = bintleft,
	 	   right = bintright;

	bool leftIsPositive = left.data[0] != '-' ? true : false;
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

	if(!leftIsPositive and rightIsPositive) 
		return true;
	else if(leftIsPositive and !rightIsPositive)
		return false;
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
bool operator>(const BIGINT& bintleft,const BIGINT& bintright){
	if(bintleft.data==bintright.data)
		return false;
	if(bintleft<bintright)
		return false;
	return true;
}
bool operator<=(const BIGINT& bintleft,const BIGINT& bintright){
	if(bintleft.data==bintright.data)
		return true;
	return bintleft<bintright;
}
bool operator>=(const BIGINT& bintleft,const BIGINT& bintright){
	if(bintleft.data==bintright.data)
		return true;
	return bintleft>bintright;
}
bool operator==(const BIGINT& bintleft,const BIGINT& bintright){
	if(bintleft.data==bintright.data)
		return true;
	return false;
}
bool operator!=(const BIGINT& bintleft,const BIGINT& bintright){
	if(bintleft.data!=bintright.data)
		return true;
	return false;
}
// --------------------------------------------------------------

// ----------------- INCREMENT/DECREMENT OPERATORS ---------------------------
  //pre-fix
	BIGINT BIGINT::operator++(){
		this->data = (BIGINT(this->data)+BIGINT("1")).data;
		return BIGINT(data);
	}
	BIGINT BIGINT::operator--(){
		this->data = (BIGINT(this->data)-BIGINT("1")).data;
		return BIGINT(data);
	}

  //post-fix
	BIGINT BIGINT::operator++(int){
        this->data = (BIGINT(this->data)+BIGINT("1")).data;
        return BIGINT(this->data)-BIGINT("1"); 
    }

    BIGINT BIGINT::operator--(int){
        this->data = (BIGINT(this->data)-BIGINT("1")).data;
        return BIGINT(this->data)+BIGINT("1"); 
    } 
// --------------------------------------------------------------------------
