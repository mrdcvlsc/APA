
<details><!-- unsigned big integers : start -->

<summary><b>unsigned big integers</b></summary>

-----

- ### Initializing ```ubint``` numbers
    - Initializing from an integral type.
        ```c++
        apa::ubint num = 255;
        // base 10 equivalent = 255
        ```
        Make sure that the integral type value you assign to a ```ubint``` will not exceed it's base size. If you compile ```apa``` with a number base of 2<sup>16</sup> the maximum value you can assign using an integral type is **```65535```**, for base of 2<sup>32</sup> it is **```4294967295```**, and for base 2<sup>64</sup> this will be **```18446744073709551615```**.

    - Initializing from a base2 (binary) number represented by a string.
        ```c++
        apa::ubint base2_bin("11001001110100111110100010101",apa::BIN);
        // base 10 equivalent = 423263509
        ```
    - Initializing from a base8 (octal) number represented by a string.
        ```c++
        apa::ubint base8_oct("122333444455555666666777777700000000",apa::OCT);
        // base 10 equivalent = 52245490915446306574707453853696
        ```
    - Initializing from a base10 (decimal) number represented by a string.
        ```c++
        apa::ubint base10_dec("1192098127666217730001983712379812737234",apa::DEC);
        ```

    - Initializing from a base16 (hex) number represented by a string.
        ```c++
        apa::ubint base16_hex("deed0feed0dead0beef0fac0bae",apa::HEX);
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

-----

- ### Supported Operators of ```apa::ubint```
    - Arithmetic Operators ; ```+```, ```-```, ```*```, ```/```, ```%```, ```+=```, ```-=```, ```*=```, ```/=```, ```%=```.
    - Increment/Decrement Operators; ```++```, ```--``` (Post-Fix and Pre-Fix).
    - Relational Operators ; ```<```, ```>```, ```==```, ```<=```, ```>=```, ```!=```.
    - Logical Operators ; ```!```, ```&&```, ```||```.
    - Bitwise Logical Operators ; ```~```, ```|```, ```&```, ```^```, ```|=```, ```&=```, ```^=```.
    - Bitwise Shifts ; ```<<```, ```>>```, ```<<=```, ```>>=``` (only takes argument of ```size_t```).
    - Standard I/O (console cin and cout) ; ```<<```, ```>>``` (only accepts and output hex format).

- ### Other Methods.
    - ```apa::swap(ubint&,ubint&)``` - **[apa namespace function]** swap values of two ```ubint``` class.
    - ```.printHex()``` - **[ubint public method]** prints the value of ```ubint``` in hex format.
    - ```.to_base10_string()``` - **[ubint public method]** returns a string that represents the value of ```ubint``` in base 10 (decimal).
    - ```.to_base16_string()``` - **[ubint public method]** returns a string that represents the value of ```ubint``` in base 16 (hex).
    - ```.capacity_size()``` - returns the total allocated number of limbs of a ```bint``` variable;
    - ```.limb_size()``` - returns the number of limbs currently used by a ```bint``` variable;
    - ```.byte_size()``` - returns the total number of bytes;
    - ```.bit_size()``` - returns the total number of bits;
    - ```*limb_view()``` - returns a ```const *limb_t``` pointer array;
    - ```*byte_view()``` - returns a ```const *uint8_t``` pointer array;

- ### Limitations of ```ubint```.
    - **unsigned big integers** or ```ubint``` for short have the following limitations
        - subtracting a larger ```ubint``` value from a smaller ```ubint```, or subtractions that will result to negative values is not possible (use ```bint``` for this case).
        - right shifting a ```ubint``` with a value greater than it's current bit count is not supported.

</details><!-- unsigned big integers : end -->

<details><!-- unsigned big integers : start -->

<summary><b>signed big integers</b></summary>

-----

- ### Initializing ```bint``` numbers

    - Initializing from an integral type.
        ```c++
        apa::bint num1 = 255, num2 = -128;
        // base 10 equivalent = 255 and -128
        ```
        Make sure that the integral type value you assign to a ```bint``` will not exceed it's base size. If you compile ```apa``` with a number base of 2<sup>16</sup> the maximum value you can assign using an integral type is **```65535```**, for base of 2<sup>32</sup> it is **```4294967295```**, and for base 2<sup>64</sup> this will be **```18446744073709551615```**.

    - Initializing from a base2 (binary) number represented by a string.
        ```c++
        apa::bint num1( "11001001110100111110100010101",apa::BIN);
        apa::bint num2("-11001001110100111110100010101",apa::BIN);
        // base 10 equivalent = 423263509 and -423263509
        ```
    - Initializing from a base8 (octal) number represented by a string.
        ```c++
        apa::bint num1( "122333444455555666666777777700000000",apa::OCT);
        apa::bint num2("-122333444455555666666777777700000000",apa::OCT);
        // base 10 equivalent
        // num1 =  52245490915446306574707453853696
        // num2 = -52245490915446306574707453853696
        ```
    - Initializing from a base10 (decimal) number represented by a string.
        ```c++
        apa::bint num1( "1192098127666217730001983712379812737234",apa::DEC);
        apa::bint num2("-1192098127666217730001983712379812737234",apa::DEC);
        // base10 equivalent
        // num1 =  1192098127666217730001983712379812737234
        // num2 = -1192098127666217730001983712379812737234
        ```

    - Initializing from a base16 (hex) number represented by a string.
        ```c++
        apa::bint num1( "deed0feed0dead0beef0fac0bae",apa::HEX);
        apa::bint num2("-deed0feed0dead0beef0fac0bae",apa::HEX);
        // base10 equivalent
        // num1 =  282592308594525234095480996891566
        // num2 = -282592308594525234095480996891566
        ```

    - initializing with specific limb values
        ```c++
        apa::bint positive_num({ 0xfeed, 0xdead, 0xbeef },apa::POSITIVE);
        apa::bint negative_num({ 0xfeed, 0xdead, 0xbeef },apa::NEGATIVE);
        ```
        The values ```0xfeed```, ```0xdead``` and ```0xbeef``` values will be assigned to each limbs of the ```bint``` instance.

        Each element in the initializer list can only hold a max value of the base size (depending on the base size you choose during compilation).
        - base2<sup>16</sup> max value = ```0xffff```
        - base2<sup>32</sup> max value = ```0xffffffff```
        - base2<sup>64</sup> max value = ```0xffffffffffffffff```

-----

- ### Supported Operators of ```apa::bint```
    - Negation Operator ; ```-```.
    - Arithmetic Operators ; ```+```, ```-```, ```*```, ```/```, ```%```, ```+=```, ```-=```, ```*=```, ```/=```, ```%=```.
    - Increment/Decrement Operators; ```++```, ```--``` (Post-Fix and Pre-Fix).
    - Relational Operators ; ```<```, ```>```, ```==```, ```<=```, ```>=```, ```!=```.
    - Logical Operators ; ```!```, ```&&```, ```||```.
    - Bitwise Logical Operators ; ```~```, ```|```, ```&```, ```^```, ```|=```, ```&=```, ```^=```.
    - Bitwise Shifts ; ```<<```, ```>>```, ```<<=```, ```>>=``` (only takes argument of ```size_t```).
    - Standard I/O (console cin and cout) ; ```<<```, ```>>``` (only accepts and output hex format).

- ### Other Methods.
    - ```apa::swap(bint&,bint&)``` - **[apa namespace function]** swap values of two ```bint``` class.
    - ```.printHex()``` - **[bint public method]** prints the value of ```bint``` in hex format.
    - ```.to_base10_string()``` - **[bint public method]** returns a string that represents the value of ```bint``` in base 10 (decimal).
    - ```.to_base16_string()``` - **[bint public method]** returns a string that represents the value of ```bint``` in base 16 (hex).
    - ```.capacity_size()``` - **[bint public method]** returns the total allocated number of limbs of a ```bint``` variable;
    - ```.limb_size()``` - **[bint public method]** returns the number of limbs currently used by a ```bint``` variable;
    - ```.byte_size()``` - **[bint public method]** returns the total number of bytes;
    - ```.bit_size()``` - **[bint public method]** returns the total number of bits;
    - ```*limb_view()``` - **[bint public method]** returns a ```const *limb_t``` pointer array;
    - ```*byte_view()``` - **[bint public method]** returns a ```const *uint8_t``` pointer array;

</details><!-- unsigned big integers : end -->

<details><!-- compilation : start -->
<summary><b>compilation</b></summary>

- ### Compiling with header only.
    - If you don't want to build the library using ```makefiles``` you can directly include the core header instead.
        ```c++
        #include "core.hpp"
        ```

    > **Note**
    > - You can choose a base during compilation with the following flags, this is optional.
    >    - ```-D_FORCE_BASE2_16``` = number base 2<sup>16</sup> (slowest)
    >    - ```-D_FORCE_BASE2_32``` = number base 2<sup>32</sup>
    >    - ```-D_FORCE_BASE2_64``` = number base 2<sup>64</sup> (fastest) might not be supported to some x86 or 32-bit computers.
        
    >    example: 
    >    ```bash
    >    g++ main.cpp -o main.exe -D_FORCE_BASE2_32 -O2
    >    ```
    >
    >    By default if a ```-D_FORCE_BASE2_XX``` flag is not specified, the code will auto decide the best available value for you.
    
- ### Compiling with the static library.
    - To build the library run the following command
        ```bash
        make -f static
        ```
    - To install it in your system use the command below. the default path for linux installation is ```/usr/local/```, you can change this by specifiying a path using the ```INSTALL_PREFIX="INSTALLATION_PATH"```.
        ```bash
        sudo make -f static install
        ```

    - If you are compiling the static library with **mingw** on windows, you need to specify where the **mingw** folder is located in the ```INSTALL_PREFIX``` during the install command. eg.
        ```bash
        make -f static install INSTALL_PREFIX=C:/User/Downloads/mingw
        ```

        If you are using **mingw64** you might want to replace ```make``` with ```mingw32-make``` in the command.

    - To uninstall library in your system just do a
        ```bash
        sudo make -f static uninstall
        ```

        For windows uninstallation you also need to specify the path of **mingw** using ```INSTALL_PREFIX``` like how you installed it but with the uninstall command.

    - If you installed the library after building it then you can just use it right away by including the headers.
        ```c++
        // main.cpp
        #include <iostream>
        #include <ubint.hpp>
        #include <bint.hpp>
        int main() {
            apa::ubint num1("8800918289723498",apa::DEC);
            apa::ubint num2("-8800918289723498",apa::DEC);
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

    > **Warning**
    > You cannot use a specific base using the flags ```-D_FORCE_BASE2_XX``` when compiling a program that uses the static library.
</details><!-- compilation : end -->

# bfloat - big floating point numbers
- Not Yet Available in version 4.
