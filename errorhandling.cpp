#include "bignum.h"

// performs a scan if the string is a valid number
void bignum::check(string &value){
	if(value.size()<=0){
		cout<<"\nbignum ERROR : NUMBER HAS NO VALUE"<<endl;
		exit(1);
	}

	if(value[value.size()-1]=='.')
		value=value+'0';

	if(value[0]=='.')
		value='0'+value;

	if(value[0]=='-' and value[1]=='.'){
		value[0]='0';
		value='-'+value;
	}

	bool decimal = false;
	bool negative= false;

	for(unsigned int i=0;i<value.size();++i){
		if(value[i]=='.' and !decimal and isdigit(value[i+1])){
			decimal = true;
			continue;
		}
		if(value[i]>='0' and value[i]<='9')
			continue;
		if(value[i]=='-' and !negative and i==0 and value.size()>1){
			negative = true;
			continue;
		}
		if(i==value.size())
			break;
		else{
			valid = false;
			cout<<"\nbignum ERROR : ASSIGNED INVALID NUMBER DETECTED ("<<value<<")"<<endl;
			exit(1);
		}	
	}
}
