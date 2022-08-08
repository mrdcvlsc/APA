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
apa::bint num1 = 255, num2 = -128;
// base 10 equivalent = 255 and -128
```

Make sure that the integral type value you assign to a ```bint``` will
not exceed its base size. If you compile ```apa``` with a number base
of 2<sup>16</sup> the maximum value you can assign using an integral
type is **```65535```**, for base of 2<sup>32</sup> it is
**```4294967295```**, and for base 2<sup>64</sup> this will be
**```18446744073709551615```**.

-----

<br>

### **Initializing from a base2 (binary) number represented by a string**.

```c++
apa::bint num1( "11001001110100111110100010101",apa::BIN);
apa::bint num2("-11001001110100111110100010101",apa::BIN);
// base 10 equivalent = 423263509 and -423263509
```

-----

<br>

### **Initializing from a base8 (octal) number represented by a string**.
```c++
apa::bint num1( "122333444455555666666777777700000000",apa::OCT);
apa::bint num2("-122333444455555666666777777700000000",apa::OCT);
// base 10 equivalent
// num1 =  52245490915446306574707453853696
// num2 = -52245490915446306574707453853696
```

-----

<br>

### **Initializing from a base10 (decimal) number represented by a string**.
```c++
apa::bint num1( "1192098127666217730001983712379812737234",apa::DEC);
apa::bint num2("-1192098127666217730001983712379812737234",apa::DEC);
// base10 equivalent
// num1 =  1192098127666217730001983712379812737234
// num2 = -1192098127666217730001983712379812737234
```

-----

<br>

### **Initializing from a base16 (hex) number represented by a string**.
```c++
apa::bint num1( "deed0feed0dead0beef0fac0bae",apa::HEX);
apa::bint num2("-deed0feed0dead0beef0fac0bae",apa::HEX);
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
- Negation `-`
- Arithmetic `+`, `-`,
`*`, `/`, `%`, `+=`, `-=`,
`*=`, `/=`, `%=`
- Increment/Decrement
`++`, `--` (Post-Fix and Pre-Fix)
- Relational
`<`, `>`, `==`, `<=`, `>=`, `!=`
- Logical `!`, `&&`, `||`
- Bitwise Logical `~`, `|`, `&`, `^`,
`|=`, `&=`, `^=`
- Bitwise Shifts `<<`, `>>`, `<<=`, `>>=`
(only takes argument of `size_t`)
- Standard I/O (console cin and cout) `<<`, `>>`
(only accepts and output hex format)

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

### **`apa` namespace functions**.
- `swap(bint& a, bint& b)` - swap values of two `bint` class.
- `factorial(size_t n)` - returns `bint` factorial
- `fibonacci(size_t nth)` - returns `bint` fibonacci
- `power(const bint& base, const bint& exponent)` - returns `bint` power
