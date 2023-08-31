# String Initialization and To Base 10 String

Compiler : clang++

Accumulated performance (nanoseconds)

### Using base 2<sup>16</sup> number system representation.

string's size use to initialize = 5500

| cases | microseconds |
| ----- | ----------- |
| base 2 initialization | 87110 |
| base 8 initialization | 86790 |
| base 10 initialization | 86924 |
| base 16 initialization | 216 |
| to_base10_string() | 66206 |

the to_base10_string() benchmark is from a 1375 limbs size big integer

### Using base 2<sup>32</sup> number system representation.

string's size use to initialize = 5500

| cases | microseconds |
| ----- | ----------- |
| base 2 initialization | 87367 |
| base 8 initialization | 86987 |
| base 10 initialization | 87043 |
| base 16 initialization | 230 |
| to_base10_string() | 54462 |

the to_base10_string() benchmark is from a 688 limbs size big integer

### Using base 2<sup>64</sup> number system representation.

string's size use to initialize = 5500

| cases | microseconds |
| ----- | ----------- |
| base 2 initialization | 86801 |
| base 8 initialization | 86778 |
| base 10 initialization | 86534 |
| base 16 initialization | 230 |
| to_base10_string() | 77640 |

the to_base10_string() benchmark is from a 344 limbs size big integer


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
Vulnerability Mmio stale data:   Unknown: No mitigations
Vulnerability Retbleed:          Not affected
Vulnerability Spec store bypass: Not affected
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, IBPB conditional, IBRS_FW, STIBP disabled, RSB filling, PBRSB-eIBRS Not affected
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
```
