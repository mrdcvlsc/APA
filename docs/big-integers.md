## **Big Integers**

### **Headers**

- **Header Mode :** `include "APA/core.hpp"`

- **Static Lib :** `include <APA/bint.hpp>`

-----

<br>

### **Namespace**

- **`apa::bint`**

-----

<br>

### **Initializing from an integral type**.

```c++
apa::bint num1 = 255;
apa::bint num2 = -128;
// base 10 equivalent = 255 and -128
```

-----

<br>

### **Initializing from a base2 (binary) number represented by a string**.

Binary formatter **`0b`**

```c++
apa::bint num1 = "0b11001001110100111110100010101";
apa::bint num2 = "-0b11001001110100111110100010101";
// base 10 equivalent = 423263509 and -423263509
```

-----

<br>

### **Initializing from a base8 (octal) number represented by a string**.

Octal formatter **`0o`**

```c++
apa::bint num1 = "0o122333444455555666666777777700000000";
apa::bint num2 = "-0o122333444455555666666777777700000000";
// base 10 equivalent
// num1 =  52245490915446306574707453853696
// num2 = -52245490915446306574707453853696
```

-----

<br>

### **Initializing from a base10 (decimal) number represented by a string**.

Decimal numbers don't need a formatter.

```c++
apa::bint num1 = "1192098127666217730001983712379812737234";
apa::bint num2 = "-1192098127666217730001983712379812737234";
// base10 equivalent
// num1 =  1192098127666217730001983712379812737234
// num2 = -1192098127666217730001983712379812737234
```

-----

<br>

### **Initializing from a base16 (hex) number represented by a string**.

Hex formatter **`0x`**

```c++
apa::bint num1 = "0xdeed0feed0dead0beef0fac0bae";
apa::bint num2 = "-0xdeed0feed0dead0beef0fac0bae";
// base10 equivalent
// num1 =  282592308594525234095480996891566
// num2 = -282592308594525234095480996891566
```

-----

<br>

### **Initializing with specific limb values**.
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

<br>

### **Supported Operators of `apa::bint`**.

| Labels                             | Operators                                             |
| ---------------------------------- | ----------------------------------------------------- |
| Negation                           | `-`                                                   |
| Arithmetic                         | `+`, `-`, `*`, `/`, `%`, `+=`, `-=`, `*=`, `/=`, `%=` |
| Increment                          | `++`  (Post-Fix and Pre-Fix)                          |
| Decrement                          | `--`  (Post-Fix and Pre-Fix)                          |
| Relational                         | `<`, `>`, `==`, `<=`, `>=`, `!=`                      |
| Logical                            | `!`, `&&`, `\|\|`                                     |
| Bitwise Logical                    | `~`, `&`, `^`, `\|=`, `&=`, `^=`                      |
| Bitwise Shifts (for `size_t` only) | `<<`, `>>`, `<<=`, `>>=`                              |
| Standard I/O (std cin and cout)    | `<<`, `>>` (only accepts and output hex format)       |

-----

<br>

### **`bint` methods**.
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

-----

<br>

Available using the header:

```c++
// for static library users only.
#include <APA/math.hpp>
```

If you are **not** using the static library and just compiling
directly using the core header file: `#include "APA/core.hpp"`,
there is **no need** to include the `math.hpp` header.

### **`apa` namespace functions**.
- `swap(bint& a, bint& b)` - swap values of two `bint` class.
- `factorial(size_t n)` - returns `bint` factorial
- `fibonacci(size_t nth)` - returns `bint` Fibonacci
- `power(const bint& base, const bint& exponent)` - returns `bint` power

-----

[**Go Back to Docs**](./docs.md)
