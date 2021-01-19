#include <iostream>
#include <chrono>
#include <string>
#include <bignum.h>

using namespace std;
using namespace std::chrono;

int main(){
    string num1(5000,'2');
    string num2(5000,'8');
    
    bignum numa = num1;
    bignum numb = num2;

    auto start = high_resolution_clock::now();
    
    bignum numc = numa * numb;

    auto stop = high_resolution_clock::now();
    auto duration  = duration_cast<microseconds>(stop-start);

    cout<<"program taken : "<<duration.count()<<" microseconds"<<endl;
    cout<<"answer : "<<numc<<endl;
    return 0;
}