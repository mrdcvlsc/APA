# bignum
https://mrdcvlsc.github.io/bignum/
## A C++ library for computing big number.

NOW, **ALL FOUR ARITHMETIC OPERATIONS CAN HANDEL INTEGER VALUE**.
CURRENTLY **DIVISION** IS THE ONLY ONE THAT SUPPORTS **OPERATION ON FLOATING POINT VALUES**.

-------------------------------------------------------------------


###### This library uses c++ class to encapsulate methods/function to perform operations on big numbers/large numbers, this implementation uses string data type to store large numbers/big numbers, the four basic arithmetic operations are implemented using old plain elementary techniques in addition, subtraction, multiplication, and division yeah that long division and addition that you are doing when you are in grade school... nothing fancy like using bitwise operations, and other advance concept. For addition, subtraction, and multiplication, each digit in the string value of the bignumber is then converted into and array of integers, then arithmetic operations are applied to each index of that array, the result is then converted back into a string and this is how this library manily works.kapahon


***The "bignum" user made data type provided by the library enables you to:***


   1.) store very large numbers in a variable.
   
   
   2.) treat it like a normal/primitive data type.
   
   
   3.) perform arithmetic and other operations with it.
   
   
   4.) IDK... you can do anything with it.


[Github Repo - source codes](https://github.com/mrdcvlsc/bignum)



-------------------------------------------------------------------


**-sample program - linux** [Folder](https://github.com/mrdcvlsc/bignum/tree/master/sample%20program/bignum%20calculator%20linux)

**-bignum library - linux** [Download](https://github.com/mrdcvlsc/bignum/blob/master/sample%20program/bignum%20calculator%20linux/bignum_lib_linux.a)

**-sample program - windows** [Folder](https://github.com/mrdcvlsc/bignum/tree/master/sample%20program/bignumber%20calculator%20windows)

**-bignum library - windows** [Download](https://github.com/mrdcvlsc/bignum/blob/master/sample%20program/bignumber%20calculator%20windows/bignum_lib_windows.lib)


-------------------------------------------------------------------


### TO USE :
  
  **- you can include all the files in the repo (.h .cpp) manually in your project then compile it yourself.**
  
  **- you can also use the already compiled library in the sample program (instructions are in folder).**

-------------------------------------------------------------------

### VARIABLE DECLARATION
    
   ```c++
   bignum var1("6716212121");
   bignum var2;  
   bignum var3 = var1
   bignum var4 = "787283287";
   var2 = "78273872832";
   var3 = var4;
   ```
-------------------------------------------------------------------

### CURRENTLY SUPPORTED OPERATIONS

   **Declared Variables:**
   
   ```c++  
   bignum var1("6526323"),
          var2="7623",
          ans;
   ``` 
   
   **-Addition (+)** (operation on floating point - not supported yet)
   
   ```c++ 
   ans = var1 + var2;
   ans = var2 + bignum("7823");  // this is also allowed
   ```
   
   **-Subtraction (-)** (operation on floating point - not supported yet)
   
   ```c++
   ans = var2 - var2
   ```
   
   **-Multiplication (x)** (operation on floating point - not supported yet)
   
   ```c++
   ans = var2 * bignum("-6722") * var1; // multiple operations is also allowed
   ```
   
   **-Division (/)** (operation on floating point - ALREADY SUPPORTED)
   
   ```c++
   ans = var2 / var1;
   ```
   
   **-Modulo (%)**
   
   ```c++
   ans = var2 % var1;
   ```

--------------------------------------------------------------------------------------



### CURRENTLY SUPPORTED OPERATORS (bignumber overloaded operators)

   **IO : <<, >> operator for "cout" output and "cin" input is supported.**
   
   ```c++     
   cout<<abigintvariable<<endl; 
   cin>>abigintvar;
   ```
   
   **COMPARISON : <, >, <=, >=, ==, != (these comparison operators are also available) note: always enclose two bignum values when you are using comparison operators ex:**
   
   ```c++
   bignum bigIntVar1 = "2887382", bigIntVar2 = "2367232";
   cout<<(bigIntVar1 != bigIntVar2); //allowed
   ```
   
   *Comparison between a bignum variable and a string value or const char* is possible*
   
      ```c++
      bignum variable1 = "72736273";
      cout<<(variable1 <= "81283798237")<<endl; // allowed 
      cout<<("82738271344" > variable1)<<endl;  // allowed
      ```
      
   *WARNING: Do not expect when comparing two "const char*" to behave like two bignum values*
   
      ```c++
      ("76327323" < "2837283"); // this is not allowed
      ```
      
**The increment and decrement operators, postfix and pre-fix form is available.**

   ```c++
   yourBigIntVar++, ++yourBigIntVar; // allowed
   yourBigIntVar--, --yourBigIntVar; // allowed
   ```     
        
**The modulo operator is also supported.**

   ```c++    
   bignum var1 = "232", var2 = "23";
   cout<<(var1%var2)<<endl;
   ```     
   
---------------------------------------------------------

### PLANNED UPCOMMING SUPPORTS FOR THE FUTURE

   **operations :**
   
   _-POWER FUNCTION FOR TWO BIG INT VARIABLES
   
   -FACTORIAL FUNCTION FOR TWO BIG INT VARIABLES
   
   -cNr FUNCTION 
   
   -pNr FUNTION_
    
   **others :**
   
   _implement support for floating point numbers for the three arithmetic operations + - *_
    
---------------------------------------------------------


### PLANNED IMPROVEMENTS
    
   ***REDUCE CODE CLUTTER***
   
   ***IMPLEMENT FASTER APPROACHES***
    
    
---------------------------------------------------------


## WHY I CREATED THIS?
  
   If you're asking...
   I know there are some C++ libraries out there that supports operations for larger integer values
   But I created this as a challenge to myself;
   to gain experience, to practice how to improve existing code, to learn more things along the development process.
   
# A C++ Class Library use for computing large numbers, add very large numbers, subtract, multiply, divide large numbers.
## LICENCE - MIT

