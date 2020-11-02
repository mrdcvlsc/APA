#include <iostream>
#include <algorithm>
#include <string>
#include "bignum.h"
using namespace std;


// NEXT TARGETS
/*
	1. Add a division support
	2. Reduce code clutter
*/

int main(int argc, char* args[]){
	
	bignum 	a="55555",
			b("-777"),
			c="2121";
			
	bignum	d = b,
			e="2121",
			f="728732";

	b = d-f;
	f = f+d+b;
	c = a*e;

	cout<<"operations"<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d+e<<endl;
	cout<<f<<endl;

	cout<<"comparisons"<<endl;
	cout<<(a==b)<<endl;
	cout<<(f<=c)<<endl;
	cout<<(d!=e)<<endl;

	cout<<"\nright"<<endl;
	cout<<(a>"18923712938")<<endl;
	cout<<(b<"-1000")<<endl;
	cout<<(c>="2121")<<endl;
	cout<<(d<="-767123")<<endl;
	cout<<(e!="2121")<<endl;
	cout<<(f=="87183")<<endl;

	cout<<endl<<endl<<"left"<<endl;
	cout<<("18923712938">a)<<endl;
	cout<<("-1000"<b)<<endl;
	cout<<("2121">=c)<<endl;
	cout<<("-767123"<=d)<<endl;
	cout<<("2121"!=e)<<endl;
	cout<<("87183"==f)<<endl;

	return 0;
}
