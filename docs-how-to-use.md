# ubint - unsigned big integers

### Initializing ```ubint``` numbers
- from a base2 (binary) number represented by a string.
    ```c++
    apa::ubint base2_bin("11001001110100111110100010101",2);
    // base 10 equivalent = 423263509
    ```
- from a base8 (octal) number represented by a string.
    ```c++
    apa::ubint base8_oct("122333444455555666666777777700000000",8);
    // base 10 equivalent = 52245490915446306574707453853696
    ```
- from a base10 (decimal) number represented by a string.
    ```c++
    apa::ubint base10_dec("1192098127666217730001983712379812737234",10);
    ```

- from a base16 (hex) number represented by a string.
    ```c++
    apa::ubint base16_hex("deed0feed0dead0beef0fac0bae",16);
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
- ```apa::swap(ubint&,ubint&)``` - **[apa namespace function]** swap values of two ```ubint``` class.
- ```.printHex()``` - **[ubint public method]** prints the value of ```ubint``` in hex format.
- ```.to_base10_string()``` - **[ubint public method]** returns a string that represents the value of ```ubint``` in base 10 (decimal).
- ```.to_base16_string()``` - **[ubint public method]** returns a string that represents the value of ```ubint``` in base 16 (hex).

### Compiling with header only.
- If you don't want to build the library using ```makefiles``` you can directly include the core header instead.
    ```c++
    #include "core.hpp"
    ```
- You can choose a base during compilation with the following flags.
    - ```-D_FORCE_BASE2_16``` - (slowest)
    - ```-D_FORCE_BASE2_32```
    - ```-D_FORCE_BASE2_64``` - (fastest) might not be supported to some x86 or 32-bit computers.
    
    example: 
    ```bash
    g++ main.cpp -o main.exe -D_FORCE_BASE2_32 -O2
    ```

    By default if a ```-D_FORCE_BASE2_XX``` flag is not specified, the code will auto decide the best available value for you.
    
### Compiling with the static library and ```#include <ubint.hpp>``` header.
- To build the library run the following command
    ```bash
    make -f static
    ```
- To install it in your system use the command.
    ```bash
    sudo make -f install
    ```

- If you are compiling the static library with **mingw** on windows, you need to specify where the **mingw** folder is located in the ```INSTALL_PREFIX``` during the install command. eg.
    ```bash
    make -f static install INSTALL_PREFIX=C:/User/Downloads/mingw
    ```

    If you are using **mingw64** you might want to replace ```make``` with ```mingw32-make``` in the command.

- To uninstall library in your system just do a
    ```bash
    sudo make -f uninstall
    ```

    For windows you also need to specify the path of **mingw** using ```INSTALL_PREFIX``` like how you installed it but with the uninstall command.

- If you installed the library after building it then you can just use it right away by including the proper header.
    ```c++
    // main.cpp
    #include <iostream>
    #include <ubint.hpp>
    int main() {
        apa::ubint num("8800918289723498",10);
        // ...
    }
    ```
    Then compile it with:
    ```
    g++ main.cpp -o main.exe -lapa -O2
    ```
- If you did not installed it you need to link the **build/include** and **build/lib** folder during compilation.
    ```
    g++ main.cpp -o main.exe -I"PATH/APA/build/include" -L"PATH/APA/build/lib" -lapa -O2
    ```

### Limitations of ```ubint```.
- **unsigned big integers** or ```ubint``` for short have the following limitations
    - subtracting a larger ```ubint``` value from a smaller ```ubint```, or subtractions that will result to negative values is not possible (use ```bint``` for this case).
    - right shifting a ```ubint``` with a value greater than it's current bit count is not supported.

# bint - signed big integers
- Not Yet Available in version 4.

# bfloat - big floating point numbers
- Not Yet Available in version 4.
