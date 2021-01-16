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
	vector<long long int> str_part_by(long long int,string) const;
	pair<string,string> dec_slice(string)const;

	pair<string,string> strfront_fill0(string,string)const;
	pair<string,string> strback_fill0(string,string) const;
	
	string removeFrontZeros(string) const;
	string removeRearZeros(string)  const;

	string moveDecimal(string,long long) const;
	
	long long int one_thsd(long long int, long long int)const;
	long long int ten_thsd(long long int) const;
	
	bool isPositive() const;
	bool isFloat() const;
	bool sameSign(const bignum&, const bignum&) const;
	
	//bignum functions
	bignum absolute(const bignum&) const;

    	//arithmetich operators
	bignum operator+(const bignum&) const;
	bignum operator-(const bignum&) const;
	bignum operator*(const bignum&) const;
	bignum operator/(const bignum&) const;

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
	friend ostream& operator<<(ostream&, const bignum&);
	friend istream& operator>>(istream&, bignum&);

	//comparison operators
	bool operator< (const bignum&) const;  // base method (use to create other comparison operators)
	bool operator> (const bignum&) const;
	bool operator<=(const bignum&) const;
	bool operator>=(const bignum&) const;
	bool operator==(const bignum&) const;  // base method (use to create other comparison operators)
	bool operator!=(const bignum&) const;

	template<class N>friend bool operator< (N cn, const bignum& bn){return bignum(cn)< bn;}
	template<class N>friend bool operator> (N cn, const bignum& bn){return bignum(cn)> bn;}
	template<class N>friend bool operator<=(N cn, const bignum& bn){return bignum(cn)<=bn;}
	template<class N>friend bool operator>=(N cn, const bignum& bn){return bignum(cn)>=bn;}
	template<class N>friend bool operator==(N cn, const bignum& bn){return bignum(cn)==bn;}
	template<class N>friend bool operator!=(N cn, const bignum& bn){return bignum(cn)!=bn;}

	/*********************************   ERROR HANDLING FUNCTIONS   *********************************/
	void check(string&);

	/**************************************  INTERNAL METHODS  **************************************/
	//internal operation for arithmetic operators
	string internal_addition(string, string) const;
	string internal_subtraction(string, string) const;
	string internal_multiplication(string, string) const;
	string internal_division(string a, string b) const;
};

#endif