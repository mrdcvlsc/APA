# Basic Arithmetic

Average performance (nanoseconds)

### Using base 2<sup>16</sup> number system representation.

- a limb size = 5763
- b limb size = 4339

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 14541 ns |
| sub (a - b) | 18087 ns |
| mul (a * b) | 14430608 ns |
| div (a / b) | 366314000 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 554547 μs |
| apa::factorial(8000) | 73850 μs |

### Using base 2<sup>32</sup> number system representation.

- a limb size = 2882
- b limb size = 2170

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 11568 ns |
| sub (a - b) | 9466 ns |
| mul (a * b) | 4828544 ns |
| div (a / b) | 235261166 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 375648 μs |
| apa::factorial(8000) | 43668 μs |

### Using base 2<sup>64</sup> number system representation.

- a limb size = 1441
- b limb size = 1085

**basic arithmetic average**

| cases | nanoseconds |
| ----- | ----------- |
| add (a + b) | 8879 ns |
| sub (a - b) | 8121 ns |
| mul (a * b) | 2894404 ns |
| div (a / b) | 277561417 ns |

**functions**

| name | microseconds |
| ---- | ------------ |
| apa::fibonacci(100000) | 341971 μs |
| apa::factorial(8000) | 38592 μs |


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
Vulnerability Retbleed:          Not affected
Vulnerability Spec store bypass: Not affected
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, IBPB conditional, IBRS_FW, STIBP disabled, RSB filling
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
```
