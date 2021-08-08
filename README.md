# bignum
https://mrdcvlsc.github.io/bignum/
## bignum - c++ for big number computation (arbitrary-precision arithmetic).

[Download Bignum - compiled library](https://github.com/mrdcvlsc/bignum/releases/tag/v2.8.8)

------------------------------------------------------------------

*this repository provides the 2 library named below*

**bint** - ___is only used to compute and perform operations on signed big integers___

**bnum** - ___on the otherhand can compute and perform operations on signed big floating point values___

------------------------------------------------------------------

# contents

- [Instructions - how to use](#instructions)

- [Performance - time per operation](#performance)

- [Overloaded Operators](#operators)

    - [Initialization/Assignment](#initialization)

    - [Arithmetic Operators](#arithmetic-operators)

    - [Comparison Operators](#comparison-operators)

    - [IO Operator](#console-input-and-output)
  
- [Functions & Methods](#functions-and-methods)

- [Sample Program](#sample-code)

- [Implementation - How?](#implementation)

- [About this project?](#about)


-------------------------------------------------------------------

# instructions

## IDE USER

  1. depending on what you are using either bint or bnum, copy all of the files 'inside' the 'include' folder and 'src' folder into your project

  2. add **```#include "bnum.hpp"```** or **```#include "bnum.hpp"```** in your ***main.cpp*** file.
  
  3. select and add the files on your project in your IDE.

  4. then compile and run.
  
# USING THE COMPILED LIBRARY IN 'RELEASE'

  1. download the compile library in release
  2. extract the files and put it in you project
  3. include the header files in you source code ex: ```#include <bint.hpp>```
  4. when compiling specify the paths of the header file and the static library using the -I & -L flags

  eg: ```g++ -o main main.cpp -I"path/bignum/bint/include" -L"path/bignum/bint/lib" -lbint```

  see the factorial sample program for more info in compilation

[Download Bignum - compiled library](https://github.com/mrdcvlsc/bignum/releases/tag/v2.8.8)
 
-------------------------------------------------------------------

## USING MAKE

  **to create the compiled library in windows**
  
  ```shell
  git clone https://github.com/mrdcvlsc/bignum.git
  cd bignum
  make win
  ```

  ```make lin``` for linux

  
  **sample program 1 - calculator***

  ```shell
  git clone https://github.com/mrdcvlsc/bignum.git
  cd bignum
  cd bint // or cd bnum
  make sample1
  ```

  **sample program 2 - performance test**

  ```shell
  git clone https://github.com/mrdcvlsc/bignum.git
  cd bignum
  cd bint // or cd bnum
  make sample2
  ```

[go back to contents](#contents)

-------------------------------------------------------------------

# operators

# Initialization

   ```c++
   bnum var1 = "23234.78665464846464686434";
   bnum var2 = -57232;
   bnum var3 = 96725372372ll;
   bnum var4 = 7676434.2323234L;
   bnum var5 = -76734.57623f;
   bnum var6 = var1;
   var3 = var4 = 65652.762;
   ```

# Arithmetic Operators
  
  ```c++
  bnum a = "966649767633554246465753766946573.67644334";;
  bnum b = 365365211765899436ll;
  bnum i = 0, j = 100;

  bnum add, sub, mul, div, mod;

  // overloaded arithmetic operators
  add = a + b;
  sub = a - b;
  mul = a * b;
  div = a / b;
  mod = a % b;

  /* you can also directly perform arithmetic operators
     on 'const char*', string and numeric data types that is a valid number
     with a bnum or bint object.
     ex:
     add = b + "-46433491854.646755464";
     sub = 64523494.666455543L - a;           */

  // arithmetic assignment operators
  i+=1;
  j-=1;
  i*=a+j;
  j/=b*"546";

  // increment/decrement operators
  i++;
  ++i;
  j--;
  --j;
  ```

# Console Input and Output

  ```c++
  bnum a;
  cin>>a;
  cout<<a;
  ```

# Comparison Operators

  ```c++
  bnum a = 745, b = "745", c = 524;
  bool s[6];
  s[0] = a != b; // 0
  s[1] = a == b; // 1
  s[2] = a < c;  // 0
  s[3] = a > c;  // 1
  s[4] = a <= b; // 1
  s[5] = a >= c; // 1
  ```

[go back to contents](#contents)

-------------------------------------------------------------------

# functions and methods

```bnum::set_div_precision(n);``` - default value is 1, increase division precision here

-------------------------------------------------------------------

# performance

### compiled with -O3 -march=native

### operation speed on two bnum variables let's call them ```bnum a``` & ```bnum b```

__Average time per operation__

_performance was recorded using ```std::chrono::high_resolution_clock```_

each level initializes the bnum variables _a & b_ with different numbers of digits, **keep in mind** these are the **number of digits**

**it is not the actual value**... for examle; the number ```778,476,234``` has 9 digits

**Level 1 :** ```bnum a``` & ```bnum b``` both having ***200 digits*** each**
   - _add      ```bnum c = a+b;```_ : ***4 microseconds***
   - _subtract ```bnum c = a-b;```_ : ***8 microseconds***
   - _multiply ```bnum c = a*b;```_ : ***32 microseconds***
   - _divide   ```bnum c = a/b;```_ : ***683 microseconds***

**Level 2 :** ```bnum a``` having ***20,001 digits***, while ```bnum b``` having ***19,001 digits***
   - _add      ```bnum c = a+b;```_ : ***33 microseconds***
   - _subtract ```bnum c = a-b;```_ : ***30 microseconds***
   - _multiply ```bnum c = a*b;```_ : ***13349 microseconds*** == _0.013349 seconds_
   - _divide   ```bnum c = a/b;```_ : ***660821 microseconds*** == _0.660821 seconds_

**Level 3 :** ```bnum a``` having ***1,413,641 digits***, while ```bnum b``` having ***1,413,631 digits***
   - _add      ```bnum c = a+b;```_ : ***4659 microseconds***
   - _subtract ```bnum c = a-b;```_ : ***4186 microseconds***
   - _multiply ```bnum c = a*b;```_ : ***145977711 microseconds*** == _145.977711 seconds_
   - _divide   ```bnum c = a/b;```_ : ***1470898793 microseconds*** == _24.51497988333 minutes_

### 'bint' has a faster performance than 'bnum' but only computes big integers

***machine specs where the preformance test was done***
```
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
Address sizes:                   36 bits physical, 48 bits virtual
CPU(s):                          4
On-line CPU(s) list:             0-3
Thread(s) per core:              1
Core(s) per socket:              4
Socket(s):                       1
NUMA node(s):                    1
Vendor ID:                       GenuineIntel
CPU family:                      6
Model:                           76
Model name:                      Intel(R) Pentium(R) CPU  N3700  @ 1.60GHz
Stepping:                        3
CPU MHz:                         2259.578
CPU max MHz:                     2400.0000
CPU min MHz:                     480.0000
BogoMIPS:                        3200.00
L1d cache:                       96 KiB
L1i cache:                       128 KiB
L2 cache:                        2 MiB
Flags:                           fpu vme . . . sse, sse2, sse_4, sse4_2 . . . .
```

[go back to contents](#contents)

-------------------------------------------------------------------

# sample code

## FACTORIAL SAMPLE CODE

  ```c++
  // main.cpp
  
  #include <iostream>
  #include "bint.hpp"

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
  ```
### FACTORIAL SAMPLE CODE: Folder Structure of the code above

- Main_Folder
  - main.cpp
  - include
    - bint.hpp
    - arr_num_arithmetic.hpp
  - lib
    - bint.lib

### FACTORIAL SAMPLE CODE: compilation

  ```g++ -o main.exe main.cpp -I"./include" -L"./lib" -lbint```

[go back to contents](#contents)

-------------------------------------------------------------------

# implementation

### HOW?

###### This implementation uses a vector of long long ints to store large numbers/big numbers.

## ELEMENTRAY TECHNIQUES (SCHOOL BOOK)

###### The four basic arithmetic operations are implemented using plain old, slightly tweeked elementary techniques in addition, subtraction, multiplication, and division... yeah that division, addition, subtraction and multiplication where you put the numbers on top of each other to compute the answer, that technique you are doing when you are in grade school, that is what this library is using... nothing fancy like using bitwise operations etc.(idk), and other advance concept.

## INTO ARRAYS

###### For addition, subtraction, and multiplication every 8 digits of the big number is converted into a long long int stored into a a vector, then arithmetic operations are applied on each index of the vector, the answer per index of vector is then stored to another vector of long long int, the results' index are then processed carried to the next index when it's value reach a certain limit

***The "bignum" user made data type provided by the library enables you to:***

   1. store very large numbers in a variable.   
   
   2. treat it like a normal/primitive data type.
   
   3. perform arithmetic and other operations with it.
   
   4. IDK... you can do anything with it.

[Download Bignum - compiled library](https://github.com/mrdcvlsc/bignum/releases/tag/v2.8.8)

[go back to contents](#contents)

---------------------------------------------------------

### MY TODO - PLANNED UPCOMMING SUPPORTS FOR THE FUTURE
   
   [ ] Remove conversion of string to long long int and vice-versa on arithmetic operations to increase performance.
   
   [ ] POWER FUNCTION
   
   [ ] FACTORIAL FUNCTION (I NEED A FAST ONE - prime swing or multithreading)
   
   [ ] cNr FUNCTION
   
   [ ] pNr FUNTION
   
   [ ] bitwise operators
   
   [ ] cube root / square root / root (fast one)
    
[go back to contents](#contents)

---------------------------------------------------------

### TO NOTE
    
   ***KEEP REDUCING CODE CLUTTER***
   
   ***IMPLEMENT FASTER APPROACHES***
    
---------------------------------------------------------

# about

## WHY I CREATED THIS?
  
   If you're asking...
   I know there are some C++ libraries out there that supports operations for larger number values
   But I created this as a challenge to myself;
   to gain experience, to practice how to improve existing code, to learn more things along the development process.
   
   *started in 2020, 2nd year CS personal project*

[go back to contents](#contents)
   
# A C++ Class Library that you can use to compute big numbers, using this library you can add, subtract, multiply, divide very large numbers in C++
 
## LICENCE - MIT

