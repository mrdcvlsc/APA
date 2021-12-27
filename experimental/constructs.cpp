#include <iostream>
#include "../bfloat/bfloat.hpp"

int main()
{
    std::cout << "\t\twhat is happening\n";
    std::cout << "#########################################\n";
    apa::bfloat a = 12673.92f;
    apa::bfloat e;
    apa::bfloat c;

    std::cout << "-----------------------------------------\n";
    
    apa::bfloat b = a;

    std::cout << "-----------------------------------------\n";
    
    c = a;

    std::cout << "-----------------------------------------\n";
    
    apa::bfloat d = a * c;

    std::cout << "-----------------------------------------\n";
    
    e = a*c;

    std::cout << "-----------------------------------------\n";

    return 0;
}