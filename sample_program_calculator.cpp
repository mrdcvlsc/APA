#include <iostream>
#include <chrono>
#include <string>
#include "bignum.h"

using namespace std;
using namespace std::chrono;

int main(){
	
	string line(20,'=');
	bignum val1, val2, answer;
	char operation;

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
	return 0;
}
