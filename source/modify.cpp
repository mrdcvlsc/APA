#include "bignum.h"

long bignum::ones(long number, long tens) const{ // one_hundred_mil 
	return number-(tens*1000000000l);
}

long bignum::tens(long number) const{				// o
	return (long)floor((double)number/1000000000.0);
}

long bignum::one_thsd(long number, long tens) const{
	return number-(tens*10000l);
}

long bignum::ten_thsd(long number) const{
	return (long)floor((double)number/10000.0);
}


pair<string,long long> bignum::removeDecimal(string bignumber) const{
	
	long long  place = 0;
	bool got   = false;
	
	size_t bn_size = bignumber.size(); 
	for(size_t i=0; i<bn_size; ++i)
		if(bignumber[i]=='.'){
			bignumber.erase(i,1);
			--bn_size;
			got = true;
			place = i;
			break;
		} 
	
	place = bn_size+1-place;
	if(!got) place = 0;
	
	return make_pair(bignumber,place);
}

string bignum::putDecimal(const string& bignumber, int index) const{
	
	string tempFrontZero(index,'0');
	string answer = tempFrontZero+bignumber;
	answer.insert((answer.size()-index),".");
	
	return answer;
}

int bignum::getDecimalPlaces(string input) const{
	
	size_t in_size = input.size();
	size_t i = in_size-1;
	while(input[i]!='.')
		--i;
	
	return in_size-i-1;
}

string bignum::removeFrontZeros(string input) const{
	
	bool stillzero = true;
	
	long long in_size = input.size();
	for(long long i=0;i<in_size && stillzero;++i){
		if(in_size>=2){
			if(input[i]=='0' && input[i+1]=='.')
				break;
		}
		if(input[i]=='0' && in_size!=1){
			input.erase(i,1);
			--in_size;
			i=-1;
			continue;
		}
		if(input[i]>='1' && input[i]<='9')
			stillzero = false;
	}
	return input;
}

string bignum::removeRearZeros(string input) const{
	
	size_t in_size = input.size();
	while(input[in_size-1]=='0' or input[in_size-1]=='.'){
		if(input[in_size-1]=='.'){
			input.erase(in_size-1);
			--in_size;
			break;
		}
		input.erase(in_size-1);
		--in_size;
	}
	return input;
}

bignum bignum::absolute(const bignum& input) const{
	string number = input.data;
	if(number[0] == '-'){
		number[0] = '0';
		number = removeFrontZeros(number);
	}
	return number;
}

vector<long> bignum::str_partby9to_long(string number) const{
	
	vector<string> str_partition;
	vector<long>   long_partition;

	size_t num_size = number.size();
	for(size_t i=0; i<num_size;++i){
		if(i==0 or i%9==0)
			str_partition.push_back("");
		str_partition.back() = number[num_size-1-i] + str_partition.back();
	}

	size_t str_size = str_partition.size();
	for(size_t i=0; i<str_size; ++i)	
		long_partition.push_back(stol(str_partition[str_size-1-i]));

	return long_partition;
}


vector<long> bignum::str_partby4to_long(string number) const{
	
	vector<string> str_partition;
	vector<long>   long_partition;

	size_t num_size = number.size();
	for(size_t i=0; i<num_size;++i){
		if(i==0 or i%4==0)
			str_partition.push_back("");
		str_partition.back() = number[num_size-1-i] + str_partition.back();
	}

	size_t str_size = str_partition.size();
	for(size_t i=0; i<str_size; ++i)	
		long_partition.push_back(stol(str_partition[str_size-1-i]));
	
	return long_partition;
}

pair<string,string> bignum::strfront_fill0(string a, string b) const{

	size_t length1 = a.length();
	size_t length2 = b.length();

	string num1 = a,
	       num2 = b;

	if(length1>length2){
		if(num2[0]=='-'){
			num2[0]='0';
			string pad(length1-length2,'0');
			num2=pad+num2;
			num2[0]='-';
		}
		else{
			string pad(length1-length2,'0');
			num2=pad+num2;
		}
	}
	else if(length2>length1){
		if(num1[0]=='-'){
			num1[0]='0';
			string pad(length2-length1,'0');
			num1=pad+num1;
			num1[0]='-';
		}
		else{
			string pad(length2-length1,'0');
			num1=pad+num1;
		}
	}
	return make_pair(num1,num2);
}

pair<string,string> bignum::strback_fill0(string a, string b) const{

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
		}
		else{
			string pad(length1-length2,'0');
			num2=num2+pad;
		}
	}
	else if(length2>length1){
		if(num1[0]=='-'){
			num1[0]='0';
			string pad(length2-length1,'0');
			num1=num1+pad;
			num1[0]='-';
		}
		else{
			string pad(length2-length1,'0');
			num1=num1+pad;
		}
	}
	return make_pair(num1,num2);
}

pair<string,string> bignum::dec_slice(string float_number) const{
	
	size_t point = 0;
	for(size_t i=0;i<float_number.size();++i){
		if(float_number[i]=='.'){
			point = i;
			break;
		}
	}
	if(!point)
		return make_pair(float_number,"");
	return make_pair(float_number.substr(0,point),float_number.substr(point+1));
}

bool bignum::isPositive() const{
	if(this->data[0] == '-')
		return false;
	return true;
}

bignum bignum::in_max(const bignum a, const bignum b) const{
	if(a>b)
		return a;
	return b;
}

bignum bignum::in_min(const bignum a, const bignum b) const{
	if(a<b)
		return a;
	return b;	
}

bool bignum::sameSign(const bignum& a, const bignum& b) const{
	if((a.data[0]=='-' && b.data[0]!='-') || (a.data[0]!='-' && b.data[0]=='-'))
		return false;
	return true;
}

bool bignum::isFloat()const{
	string temp = this->data;
	size_t tmp_size = temp.size();
	for(size_t i=0; i<(tmp_size/2)+1; ++i)
		if(temp[i] == '.' || temp[tmp_size-1-i] == '.')
			return true;
	return false;
}