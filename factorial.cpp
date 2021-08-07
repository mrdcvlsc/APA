// sample program
// compile : g++ factorial.cpp -I"./include" -L"./lib" -lbint -o factorial.exe

// run
// linux terminal : ./factorial.exe
// windows cmd    : start factorial

#include <iostream>
#include <bint.hpp>

using namespace std;

int main(){

  // A very slow factorial

  cout<<"FACTORIAL OF A NUMBER : "<<endl;

  bint limit = 1000;
  
  bint n = limit, fac = "1";

  for(bint i=1; i<=limit; ++i)
  {
    fac = fac*i;
  }

  cout<<"Answer to factorial of 1000 is : "<<fac<<endl;

  return 0;
}