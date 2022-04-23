# APA - Arbitrary Precision Arithmetic

A c++ library for big number computation (arbitrary-precision arithmetic).

# Version 4

[A WORK IN PROGRESS]

This branch **version 4** is an ongoing rewrite of the whole library.

Visit [version3.9](https://github.com/mrdcvlsc/APA/tree/version_3.9) branch for the latest previous working version and implementation.

This version will address the problems in the previous versions.

- This version will use a larger base either **2^16**, **2^32** or **2^64** for the limbs (the user can choose one of the three bases during compilation), the old versions only use base **10^8**, and the very first version uses a ```string``` of base 10 digits to implement big numbers which is very slow.
- The total size of each limbs is doubled by it's base size, so for bases **2^16**, **2^32** and **2^64**, their limb size would be **2^32**, **2^64**, and **2^128**. (This would also mean that using **base 2^64** on 32-bit computers is not supported).
- more effecient memory reallocation for ```--```, ```++```, ```+=``` and ```-=``` operators, kinda how ```std::vector```'s work when adding an element, wherin it implements a ```capacity()``` and ```size()``` and only reallocation the ```size()``` when the ```capacity()``` is reached.
- due to using a base that is a power of **2**, the implementation of bitwise and bitwise logical operators will be much easier.

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

-----

**About**

This repository started as a personal hobby project not intended to replace big number libraries like [boost multiprecision](https://www.boost.org/doc/libs/1_72_0/libs/multiprecision/doc/html/index.html) and [gmplib](https://gmplib.org/) and is only for didactic purposes. Though performance is still a priority, meaning this library will... as much as possible, use the fastest and the most effecient algorithms and implementations THAT THE AUTHOR(s) KNOW OF.
