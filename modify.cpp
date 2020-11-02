#include "bignum.h"

int bignum::ones(int number, int tens){
	return number-(tens*10);
}

int bignum::tens(int number){
	return (int)floor((double)number/10);
}

string bignum::removeFrontZeros(string input){
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
