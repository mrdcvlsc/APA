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