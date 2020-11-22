#include <iostream>
#include <string>
#include "bignum.h"

using namespace std;

int main(){

	cout<<"FACTORIAL OF A NUMBER : "<<endl;
	bignum n = 1000, fac="1";
	bignum limit = n;
	for(bignum i=1; i<=limit; ++i)
		fac = fac*i;
	cout<<"Answer to factorial of 1000 is : "<<fac<<endl;
	// pelase don't use this for loop for computing larger factorials just don't
	// you can use more advance algorithm like prime swing factorization.
	//*
	string line(20,'=');
	bignum val1, val2, answer;
	char operation;
	string jump(20,'\n');
	cout<<jump;

	while(true){


		cout<<line<<endl;
		cout<<"OPERATIONS : + - / * %"<<endl;
		cout<<"\nINPUT FORMAT : (NUMBER SPACE OPERATION_SIGN SPACE NUMBER) \nCALCULATE : ";
		cin>>val1>>operation>>val2;

		switch(operation){
			case '+':
				answer=val1+val2;
				break;
			case '-':
				answer=val1-val2;
				break;
			case '*':
				answer=val1*val2;
				break;
			case '/':
				answer=val1/val2;
				break;
			case '%':
				answer=val1%val2;
				break;
			default:
				cout<<"\nINVALID OPERATION\n"<<endl;
				break;
		}
		cout<<line<<endl;
		cout<<"ANSWER : "<<answer<<endl;
	}
	//*/
	return 0;
}
