#include <iostream>
#include <chrono>
#include <string>
#include "bignum.h"

using namespace std;
using namespace std::chrono;

int main(){

	bignum t = "1";

	
	cout<<"test internal : "<<t.internal_multiplication("128736723",
														"2619920170325641109792152254225082302273609993940889")<<endl;
	
	// 1287367.23 * 2619920170325641109792.152254225082302273609993940889
	
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
