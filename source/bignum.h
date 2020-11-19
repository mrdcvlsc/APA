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

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**********************************      CONSTRUCTORS      **********************************/
	//////////////////////////////////////////////////////////////////////////////////////////////

	bignum():data("0"){}
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
	vector<long>		str_partby9to_long(string number) const;
	vector<long>		str_partby4to_long(string number) const;
	pair<string,string> dec_slice(string float_number) const;

	//fill zeros function
	pair<string,string> strfront_fill0(string a, string b) const;
	pair<string,string> strback_fill0(string a, string b) const;
	
	//remove functions
	pair<string,long long> 	removeDecimal(string bignumber) const;
	string				removeFrontZeros(string input) const;
	string				removeRearZeros(string input) const;
	
	//get and put decimal funtions
	string 				putDecimal(const string& bignumber, int index) const;
	int	   				getDecimalPlaces(string input) const;
	
	//convertion functions
	char   				intToChar(const int& n)  const { return (char)'0'+ (char)n;}
	int    				charToInt(const char& c) const { return (int)c - (int)'0';}
	
	//multiplication shifting functions
	long   				ones(long number, long tens) const;
	long   				tens(long number) const;
	long   				one_thsd(long number, long tens) const;
	long   				ten_thsd(long number) const;
	
	//check functions
	bool   				isPositive() const;
	bool			    isFloat() const;
	bool    			sameSign(const bignum& a, const bignum& b) const;
	
	//bignum functions
	bignum 				absolute(const bignum& input) const;
	bignum 				in_max(const bignum a, const bignum b) const;
	bignum 				in_min(const bignum a, const bignum b) const;

	/////////////////////////////////////////////////////////////////////////////////////////////
	/***********************************      OPERATORS      ***********************************/
	/////////////////////////////////////////////////////////////////////////////////////////////

    //arithmetich operators
	bignum operator+(const bignum& bigNum2) const;
	bignum operator-(const bignum& bigNum2) const;
	bignum operator*(const bignum& bigNum2) const;
	bignum operator/(const bignum& bignum2) const;

	template<class N>friend bignum operator+(N cn,const bignum& bn){bignum ra=ra.pa(cn,bn);return ra;}
	template<class N>friend bignum operator-(N cn,const bignum& bn){bignum ra=ra.ps(cn,bn);return ra;}
	template<class N>friend bignum operator*(N cn,const bignum& bn){bignum ra=ra.pm(cn,bn);return ra;}
	template<class N>friend bignum operator/(N cn,const bignum& bn){bignum ra=ra.pd(cn,bn);return ra;}

	template<class N> bignum pa(N cn,bignum bn)const{return bignum(cn)+bn;}
	template<class N> bignum ps(N cn,bignum bn)const{return bignum(cn)-bn;}
	template<class N> bignum pm(N cn,bignum bn)const{return bignum(cn)*bn;}
	template<class N> bignum pd(N cn,bignum bn)const{return bignum(cn)/bn;}

	bignum operator%(const bignum& divisor) const; //modulo operator
	
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

	template<class N>friend bool operator< (N cn, const bignum& bn){return bignum(cn)< bn;}
	template<class N>friend bool operator> (N cn, const bignum& bn){return bignum(cn)> bn;}
	template<class N>friend bool operator<=(N cn, const bignum& bn){return bignum(cn)<=bn;}
	template<class N>friend bool operator>=(N cn, const bignum& bn){return bignum(cn)>=bn;}
	template<class N>friend bool operator==(N cn, const bignum& bn){return bignum(cn)==bn;}
	template<class N>friend bool operator!=(N cn, const bignum& bn){return bignum(cn)!=bn;}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	/*********************************   ERROR HANDLING FUNCTIONS   *********************************/
	//////////////////////////////////////////////////////////////////////////////////////////////////

	void check(string &value);
	void internal_division_check(const bignum& value_1, const bignum& value_2) const;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	/**************************************  INTERNAL METHODS  **************************************/
	//////////////////////////////////////////////////////////////////////////////////////////////////

	//internal operation for arithmetic operators
	string internal_addition(string a, string b) const;
	string internal_subtraction(string a, string b) const;
	string internal_multiplication(string upperNumber, string bottomNumber) const;
	bignum internal_division(bignum& dividen, bignum& divisor) const;	// this method is dependent on the 3 basic arithmetic operators
								
};

#endif