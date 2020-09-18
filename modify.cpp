#include "bigint.h"

int BIGINT::ones(int number, int tens){
	int ones = number-(tens*10);
	return ones;
}

int BIGINT::tens(int number){
	int tens = (int)floor((double)number/10);
	return tens;
}

string BIGINT::removeFrontZeros(string input){
	bool stillzero = true;
	for(int i=0;i<input.size() and stillzero;++i){
		if(input[i]=='0' and input.size()!=1){
			input.erase(i,1);
			i=-1;
		}
		if(input[i]>='1' and input[i]<='9')
			stillzero = false;
	}
	return input;
}