#include <iostream>
#include <chrono>
#include <string>
#include "bignum.h"

using namespace std;
using namespace std::chrono;

int main(){

	bignum a=1;
	auto start2 = high_resolution_clock::now();
	cout<<a.moveDecimal("49",3)<<endl;
	cout<<a.moveDecimal("49",-3)<<endl;
	cout<<a.moveDecimal("49",1)<<endl;
	cout<<a.moveDecimal("49",-1)<<endl;
	cout<<a.moveDecimal("49",0)<<endl;
	auto stop2 = high_resolution_clock::now();
	auto dur2 = duration_cast<microseconds>(stop2-start2);
	cout<<"secnd = "<<dur2.count()<<" microseconds"<<endl;
	/*
	bignum a = "1";
	bignum dividen = "146217325473526745324587345826354673242342346712486214612381236.27637812637";
	bignum divisor = "23427642042424002340920894266423432.7235485632548265482654738725476523742344234";
	
	auto start2 = high_resolution_clock::now();
	cout<<"old answer = "<<dividen/divisor<<endl;
	auto stop2 = high_resolution_clock::now();

	auto start1 = high_resolution_clock::now();
	cout<<"new answer = "<<a.new_division_test(dividen,divisor)<<endl;
	auto stop1 = high_resolution_clock::now();

	

	auto dur1 = duration_cast<microseconds>(stop1-start1);
	auto dur2 = duration_cast<microseconds>(stop2-start2);

	cout<<"first = "<<dur1.count()<<" microseconds"<<endl;
	cout<<"secnd = "<<dur2.count()<<" microseconds"<<endl;
	*/

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
