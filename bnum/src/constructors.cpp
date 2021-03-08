#include "bnum.hpp"

bnum::bnum(){
	integer.push_back(0);
	point_place = 1;
	integer.push_back(0);
	sign = 1;
}

bnum::bnum(const char* number)
{
	string value(number);

	if(value[0]=='-')
	{
		sign = -1;
		value = value.substr(1,value.size()-1);
	}
	else sign = 1;

	value = removeRearZeros(removeFrontZeros(value));
	check(value,number);

	pair<string,string> num_slice = dec_slice(value);
	integer = str_part_by(8,num_slice.first);
	point_place = integer.size();

	bnumfield decimalsfield = dec_str_part_by(8,num_slice.second);
	integer.insert(integer.end(),decimalsfield.begin(),decimalsfield.end());
}

bnum::bnum(string value)
{
	string original_form = value;
	if(value[0]=='-')
	{
		sign = -1;
		value = value.substr(1,value.size()-1);
	}
	else sign = 1;

	value = removeRearZeros(removeFrontZeros(value));
	check(value,value);

	pair<string,string> num_slice = dec_slice(value);
	bnumfield temp_holder = str_part_by(8,num_slice.first);
	point_place = temp_holder.size();

	bnumfield decimalsfield = dec_str_part_by(8,num_slice.second);

	integer.reserve(point_place+decimalsfield.size());
	integer.insert(integer.end(),temp_holder.begin(),temp_holder.end());
	integer.insert(integer.end(),decimalsfield.begin(),decimalsfield.end());
}
