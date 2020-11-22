# bignum
https://mrdcvlsc.github.io/bignum/
## A C++ library for computing big number

### **SUPPORTS OPERATION ON INTEGER AND RATIONAL NUMBERS(DECIMAL FORM)** ###


-------------------------------------------------------------------

### TO USE :

  
  **you can put all the files in the repo (.h .cpp) and include it manually in your project then compile it yourself**
  	-put the bignum.h and all the .cpp files in your project
  	-set #include "bignum.h" in your main file
  	-then build and run
  
  **You can also use the "make" command to generate the static library "bignum.lib" then include/link it to your project along the header file bignum.h**
  	-for complete beginners a "make" is a program in the MinGW folders
  	-you can also install "make" yourself if you like its up to you
  	-make sure that your "make" path is included in your environment variables path
  	-the generated library "bignum.lib" when compiled will be the alternative for all the ".cpp" files
  	 this is much faster to compile again with your main.cpp file
  
  **(optional) use the "make test" after make to run the test program if you want**
  

-------------------------------------------------------------------

### bignum initialization
    
   ```c++
   // use string or const char* for big values
   bignum var1("671625.12121");
   bignum var2 = "-67864254234324234";
   
   // you can also use constant integers up to 18.4e+18
   bignum var3  = -57232;
   bignum var3l = 96725372372ll;
   
   // or float and doubles
   // for very long rational numbers use strings instead to avoid automatic rounding
   bignum var4 = 7676434.2323234L; // long doubles
   bignum var5 = -76734.57623f;
   
   // copy bignum
   bignum var6 = var1;
   var2 = "78273872832";
   var3 = var4 = 65652.762;
   ```
-------------------------------------------------------------------

### SUPPORTED OPERATIONS (FOR INTEGERS AND RATIONAL NUMBERS/DECIMAL FORM)
   
   **[+] Addition (+)**
   
   **[+] Subtraction (-)**
   
   **[+] Multiplication (x)**
   
   **[+] Division (/)**
   
   **[+] Modulo (%)**
   
   ```c++  
   // Intitialization
   bignum var1 = "67576723489743243243";
   bignum var2 = 73442423233ull;
   bignum var3 = 6523.767;
   bignum answer;
   
   // addition
   cout<<var1+var3<<endl;
   cout<<var3+"56756.4645"<<endl;
   cout<<7567634+var1<<endl;
   
   // subtraction
   cout<<var2-var1<<endl;
   cout<<var1-74672323232ull<<endl;
   cout<<"656422"-var3<<endl;
   
   // multiplication
   cout<<var1*var3<<endl;
   cout<<var2*2234544.65<<endl;
   cout<<"64652823.42"*var3<<endl;
   
   // division
   cout<<var2/var1<<endl;
   cout<<var3/"521321"<<endl;
   cout<<"652323"/var1<<endl;
   
   // mod
   cout<<var2 % var1<<endl;
   
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
      
**The increment and decrement operators, postfix and pre-fix form is available.**


   ```c++
   
   bignum up=0, down="2";
   up++;
   ++up;
   --down;
   down--;
   
   ```     

### **SUPPORTS INTEGER AND RATIONAL NUMBERS(DECIMAL FORM)** ###

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


---------------------------------------------------------


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

