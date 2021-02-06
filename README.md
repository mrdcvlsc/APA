# bignum
https://mrdcvlsc.github.io/bignum/
## bignum - c++ for big number computation (arbitrary-precision arithmetic).

#### **SUPPORTS OPERATION ON INTEGER AND RATIONAL NUMBERS IN DECIMAL FORM** ###

#### Download It Here - [Github Repo - source codes](https://github.com/mrdcvlsc/bignum)

------------------------------------------------------------------

# contents

- [Instructions - how to use](#instructions)

- [Performance - time per operation](#performance)

- [Initialization/Assignment](#initialization)

- [Arithmetic Operators](#arithmetic-operators)

- [Comparison Operators](#comparison-operators)

- [IO Operator](#io-operators)

- [Sample Program](#sample-code)

- [Implementation - How?](#implementation)

- [About this project?](#about)


-------------------------------------------------------------------

# instructions

## IDE USER

  1. put the **bignum.h** and all the **.cpp** files that is inside the ***source*** folder to your project folder.

  2. add **```#include "bignum.h"```** in your ***main.cpp*** file.
  
  3. select and add the files on your project in your IDE.

  4. then compile and run.
  
-------------------------------------------------------------------

## USING MAKE

  **make - will compile bignum.lib (compiled library)**
  
  **make test - will compile the sample program with the compiled library**
 
  ```shell
  make
  make test
  ```  
  
[go back to contents](#contents)

-------------------------------------------------------------------

# initialization

### bignum initialization (using double quote "" is more recommended)
    
   ```c++
   // use string or const char* for big values
   bignum var1 = "23234.78634";
   bignum var2 = "-67864254234324234";
   
   // you can also use constant integers up to 18.4e+18
   bignum var3  = -57232;
   bignum var4 = 96725372372ll;
   
   // or float and doubles
   // for very long rational numbers use strings instead to avoid automatic rounding
   bignum var5 = 7676434.2323234L; // long doubles
   bignum var6 = -76734.57623f;
   
   // copy bignum
   bignum var7 = var1;
   var3 = var4 = 65652.762;
   ```
[go back to contents](#contents)

-------------------------------------------------------------------

# arithmetic operators

### SUPPORTED OPERATIONS (FOR INTEGERS AND RATIONAL NUMBERS/DECIMAL FORM): EXAMPLES OF USES BELOW

   **[done] Addition (+)**
   ```c++   
   cout<< var1 + var3 <<endl;
   cout<< var3 + "56756.4645" <<endl;
   cout<< 7567634 + var1 <<endl;
   ```
   **[done] Subtraction (-)**
   ```c++
   cout<< var2 - var1 <<endl;
   cout<< var4 - 74672323232ull <<endl;
   cout<< "656422" - var3 <<endl;
   ```
   **[done] Multiplication (x)**
   ```c++
   cout<< var1 * var3 <<endl;
   cout<< var2 * 2234544.65 <<endl;
   cout<< "64652823.42" * var3 <<endl;
   ```
   **[done] Division (/)**
   ```c++
   cout<< var2 / var6 <<endl;
   cout<< var3 / "521321" <<endl;
   cout<< "652323" / var1 <<endl;
   ```
   **[done] Modulo (%)**
   ```c++
   cout<< var2 % var1 <<endl
   ```
   **[done] Addition Assignment (+=)**
   ```c++
   var1+=var2;
   var1+="7822.22";
   var1+=2321;
   ```
   **[done] Subtraction Assignment (-=)**
   ```c++
   var2-=2112312;
   var1-="2322.32";
   ```
   **[done] Multiplication Assignment (*=)**
   ```c++
   bignum varNew = var1*="222";
   var1*=var2;
   ```
   **[done] Division Assignment (/=)**
   ```c++
   var1/="2222";
   var1/=var3;
   ```
   **[done] Increment (++)**
   ```c++
   var1++;  // post-fix
   ++var1;  // pre-fix
   ```
   **[done] Decrement (--)**
   ```c++
   var1++;  // post-fix
   ++var1;  // pre-fix
   ```
[go back to contents](#contents)

-------------------------------------------------------------------

# performance

## AVERAGE TIME IN MICROSECONDS PER ONE OPERATION :

### NOTE: (DEFAULT COMPILATION) NO G++ OPTIMIZATION FLAG USED

### time for two "200 digit/length" string numbers (Nx10^200)

**Addition Operation       :** ***463.5 microseconds***

**Subtraction Operation    :** ***353.5 microseconds***

**Multiplication Operation :** ***434.5 microseconds***

**Division Operation       :** ***5,473.32 microseconds***

__The performance can be increase further to 5-60 microseconds only (probally) by removing the conversion of string to int data type and vice versa inside the arithmetic operations, and only convert it to string when outputting the result value or by creating a toString() method to get the converted string value, (I will implement this in the future)__

[go back to contents](#contents)

-------------------------------------------------------------------

# sample code

## FACTORIAL SAMPLE CODE

  ```c++
  // main.cpp
  
  #include <iostream>
  #include "bignum.h"

  using namespace std;

  int main(){

    // A very slow factorial

    cout<<"FACTORIAL OF A NUMBER : "<<endl;

    bignum limit = 1000;
    
    bignum n = limit, fac = "1";

    for(bignum i=1; i<=limit; ++i)
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
  - bignum.h
  - bignum.lib

### FACTORIAL SAMPLE CODE: compilation `g++ -o output.exe main.cpp bignum.lib -O3`

[go back to contents](#contents)

-------------------------------------------------------------------

# io operators

   ```c++
   bignum bignumberVariable = 213213123;
   cout << bignumberVariable << endl; // output - 213213123
   cin >> bignumberVariable;     // take user input - should be a number: will end the program if not
   ```
[go back to contents](#contents)   

-------------------------------------------------------------------

# comparison operators

  **All of the follwing comparison operators below are overloaded/available
   - ***less than (<)***
   - ***greater than (>)***
   - ***less than or equal (<=)***
   - ***greater than or equal (>=)***
   - ***equal to (==)***
   - ***not equal to (!=)***
   
   ***note: always enclose two bignum values when you are using comparison operators inside the ff. operators : <<,>>,() ex:***
   
   ```c++
   bignum large_number = "2887382", big_number = "2367232";
   cout<< (large_number != bignum); //allowed
   ```
   
*Comparison between a bignum variable and a string value or const char* is possible, but you should enclose it with ()*
   
   ```c++
   bignum variable1 = "72736273";
   cout<<(variable1 <= "81283798237")<<endl; // allowed 
   cout<<(-76323.6763f > variable1)<<endl;  // allowed
   ```
   
*WARNING: Do not expect when comparing two "const char*" to behave like two bignum values*
   
   ```c++
   cout<<("76327323" < "2837283"); // this is not allowed
   ```

[go back to contents](#contents)

-------------------------------------------------------------------

# implementation

### HOW?

###### This library uses c++ class to encapsulate methods/function to perform operations on big numbers/large numbers.

## JUST STRINGS

###### This implementation uses string data type to store large numbers/big numbers.

## ELEMENTRAY TECHNIQUES (SCHOOL BOOK)

###### The four basic arithmetic operations are implemented using plain old, slightly tweeked elementary techniques in addition, subtraction, multiplication, and division... yeah that division, addition, subtraction and multiplication where you put the numbers on top of each other to compute the answer, that technique you are doing when you are in grade school, that is what this library is using... nothing fancy like using bitwise operations etc.(idk), and other advance concept.

## INTO ARRAYS

###### For addition, subtraction, and multiplication every 18 digits (8 digits for multiplication) in the string value of the bignumber is then converted into a  long long int number then stored into an array of long long ints, then arithmetic operations are applied on each index of the array then stored to another array of long long int, the results' index are then processed carried to the next index when it's value reach a certain limit, then each index is converted back and joined into a string... this is how this library mainly works

***The "bignum" user made data type provided by the library enables you to:***

   1. store very large numbers in a variable.   
   
   2. treat it like a normal/primitive data type.
   
   3. perform arithmetic and other operations with it.
   
   4. IDK... you can do anything with it.

[Github Repo - source codes](https://github.com/mrdcvlsc/bignum)

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

