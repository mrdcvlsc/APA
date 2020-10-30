# bintlib

A c++ .h,.cpp files for computing big integer values

TO USE : just include the .h and the .cpp files to your c++ projects, or you can put everything in just one .h file

--------------------------------------------------------------------------------------
VARIABLE DECLARATION
  supported:
  
    BIGINT variableName("6716212121");
    BIGINT var2;  
    var2 = "78273872832";
    BIGINT var3 = "7232832323283";
--------------------------------------------------------------------------------------
ASSIGNING VALUE (supported)

    BIGINT newVariable("7627386276"), newVar2;
    BIGINT thisIsPossibleNow = "782837232";
    newVariable = "2732984754";
    newVar2 = "87845485";
    BIGINT newNum = newVar2;
    BIGINT newNum2 = newVar2*newNum+newVariable;
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATIONS

    BIGINT var1("6526323"),var2="7623", ans;
    
    //addition
    ans = var1 + var2;
    ans = var2 + BIGINT("7823");  // this is also allowed
    
    //subtraction
    ans = var2 - var2
    
    //multiplication
    ans = var2 * BIGINT("-6722") * var1; // multiple operations is also allowed
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATORS (big integer overloaded operators)

    << operator for cout output is supported
        cout<<abigintvariable<<endl; 
        
    >> operator for cin input is supported
        cin>>abigintvar;
        
    <  operator(lessthan operator)
    >  greaterthan operator
    <=, >=, ==, !=  are also available
        ex: (bigIntVar1 > bigIntVar2), (bigIntVar1 != bigIntVar2), etc.
        
    ++ the increment operator, supports both postfix and prefix use
        yourBigIntVar++, ++yourBigIntVar; // allowed
        
    -- the decrement operator, supports both postfix and prefix use
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
    
    
