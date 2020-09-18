# bintlib
A c++ .h,.cpp files for computing big integer values

TO USE : just include the .h and the .cpp files to your c++ projects, or you can put everything in just one .h file

-VARIABLE DECLARATION
  supported:
  
    BIGINT variableName("6716212121");   // this use a string to store large int values
    BIGINT var2;
  not supported yet:
  
    BIGINT var2 = "78273872832";
    
-ASSIGNING VALUE:

    BIGINT newVariable("7627386276"), newVar2;
    newVariable = "2732984754";
    newVar2 = "87845485";
    
-current operations it supports, use the (-,+,*) operators
    -addition
    -subtraction
    -multiplication
