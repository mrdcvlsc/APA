# bintlib

A c++ .h,.cpp files for computing big integer values

TO USE : just include the .h and the .cpp files to your c++ projects, or you can put everything in just one .h file

--------------------------------------------------------------------------------------
VARIABLE DECLARATION
  supported:
  
    bignum var1("6716212121");
    bignum var2;  
    var2 = "78273872832";
    bignum var3 = var1
    bignum var4 = "787283287";
--------------------------------------------------------------------------------------
ASSIGNING VALUE (supported)

    bignum newVariable("7627386276"), newVar2;
    bignum thisIsPossibleNow = "782837232";
    newVariable = "2732984754";
    newVar2 = "87845485";
    bignum newNum = newVar2;
    bignum newNum2 = newVar2*newNum+newVariable;
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATIONS

    bignum var1("6526323"),var2="7623", ans;
    
    //addition
    ans = var1 + var2;
    ans = var2 + bignum("7823");  // this is also allowed
    
    //subtraction
    ans = var2 - var2
    
    //multiplication
    ans = var2 * bignum("-6722") * var1; // multiple operations is also allowed
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATORS (big integer overloaded operators)

<<, >> operator for "cout" output and "cin" input is supported

    cout<<abigintvariable<<endl; 
    cin>>abigintvar;
        
   
<, >, <=, >=, ==, != (these comparison operators are also available)
note: always enclose two bignum values when you are using comparison operators
ex:

    bignum bigIntVar1 = "2887382", bigIntVar2 = "2367232";
    (bigIntVar1 != bigIntVar2); //allowed

Comparison between a bignum variable and a string value or const char* is possible

    bignum variable1 = "72736273";
    (variable1 <= "81283798237"); // allowed 
    ("82738271344" > variable1);  // allowed

WARNING: Do not expect when comparing two "const char*" to behave like two bignum values

    ("76327323" < "2837283"); // this is not allowed


The increment and decrement operators, postfix and pre-fix form is available

        yourBigIntVar++, ++yourBigIntVar; // allowed
        yourBigIntVar--, --yourBigIntVar; // allowed
    
---------------------------------------------------------------------------------------

PLANNED UPCOMMING SUPPORTS FOR THE FUTURE

   operations :
   
    DIVISION OPERATION
    POWER FUNCTION FOR TWO BIG INT VARIABLES
    FACTORIAL FUNCTION FOR TWO BIG INT VARIABLES
    cNr FUNCTION 
    pNr FUNTION
    
   operators :
   
    / operator (overload division operator)
    
   others :
     
    implement support for floating point numbers
    
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
    
    
