#include "bnum.hpp"

ostream& operator<<(ostream &out, const bnum& value)
{
    string outputstring = value.string_form();
    out << outputstring;
    return out;
}

istream& operator>>(istream &in, bnum &value)
{
    string input;
	in >> input;
    string original_form = input;

    if(input[0]=='-')
    {
		value.set_sign(-1);
        input = input.substr(1,input.size()-1);
	}

    input = removeRearZeros(removeFrontZeros(input));
    check(input,original_form);

    pair<string,string> num_slice = dec_slice(input);
    value.integer = str_part_by(8,num_slice.first);
    value.point_place = value.integer.size();

    bnumfield deimalsfield = dec_str_part_by(8,num_slice.second);
    value.integer.insert(value.integer.end(),deimalsfield.begin(),deimalsfield.end());
	return in;
}
