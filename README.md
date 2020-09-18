# bintlib

A c++ .h,.cpp files for computing big integer values

TO USE : just include the .h and the .cpp files to your c++ projects, or you can put everything in just one .h file

--------------------------------------------------------------------------------------
VARIABLE DECLARATION
  supported:
  
    BIGINT variableName("6716212121");   // this use a string to store large int values
    BIGINT var2;
  not supported yet:
  
    BIGINT var2 = "78273872832";
--------------------------------------------------------------------------------------
ASSIGNING VALUE (supported)

    BIGINT newVariable("7627386276"), newVar2;
    newVariable = "2732984754";
    newVar2 = "87845485";
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED OPERATIONS

    BIGINT var1("6526323"),var2("7623"), ans;
    
    //addition
    ans = var1 + var2;
    ans = var2 + BIGINT("7823");  // this is also allowed
    
    //subtraction
    ans = var2 - var2
    
    //multiplication
    ans = var2 * BIGINT("-6722") * var1; // multiple operations is also allowed
--------------------------------------------------------------------------------------
CURRENTLY SUPPORTED COMPARISON OPERATORS

    // THE < (lessthan operator) is still the currently supported comparison operator as of now for sorting 
--------------------------------------------------------------------------------------
PLANNED UPCOMMING SUPPORTS FOR THE FUTURE

   operations :
   
    DIVISION OPERATION and the / operator
    POWER FUNCTION
    FACTORIAL FUNCTION
    cNr FUNCTION
    pNr FUNTION
    
   operators :
   
    / operator
    > operator
    == operator
    >= operator
    <= operator
    ++ operator
    -- operator
--------------------------------------------------------------------------------------
WHY I CREATED THIS?
    
    If you're asking...
    I know there are some C++ libraries out there that supports operations for larger integer values
    But I created this as a challenge to myself;
    to gain experience, to practice how to improve existing code, to learn more things along the development process.
    
    
