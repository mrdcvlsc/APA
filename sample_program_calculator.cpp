#include <iostream>
#include <chrono>
#include <string>
#include "bignum.h"

using namespace std;
using namespace std::chrono;

int main(){

	bignum a = "1";
	bignum dividen = "77718213";
	bignum divisor = "171311";
	
	auto start1 = high_resolution_clock::now();
	cout<<"answer = "<<a.dev_div(dividen.data,divisor.data)<<endl;
	auto stop1 = high_resolution_clock::now();

	auto start2 = high_resolution_clock::now();
	cout<<"answer = "<<a.internal_division(dividen,divisor)<<endl;
	auto stop2 = high_resolution_clock::now();

	auto dur1 = duration_cast<microseconds>(stop1-start1);
	auto dur2 = duration_cast<microseconds>(stop2-start2);

	cout<<"first = "<<dur1.count()<<endl;
	cout<<"secnd = "<<dur2.count()<<endl;
	/*
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
	*/
	return 0;
}
