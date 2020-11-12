////////////////////////////////////////////////////////////////////////////
///		RECENT UPDATES :					 ///
///			- overloaded division operator			 ///
///			  division supports floating point I.O. values	 ///
///			- implemented internal_divison method		 ///
///			- along with modulo operator			 ///
////////////////////////////////////////////////////////////////////////////

#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class bignum{
public:
	string data;
	int precision;
	bool valid;
	bool is_float;

	// constructors
	bignum():data("0"), valid(true), is_float(false), precision(0) {}
	bignum(const char* value){
		string temp(value);
		check(temp);
		if(!is_float)	
			temp = removeFrontZeros(temp);
		this->data = temp;
	}
	bignum(string value){
		check(value);
		if(!is_float)
			value = removeFrontZeros(value);
		this->data=value; }

	// necessary functions
	int    charToInt(const char& c) const { return (int)c - (int)'0';}
	char   intToChar(const int& n)  const { return (char)'0'+ (char)n;}
	int    ones(int number, int tens);
	int    tens(int number);
	pair<string,int> removeDecimal(const string& bignumber);
	string putDecimal(const string& bignumber, int index);
	int	   getDecimalPlaces(string input);
	bignum absolute(const bignum input);
	string removeFrontZeros(string input);
	string removeRearZeros(string input);


	// OPERATORS

    //arithmetich operators
	bignum operator+(const bignum& bigNum2);
	bignum operator-(const bignum& bigNum2);
	bignum operator*(const bignum& bigNum2);
	bignum operator/(const bignum& bignum2);

	// modulo operator
	bignum operator%(bignum& divisor);
	
	//pre-fix increment/decrement
	bignum operator++();
	bignum operator--();

	//post-fix increment/decrement
	bignum operator++(int);
    bignum operator--(int);

	//input and output stream operators
	friend ostream& operator<<(ostream &out, const bignum &value);
	friend istream& operator>>(istream &in, bignum &value);

	//comparison operators bignum right, const char*/string left
	bool operator<(const bignum& bintright)  const;  // base method (use to create other comparison operators)
	bool operator>(const bignum& bintright)  const;
	bool operator<=(const bignum& bintright) const;
	bool operator>=(const bignum& bintright) const;
	bool operator==(const bignum& bintright) const;  // base method (use to create other comparison operators)
	bool operator!=(const bignum& bintright) const;

	// const char* left, bignum left
	friend bool operator <  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator <=  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >=  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator == (const char* dQuoteStrValue, const bignum& left);
	friend bool operator != (const char* dQuoteStrValue, const bignum& left);



	// error handling methods
	void check(string &value);
	void internal_division_check(const bignum& value_1, const bignum& value_2);

	/* ########################## INTERNAL METHODS ########################## */

	// internal operation for arithmetic operators
	string internal_addition(string a, string b);
	string internal_subtraction(string a, string b);
	string internal_multiplication(string upperNumber, string bottomNumber);
	bignum internal_division(bignum& dividen, bignum& divisor);	// this method is dependent on the 3 basic arithmetic operators
								
};

#endif
