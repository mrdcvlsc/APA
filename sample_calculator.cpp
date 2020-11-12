#include <iostream>
#include <string>
#include "bignum.h"

using namespace std;

int main(){
	string line(20,'-');
	bignum val1, val2, answer;
	char operation;

	while(true){

		cout<<line<<endl;
		cout<<"OPERATIONS : + - / * %"<<endl;
		cout<<"\ninput: (value_1)(space)(operation_sign)(space)(value_2) \nCALCULATE : ";
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

		cout<<"ANSWER : "<<answer<<endl;
	}

	return 0;
}
