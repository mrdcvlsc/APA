#include <iostream>
#include "bint.hpp"
using namespace std;

int main()
{
    bint a;
    bint b;
    bint ans;
    char o;
    while(true){
        cout<<"\nbint sample program 1 - bignumber calculator"<<endl;
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