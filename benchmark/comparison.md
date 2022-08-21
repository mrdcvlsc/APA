## **APA performance comparison with other popular lightweight C++ big intger libraries in Github**

Compiler : **g++**


apa::bint limb base = 2<sup>64</sup>

## **Factorial of (400) - Average (less is better)**

| Library | Nanoseconds |
| ------- | ----------- |
| [boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision) | 59721 ns |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 167070 ns |
| [InfInt](https://github.com/sercantutar/infint) | 603272 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 5057080 ns |
| [BigInt](https://github.com/faheel/BigInt) | 741302270 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 23279299791 ns |

## **fibonacci of (300) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision) | 32931 ns |
| [InfInt](https://github.com/sercantutar/infint) | 112260 ns |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 128875 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 574628 ns |
| [BigInt](https://github.com/faheel/BigInt) | 1523110 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 2972637 ns |

## **fibonacci of (6000) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision) | 1170454 ns |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 4569290 ns |
| [InfInt](https://github.com/sercantutar/infint) | 8754668 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 81369147 ns |
| [BigInt](https://github.com/faheel/BigInt) | 733176815 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 901492574 ns |

## Division : **fac(1537) / fib(713) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision) | 226767 ns |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 1614394 ns |
| [InfInt](https://github.com/sercantutar/infint) | 7160843 ns |
| [BigInt](https://github.com/faheel/BigInt) | 646576466 ns |

- **[BigNumber](https://github.com/Limeoats/BigNumber)** - not included, division is taking too long
- **[BhimInteger](https://github.com/kothariji/BhimIntegers)** - not included, producing zero quotients


## System Runner

```
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Address sizes:                   36 bits physical, 48 bits virtual
Byte Order:                      Little Endian
CPU(s):                          4
On-line CPU(s) list:             0-3
Vendor ID:                       GenuineIntel
Model name:                      Intel(R) Pentium(R) CPU  N3700  @ 1.60GHz
CPU family:                      6
Model:                           76
Thread(s) per core:              1
Core(s) per socket:              4
Socket(s):                       1
Stepping:                        3
CPU max MHz:                     2400.0000
CPU min MHz:                     480.0000
BogoMIPS:                        3200.00
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx rdtscp lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology tsc_reliable nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx est tm2 ssse3 cx16 xtpr pdcm sse4_1 sse4_2 movbe popcnt tsc_deadline_timer aes rdrand lahf_lm 3dnowprefetch epb pti ibrs ibpb stibp tpr_shadow vnmi flexpriority ept vpid tsc_adjust smep erms dtherm ida arat md_clear
Virtualization:                  VT-x
L1d cache:                       96 KiB (4 instances)
L1i cache:                       128 KiB (4 instances)
L2 cache:                        2 MiB (2 instances)
```
