# Basic Arithmetic

Compiler : clang++

Average performance (nanoseconds)

### Using base 2<sup>16</sup> number system representation.

- a limb size = 5763
- b limb size = 4339

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 12283 ns |
| sub (a - b) | 13182 ns |
| mul (a * b) | 11518904 ns |
| div (a / b) | 516012770 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 381786 μs |
| apa::factorial(8000) | 40508 μs |

### Using base 2<sup>32</sup> number system representation.

- a limb size = 2882
- b limb size = 2170

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 6103 ns |
| sub (a - b) | 6965 ns |
| mul (a * b) | 4095016 ns |
| div (a / b) | 141583071 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 200316 μs |
| apa::factorial(8000) | 22356 μs |

### Using base 2<sup>64</sup> number system representation.

- a limb size = 1441
- b limb size = 1085

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 4855 ns |
| sub (a - b) | 4964 ns |
| mul (a * b) | 2354460 ns |
| div (a / b) | 132928017 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 144724 μs |
| apa::factorial(8000) | 21992 μs |


### System Runner

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
