# APA - Arbitrary Precision Arithmetic

**Visit branch [version3.9](https://github.com/mrdcvlsc/APA/tree/version_3.9) for the latest previous working version.**

A c++ library for big integer and big number computation in general (arbitrary-precision arithmetic).

# Version 4 [A WORK IN PROGRESS]

How to use? see : [version 4 - docs](docs-how-to-use.md)

This branch **version 4** is an ongoing rewrite of the whole library.

This version will address the problems in the previous versions.

- This version will be able to use a larger number base to further increase the performance... either base **2<sup>16</sup>**, **2<sup>32</sup>** or **2<sup>64</sup>** for each digit limbs (the user can choose one of the three bases during compilation), the older versions (2-3) only used number base of **10<sup>8</sup>** which is faster than the very first version. version 1 uses a ```string``` of base 10 character digits to implement big numbers which is very slow.
- The total size of each limbs is doubled by it's base size, so for bases **2<sup>16</sup>**, **2<sup>32</sup>** and **2<sup>64</sup>**, their limb would be **```uint32_t```**, **```uint64_t```**, and **```__uint128_t```**. (This would also mean that using **base 2<sup>64</sup>** on 32-bit computers is not supported).
- More effecient memory reallocation for ```--```, ```++```, ```+=``` and ```-=``` operators, kinda how ```std::vector```'s work when adding an element, wherin it implements a ```capacity()``` and ```size()``` and only reallocation the ```size()``` when the ```capacity()``` is reached.
- Due to using a base that is a power of **2**, the implementation of bitwise and bitwise logical operators will be much easier.

<!-- ![build](https://github.com/mrdcvlsc/uint320/actions/workflows/build.yml/badge.svg) -->
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

**mini-tests:**

![gcc-gnu](https://github.com/mrdcvlsc/APA/actions/workflows/gcc-gnu.yml/badge.svg)
![clang](https://github.com/mrdcvlsc/APA/actions/workflows/clang.yml/badge.svg)
![mingw32](https://github.com/mrdcvlsc/APA/actions/workflows/mingw64.yml/badge.svg)

-----

# Environment Requirements
- little endian system

If your system does not have these requirements, it might produce wrong results.

-----

# Description

This is a C++ Arbitrary Precision Arithmetic library used to compute big integers & big floating point numbers, used on big numbers (bignum) that usually cannot fit in the standard C++ primitive data types.

**user defined data types/classes**

- ```apa::ubint``` dynamically big unsigned integers (all implementations here a naive).
- ```apa::bint``` dynamically big signed integers (uses ```ubint``` inside, and will also use faster algorithms like karatsuba).
- ```apa::bfloat``` dynamically big floating point (real) numbers, will use ```bint``` inside.

The sizes of these data types are dynamic, meaning they are not fix and they can grow in size. There is no max value or range for these data types, and the only limit is the available memory of the device.

-----

**About**

This repository started as a personal hobby project not intended to replace big number libraries like [boost multiprecision](https://www.boost.org/doc/libs/1_72_0/libs/multiprecision/doc/html/index.html) and [gmplib](https://gmplib.org/) and is only for didactic purposes. Though performance is still a priority, meaning this library will... as much as possible, use the fastest and the most effecient algorithms and implementations THAT THE AUTHOR(s) KNOW OF.
