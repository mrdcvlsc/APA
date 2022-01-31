#include <iostream>
#include "../core.hpp"

using namespace apa;

int main(){
    
    bint bigIntA = 671876321;
    bint bigIntB("-898278974823974723842342874623424278623424");

    bint bint_sum = bigIntA + bigIntB;
    bint bint_difference = bigIntA - bigIntB;
    bint bint_product = bigIntA * bigIntB;
    bint bint_quotient = bigIntA / bigIntB;

    std::cout << "============ Big Integers ===============\n";

    std::cout << "bigIntA = " << bigIntA << "\n";
    std::cout << "bigIntB = " << bigIntB << "\n";

    std::cout << "sum        = " << bint_sum << "\n";
    std::cout << "difference = " << bint_difference << "\n";
    std::cout << "product    = " << bint_product << "\n";
    std::cout << "quotient   = " << bint_quotient << "\n";


    bfloat bigFloatA("-8762723764723468723647.7468726468234");
    bfloat bigFloatB = 0.65f;

    bfloat bfloat_sum = bigFloatA + bigFloatB;
    bfloat bfloat_difference = bigFloatA - bigFloatB;
    bfloat bfloat_product = bigFloatA * bigFloatB;
    bfloat bfloat_quotient = bigFloatA / bigFloatB;

    std::cout << "\n\n============ Big Floating Point ===============\n";

    std::cout << "bigFloatA = " << bigFloatA << "\n";
    std::cout << "bigFloatB = " << bigFloatB << "\n";

    std::cout << "sum        = " << bfloat_sum << "\n";
    std::cout << "difference = " << bfloat_difference << "\n";
    std::cout << "product    = " << bfloat_product << "\n";
    std::cout << "product    = " << bfloat_product.string_form() << "\n";
    std::cout << "quotient   = " << bfloat_quotient << "\n";

    return 0;
}