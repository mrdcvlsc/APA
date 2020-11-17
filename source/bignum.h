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
	bignum(short int value);
	bignum(unsigned short int value);
	bignum(int value);
	bignum(unsigned int value);
	bignum(long int value);
	bignum(unsigned long int value);
	bignum(long long int value);
	bignum(unsigned long long int value);
	bignum(float value);
	bignum(double value);
	bignum(long double value);
	bignum(const char* value);
	bignum(string value);

	//////////////////////////////////////////////////////////////////////////////////////////////
	/****************************** BELOW ARE THE INSIDE FUNCTIONS ******************************/
	//////////////////////////////////////////////////////////////////////////////////////////////

	// this functions are only used inside the class

	//partition/slice function
	vector<long>		str_partby9to_long(string number);
	vector<long>		str_partby4to_long(string number);
	pair<string,string> dec_slice(string float_number);

	//fill zeros function
	pair<string,string> strfront_fill0(string a, string b);
	pair<string,string> strback_fill0(string a, string b);
	
	//remove functions
	pair<string,int> 	removeDecimal(const string& bignumber);
	string				removeFrontZeros(string input);
	string				removeRearZeros(string input);
	
	//get and put decimal funtions
	string 				putDecimal(const string& bignumber, int index);
	int	   				getDecimalPlaces(string input);
	
	//convertion functions
	char   				intToChar(const int& n)  const { return (char)'0'+ (char)n;}
	int    				charToInt(const char& c) const { return (int)c - (int)'0';}
	
	//multiplication shifting functions
	long   				ones(long number, long tens);
	long   				tens(long number);
	long   				one_thsd(long number, long tens);
	long   				ten_thsd(long number);
	
	//check functions
	bool   				isPositive();
	bool				isFloat();
	bool    			sameSign(const bignum& a, const bignum& b);
	
	//bignum functions
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

	template<class N>friend bignum operator+(N cn,const bignum& bn){bignum ra=ra.pa(cn,bn);return ra;}
	template<class N>friend bignum operator-(N cn,const bignum& bn){bignum ra=ra.ps(cn,bn);return ra;}
	template<class N>friend bignum operator*(N cn,const bignum& bn){bignum ra=ra.pm(cn,bn);return ra;}
	template<class N>friend bignum operator/(N cn,const bignum& bn){bignum ra=ra.pd(cn,bn);return ra;}

	template<class N> bignum pa(N cn,bignum bn){return bignum(cn)+bn;}
	template<class N> bignum ps(N cn,bignum bn){return bignum(cn)-bn;}
	template<class N> bignum pm(N cn,bignum bn){return bignum(cn)*bn;}
	template<class N> bignum pd(N cn,bignum bn){return bignum(cn)/bn;}

	bignum operator%(bignum& divisor); //modulo operator
	
	//pre-fix and post-fix increment/decrement
	bignum operator++(); //pre
	bignum operator--();
	bignum operator++(int); //post
    bignum operator--(int);

	//input and output stream operators
	friend ostream& operator<<(ostream &out, const bignum &value);
	friend istream& operator>>(istream &in, bignum &value);

	//comparison operators
	bool operator< (const bignum& bintright) const;  // base method (use to create other comparison operators)
	bool operator> (const bignum& bintright) const;
	bool operator<=(const bignum& bintright) const;
	bool operator>=(const bignum& bintright) const;
	bool operator==(const bignum& bintright) const;  // base method (use to create other comparison operators)
	bool operator!=(const bignum& bintright) const;

	friend bool operator <  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >  (const char* dQuoteStrValue, const bignum& left);
	friend bool operator <= (const char* dQuoteStrValue, const bignum& left);
	friend bool operator >= (const char* dQuoteStrValue, const bignum& left);
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

	//internal operation for arithmetic operators
	string internal_addition(string a, string b);
	string internal_subtraction(string a, string b);
	string internal_multiplication(string upperNumber, string bottomNumber);
	bignum internal_division(bignum& dividen, bignum& divisor);	// this method is dependent on the 3 basic arithmetic operators
								
};

#endif