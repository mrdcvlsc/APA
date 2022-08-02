# Basic Arithmetic

Average performance (nanoseconds)

### Using base 2<sup>16</sup> number system representation.

- a limb size = 4419
- b limb size = 3099

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 15380 ns |
| sub (a - b) | 15109 ns |
| mul (a * b) | 10587549 ns |
| div (a / b) | 429742784 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(71421) | 304283 μs |
| apa::factorial(6321) | 47585 μs |

### Using base 2<sup>32</sup> number system representation.

- a limb size = 2210
- b limb size = 1550

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 9404 ns |
| sub (a - b) | 8430 ns |
| mul (a * b) | 3411971 ns |
| div (a / b) | 303007096 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(71421) | 186637 μs |
| apa::factorial(6321) | 29460 μs |

### Using base 2<sup>64</sup> number system representation.

- a limb size = 1105
- b limb size = 775

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 9989 ns |
| sub (a - b) | 7232 ns |
| mul (a * b) | 1941847 ns |
| div (a / b) | 357658909 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(71421) | 187595 μs |
| apa::factorial(6321) | 25904 μs |


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
NUMA node(s):                    1
NUMA node0 CPU(s):               0-3
Vulnerability Itlb multihit:     Not affected
Vulnerability L1tf:              Not affected
Vulnerability Mds:               Mitigation; Clear CPU buffers; SMT disabled
Vulnerability Meltdown:          Mitigation; PTI
Vulnerability Mmio stale data:   Not affected
Vulnerability Spec store bypass: Not affected
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, IBPB conditional, IBRS_FW, STIBP disabled, RSB filling
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
```
