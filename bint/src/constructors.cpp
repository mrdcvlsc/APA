#include "bint.hpp"

bint::bint()
{
	integer.push_back(0);
	sign = 1;
}

bint::bint(const char* number)
{
	string value(number);
	if(value[0]=='-'){
		sign = -1;
		value = value.substr(1,value.size()-1);
	}
	else sign = 1;

	value = removeFrontZeros(value);
	check(value,number);
	integer = str_part_by(8,value);
}

bint::bint(string value)
{
	string original_form = value;
	if(value[0]=='-'){
		sign = -1;
		value = value.substr(1,value.size()-1);
	}
	else sign = 1;

	value = removeFrontZeros(value);
	check(value,original_form);
	integer = str_part_by(8,value);
}
