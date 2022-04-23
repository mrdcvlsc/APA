# APA - Arbitrary Precision Arithmetic

A c++ library for big number computation (arbitrary-precision arithmetic).

Note: this **version 4** is a complete rewrite from the previous versions.

New approaches:
- using a larger base either **2^16**, **2^32** or **2^64** for the limbs (the user can choose during compilation which of the three bases they want to use), the old versions only use base **10^8**.
- more effecient memory reallocation for ```--```, ```++```, ```+=``` and ```-=``` operators, kinda how ```std::vector```'s work when adding an element, wherin it implements a ```capacity()``` and ```size()``` and only reallocation the ```size()``` when the ```capacity()``` is reached.

<!-- ![build](https://github.com/mrdcvlsc/uint320/actions/workflows/build.yml/badge.svg) -->
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

**mini-tests:**

![gcc-gnu](https://github.com/mrdcvlsc/APA/actions/workflows/gcc-gnu.yml/badge.svg)
![clang](https://github.com/mrdcvlsc/APA/actions/workflows/clang.yml/badge.svg)
![mingw32](https://github.com/mrdcvlsc/APA/actions/workflows/mingw32.yml/badge.svg)

-----

# Environment Requirements
- little endian system

If your system does not have these requirements, it might produce wrong results.

-----

This is a C++ Arbitrary Precision Arithmetic library used to compute big integers & big floating point numbers, used on big numbers (bignum) that usually cannot fit in the standard C++ primitive data types.