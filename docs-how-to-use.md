# ubint - unsigned big integers

### Initializing ```ubint``` numbers
- from a base2 (binary) number represented by a string.
    ```c++
    apa::ubint base2("11001001110100111110100010101",2);
    // base 10 equivalent = 423263509
    ```
- from a base8 (octal) number represented by a string.
    ```c++
    apa::ubint base8("122333444455555666666777777700000000",8);
    // base 10 equivalent = 52245490915446306574707453853696
    ```
- from a base10 (decimal) number represented by a string.
    ```c++
    apa::ubint base8("1192098127666217730001983712379812737234",10);
    ```

- from a base16 (hex) number represented by a string.
    ```c++
    apa::ubint base8("deed0feed0dead0beef0fac0bae",16);
    // base10 equivalent = 282592308594525234095480996891566
    ```

- initializing with specific limb values
    ```c++
    apa::ubint num = { 0xfeed, 0xdead, 0xbeef };
    ```
    The values ```0xfeed```, ```0xdead``` and ```0xbeef``` values will be assigned to each limbs of the ```ubint``` instance.

    Each element in the initializer list can only hold a max value of the base size (depending on the base size you choose during compilation).
    - base2<sup>16</sup> max value = ```0xffff```
    - base2<sup>32</sup> max value = ```0xffffffff```
    - base2<sup>64</sup> max value = ```0xffffffffffffffff```

### Supported Operators of ```apa::ubint```
- Arithmetic Operators ; ```+```, ```-```, ```*```, ```/```, ```%```, ```+=```, ```-=```, ```*=```, ```/=```, ```%=```.
- Relational Operators ; ```<```, ```>```, ```==```, ```<=```, ```>=```, ```!=```.
- Logical Operators ; ```!```, ```&&```, ```||```.
- Bitwise Logical Operators ; ```~```, ```|```, ```&```, ```^```, ```|=```, ```&=```, ```^=```.
- Bitwise Shifts ; ```<<```, ```>>```, ```<<=```, ```>>=``` (only takes argument of ```size_t```).

### Other Methods.
- ```apa::swap(ubint&,ubint&)``` - **[apa namespace function]** swap values of to ```ubint``` class.
- ```.printHex()``` - **[ubint public method]** prints the value of ```ubint``` in hex format.
- ```.to_base10_string()``` - **[ubint public method]** returns a string that represents the value of ```ubint``` in base 10 (decimal).

### Compiling with the static library and ```#include <ubint.hpp>``` header.
- (not implemented yet)

### Compiling with the ```#include "ubint.hpp"``` header.
- To use the ```ubint``` class just include the header ```ubint.hpp``` to your main source code then use the namespace ```apa``` to access the ```ubint``` class like in the example above.
- Choose a base during compilation with the following flags.
    - ```-D_BASE2_16``` - (slowest)
    - ```-D_BASE2_32```
    - ```-D_BASE2_64``` - (fastest) might not be supported to some x86 or 32-bit computers.
    
        example: **```g++ main.cpp -o main.exe -D_BASE2_32 -O2```**

### Limitations of ```ubint```.
- **unsigned big integers** or ```ubint``` for short have the following limitations
    - subtracting a larger ```ubint``` value from a smaller ```ubint```, or subtractions that will result to negative values is not possible (use ```bint``` for this case).
    - right shifting a ```ubint``` with a value greater than it's current bit count is not supported.

# bint - signed big integers
- Not Yet Available in version 4.

# bfloat - big floating point numbers
- Not Yet Available in version 4.
