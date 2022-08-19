## **Compilation**

### **Compiling with Header only**.

- If you don't want to build the library using ```makefiles``` you can directly
include the core header instead, then compile right away with your main program.

    ```c++
    #include "APA/core.hpp"
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

-----

<br>

### **Compiling and Using the Static Library**.

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

- If you are compiling the static library with **MinGW** on Windows, you need to
specify where the **MinGW** folder is located in the ```INSTALL_PREFIX```; e.g.
    ```bash
    make -f static install INSTALL_PREFIX=C:/User/Downloads/mingw
    ```

    If you are using **mingw64** you might want to replace ```make``` with
    ```mingw32-make``` in the command.

- To uninstall library in your system just do a
    ```bash
    sudo make -f static uninstall
    ```

    For windows uninstallation you also need to specify the path of **MinGW** using
    ```INSTALL_PREFIX``` like how you installed it but by using uninstall command.

- If you installed the library after building it then you can just use it right away
by including the headers.
    ```c++
    // main.cpp
    #include <iostream>
    #include <APA/bint.hpp>
    #include <APA/math.hpp>
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
- If you did not install it, you need to link the **build/include** and **build/lib**
directory during compilation.
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

-----

[**Go Back to Docs**](./docs.md)