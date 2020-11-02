#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class bignum{
public:
	string data;
	bool valid;
	bool is_float;

	// constructors
	bignum():data("0"), valid(true), is_float(false) {}
	bignum(const char* value){
		string temp(value);
		check(temp);
		this->data = temp;
		is_float = true; // this is temporary, should be change when operation with floating point is added
	}
	bignum(string value){ check(value); data=value; is_float=false; }

	// necessary functions
	int    charToInt(const char& c) const { return (int)c - (int)'0';}
	char   intToChar(const int& n)  const { return (char)'0'+ (char)n;}
	int    ones(int number, int tens);
	int    tens(int number);
	string removeFrontZeros(string input);


	// operators
	//pre-fix
	bignum operator++();
	bignum operator--();
	//post-fix
	bignum operator++(int);
    bignum operator--(int);

    //arithmetich operators
	bignum operator+(const bignum& bigNum2);
	bignum operator-(const bignum& bigNum2);
	bignum operator*(const bignum& bigNum2);


	//input and output stream operators
	friend ostream& operator<<(ostream &out, const bignum &value);
	friend istream& operator>>(istream &in, bignum &value);


	//comparison operators
	bool operator<(const bignum& bintright)  const;  // base method (use to create other comparison operators)
	bool operator>(const bignum& bintright)  const;
	bool operator<=(const bignum& bintright) const;
	bool operator>=(const bignum& bintright) const;
	bool operator==(const bignum& bintright) const;  // base method (use to create other comparison operators)
	bool operator!=(const bignum& bintright) const;

	// bignum left, const char* right
	bool operator<(const char* dQuoteStrValue) const;
	bool operator>(const char* dQuoteStrValue) const; 
	bool operator<=(const char* dQuoteStrValue) const;
	bool operator>=(const char* dQuoteStrValue) const;
	bool operator!=(const char* dQuoteStrValue) const;
	bool operator==(const char* dQuoteStrValue) const;

	// const char* left, bignum left
	friend bool operator <  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator <=  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >=  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator == (const char* dQuoteStrValue, const bignum& left);
	friend bool operator != (const char* dQuoteStrValue, const bignum& left);


	// error handling methods
	void check(string &value);

	//operation
	string addstrn(string a, string b);
	string substrn(string a, string b);
	string mltpstrn(string upperNumber, string bottomNumber);
};

#endif

////////////////////////////////////////////////////////////////////////
///		RECENT UPDATES :											 ///
///			- the prefix and post-fix version of increment			 ///
///		      and decrement operators and it's functionality		 ///
///			  is added.												 ///
///			- the >, >=, ==, != and <= operators are added			 ///
///			- use of = for declaration/initiation of bigint value 	 ///
///			  is added also											 ///
////////////////////////////////////////////////////////////////////////

// next goals:
//		-> add division operation with overloaded /(division) operator
//		-> add a direct const char* operator functionality to comparison operator
//		   to enable aBigIntVariable != "43434", bintvar > "323" (direct comparison) 