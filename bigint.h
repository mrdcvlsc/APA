#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class BIGINT{
public:
	string data;
	bool valid;
	bool positive;
	
	BIGINT(){}
	BIGINT(const char* value){
		string temp = "";
		for(long i = 0;value[i]!='\0';++i)
			temp = temp+value[i];
		check(temp);
		this->data = temp;
	}
	BIGINT(string value){ check(value); data=value;}

	// necessary functions
	int    charToInt(char c){return (int)c - (int)'0';}
	char   intToChar(int n){return (char)'0'+ (char)n;}
	int    ones(int number, int tens);
	int    tens(int number);
	string removeFrontZeros(string input);


	// operators
	//pre-fix
	BIGINT operator++();
	BIGINT operator--();
	//post-fix
	BIGINT operator++(int);
        BIGINT operator--(int);

        //arithmetich operators
	BIGINT operator+(const BIGINT& bigNum2);
	BIGINT operator-(const BIGINT& bigNum2);
	BIGINT operator*(const BIGINT& bigNum2);

	//input and output stream operators
	friend ostream& operator<<(ostream &out, const BIGINT &value);
	friend istream& operator>>(istream &in, BIGINT &value);

	//comparison operators
	friend bool operator<(const BIGINT& bintleft,const BIGINT& bintright);
	friend bool operator>(const BIGINT& bintleft,const BIGINT& bintright);
	friend bool operator<=(const BIGINT& bintleft,const BIGINT& bintright);
	friend bool operator>=(const BIGINT& bintleft,const BIGINT& bintright);
	friend bool operator==(const BIGINT& bintleft,const BIGINT& bintright);
	friend bool operator!=(const BIGINT& bintleft,const BIGINT& bintright);

	// error handling methods
	void check(string &value);

	//operation
	string addstrn(string a, string b);
	string substrn(string a, string b);
	string mltpstrn(string upperNumber, string bottomNumber);
};

#endif

// next goals:
//		-> add division operation with overloaded /(division) operator
//		-> add a direct const char* operator functionality to comparison operator
//		   to enable aBigIntVariable != "43434", bintvar > "323" (direct comparison) 
