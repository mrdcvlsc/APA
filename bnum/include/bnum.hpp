#ifndef BNUM_H
#define BNUM_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <stdexcept>

using namespace std;

typedef vector <long long int> bnumfield;

void check(const string &value, const string original_form);

// string manipulation
pair<string,string> dec_slice(const string&);
string removeFrontZeros(const string&);
string removeRearZeros(const string&);

vector<long long int> str_part_by(long long int, const string&);
vector<long long int> str_part_byu1(long long int, const string&);
vector<long long int> dec_str_part_by(long long int, const string&);

// internal arithmetic operations
bnumfield addint(const bnumfield&, const bnumfield&);
bnumfield subnum(const bnumfield&, const bnumfield&, size_t);
long long int one_thsd(long long int, long long int);
long long int ten_thsd(long long int);
bnumfield mulint(const bnumfield&, const bnumfield&);
//bnumfield divint(bnumfield dividen, bnumfield divisor);
string divint(const bnumfield&, const bnumfield&);

bool chunk_is_equal(const bnumfield&,const bnumfield&);
bool chunk_is_not_equal(const bnumfield&,const bnumfield&);
bool chunk_is_less(const bnumfield&,const bnumfield&);
bool chunk_is_great(const bnumfield&,const bnumfield&);
bool chunk_is_less_equal(const bnumfield&,const bnumfield&);
bool chunk_is_great_equal(const bnumfield&,const bnumfield&);

bnumfield get_field_subset(const bnumfield&, size_t istart, size_t iend);
bnumfield join_field_sets(const bnumfield&, const bnumfield&);

class bnum{
	private:
		bnumfield integer;
		short sign;
		size_t point_place;
		static size_t div_precision;
		static bnumfield precision_chunk;

	public:
		//// constructors

		bnum();
		bnum(const char* value);
		bnum(string value);
		template<class N> bnum(N number){
			string value = to_string(number);
			if(value[0]=='-'){
				sign = -1;
				value = value.substr(1,value.size()-1);
			}
			else sign = 1;
			
			pair<string,string> num_slice = dec_slice(value);
			integer = str_part_by(8,num_slice.first);
			point_place = integer.size();

			bnumfield decimalsfield = dec_str_part_by(8,num_slice.second);
			integer.insert(integer.end(),decimalsfield.begin(),decimalsfield.end());
		}


		/// @arg precision chunk
		/// @def increase by level, 1 value of level is equal to 8 point precision
		/// @def ex. if set_div_precision(5) was set, division will compute additional precision of up to 40 point precision
		static void set_div_precision(size_t prec)
		{
			div_precision = prec;
			bnumfield addprec(prec,0);
			precision_chunk = addprec;
		}

		size_t get_div_precision() const{
			return div_precision;
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
				if(i==point_place-1) carried_answer+='.';
				// check the posibility of insert being fasteer on a reserved vector
			}

			string rmedgezero = removeFrontZeros(removeRearZeros(carried_answer));

			if(rmedgezero.back()=='.') rmedgezero.push_back('0');

			if(sign == -1) return "-"+rmedgezero;
			return rmedgezero;
		}

		string string_form_raw() const
		{
			size_t n = integer.size();
			string carried_answer, current_index;

			for(size_t i=0ll;i<n;++i) {
				current_index = to_string(integer[i]);
				string front_zeros(8-current_index.size(),'0');
				carried_answer+=(front_zeros+current_index);
				if(i==point_place-1) carried_answer+='.';
				// check the posibility of insert being fasteer on a reserved vector
			}

			if(carried_answer.back()=='.') carried_answer=carried_answer+"00000000";

			return carried_answer;
		}
		
		string string_form_chunks() const
		{
			size_t n = integer.size();
			string carried_answer="", current_index;


			for(size_t i=0ll;i<n;++i) {
				current_index = to_string(integer[i]);
				string front_zeros(8-current_index.size(),'0');
				carried_answer+=(front_zeros+current_index);
				// check the posibility of insert being fasteer on a reserved vector
			}
			return carried_answer;
		}

		void disp_chunks()const{
			for(auto e: integer){
				cout<<e<<' ';
			}
		}

		bnumfield get_int_chunks()
		{
			bnumfield whole_num;
			whole_num.reserve(point_place);
			whole_num.insert(whole_num.end(),integer.begin(),integer.begin()+point_place);
			return whole_num;
		}

		size_t chunk_size() const{
			return integer.size();
		}

		size_t get_point_place() const{
			return point_place;
		}

		void set_point_place(size_t point_place){
			this->point_place = point_place;
		}

		/// return the vector of chunks
		bnumfield get_bnum_field()const{
			return integer;
		}

		void set_bnum_field(const bnumfield& integer) { 
			this->integer = integer;
		}

		void set_sign(short one){
			this->sign = one;
		}

		short get_sign() const{ return sign; }

		//// IO Operators
		friend ostream& operator<<(ostream &out, const bnum &value);
		friend istream& operator>>(istream&, bnum&);

		//// Comparison Operators
		bool operator< (const bnum&) const;  // base comparison operator (use to create other comparison operators)
		bool operator> (const bnum&) const;
		bool operator<=(const bnum&) const;
		bool operator>=(const bnum&) const;
		bool operator==(const bnum&) const;  // base  comparison operator (use to create other comparison operators)
		bool operator!=(const bnum&) const;

		template<class N>friend bool operator< (N cn, const bnum& bn){return bnum(cn)< bn;}
		template<class N>friend bool operator> (N cn, const bnum& bn){return bnum(cn)> bn;}
		template<class N>friend bool operator<=(N cn, const bnum& bn){return bnum(cn)<=bn;}
		template<class N>friend bool operator>=(N cn, const bnum& bn){return bnum(cn)>=bn;}
		template<class N>friend bool operator==(N cn, const bnum& bn){return bnum(cn)==bn;}
		template<class N>friend bool operator!=(N cn, const bnum& bn){return bnum(cn)!=bn;}

		//// Arithmetic Operators
		bnum operator+(const bnum&) const;
		bnum operator-(const bnum&) const;
		bnum operator*(const bnum&) const;
		bnum operator/(const bnum&) const;
		bnum operator%(const bnum&) const;

		bnum& operator+=(const bnum);
		bnum& operator-=(const bnum);
		bnum& operator*=(const bnum);
		bnum& operator/=(const bnum);

		template<class N> bnum pa(N cn,bnum bn)const{return bnum(cn)+bn;}
		template<class N> bnum ps(N cn,bnum bn)const{return bnum(cn)-bn;}
		template<class N> bnum pm(N cn,bnum bn)const{return bnum(cn)*bn;}
		template<class N> bnum pd(N cn,bnum bn)const{return bnum(cn)/bn;}
		
		template<class N>friend bnum operator+(N cn,const bnum& bn){bnum ra=ra.pa(cn,bn);return ra;}
		template<class N>friend bnum operator-(N cn,const bnum& bn){bnum ra=ra.ps(cn,bn);return ra;}
		template<class N>friend bnum operator*(N cn,const bnum& bn){bnum ra=ra.pm(cn,bn);return ra;}
		template<class N>friend bnum operator/(N cn,const bnum& bn){bnum ra=ra.pd(cn,bn);return ra;}

		//// Increment Decrement Operators
		//pre-fix and post-fix increment/decrement
		bnum operator++(); //pre
		bnum operator--();
		bnum operator++(int); //post
		bnum operator--(int);
};

#endif