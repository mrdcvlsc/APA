## **APA performance comparison with other popular lightweight C++ big intger libraries in Github**

Compiler : **g++**


apa::bint limb base = 64

## **Factorial of (400) - Average (less is better)**

| Library | Nanoseconds |
| ------- | ----------- |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 186589 ns |
| [InfInt](https://github.com/sercantutar/infint) | 601894 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 5019699 ns |
| [BigInt](https://github.com/faheel/BigInt) | 732736192 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 23114589776 ns |

## **fibonacci of (300) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [InfInt](https://github.com/sercantutar/infint) | 110392 ns |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 133085 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 575688 ns |
| [BigInt](https://github.com/faheel/BigInt) | 1512735 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 2984087 ns |

## **fibonacci of (6000) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 4641501 ns |
| [InfInt](https://github.com/sercantutar/infint) | 8428139 ns |
| [BhimInteger](https://github.com/kothariji/BhimIntegers) | 81617300 ns |
| [BigInt](https://github.com/faheel/BigInt) | 724869024 ns |
| [BigNumber](https://github.com/Limeoats/BigNumber) | 903456614 ns |

## Division : **fac(1537) / fib(713) - Average (less is better)**


| Library | Nanoseconds |
| ------- | ----------- |
| [apa::bint](https://github.com/mrdcvlsc/APA) | 1700330 ns |
| [InfInt](https://github.com/sercantutar/infint) | 7190028 ns |
| [BigInt](https://github.com/faheel/BigInt) | 651806227 ns |

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
NUMA node(s):                    1
NUMA node0 CPU(s):               0-3
Vulnerability Itlb multihit:     Not affected
Vulnerability L1tf:              Not affected
Vulnerability Mds:               Mitigation; Clear CPU buffers; SMT disabled
Vulnerability Meltdown:          Mitigation; PTI
Vulnerability Mmio stale data:   Not affected
Vulnerability Retbleed:          Not affected
Vulnerability Spec store bypass: Not affected
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, IBPB conditional, IBRS_FW, STIBP disabled, RSB filling
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
```