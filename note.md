### Python's Bitwise Not Operator For Positive Numbers

In ```bint``` This will be equivalent to adding 1 for ```number``` member, then flipping the ```sign``` member to negative.

### Python's Bitwise Not Operator For Negative Numbers

In ```bint``` This will be equivalent to subtracting 1 for ```number``` member, then flipping the ```sign``` member to positive.

### Python's Bitwise Operators &, |, ^

In ```bint``` if a negative ```bint``` is passed to the bitwise operators, it's ```number``` should be **RAW flipped** then add 1 to it before applying the bitwise logical operators.

### Overloading Negation Operator
```c++
class YourClass {
    int value;
    // ...
    YourClass operator-() const {
        value = -value;
        return YourClass(*this);
    }
};
```

### ```bint``` : Division

- The division operator of bint is more similar to C/C++ than in python. ```bint``` don't apply a floor function to the quotient, instead it stops calculating the value after the decimal.

    To show the difference here is an example:

    - **C/C++ & bint division output:**

    $$-9/4 = -2$$

    - **Python3 floor division output:**

    $$-9//4 = -3$$

### ```bint``` : Modulo

- Since the division of bint is more similar to C/C++ the modulo output of ```bint``` in some cases for negative numbers will be different to the output of python's modulo.

    - **C/C++ & bint modulo output:**

    $$-9 \ mod \ 4  = -1$$

    - **Python3 modulo output:**

    $$-9 \ mod \ 4  = 3$$

    This is because python uses the floor division to get the mod: 

    $$remainder = a - b \lfloor a/b\rfloor$$