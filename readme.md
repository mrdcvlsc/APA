# APA : *Arbitrary Precision Arithmetic*

[![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://opensource.org/licenses/MIT)
![build](https://github.com/mrdcvlsc/APA/actions/workflows/build.yml/badge.svg)
![gcc-gnu](https://github.com/mrdcvlsc/APA/actions/workflows/gcc-gnu.yml/badge.svg)
![clang](https://github.com/mrdcvlsc/APA/actions/workflows/clang.yml/badge.svg)
![mingw32](https://github.com/mrdcvlsc/APA/actions/workflows/mingw64.yml/badge.svg)

A c++ library for big integers and big number computation.

**Version 4 Status : [WIP - Work In Progress]**

This branch (**version 4**) is an ongoing rewrite of the whole library.

**Visit branch [version3.9](https://github.com/mrdcvlsc/APA/tree/version_3.9) 
for the latest previous working version.**

-----

### **Documentation**

- [**docs.md**](docs.md) - learn how to use the library.

- [**quick-tutorial**](quick-tutorial.md) - learn how this library works internally.

-----

### **Environment Requirements**

|                  |                  |
| ---------------- | ---------------- |
| **Byte Order**   | little-endian    |
| **OS**           | Windows, Linux   |
| **Architecture** | x86, x86, x86-86 |

If your system does not have these requirements, it **might** produce wrong
results (on other system it this could still work, the chances of the tests
failing will be higher).

-----

### **Description**

This is a mini C++ Arbitrary Precision Arithmetic library. Used to compute
big integers & big floating point numbers. If you need to compute numbers that
is greater than the max value of `unsigned long long int`, `uint64_t` or
`__uint128_t` this library can do it for you.

-----

### **About**

This repository started as a personal hobby project **not intended** to
replace big number libraries like [boost multiprecision](https://www.boost.org/)
and [gmplib](https://gmplib.org/) and is **only for didactic purposes**.
Though performance is still a priority, meaning this library will... as much
as possible, use the fastest and the most efficient algorithms and
implementations THAT THE AUTHOR(s) KNOW OF.
