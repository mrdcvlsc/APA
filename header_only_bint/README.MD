### This is ```bint```'s header only version

  - this version is much more dynamic and is expected to work on a wider types of system than it's previous version
  - this has a much more optimized long division algorithm
  - the code is also restructured, renamed some variables and fuctions, and the bint class is enclosed inside the ```arb``` namespace
  - the assignment of ```std::string``` &/or ```const char*``` values to ```bint``` variables is dropped, example the expression  ```bint a = "78782323;"``` will no longer work,... this type of expression will now only work for integral types ```int```, ```long``` and ```long long```, example: ```bint a = 78278323ll;``` is a valid expression. To initialize a ```bint``` from ```std::string``` or ```const char*``` you need to use the bint constructor instead, example: ```bint a("78782323");```
  - apart from those changes all functionalities are still the same

### to use just ```include "bint.hpp"``` to your program then compile it, use the ```arb::bint``` class for big integers

test are still ongoing
