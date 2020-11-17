#include "bignum.h"

bignum::bignum(short int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}

bignum::bignum(unsigned short int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}

bignum::bignum(int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}

bignum::bignum(unsigned int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(long int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(unsigned long int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(long long int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(unsigned long long int value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(float value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(double value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(long double value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
}
bignum::bignum(const char* value){
		string temp(value);
		check(temp);	
		temp = removeFrontZeros(temp);
		this->data = temp;
}
bignum::bignum(string value){
		check(value);
		string value2 = removeFrontZeros(value);
		this->data=value2;
}
