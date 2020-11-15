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
#include <vector>
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

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**********************************      CONSTRUCTORS      **********************************/
	//////////////////////////////////////////////////////////////////////////////////////////////

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

	//////////////////////////////////////////////////////////////////////////////////////////////
	/****************************** BELOW ARE THE INSIDE FUNCTIONS ******************************/
	//////////////////////////////////////////////////////////////////////////////////////////////

		// this functions are only used inside the class

	// partition/slice function
	vector<long>		str_partby9to_long(string number);
	pair<string,string> dec_slice(string float_number);

	// fill zeros function
	pair<string,string> strfront_fill0(string a, string b);
	pair<string,string> strback_fill0(string a, string b);
	
	// remove functions
	pair<string,int> 	removeDecimal(const string& bignumber);
	string				removeFrontZeros(string input);
	string				removeRearZeros(string input);
	
	// get and put decimal funtions
	string 				putDecimal(const string& bignumber, int index);
	int	   				getDecimalPlaces(string input);
	
	// convertion functions
	char   				intToChar(const int& n)  const { return (char)'0'+ (char)n;}
	int    				charToInt(const char& c) const { return (int)c - (int)'0';}
	
	// multiplication shifting functions
	long   				ones(long number, long tens);
	long   				tens(long number);
	
	// check functions
	bool   				isPositive();
	bool				isFloat();
	bool    			sameSign(const bignum& a, const bignum& b);
	
	// bignum functions
	bignum 				absolute(const bignum& input);
	bignum 				in_max(const bignum a, const bignum b);
	bignum 				in_min(const bignum a, const bignum b);

	/////////////////////////////////////////////////////////////////////////////////////////////
	/***********************************      OPERATORS      ***********************************/
	/////////////////////////////////////////////////////////////////////////////////////////////

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

	//////////////////////////////////////////////////////////////////////////////////////////////////
	/*********************************   ERROR HANDLING FUNCTIONS   *********************************/
	//////////////////////////////////////////////////////////////////////////////////////////////////

	void check(string &value);
	void internal_division_check(const bignum& value_1, const bignum& value_2);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	/**************************************  INTERNAL METHODS  **************************************/
	//////////////////////////////////////////////////////////////////////////////////////////////////

	// internal operation for arithmetic operators
	string internal_addition(string a, string b);
	string internal_subtraction(string a, string b);
	string internal_multiplication(string upperNumber, string bottomNumber);
	bignum internal_division(bignum& dividen, bignum& divisor);	// this method is dependent on the 3 basic arithmetic operators
								
};

#endif