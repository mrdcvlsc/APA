# bignum
https://mrdcvlsc.github.io/bignum/
## A C++ library for computing big number.

## FIXED : bignum v2.0 - fixed bugs from v1.3-v1.7 (Nov. 16, 2020) ##

-------------------------------------------------------------------

### **NOW bignum's ADDITION, SUBTRACTION, MULTIPLICATION, AND DIVISION OPERATIONS CAN HANDEL INTEGERS AND RATIONAL NUMBERS(DECIMAL FORM)** ###

-------------------------------------------------------------------

### HOW?

###### This library uses c++ class to encapsulate methods/function to perform operations on big numbers/large numbers.

## JUST STRINGS

###### This implementation uses string data type to store large numbers/big numbers.

## ELEMENTRAY TECHNIQUES

###### The four basic arithmetic operations are implemented using plain old, slightly tweeked elementary techniques in addition, subtraction, multiplication, and division... yeah that long division and that addition, subtraction, multiplication where you put the numbers on top of each other, that technique you are doing when you are in grade school, that is what this library is using... nothing fancy like using bitwise operations, and other advance concept.

## IMPLEMENTATION

###### For addition, subtraction, and multiplication every 9 digits (4 digits for multiplication) in the string value of the bignumber is then converted into a long int number then stored into an array of long ints, then arithmetic operations are applied on each index of the array, the results are then processed then each index is converted back and joined into a string... this is how this library mainly works

## IM HUNGRY

***The "bignum" user made data type provided by the library enables you to:***


   1.) store very large numbers in a variable.
   
   
   2.) treat it like a normal/primitive data type.
   
   
   3.) perform arithmetic and other operations with it.
   
   
   4.) IDK... you can do anything with it.


[Github Repo - source codes](https://github.com/mrdcvlsc/bignum)


-------------------------------------------------------------------

**-sample program - windows** [Folder](https://github.com/mrdcvlsc/bignum/tree/master/sample%20program%20windows)

**-bignum library - windows** [Download](https://github.com/mrdcvlsc/bignum/blob/master/sample%20program%20windows/bignumlib_win.lib)

**-sample program - linux** [Folder](https://github.com/mrdcvlsc/bignum/tree/master/sample%20program%20linux)

**-bignum library - linux** [Download](https://github.com/mrdcvlsc/bignum/blob/master/sample%20program%20linux/bignumlib_linux.a)


-------------------------------------------------------------------

### TO USE :
  
  **- you can include all the files in the repo (.h .cpp) manually in your project then compile it yourself.**
  
  **- you can also use the already compiled library in the sample program (less work - instructions are in folder).**
  

-------------------------------------------------------------------

### bignum initialization
    
   ```c++
   // use string or const char* for big values
   bignum var1("67162512121");
   bignum var2 = "67864254234324234";
   
   // you can also use constant integers up to 18.4e+18
   bignum var3  = 57232;
   bignum var3l = 96725372372ll;
   
   // or float and doubles
   bignum var4 = 767643434ll;
   bignum var5 = 76734.57623f;
   
   // copy bignum
   bignum var6 = var1;
   var2 = "78273872832";
   var3 = var4 = 65652.762;
   ```
-------------------------------------------------------------------

### CURRENTLY SUPPORTED OPERATIONS
   
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
      
      cout<<("76327323" < "2837283"); // this is not allowed
      
      ```
      
**The increment and decrement operators, postfix and pre-fix form is available.**


   ```c++
   
   yourBigIntVar++;
   ++yourBigIntVar;
   yourBigIntVar--,
   --yourBigIntVar;
   
   ```     
        
**The modulo operator is also supported.**


   ```c++
   
   bignum var1 = "232", var2 = "23";
   cout<<(var1%var2)<<endl;
   
   ```     
   
---------------------------------------------------------

### PLANNED UPCOMMING SUPPORTS FOR THE FUTURE

   **operations :**
   
   [ ] POWER FUNCTION FOR TWO BIG INT VARIABLES
   
   [ ] FACTORIAL FUNCTION FOR TWO BIG INT VARIABLES
   
   [ ] cNr FUNCTION 
   
   [ ] pNr FUNTION 
   
   [ ] XOR
   
   [ ] cube root / square root / root
    
---------------------------------------------------------


### PLANNED IMPROVEMENTS
    
   [ ] ***REDUCE CODE CLUTTER***
   
   [ ] ***IMPLEMENT FASTER APPROACHES***
    
   [+] maximize int array values when performing arithmetic operations for internal methods of multiplication, from one digit to possibly 4-8?
    
---------------------------------------------------------


## WHY I CREATED THIS?
  
   If you're asking...
   I know there are some C++ libraries out there that supports operations for larger integer values
   But I created this as a challenge to myself;
   to gain experience, to practice how to improve existing code, to learn more things along the development process.
   
   *my 2nd year CS personal project*
   
# A C++ Class Library that you can use for computing big numbers, using this library you can add, subtract, multiply, divide very large numbers in C++
 
## LICENCE - MIT

