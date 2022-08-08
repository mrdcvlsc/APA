### **`apa::bint` : Bitwise Not (~)**

- The bitwise not (~) of `bint` is the same as Python's not operator, or in general it performs a 2's complement conversion.

    $$y = -(x+1)$$

    In `bint` This will be equivalent to adding 1 for the `number` member, then flipping the `sign` member to negative.

### **`apa::bint`'s bitwise logical &, |, ^ operators**
- The other bitwise logical operators of `bint` (&, |, ^) applies a special 2's complement conversion to negative `bint` parameters before applying the operators.

    If the output is negative we then again applies a special 2's complement conversion.

    This special 2's complement conversion is different from the `bint::operator~`, it involves padding the operands and the `sign` does not flip here.

    In general the output of these operators should be the same as python3's bitwise logical operators.

### **`apa::bint` : Division**

- The division operator of `bint` is more similar to C/C++ than in python. `bint` don't apply a floor function to the quotient, instead it stops calculating the value after the decimal.

    To show the difference here is an example:

    - **C/C++ & bint division output:**

        $$-9/4 = -2$$

    - **Python3 floor division output:**

        $$-9//4 = -3$$

### **`apa::bint` : Modulo**

- Since the division of bint is more similar to C/C++ the modulo output of `bint` in some cases for negative numbers will be different to the output of python's modulo.

    - **C/C++ & bint modulo output:**

        $$-9 \ mod \ 4  = -1$$

    - **Python3 modulo output:**

        $$-9 \ mod \ 4  = 3$$

    This is because python uses the floor division to get the mod: 

    $$remainder = a - b \lfloor a/b\rfloor$$