# bignum

A C++ library for computing big number values.

NOW, ALL FOUR ARITHMETIC OPERATIONS CAN HANDEL INTEGER VALUE.
CURRENTLY DIVISION IS THE ONLY ONE THAT SUPPORTS OPERATION ON FLOATING POINT VALUE.

TO USE :

    -you can include all the files(.h .cpp) manually in your project then compile it yourself.
    -you can also use the already compiled library in the sample program (instructions are in folder).

--------------------------------------------------------------------------------------
VARIABLE DECLARATION
  supported:
  
    bignum var1("6716212121");
    bignum var2;  
    bignum var3 = var1
    bignum var4 = "787283287";
    var2 = "78273872832";
    var3 = var4;
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATIONS

    bignum var1("6526323"),var2="7623", ans;
    
    //addition (operation on floating point - not supported yet)
    ans = var1 + var2;
    ans = var2 + bignum("7823");  // this is also allowed
    
    //subtraction (operation on floating point - not supported yet)
    ans = var2 - var2
    
    //multiplication (operation on floating point - not supported yet)
    ans = var2 * bignum("-6722") * var1; // multiple operations is also allowed
    
    //division (operation on floating point - ALREADY SUPPORTED)
    ans = var2 / var1;
    
    //modulo
    ans = var2 % var1;
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATORS (bignumber overloaded operators)

<<, >> operator for "cout" output and "cin" input is supported

    cout<<abigintvariable<<endl; 
    cin>>abigintvar;
        
   
<, >, <=, >=, ==, != (these comparison operators are also available)
note: always enclose two bignum values when you are using comparison operators
ex:

    bignum bigIntVar1 = "2887382", bigIntVar2 = "2367232";
    cout<<(bigIntVar1 != bigIntVar2); //allowed

Comparison between a bignum variable and a string value or const char* is possible

    bignum variable1 = "72736273";
    cout<<(variable1 <= "81283798237")<<endl; // allowed 
    cout<<("82738271344" > variable1)<<endl;  // allowed

WARNING: Do not expect when comparing two "const char*" to behave like two bignum values

    ("76327323" < "2837283"); // this is not allowed


The increment and decrement operators, postfix and pre-fix form is available

        yourBigIntVar++, ++yourBigIntVar; // allowed
        yourBigIntVar--, --yourBigIntVar; // allowed
        
The modulo operator is also supported
        
        bignum var1 = "232", var2 = "23";
        cout<<(var1%var2)<<endl;
    
---------------------------------------------------------------------------------------

PLANNED UPCOMMING SUPPORTS FOR THE FUTURE

   operations :
   
    POWER FUNCTION FOR TWO BIG INT VARIABLES
    FACTORIAL FUNCTION FOR TWO BIG INT VARIABLES
    cNr FUNCTION 
    pNr FUNTION
    
   others :
     
    implement support for floating point numbers for the three arithmetic operations + - *
    
--------------------------------------------------------------------------------------
PLANNED IMPROVEMENTS
    
    REDUCE CODE CLUTTER
    IMPLEMENT FASTER APPROACHES
    
--------------------------------------------------------------------------------------

WHY I CREATED THIS?
    
    If you're asking...
    I know there are some C++ libraries out there that supports operations for larger integer values
    But I created this as a challenge to myself;
    to gain experience, to practice how to improve existing code, to learn more things along the development process.
    
    
