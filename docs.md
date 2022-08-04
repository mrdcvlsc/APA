## **Documentation**

<details><!-- big integers : start -->

<summary><b>Big Integers</b></summary>

-----

## Big Integers - **`bint`**

- **Initializing from an integral type**.
    ```c++
    apa::bint num1 = 255, num2 = -128;
    // base 10 equivalent = 255 and -128
    ```
    Make sure that the integral type value you assign to a ```bint``` will
    not exceed its base size. If you compile ```apa``` with a number base
    of 2<sup>16</sup> the maximum value you can assign using an integral
    type is **```65535```**, for base of 2<sup>32</sup> it is
    **```4294967295```**, and for base 2<sup>64</sup> this will be
    **```18446744073709551615```**.

- **Initializing from a base2 (binary) number represented by a string**.
    ```c++
    apa::bint num1( "11001001110100111110100010101",apa::BIN);
    apa::bint num2("-11001001110100111110100010101",apa::BIN);
    // base 10 equivalent = 423263509 and -423263509
    ```

- **Initializing from a base8 (octal) number represented by a string**.
    ```c++
    apa::bint num1( "122333444455555666666777777700000000",apa::OCT);
    apa::bint num2("-122333444455555666666777777700000000",apa::OCT);
    // base 10 equivalent
    // num1 =  52245490915446306574707453853696
    // num2 = -52245490915446306574707453853696
    ```

- **Initializing from a base10 (decimal) number represented by a string**.
    ```c++
    apa::bint num1( "1192098127666217730001983712379812737234",apa::DEC);
    apa::bint num2("-1192098127666217730001983712379812737234",apa::DEC);
    // base10 equivalent
    // num1 =  1192098127666217730001983712379812737234
    // num2 = -1192098127666217730001983712379812737234
    ```

- **Initializing from a base16 (hex) number represented by a string**.
    ```c++
    apa::bint num1( "deed0feed0dead0beef0fac0bae",apa::HEX);
    apa::bint num2("-deed0feed0dead0beef0fac0bae",apa::HEX);
    // base10 equivalent
    // num1 =  282592308594525234095480996891566
    // num2 = -282592308594525234095480996891566
    ```

- **Initializing with specific limb values**.
    ```c++
    apa::bint positive_num({ 0xfeed, 0xdead, 0xbeef },apa::POSITIVE);
    apa::bint negative_num({ 0xfeed, 0xdead, 0xbeef },apa::NEGATIVE);
    ```
    The values ```0xfeed```, ```0xdead``` and ```0xbeef``` values will be
    assigned to each limb of the ```bint``` instance.

    Each element in the initializer list can only hold a max value of the
    base size (depending on the base size you choose during compilation).
    - Base 2<sup>16</sup> max value = ```0xffff```
    - Base 2<sup>32</sup> max value = ```0xffffffff```
    - Base 2<sup>64</sup> max value = ```0xffffffffffffffff```

-----

- **Supported Operators of `apa::bint`**.
    - Negation Operator `-`
    - Arithmetic Operators `+`, `-`,
    `*`, `/`, `%`, `+=`, `-=`,
    `*=`, `/=`, `%=`
    - Increment/Decrement Operators
    `++`, `--` (Post-Fix and Pre-Fix)
    - Relational Operators
    `<`, `>`, `==`, `<=`, `>=`, `!=`
    - Logical Operators `!`, `&&`, `||`
    - Bitwise Logical Operators `~`, `|`, `&`, `^`,
    `|=`, `&=`, `^=`
    - Bitwise Shifts `<<`, `>>`, `<<=`, `>>=`
    (only takes argument of `size_t`)
    - Standard I/O (console cin and cout) `<<`, `>>`
    (only accepts and output hex format)

- **`bint` methods**.
    - `.printHex()` - prints the value of `bint` in hex format
    - `.to_base10_string()` - returns a string that represents the value of
    `bint` in base 10 (decimal)
    - `.to_base16_string()` - returns a string that represents the value of
    `bint` in base 16 (hex)
    - `.capacity_size()` - returns the total allocated number of limbs of
    a `bint` variable
    - `.limb_size()` - returns the number of limbs currently used by
    a `bint` variable
    - `.byte_size()` - returns the total number of bytes
    - `.bit_size()` - returns the total number of bits
    - `.limb_view()` - returns a `const *limb_t` pointer array
    - `.byte_view()` - returns a `const *uint8_t` pointer array
    - `.detach()` - returns a pointer that points to the `limbs` array of `bint`
    instance, while setting the `limbs` of the `bint` instance to `NULL`

- **`apa` namespace functions**.
    - `swap(bint& a, bint& b)` - swap values of two `bint` class.
    - `factorial(size_t n)` - returns `bint` factorial
    - `fibonacci(size_t nth)` - returns `bint` fibonacci
    - `power(const bint& base, const bint& exponent)` - returns `bint` power

</details><!-- big integers : end -->








<details><!-- big floating point : start -->

<summary><b>Big Real Numbers (floating points)</b></summary>

## Big Real Numbers - **`bfloat`**

- **`bfloat` - big floating point numbers**

    - ***Not Yet Available in version 4.***
    
    - **Visit branch [version3.9](https://github.com/mrdcvlsc/APA/tree/version_3.9)
    for the latest previous working version of `bfloat`.**


</details><!-- big floating point : end -->









<details><!-- compilation : start -->
<summary><b>Compilation</b></summary>

- ### Compiling with **Header only**.

    - If you don't want to build the library using ```makefiles``` you can directly
    include the core header instead, then compile right away with your main program.
    
        ```c++
        #include "core.hpp"
        ```

        > **Note**
        > - You can choose a base during compilation with the following flags, this
        is optional.
        >    - ```-D_FORCE_BASE2_16``` = number base 2<sup>16</sup> (slowest)
        >    - ```-D_FORCE_BASE2_32``` = number base 2<sup>32</sup>
        >    - ```-D_FORCE_BASE2_64``` = number base 2<sup>64</sup> (fastest) might
        not be supported to some x86 or 32-bit computers.
            
        **Example:**

        ```bash
        g++ main.cpp -o main.exe -D_FORCE_BASE2_32 -O2
        ```
    
    By default, if a ```-D_FORCE_BASE2_XX``` flag is not specified, the code will auto
    decide the best available value for you.
    
- ### Compiling the **Static Library**.

    - To build the library run the following command
        ```bash
        make -f static
        ```
    - To install it in your system use the command below. The default path for Linux
    installation is ```/usr/local/```, you can change this by specifying a path using
    the ```INSTALL_PREFIX="INSTALLATION_PATH"```.
        ```bash
        sudo make -f static install
        ```

    - If you are compiling the static library with **mingw** on Windows, you need to
    specify where the **mingw** folder is located in the ```INSTALL_PREFIX```; e.g.
        ```bash
        make -f static install INSTALL_PREFIX=C:/User/Downloads/mingw
        ```

        If you are using **mingw64** you might want to replace ```make``` with
        ```mingw32-make``` in the command.

    - To uninstall library in your system just do a
        ```bash
        sudo make -f static uninstall
        ```

        For windows uninstallation you also need to specify the path of **mingw** using
        ```INSTALL_PREFIX``` like how you installed it but by using uninstall command.

    - If you installed the library after building it then you can just use it right away
    by including the headers.
        ```c++
        // main.cpp
        #include <iostream>
        #include <ubint.hpp>
        #include <bint.hpp>
        int main() {
            apa::ubint num1("8800918289723498",apa::DEC);
            apa::bint  num2("-8800918289723498",apa::DEC);
            // ...
        }
        ```
        Then compile it with:
        ```
        g++ main.cpp -o main.exe -lapa -O2
        ```
    - If you did not installed it you need to link the **build/include** and **build/lib**
    folder during compilation.
        ```
        g++ main.cpp -o main.exe -I"PATH/APA/build/include" -L"PATH/APA/build/lib" -lapa -O2
        ```

    > **Warning**
    >
    > You cannot use a specific base using the flag ```-D_FORCE_BASE2_XX``` when compiling
    > your own program that uses the static library. This is because the static library
    > will auto decide the best available base value during its compilation. So if you
    > define a specific base using the ```D_FORCE_BASE2_XX``` flag, a mismatch
    > might occur throwing an undefined reference or other errors.

</details><!-- compilation : end -->


