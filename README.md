# APA

## a c++ library for big number computation (arbitrary-precision arithmetic).

![ubuntu](https://github.com/mrdcvlsc/bignum/actions/workflows/c-cpp.yml/badge.svg)
![windows](https://github.com/mrdcvlsc/bignum/actions/workflows/windows_output.yml/badge.svg)

this is a C++ Arbitrary Precision Arithmetic library used to compute big integers & big floating point numbers, used on values that usually cannot fit in the standard primitive C++ data types.

------------------------------------------------------------------

- header only version
- more optimized cases for long division than the previous version

<details>
<summary><b><i>Notice</i></b></summary>
<br>
<ul>

this version is still new, and might still have some bugs

- you can use the more stable previous version in this link
  - https://github.com/mrdcvlsc/bignum/tree/version_2.8.8

- or clone it
  - ```git clone --single-branch --branch version_2.8.8 https://github.com/mrdcvlsc/bignum```

</details>

## DOCUMENTATION

<!--=====================================================================================-->
<details>
<summary><b>Getting Started</b></summary>
<br>
<ul>

*1. Download or Clone this repository*
  - [Download Repository](https://github.com/mrdcvlsc/bignum/archive/refs/heads/main.zip)
  - ```git clone https://github.com/mrdcvlsc/bignum.git```


*2. link the header files of the library in your source code*

  ```c++
  #include <iostream>
  
  #include "bignum/bint/bint.hpp" // for big integers
  #include "bignum/bfloat/bfloat.hpp" // for big rational numbers

  //or

  #include "bignum/bignum.hpp" // to include both bint.hpp & bfloat.hpp and the function headers
  ```

</ul>
</details>

<details>
<summary><b><i>Constructors</i></b></summary>
<br>
<ul>

**this will show you how you can declare big integers, and big rational numbers in your code**

<!--=====================================================================================-->
<details>
<summary><b>large integers</b></summary>
<br>
<ul>

***using std::string or const char****
```c++
#include <iostream>
#include "bignum/bint/bint.hpp"

int main()
{
  apa::bint a("-888349834923489328492834983294234873284672346877264872");
}
```

***using integral types***
```c++
#include <iostream>
#include "bignum/bint/bint.hpp"

int main()
{
  short num1 = -23;
  unsigned short num2 = 32;

  apa::bint a = num1,               // short
            b = num2,              // unsigned short
            c = -788834,           // int
            d = 977342,            // unsigned int
            e = -8873284234l,      // long
            f = 8890000324ul,      // unsigned long
            g = -9900003024723ll,  // long long
            h = 17782183773232ull; // unsigned long long

  // output will be exactly the same with the assigned value
  // as long as the type you are using does not overflows or underflow

}
```

***using floating types***

you cannot use floating point types directly to construct big integers, so you need to cast it first to any integral types, take note that the decimal numbers will be cut off too, this is also the same for big floating point ```bfloat``` you need to cast integral types first into any floating point types
```c++
#include <iostream>
#include "bignum/bint/bint.hpp"

int main()
{
  apa::bint a = (int)89.02f,    // float
            b = (int)8923.123,  // double
            c = (long)723.236L; // long double

  std::cout<<a<<"\n";
  std::cout<<b<<"\n";
  std::cout<<c<<"\n";

  /* output

    89
    8923
    723

  */

}
```
</ul>
</details>

<!--=====================================================================================-->
<details>
<summary><b>large floating point numbers</b></summary>
<br>
<ul>

***using std::string or const char****
```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"

int main()
{
  apa::bfloat a("-777238478264784234234.632456723574236727362465623564723");
  std::cout<<a<<"\n";

  /* output

    -777238478264784234234.632456723574236727362465623564723

  */
}
```

***using integral types***
```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"

int main()
{
  short num1 = -23;
  unsigned short num2 = 32;

  apa::bfloat a = (float) num1,                    // short
            b = (float) num2,                    // unsigned short
            c = (double) -788834,                // int
            d = (double) 977342,                 // unsigned int
            e = (long double) -8873284234l,      // long
            f = (long double) 8890000324ul,      // unsigned long
            g = (long double) -9900003024723ll,  // long long
            h = (long double) 17782183773232ull; // unsigned long long

  std::cout<<a<<"\n";
  std::cout<<b<<"\n";
  std::cout<<c<<"\n";
  std::cout<<d<<"\n";
  std::cout<<e<<"\n";
  std::cout<<f<<"\n";
  std::cout<<g<<"\n";
  std::cout<<h<<"\n";

/* output

  -23.0
  32.0
  -788834.0
  977342.0
  -8873284234.0
  8890000324.0
  -9900003024723.0
  17782183773232.0

*/
}
```

***using floating types***

the output might be different in your machine/compiler because of different rounding

```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"

int main()
{
  apa::bfloat a = 89.02f,   // float
              b = 8923.123, // double
              c = 723.236L; // long double

/* output

  89.2
  8923.123
  723.235999999999999987565502124

*/
}

```
</ul>
</details>

</details>

<details>
<summary><b><i>Arithmetic Operators</i></b></summary>
<br>
<ul>

**the following operators are available for both ```bint``` and ```bfloat``` class**

  - **```+```** addition
  - **```-```** subtration
  - **```*```** multiplication
  - **```/```** division
  - **```+=```** addition assignment
  - **```-=```** subtraction assignment
  - **```*=```** multiplication assignment
  - **```/=```** division assignment

<!--=====================================================================================-->
<details>
<summary><b>large integer arithmetic</b></summary>
<br>
<ul>

```c++
#include <iostream>
#include "bignum/bint/bint.hpp"

int main()
{
  apa::bint a("-89283483274977878767667823647234682364823647368462382837498237489723984789324634864723"),
            b("374782837462364823646327648238467236846237468723678667678346786436346574365876435");

  apa::bint add = a+b,
            sub = a-b,
            mul = a*b,
            div = a/b;

  std::cout<<"a = "<<a<<"\n\n";
  std::cout<<"b = "<<b<<"\n\n";

  std::cout<<"add = "<<add<<"\n\n";
  std::cout<<"sub = "<<sub<<"\n\n";
  std::cout<<"mul = "<<mul<<"\n\n";
  std::cout<<"div = "<<div<<"\n\n";
}

/* outputs

a = -89283483274977878767667823647234682364823647368462382837498237489723984789324634864723

b = 374782837462364823646327648238467236846237468723678667678346786436346574365876435

add = -89283108492140416402844177319586443897586801130993659158830559142937548442750268988288

sub = -89283858057815341132491469974882920832060493605931106516165915836510421135899000741158

mul = -33461917200319802515753601837109468053458468416027809444006393607838140276917046124034670454166917107793360767935411247550317463348179555322868716013157970983558502505

div = -238227


*/

```

</details>

<!--=====================================================================================-->
<details>
<summary><b>large floating point arithmetic</b></summary>
<br>
<ul>

```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"

int main()
{
  apa::bfloat a("1238213681276386123123123435.2432499000023949238947982348723894798234"),
            b("-0.7777263483274682347382764236846237468236472364876238476238467");

  apa::bfloat add = a+b,
              sub = a-b,
              mul = a*b,
              div = a/b;

  std::cout<<"a = "<<a<<"\n\n";
  std::cout<<"b = "<<b<<"\n\n";

  std::cout<<"add = "<<add<<"\n\n";
  std::cout<<"sub = "<<sub<<"\n\n";
  std::cout<<"mul = "<<mul<<"\n\n";
  std::cout<<"div = "<<div<<"\n\n";

  /* output
  
        a = 1238213681276386123123123435.2432499000023949238947982348723894798234

        b = -0.7777263483274682347382764236846237468236472364876238476238467

        add = 1238213681276386123123123434.4655235516749266891565218111877657329997527635123761523761533

        sub = 1238213681276386123123123436.0209762483298631586330746585570132266470472364876238476238467

        mul = -962991404788195406610786141.65628594347326616466719178725163677523559119895726279221205273167088773817422631634718028672234467278

        div = -1592094293756684986593432084.19345313792091477747174945246646295786388435299056945084

  */
}
```

</details>
</details>

<details>
<summary><b><i>Comparison Operators</i></b></summary>
<br>
<ul>

**all comparison operators are overloaded and supported**

  - **```<```** less-than
  - **```>```** greater-than
  - **```<=```** less-than-equal
  - **```>=```** less-than-equal
  - **```==```** equal
  - **```!=```** not equal



```c++
#include <iostream>
#include "bignum/bint/bint.hpp"
#include "bignum/bfloat/bfloat.hpp"

int main()
{
    apa::bint a = 87832423432ll,
              b ("-656324364572634");

    if(a<b)
    {
        std::cout<<"a is less-than b\n";
    }
    else
    {
        std::cout<<"a is greater-than b\n";
    }

    apa::bfloat c = -8734.34,
                d = 73.43f;

    if(c>d)
    {
        std::cout<<"c is greater-than d\n";
    }
    else
    {
        std::cout<<"c is less-than d\n";
    }

    apa::bint e("-37824678234234234234555");

    if(e==e) std::cout<<"e is equal with itself\n";
}

/* output

  a is greater-than b
  c is less-than d
  e is equal with itself

*/

```

</details>

<details>
<summary><b><i>Other Overloaded Operators</i></b></summary>
<br>
<ul>

**the following operators are also available for both ```bint``` and ```bfloat``` class**

  - **```++```** post-fix & pre-fix increment
  - **```--```** post-fix & pre-fix decrement
  - **```%```** mod

</details>

<details>
<summary><b><i>Bfloat precision increase</i></b></summary>
<br>
<ul>

**you can increase the precision of the quotient of ```bfloat``` using ```apa::bfloat::set_div_precision(n);``` function by a level of n, one level of n adds 8 digit precision if your ```dtype``` is ```long long```**

```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"

int main()
{
    apa::bfloat a = 355.0,
                b = 113.0;

    apa::bfloat pi_approximation1 = a/b;
    std::cout<<"pi1 = "<<pi_approximation1<<"\n\n";

    apa::bfloat::set_div_precision(10);

    apa::bfloat pi_approximation2 = a/b;
    std::cout<<"pi2 = "<<pi_approximation2<<"\n";
}

/* output

  pi1 = 3.141592920353982300884955

  pi2 = 3.1415929203539823008849557522123893805309734513274336283185840707964601769911504424778761619469

*/

```
</details>


</details>

<!----------------------------------------------------------------------------------->
<details>
<summary><b><i>Math Functions</i></b></summary>
<br>
<ul>

<!--=====================================================================================-->
<details>
<summary><b>power</b></summary>
<br>
<ul>

**overloads**
- ```bint apa::math::pow(const bint& base, const bint& exponent);```
- ```bfloat apa::math::pow(const bfloat& base, const bint& exponent);```

```c++
#include <iostream>
#include "bignum/bfloat/bfloat.hpp"
#include "bignum/function/apa_math.hpp"

int main()
{
  apa::bfloat b("2.2");
  apa::bint e = 321;

  apa::power = apa::math::pow(b,e);
  
  std::cout<<power<<"\n";

  /* output

  82733337426266713526325852808546470983403982888124144770331506094928027938777139065229084725716751315911897210.74543221264142915
  75696707119831328517886660461460858728136256844778637653193470359856043666862962857819245746193505881242508583105869039144390543
  43119594612138707164329955150317078286139488995582660335248028665245492930295727471626133973850977966242139290346266904810277993
  046638156865321497984580207663602337611169923072

  */

}
```

</details>
</details>


</details>


