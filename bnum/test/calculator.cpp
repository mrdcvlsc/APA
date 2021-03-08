#include <iostream>
#include "bnum.hpp"
using namespace std;

int main()
{
    bnum::set_div_precision(5);
    
    bnum a;
    bnum b;
    bnum ans;
    char o;
    while(true){
        cout<<"\nbnum sample program 1 - bignumber calculator"<<endl;
        cout<<"Enter expression : ";
        cin>>a>>o>>b;

        switch(o){
            case '+':
                ans = a+b;
                break;
            case '-':
                ans = a-b;
                break;
            case '*':
                ans = a*b;
                break;
            case '/':
                ans = a/b;
                break;
            case '%':
                ans = a%b;
                break;
            default:
                break;
        }
        cout<<"\nAnswer = "<<ans<<endl;
    }
    return 0;
}