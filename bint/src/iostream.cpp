#include "bint.hpp"

ostream& operator<<(ostream &out, const bint& value)
{
    string outputstring = value.string_form();
    out << outputstring;
    return out;
}

istream& operator>>(istream &in, bint &value) {
    string input;
	in >> input;
    if(input[0]=='-'){
		value.set_sign(-1);
		input[0] = '0';
	}
	else
		value.set_sign(1);
    check(input,input);
    value.set_bint_field(str_part_by(8,input));
	return in;
}
