# To-do

- [ ] - optimize `bit_division` : instead of shifting the
remainder by one `BASE_BITS` per loop iteration, I think
a much faster performance can be achieved by getting the
padding needed by the `remainder` so that it will be equal
to the `op` divisor right away.

- [ ] - add lcd, gcd, finding prime functions, and more math functions.

- [ ] - add CMake support for the static library.

- [ ] - improve naming conventions being used.

- [ ] - organize the code structure.