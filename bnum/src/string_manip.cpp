#include "bnum.hpp"

// performs a scan if the string is a valid number
void check(const string &value, const string original_form){
	try{
		size_t value_size = value.size(); 
		if(value_size<=0){
			throw value_size;
		}

		size_t rational_true = 0;

		for(size_t i=0; i<value_size; ++i)
		{	
			if(value[i]=='.')
			{
				rational_true++;
				continue;
			}

			if(value[i]<'0'^value[i]>'9')
			{
				throw value;
			}
		}

		if(rational_true>1)
		{
			throw value;
		}
	}
	catch(size_t NO_VALUE_ERROR)
	{
		cerr<<"\n\x1B[31mbignum ERROR\033[0m [check] : NUMBER HAS NO VALUE\n";
		exit(1);
	}
	catch(string VALUE_ERROR)
	{
		if(VALUE_ERROR[0]=='-') // error for double negative signs
		{
			cerr<<"\n\x1B[31mbint ERROR\033[0m [check] : YOU ASSIGNED AN INVALID NUMBER FORMAT : (-"<<original_form<<")\n";
		}
		else cerr<<"\n\x1B[31mbignum ERROR\033[0m [check] : YOU ASSIGNED AN INVALID NUMBER FORMAT : ("<<original_form<<")\n";
		exit(2);
	}
}

pair<string,string> dec_slice(const string& float_number){
	
	size_t point = 0;
	size_t float_size_num = float_number.size();

	for(size_t i=0; i<float_size_num; ++i){
		
		if(float_number[i]=='.') {
			
			point = i;
			break;
		}
	}
	if(!point)
		return make_pair(float_number,"00000000");
	return make_pair(float_number.substr(0,point),float_number.substr(point+1));
}

vector<long long int> str_part_by(long long int length, const string& number)
{
	vector<string> str_partition;
	vector<long long int> long_partition;

	string str_temp(length,'0');
	size_t num_size = number.size();

	long long int memreserve = ((long long int)num_size/(long long int)length)+1;
	str_partition.reserve(memreserve);
	long_partition.reserve(memreserve);

	for(size_t i=0, str_i; i<num_size;++i)
	{	
		if(i==0 or i%length==0)
		{
			str_i = length;
			str_partition.push_back(str_temp);
		}
		str_partition.back()[str_i-1] = number[num_size-1-i];
		--str_i;
	}

	size_t str_size = str_partition.size();
	for(size_t i=0; i<str_size; ++i)
	{
		long_partition.push_back(stoll(str_partition[str_size-1-i]));
	}

	return long_partition;
}

vector<long long int> dec_str_part_by(long long int length, const string& number)
{
	vector<string> str_partition;
	vector<long long int> long_partition;

	string str_temp(length,'0');
	size_t num_size = number.size();

	long long int memreserve = ((long long int)num_size/(long long int)length)+1;
	str_partition.reserve(memreserve);
	long_partition.reserve(memreserve);

	for(size_t i=0, str_i; i<num_size;++i) {
		
		if(i==0 or i%length==0){
			str_i = length;
			str_partition.push_back(str_temp);
		}
		str_partition.back()[length-str_i] = number[i];
		--str_i;
	}

	size_t str_size = str_partition.size();
	for(size_t i=0; i<str_size; ++i)	
		long_partition.push_back(stoll(str_partition[i]));

	return long_partition;
}


string removeRearZeros(const string& str)
{
	size_t str_len = str.size();
    size_t zero_indecies = 0;

    if(str_len==1) return str;

    for(size_t i=0; i<str_len; ++i)
    {
    	if(str[str_len-1-i]!='0')
        {
        	break;
        }
        ++zero_indecies;
    }

    string newstr = str.substr(0,str_len-zero_indecies);
	if(newstr[newstr.size()-1]=='.')
	{
		newstr.push_back('0');
	}
	return newstr;
}

string removeFrontZeros(const string& str)
{	
	size_t str_len = str.size();
    size_t zero_indecies = 0;

    if(str_len==1) return str;

    for(size_t i=0; i<str_len-1; ++i)
    {
    	if(str[i]!='0')
        {
        	break;
        }
        ++zero_indecies;
    }

	if(str_len==zero_indecies) //if all are zeroes
	{
		return "0.0";
	}

    string newstr = str.substr(zero_indecies,str_len-zero_indecies);
	if(newstr[0]=='.')
	{
		newstr="0"+newstr;
	}
	return newstr;
}