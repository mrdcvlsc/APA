#include "bignum.h"

// performs a scan if the string is a valid number
void bignum::check(string &value){
	size_t value_size = value.size(); 
	if(value_size<=0){
		cout<<"\nERROR - bignum [check] : NUMBER HAS NO VALUE"<<endl;
		exit(1);
	}

	if(value[value_size-1]=='.')
		value=value+'0';
	if(value[0]=='.')
		value='0'+value;
	if(value[0]=='-' and value[1]=='.'){
		value[0]='0';
		value='-'+value;
	}

	bool decimal  = false;
	bool negative = false;
	size_t prec = 0;

	for(size_t i=0; i<value_size; ++i){
		
		if(decimal) ++prec; // counts the precision value of the big number
		if(value[i]=='.' and !decimal and isdigit(value[i+1])){
			decimal = true;
			continue;
		}
		if(value[i]>='0' and value[i]<='9')
			continue;
		if(value[i]=='-' and !negative and i==0 and value_size>1){
			negative = true;
			continue;
		}
		if(i==value_size)
			break;
		else{
			cout<<"\nERROR - bignum [check] : ASSIGNED INVALID NUMBER DETECTED ("<<value<<")"<<endl;
			exit(1);
		}
	}
}

// you see I'm not so confident with my implementation of division operation thats why this is here
void bignum::internal_division_check(const bignum& dividen, const bignum& divisor) const{

	if(divisor=="0"){
		cout<<"\nERROR - bignum [internal division]: ("<<dividen<<'/'<<divisor<<") dividing by zero is not possible"<<endl;
		exit(1);
	}

	if(divisor>dividen){
		cout<<"\nERROR - bignum [internal division]:\n\n\t"<<endl;
		cout<<"\t internal_division() do not support dividing 'dividen' to a greater 'divisor'"<<endl;
		cout<<"\t your divisor ("<<divisor<<") is greater than your dividen ("<<dividen<<"."<<endl;
		exit(1);
	}
	
	if(divisor<"0"){	
		cout<<"\nERROR - bignum [internal division]:"; 
		cout<<"\n\t internal_division() do not support division to a negative value"<<endl;
		cout<<"\t the 'DIVISOR' is ("<<divisor<<") lessthan zero(0). "<<endl;
		exit(1);
	}

	if(dividen<"0"){
		cout<<"\nERROR - bignum [internal division]:"<<endl; 
	    cout<<"\t internal_division() do not support division to a negative value"<<endl;
		cout<<"\t the 'DIVIDEN' is ("<<dividen<<") lessthan zero(0). "<<endl;
		exit(1);
	}
}