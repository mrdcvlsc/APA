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
	BIGINT(int value): data(to_string(value)) {}
	BIGINT(string value){ check(value); data=value;}
	//BIGINT& operator=(string value);
	//BIGINT operator=(const char* value);
	BIGINT& operator=(string value);

	// necessary functions
	int    charToInt(char c){return (int)c - (int)'0';}
	char   intToChar(int n){return (char)'0'+ (char)n;}
	int    ones(int number, int tens);
	int    tens(int number);
	string removeFrontZeros(string input);


	// operators
	BIGINT operator+(const BIGINT& bigNum2);
	BIGINT operator-(const BIGINT& bigNum2);
	BIGINT operator*(const BIGINT& bigNum2);
	friend ostream& operator<<(ostream &out, const BIGINT &value);
	friend istream& operator>>(istream &in, BIGINT &value);
	friend bool operator<(const BIGINT& bintleft,const BIGINT& bintright);
	
	// error handling methods
	void check(string &value);

	//operation
	string addstrn(string a, string b);
	string substrn(string a, string b);
	string mltpstrn(string upperNumber, string bottomNumber);
};

#endif