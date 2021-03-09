#include <iostream>
#include <chrono>
#include "bnum.hpp"
using namespace std;
using namespace std::chrono;
int main()
{ 
    string line(80,')');
    line = "\n"+line+"\n";

    cout<<line<<endl;
    cout<<"\nbnum sample program 2 - performance test"<<endl;
    cout<<line<<endl;
    auto start1 = high_resolution_clock::now();
    // initialize
    bnum var1 = (string(50,'5')+string(50,'2')+string(50,'1')+"."+string(50,'9')); // a 200 digit length number
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout<<"Var1 Initialization1 taken : "<<duration1.count()<<" microseconds"<<endl;

    auto start2 = high_resolution_clock::now();
    // initialize 200 length digit
    bnum var2 = "-9999999999999999999999999999999999999999999999999988888888888888888888888888888888888888888888888888.2222222222222222222222222222222222222222222222222277777777777777777777777777777777777777777777777777"; // a negative 200 digit length number
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);
    cout<<"Var2 Initialization2 taken : "<<duration1.count()<<" microseconds"<<endl;

    cout<<line<<endl;

    cout<<"OUTPUT VARIABLE_1 and VARIABLE_2"<<endl;
    cout<<"var1 = "<<var1<<endl<<endl;
    cout<<"var2 = "<<var2<<endl;

    cout<<line<<endl;
    cout<<"\t\tPerformace of 4 basic arithmetic operations"<<endl;
    bnum add, sub, mul, div, mod;
    
    auto start3 = high_resolution_clock::now();
    add = var1 + var2;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3-start3);
    cout<<"Addition taken : "<<duration3.count()<<" microseconds"<<endl;

    auto start4 = high_resolution_clock::now();
    sub = var1 - var2;
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4-start4);
    cout<<"Subtraction taken : "<<duration4.count()<<" microseconds"<<endl;

    auto start5 = high_resolution_clock::now();
    mul = var1 * var2;
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5-start5);
    cout<<"Multiplication taken : "<<duration5.count()<<" microseconds"<<endl;

    auto start6 = high_resolution_clock::now();
    div = var1 / var2;
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6-start6);
    cout<<"Division taken : "<<duration6.count()<<" microseconds"<<endl;

    cout<<line<<endl;

    auto start7 = high_resolution_clock::now();
    mod = var1 % var2;
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(stop7-start7);
    cout<<"Modulo taken : "<<duration7.count()<<" microseconds"<<endl;
    cout<<"NOTE : Modulo's output might not be right as of now"<<endl;

    cout<<line<<endl;
    cout<<"Answers : "<<endl<<endl;
    cout<<"var1 + var2 = "<<add<<endl<<endl;
    cout<<"var1 - var2 = "<<sub<<endl<<endl;
    cout<<"var1 * var2 = "<<mul<<endl<<endl;
    cout<<"var1 / var2 = "<<div<<endl<<endl;
    cout<<"var1 % var2 = "<<mod<<endl<<endl;

    cout<<line<<endl;

    cout<<endl;
}
