#include "bignum.h"

int bignum::ones(int number, int tens){
	return number-(tens*10);
}

int bignum::tens(int number){
	return (int)floor((double)number/10);
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

string bignum::removeFrontZeros(string input){
	
	bool stillzero = true;
	
	for(int i=0;i<input.size() and stillzero;++i){
		if(input.size()>=2){
			if(input[i]=='0' and input[i+1]=='.')
				break;
		}
		if(input[i]=='0' and input.size()!=1){
			input.erase(i,1);
			i=-1;
		}
		if(input[i]>='1' and input[i]<='9')
			stillzero = false;
	}
	
	return input;
}

string bignum::removeRearZeros(string input){
	
	bool stillzero = true;
	
	while(input[input.size()-1]=='0' or input[input.size()-1]=='.')
		input.erase(input.size()-1);

	return input;
}

bignum bignum::absolute(const bignum input){
	
	if(input<"0")
		return bignum(input.data.substr(1,input.data.size()-1));
	
	return input;
}
