#ifndef BINT_H
#define BINT_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <stdexcept>

#define SINGLE_CHUNK_SIZE 8

using namespace std;

typedef vector <long long int> bintfield;

void check(const string &value, const string original_form);

// string manipulation
string removeFrontZeros(const string&);

vector<long long int> str_part_by(long long int, const string&);

// internal arithmetic operations
bintfield addint(const bintfield&, const bintfield&);
bintfield subint(const bintfield&, const bintfield&);
long long int one_thsd(long long int, long long int);
long long int ten_thsd(long long int);
bintfield mulint(const bintfield&, const bintfield&);
bintfield divint(const bintfield&, const bintfield&);

bool chunk_is_equal(const bintfield&,const bintfield&);
bool chunk_is_not_equal(const bintfield&,const bintfield&);
bool chunk_is_less(const bintfield&,const bintfield&);
bool chunk_is_great(const bintfield&,const bintfield&);
bool chunk_is_less_equal(const bintfield&,const bintfield&);
bool chunk_is_great_equal(const bintfield&,const bintfield&);

bintfield get_field_subset(const bintfield&, size_t istart, size_t iend);
bintfield join_field_sets(const bintfield&, const bintfield&);

class bint{
	private:
		bintfield integer;
		short sign;

	public:

		//// constructors

		bint();
		bint(const char* value);
		bint(string value);
		template<class N> bint(N number){
			string value = to_string(number);
			if(value[0]=='-'){
				sign = -1;
				value = value.substr(1,value.size()-1);
			}
			else
				sign = 1;
			integer = str_part_by(8,value);
		}

		/// returns the string form of the big integer
		string string_form() const
		{
			size_t n = integer.size();
			string carried_answer="", current_index;
			
			for(size_t i=0ll;i<n;++i) {
				current_index = to_string(integer[i]);
				string front_zeros(8-current_index.size(),'0');
				carried_answer+=(front_zeros+current_index);
			}
			if(sign == -1) return "-"+removeFrontZeros(carried_answer);
			return removeFrontZeros(carried_answer);
		}

		size_t chunk_size() const{
			return integer.size();
		}

		/// return the vector of chunks
		bintfield get_bint_field()const{
			return integer; 
		}

		void set_bint_field(bintfield integer) { 
			this->integer = integer;
		}

		void set_sign(short one){
			this->sign = one;
		}

		short get_sign() const{ return sign; }

		//// IO Operators
		friend ostream& operator<<(ostream &out, const bint &value);
		friend istream& operator>>(istream&, bint&);

		//// Comparison Operators
		bool operator< (const bint&) const;  // base comparison operator (use to create other comparison operators)
		bool operator> (const bint&) const;
		bool operator<=(const bint&) const;
		bool operator>=(const bint&) const;
		bool operator==(const bint&) const;  // base  comparison operator (use to create other comparison operators)
		bool operator!=(const bint&) const;

		template<class N>friend bool operator< (N cn, const bint& bn){return bint(cn)< bn;}
		template<class N>friend bool operator> (N cn, const bint& bn){return bint(cn)> bn;}
		template<class N>friend bool operator<=(N cn, const bint& bn){return bint(cn)<=bn;}
		template<class N>friend bool operator>=(N cn, const bint& bn){return bint(cn)>=bn;}
		template<class N>friend bool operator==(N cn, const bint& bn){return bint(cn)==bn;}
		template<class N>friend bool operator!=(N cn, const bint& bn){return bint(cn)!=bn;}

		//// Arithmetic Operators
		bint operator+(const bint&) const;
		bint operator-(const bint&) const;
		bint operator*(const bint&) const;
		bint operator/(const bint&) const;
		bint operator%(const bint&) const;

		bint& operator+=(const bint);
		bint& operator-=(const bint);
		bint& operator*=(const bint);
		bint& operator/=(const bint);

		template<class N> bint pa(N cn,bint bn)const{return bint(cn)+bn;}
		template<class N> bint ps(N cn,bint bn)const{return bint(cn)-bn;}
		template<class N> bint pm(N cn,bint bn)const{return bint(cn)*bn;}
		template<class N> bint pd(N cn,bint bn)const{return bint(cn)/bn;}
		
		template<class N>friend bint operator+(N cn,const bint& bn){bint ra=ra.pa(cn,bn);return ra;}
		template<class N>friend bint operator-(N cn,const bint& bn){bint ra=ra.ps(cn,bn);return ra;}
		template<class N>friend bint operator*(N cn,const bint& bn){bint ra=ra.pm(cn,bn);return ra;}
		template<class N>friend bint operator/(N cn,const bint& bn){bint ra=ra.pd(cn,bn);return ra;}

		//// Increment Decrement Operators
		//pre-fix and post-fix increment/decrement
		bint operator++(); //pre
		bint operator--();
		bint operator++(int); //post
		bint operator--(int);
};

#endif