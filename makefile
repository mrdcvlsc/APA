CC= g++

CFLAGSBINT= -I ./bint/include -c
SRCBINT= ./bint/src/
OUTBINT= ./bint/obj/

CFLAGSBNUM= -I ./bnum/include -c
SRCBNUM= ./bnum/src/
OUTBNUM= ./bnum/obj/

PRO= -static-libgcc -static-libstdc++
DEV= -Wall -Wextra -Wshadow -Wpedantic
OFLAG= -O3

win:
	make bintlib
	make bnumlib
	mkdir bignum_win
	copy ./bint/lib/bint.lib ./bignum_win
	copy ./bnum/lib/bnum.lib ./bignum_win
	copy ./bint/include/bint.hpp ./bignum_win
	copy ./bnum/include/bnum.hpp ./bignum_win
	copy ./bint/include/arr_num_arithmetic.hpp ./bignum_win
	copy ./bnum/include/arr_num_arithmetic.hpp ./bignum_win

lin:
	make bintlib
	make bnumlib
	mkdir bignum_lin
	cp ./bint/lib/bint.lib ./bignum_lin
	cp ./bnum/lib/bnum.lib ./bignum_lin
	cp ./bint/include/bint.hpp ./bignum_lin
	cp ./bnum/include/bnum.hpp ./bignum_lin
	cp ./bint/include/arr_num_arithmetic.hpp ./bignum_lin
	cp ./bnum/include/arr_num_arithmetic.hpp ./bignum_lin

bintlib: $(OUTBINT)arithmetic_operators.o $(OUTBINT)comparison.o $(OUTBINT)constructors.o $(OUTBINT)integer_arithmetic.o $(OUTBINT)iostream.o $(OUTBINT)string_manip.o $(OUTBINT)sets.o
	@echo "compiling static library : bint.lib"
	@ar rvs lib/bint.lib $(OUTBINT)*.o

$(OUTBINT)arithmetic_operators.o :$(SRCBINT)arithmetic_operators.cpp
	@echo "compiling source code to obj files ... 1/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)arithmetic_operators.cpp -o obj/arithmetic_operators.o $(OFLAG)

$(OUTBINT)comparison.o :$(SRCBINT)comparison.cpp
	@echo "compiling source code to obj files ... 2/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)comparison.cpp -o obj/comparison.o $(OFLAG)

$(OUTBINT)constructors.o :$(SRCBINT)constructors.cpp
	@echo "compiling source code to obj files ... 3/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)constructors.cpp -o obj/constructors.o $(OFLAG)

$(OUTBINT)integer_arithmetic.o :$(SRCBINT)integer_arithmetic.cpp
	@echo "compiling source code to obj files ... 4/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)integer_arithmetic.cpp -o obj/integer_arithmetic.o $(OFLAG)

$(OUTBINT)iostream.o :$(SRCBINT)iostream.cpp
	@echo "compiling source code to obj files ... 5/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)iostream.cpp -o obj/iostream.o $(OFLAG)

$(OUTBINT)string_manip.o :$(SRCBINT)string_manip.cpp
	@echo "compiling source code to obj files ... 6/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)string_manip.cpp -o obj/string_manip.o $(OFLAG)

$(OUTBINT)sets.o :$(SRCBINT)sets.cpp
	@echo "compiling source code to obj files ... 7/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)sets.cpp -o obj/sets.o $(OFLAG)


bnumlib: $(OUTBNUM)arithmetic_operators.o $(OUTBNUM)comparison.o $(OUTBNUM)constructors.o $(OUTBNUM)integer_arithmetic.o $(OUTBNUM)iostream.o $(OUTBNUM)string_manip.o $(OUTBNUM)sets.o
	@echo "compiling static library : bint.lib"
	@ar rvs lib/bint.lib $(OUTBNUM)*.o

$(OUTBNUM)arithmetic_operators.o :$(SRCBNUM)arithmetic_operators.cpp
	@echo "compiling source code to obj files ... 1/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)arithmetic_operators.cpp -o obj/arithmetic_operators.o $(OFLAG)

$(OUTBNUM)comparison.o :$(SRCBNUM)comparison.cpp
	@echo "compiling source code to obj files ... 2/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)comparison.cpp -o obj/comparison.o $(OFLAG)

$(OUTBNUM)constructors.o :$(SRCBNUM)constructors.cpp
	@echo "compiling source code to obj files ... 3/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)constructors.cpp -o obj/constructors.o $(OFLAG)

$(OUTBNUM)integer_arithmetic.o :$(SRCBNUM)integer_arithmetic.cpp
	@echo "compiling source code to obj files ... 4/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)integer_arithmetic.cpp -o obj/integer_arithmetic.o $(OFLAG)

$(OUTBNUM)iostream.o :$(SRCBNUM)iostream.cpp
	@echo "compiling source code to obj files ... 5/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)iostream.cpp -o obj/iostream.o $(OFLAG)

$(OUTBNUM)string_manip.o :$(SRCBNUM)string_manip.cpp
	@echo "compiling source code to obj files ... 6/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)string_manip.cpp -o obj/string_manip.o $(OFLAG)

$(OUTBNUM)sets.o :$(SRCBNUM)sets.cpp
	@echo "compiling source code to obj files ... 7/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)sets.cpp -o obj/sets.o $(OFLAG)