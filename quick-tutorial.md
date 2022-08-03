# Quick Tutorial

In this section, I will share my knowledge about big number implementations,
this is not a tutorial for using the library, go to the [docs.md](docs.md)
if that is what you are trying to find.

If you want to know gain a little knowledge about big number
implementations, continue reading this section.

## **Representing Big Numbers**

This library uses a **packed radix** representation to represent big numbers.

To understand how this work, let's look at the basics.

<br>

*Note: In number base systems, `0` is always the minimum digit, but the
maximum digit is computed by subtracting `1` to the base.*

$min = 0 \\
max = base - 1$

### **Using a Base 10 Representation**

The most beginner-friendly way to represent big integers is to use an
array of number or string where each element contains a one-digit number
from **0 to 9**.

This representation is called the **base 10** number system, this is
the number system that we humans always use, here we only operate on
one digit at a time, when adding, subtracting, multiplying and dividing.
Let's implement this in code:

Let's add **1,999 + 23** using a base 10 number system approach.

```c++
const int BASE = 10;
const int LEN = 4;

int A[LEN] = {9, 9, 9, 1}; // 1999
int B[LEN] = {3, 2, 0, 0}; //   23
int C[LEN];

int carry = 0;
for(int i = 0; i < LEN; ++i) {
    int sum = A[i] + B[i] + carry;
    C[i] = sum % BASE;
    carry = sum / BASE;
}

for(int i=0; i<LEN; ++i) {
    std::cout << C[LEN-1-i];
}
```

**Output:** `2022`

Here we used the modulo `%` operator to get the sum of the current index
and the division `/` operator to get the carry.

It is also noticeable that we position each digit of our number in the
arrays on a reverse order, this is just a preference.

Well that's easy, though there is only one problem with this approach,
**IT IS VERY SLOW!!!**, since we are only operating on one digit at a
time, a very big number that have thousands of digits would require a
very large array with the same exact thousands of elements, this will
require more loop iterations, more instructions, resulting to a very
slow running time.

<br>

### **Using a Base that is a power of 10**

How can we solve this slow performance? Well **using a larger base**
would speed up our implementation, most intermediate implementations
would use a larger base that is a power of **10**, let us implement
our previous example using a slightly larger base, let us use **base 100**.

```c++
const int BASE = 100;
const int LEN = 2;

int A[LEN] = {99, 19}; // 1999
int B[LEN] = {23, 0}; //    23
int C[LEN];

int carry = 0;
for(int i = 0; i < LEN; ++i) {
    int sum = A[i] + B[i] + carry;
    C[i] = sum % BASE;
    carry = sum / BASE;
}

for(int i=0; i<LEN; ++i) {
    std::cout << C[LEN-1-i];
}
```
**Output :** `2022`

By using **base 100** which is a power of 10, our implementation would
become faster, since we are operating on 2 more digits per array element.

This would require less space, less loop iterations, and fewer instructions.

You might also realize by now that you can extend to an even larger base to
further speed up the performance, something crazy like **base 1,000,000,000**
where you can perform **one** operation per **9** digits at a **single** time.

<br>

### **Packed Radix Representation**

So far we've been using **bases** that are a power of **10** in our examples,
but we can further optimize the representation of a big number using a packed
radix implementation.

As we can see in our previous examples, ***the higher our base is, the less
element our array would have, meaning less loop iterations, fewer instructions
etc. which can lead to a faster running time of our program***.

In **packed radix implementation** we can further take advantage of this
knowledge and instead of using a base that is a power of 10, we would use a
base that is a **power of 2** instead.

***Why power of 2 you ask?***

Our computer CPU has registers in them, imagine it like a physical variable
where we can store our values. A typical x86 (32-bit) computer will be able
to store at maximum 32 bits inside one of its register.

With higher level languages like C and C++ we don't deal with the registers
on a direct way anymore, these languages provides abstractions, and have given
us data types that can hold certain sizes.

[(*More About Max Values*)](values.md)

If you notice those max values, they are in actually a **(power of 2) - 1**,
this is advantageous for us, meaning we can use a base that is a **power of
2** at maximum.

For example, if we have an array of `uint32_t`, and if we are going to use a
base that is a **power of 10** to represent our big integer, the maximum base
we can use would be **base 1,000,000,000** or (**base 10<sup>9</sup>**), any
higher bases that is a power 10 would not fit in the max value of `uint32_t`
which is **4,294,967,295**.

By using a base that is a **power of 2** we can further increase the base
without getting over the `uint32_t` max value limit, for example the max base
that is a power of 2 that we can use with `uint32_t` is **4,294,967,296** or
**base 2<sup>32</sup>** which is just **+1** higher than the `uint32_t` max
value limit, hence the name **packed radix representation**. We packed the
base tightly, filling up all the bits in the register, and leaving no space
in our data type yet not overflowing.

Usually we aim for bases with the power of 2, this library supports bases
**2<sup>16</sup>**, **2<sup>32</sup>**, **2<sup>64</sup>**.

### **Reduce Radix Representation**

There are other representations that is also significantly faster than base 10
representations, but don't use the whole bits/size of a data type like in packed
radix representations. It is called the reduced radix representation where instead
of aiming for number bases **2<sup>16</sup>**, **2<sup>32</sup>**, **2<sup>64</sup>**,
we choose a somehow near full bases **2<sup>15</sup>**, **2<sup>31</sup>**,
**2<sup>63</sup>**, this representation is beneficial when used in some
cases (see [Poly1305-donna](https://github.com/floodyberry/poly1305-donna), 
[Karatsuba Multiplication](https://eprint.iacr.org/2015/1247.pdf))
and might outperform the **Packed Radix Representations** in other cases
(maybe even in most cases), this is due to the reduction of immediate carries and
casting, or even complete avoidance of using or casting to a larger data type.

This library uses packed radix implementation, not reduced radix.

-----

<br>

### **Multiplication & it's overflow problem**
When multiplying two numbers together you might encounter overflows in you
multiplication algorithm, for example;

- If we use the data type `unsigned short int` or `uint16_t` which can only
hold a max value of **65,535**.
- And a **base 10,000** number system to represent our big integer.

Most of the time (depending on the value of digits) we would get an overflow.

The code below shows the overflow that might happen when multiplying
**999,990,010,001** to **12,345,762**. In this example we are using a
**base 10,000** representation, stored in an array of `uint16_t`.

```c++
const uint16_t BASE = 10000;
const size_t A_LEN = 3;
const size_t B_LEN = 2;
const size_t C_LEN = 3+2;

uint16_t A[A_LEN] = {1, 9001, 9999}; // 999,990,010,001
uint16_t B[B_LEN] = {5762, 1234};    //      12,345,762
uint16_t C[C_LEN] = {0,0,0,0,0};

for(size_t i=0; i<B_LEN; ++i) {
    uint16_t carry = 0;
    for(size_t j=0; j<A_LEN; ++j) {
        uint16_t product = A[j] * B[i] + C[i+j] + carry;
        C[i+j] = product % BASE;
        carry = product / BASE;
    }
    C[i+A_LEN] += carry;
}

for(int i=0; i<C_LEN; ++i) {
    std::cout << C[C_LEN-1-i];
}
```

**Output :** `18001974660205762`

The program above will output **18,001,974,660,205,762** which the wrong
answer, this happens due to the overflow in the `product` and not being able
to pass the carry, for example when multiplying the first index of `A` that
has a value of `9999`, to the first index of `B` that has a value of `1234`,
the exact product would be **12,338,766**, but since we are only using a
`uint_16` for our product where at maximum can only hold **65,535** we got
the incorrect answer.

To solve this problem we simply use a larger data type to hold the `product`
and perform the necessary casting to get the correct answer, this solution
is shown below.

```c++
const uint16_t BASE = 10000;
const size_t A_LEN = 3;
const size_t B_LEN = 2;
const size_t C_LEN = 3+2;

uint16_t A[A_LEN] = {1, 9001, 9999}; // 999,990,010,001
uint16_t B[B_LEN] = {5762, 1234};    //      12,345,762
uint16_t C[C_LEN] = {0,0,0,0,0};

for(size_t i=0; i<B_LEN; ++i) {
    uint16_t carry = 0;
    for(size_t j=0; j<A_LEN; ++j) {
        uint32_t product = (uint32_t) A[j] * B[i] + C[i+j] + carry;
        C[i+j] = product % BASE;
        carry = product / BASE;
    }
    C[i+A_LEN] += carry;
}

for(int i=0; i<C_LEN; ++i) {
    std::cout << C[C_LEN-1-i];
}
```

**Output :** `12345638665849965762`

On the code above we use the larger type `uint32_t` to get each `product`,
this would avoid overflows and carry loss in the multiplication algorithm,
hence getting the correct product **12,345,638,665,849,965,762**.
