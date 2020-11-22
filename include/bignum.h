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

	//constructors
	bignum():data("0"){}
	bignum(const char* value);
	bignum(string value);
	template<class N> bignum(N value){
		string temp = to_string(value);
		check(temp);
		this->data = temp;
	}

	//partition/slice function
	vector<long> str_partby9to_long(string number)const;
	vector<long> str_partby4to_long(string number)const;
	
	pair<string,string> dec_slice(string float_number)const;

	pair<string,string> strfront_fill0(string a, string b)const;
	pair<string,string> strback_fill0(string a, string b) const;
	
	pair<string,long long> removeDecimal(string bignumber)const;
	
	string removeFrontZeros(string input) const;
	string removeRearZeros(string input)  const;
	
	string putDecimal(const string& bignumber, int index) const;
	int    getDecimalPlaces(string input) const;
	
	char intToChar(const int& n) const{return(char)'0'+(char)n;} // still being used by division
	int  charToInt(const char& c)const{return(int)c - (int)'0';}	 // will remove in the future
	
	long ones(long number, long tens)const;
	long tens(long number) const;
	long one_thsd(long number, long tens)const;
	long ten_thsd(long number) const;
	
	bool isPositive() const;
	bool isFloat() const;
	bool sameSign(const bignum& a, const bignum& b) const;
	
	//bignum functions
	bignum absolute(const bignum& input) const;

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

	/*********************************   ERROR HANDLING FUNCTIONS   *********************************/
	void check(string &value);
	void internal_division_check(const bignum& value_1, const bignum& value_2) const; // for development only will remove in future

	/**************************************  INTERNAL METHODS  **************************************/
	//internal operation for arithmetic operators
	string internal_addition(string a, string b) const;
	string internal_subtraction(string a, string b) const;
	string internal_multiplication(string upperNumber, string bottomNumber) const;
	bignum internal_division(bignum& dividen, bignum& divisor) const;	// this method is dependent on the 3 basic arithmetic operators				
};

#endif
