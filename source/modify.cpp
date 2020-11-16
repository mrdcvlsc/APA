#include "bignum.h"

long bignum::ones(long number, long tens){ // one_hundred_mil 
	return number-(tens*1000000000l);
}

long bignum::tens(long number){				// o
	return (long)floor((double)number/1000000000.0);
}

long bignum::one_thsd(long number, long tens){
	return number-(tens*10000l);
}

long bignum::ten_thsd(long number){
	return (long)floor((double)number/10000.0);
}


pair<string,int> bignum::removeDecimal(const string& input){
	
	string bignumber = input;
	int    place     = 0;
	bool   got       = false;
	
	for(int i=0; i<bignumber.size(); ++i)
		if(bignumber[i]=='.'){
			bignumber.erase(i,1);
			got = true;
			place = i;
			break;
		} 
	
	place = bignumber.size()+1-place;
	if(!got) place = 0;
	
	return make_pair(bignumber,place);
}

string bignum::putDecimal(const string& bignumber, int index){
	
	string tempFrontZero(index,'0');
	string answer = tempFrontZero+bignumber;
	answer.insert((answer.size()-index),".");
	
	return answer;
}

int bignum::getDecimalPlaces(string input){
	
	int i = input.size()-1;
	while(input[i]!='.')
		--i;
	
	return input.size()-i-1;
}

string bignum::removeFrontZeros(string numbers){
	
	bool stillzero = true;
	string input = numbers;
	
	for(int i=0;i<input.size() && stillzero;++i){
		if(input.size()>=2){
			if(input[i]=='0' && input[i+1]=='.')
				break;
		}
		if(input[i]=='0' && input.size()!=1){
			input.erase(i,1);
			i=-1;
			continue;
		}
		if(input[i]>='1' && input[i]<='9')
			stillzero = false;
	}

	return input;
}

string bignum::removeRearZeros(string input){
	
	bool stillzero = true;
	
	while(input[input.size()-1]=='0' or input[input.size()-1]=='.'){
		if(input[input.size()-1]=='.'){
			input.erase(input.size()-1);
			break;
		}

		input.erase(input.size()-1);
	}

	return input;
}

bignum bignum::absolute(const bignum& input){
	
	if(input<"0")
		return bignum(input.data.substr(1,input.data.size()-1));
	
	return bignum(input);
}

vector<long> bignum::str_partby9to_long(string number){
	
	reverse(number.begin(),number.end());

	vector<string> str_partition;
	vector<long>   long_partition;

	for(size_t i=0; i<number.size();++i){
		if(i==0 or i%9==0)
			str_partition.push_back("");
		str_partition.back() = number[i] + str_partition.back();
	}

	for(size_t i=0; i<str_partition.size(); ++i)	
		long_partition.push_back(stol(str_partition[i]));

	reverse(long_partition.begin(),long_partition.end());
	
	return long_partition;
}


vector<long> bignum::str_partby4to_long(string number){
	
	reverse(number.begin(),number.end());

	vector<string> str_partition;
	vector<long>   long_partition;

	for(size_t i=0; i<number.size();++i){
		if(i==0 or i%4==0)
			str_partition.push_back("");
		str_partition.back() = number[i] + str_partition.back();
	}

	for(size_t i=0; i<str_partition.size(); ++i)	
		long_partition.push_back(stol(str_partition[i]));

	reverse(long_partition.begin(),long_partition.end());
	
	return long_partition;
}

pair<string,string> bignum::strfront_fill0(string a, string b){

	size_t length1 = a.length();
	size_t length2 = b.length();

	string num1 = a,
	       num2 = b,
	       answerWidth;

	if(length1>length2){
		if(num2[0]=='-'){
			num2[0]='0';
			string pad(length1-length2,'0');
			num2=pad+num2;
			num2[0]='-';
			answerWidth=num1.size();
		}
		else{
			string pad(length1-length2,'0');
			num2=pad+num2;
			answerWidth=num1.size();
		}
	}
	else if(length2>length1){
		if(num1[0]=='-'){
			num1[0]='0';
			string pad(length2-length1,'0');
			num1=pad+num1;
			num1[0]='-';
			answerWidth=num2.size();
		}
		else{
			string pad(length2-length1,'0');
			num1=pad+num1;
			answerWidth=num2.size();
		}
	}

	return make_pair(num1,num2);
}

pair<string,string> bignum::strback_fill0(string a, string b){

	size_t length1 = a.length();
	size_t length2 = b.length();

	string num1 = a,
	       num2 = b,
	       answerWidth;

	if(length1>length2){
		if(num2[0]=='-'){
			num2[0]='0';
			string pad(length1-length2,'0');
			num2=num2+pad;
			num2[0]='-';
			answerWidth=num1.size();
		}
		else{
			string pad(length1-length2,'0');
			num2=num2+pad;
			answerWidth=num1.size();
		}
	}
	else if(length2>length1){
		if(num1[0]=='-'){
			num1[0]='0';
			string pad(length2-length1,'0');
			num1=num1+pad;
			num1[0]='-';
			answerWidth=num2.size();
		}
		else{
			string pad(length2-length1,'0');
			num1=num1+pad;
			answerWidth=num2.size();
		}
	}

	return make_pair(num1,num2);
}

pair<string,string> bignum::dec_slice(string float_number){
	
	size_t point = 0;
	for(int i=0;i<float_number.size();++i){
		if(float_number[i]=='.'){
			point = i;
			break;
		}
	}

	if(!point)
		return make_pair(float_number,"");

	string part1 = float_number.substr(0,point);
	string part2 = float_number.substr(point+1);

	return make_pair(part1,part2);
}

bool bignum::isPositive(){
	if(bignum(this->data)<"0")
		return false;
	return true;
}

bignum bignum::in_max(const bignum a, const bignum b){
	if(a>b)
		return a;
	return b;
}

bignum bignum::in_min(const bignum a, const bignum b){
	if(a<b)
		return a;
	return b;	
}

bool bignum::sameSign(const bignum& a, const bignum& b){
	if((a>"0" && b>"0") or (a<"0" && b<"0"))
		return true;
	return false;
}

bool bignum::isFloat(){
	string temp = this->data;
	for(size_t i=0; i<temp.size(); ++i)
		if(temp[i] == '.')
			return true;
	return false;
}