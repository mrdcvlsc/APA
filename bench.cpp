#include <iostream>
#include <chrono>
#include <string>
#include <bignum.h>

using namespace std;
using namespace std::chrono;

//test
int main(){
    string num1(10,'2');
    string num2(10,'8');
    
    bignum numa = num1;
    bignum numb = num2;

    auto start = high_resolution_clock::now();
    
    bignum numc = numa * numb;

    auto stop = high_resolution_clock::now();
    auto duration  = duration_cast<microseconds>(stop-start);

    cout<<"program taken : "<<duration.count()<<" microseconds"<<endl;
    
    cout<<"\na = "<<numa<<endl;
    cout<<"\nb = "<<numb<<endl;
    cout<<"\nanswer : "<<numc<<endl;

    return 0;
}