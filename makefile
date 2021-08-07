CC= g++

CFLAGSBINT= -I ./bint/include -c
SRCBINT= ./bint/src/
OUTBINT= ./bint/obj/

CFLAGSBNUM= -I ./bnum/include -c
SRCBNUM= ./bnum/src/
OUTBNUM= ./bnum/obj/

PRO= -static-libgcc -static-libstdc++
DEV= -Wall -Wextra -Wshadow -Wpedantic
OFLAG= -O3 -march=native

win:
	@echo "building for windows..."
	@echo "building bint library..."
	@make bintlib
	@echo "building bnum library..."
	@make bnumlib
	@echo "creating bignum library..."
	@mkdir bignum_win
	@mkdir bignum_win/include
	@mkdir bignum_win/lib
	@echo "moving files... 0/6"
	@cp "factorial.cpp" "bignum_win\factorial.cpp"
	@echo "moving files... 1/6"
	@cp "bint\lib\libbint.a" "bignum_win\lib\libbint.a"
	@echo "moving files... 2/6"
	@cp "bnum\lib\libbnum.a" "bignum_win\lib\libbnum.a"
	@echo "moving files... 3/6"
	@cp "bint\include\bint.hpp" "bignum_win\include\bint.hpp"
	@echo "moving files... 4/6"
	@cp "bnum\include\bnum.hpp" "bignum_win\include\bnum.hpp"
	@echo "moving files... 5/6"
	@cp "bint\include\arr_num_arithmetic.hpp" "bignum_win\include\arr_num_arithmetic.hpp"
	@echo "moving files... 6/6"
	@cp "bnum\include\arr_num_arithmetic.hpp" "bignum_win\include\arr_num_arithmetic.hpp"
	@echo "release build for windows done..."

lin:
	@echo "building for windows..."
	@echo "building bint library..."
	@make bintlib
	@echo "building bnum library..."
	@make bnumlib
	@echo "creating bignum library..."
	@mkdir bignum_lin
	@mkdir bignum_lin/include
	@mkdir bignum_lin/lib
	@echo "moving files... 0/6"
	@cp ./factorial.cpp ./bignum_lin
	@echo "moving files... 1/6"
	@cp ./bint/lib/libbint.a ./bignum_lin/lib
	@echo "moving files... 2/6"
	@cp ./bnum/lib/libbnum.a ./bignum_lin/lib
	@echo "moving files... 3/6"
	@cp ./bint/include/bint.hpp ./bignum_lin/include
	@echo "moving files... 4/6"
	@cp ./bnum/include/bnum.hpp ./bignum_lin/include
	@echo "moving files... 5/6"
	@cp ./bint/include/arr_num_arithmetic.hpp ./bignum_lin/include
	@echo "moving files... 6/6"
	@cp ./bnum/include/arr_num_arithmetic.hpp ./bignum_lin/include
	@echo "release build for linux done..."

bintlib: $(OUTBINT)arithmetic_operators.o $(OUTBINT)comparison.o $(OUTBINT)constructors.o $(OUTBINT)integer_arithmetic.o $(OUTBINT)iostream.o $(OUTBINT)string_manip.o $(OUTBINT)sets.o
	@echo "compiling static library : libbint.a"
	@ar rvs bint/lib/libbint.a $(OUTBINT)*.o

$(OUTBINT)arithmetic_operators.o :$(SRCBINT)arithmetic_operators.cpp
	@echo "compiling source code to obj files ... 1/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)arithmetic_operators.cpp -o bint/obj/arithmetic_operators.o $(OFLAG)

$(OUTBINT)comparison.o :$(SRCBINT)comparison.cpp
	@echo "compiling source code to obj files ... 2/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)comparison.cpp -o bint/obj/comparison.o $(OFLAG)

$(OUTBINT)constructors.o :$(SRCBINT)constructors.cpp
	@echo "compiling source code to obj files ... 3/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)constructors.cpp -o bint/obj/constructors.o $(OFLAG)

$(OUTBINT)integer_arithmetic.o :$(SRCBINT)integer_arithmetic.cpp
	@echo "compiling source code to obj files ... 4/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)integer_arithmetic.cpp -o bint/obj/integer_arithmetic.o $(OFLAG)

$(OUTBINT)iostream.o :$(SRCBINT)iostream.cpp
	@echo "compiling source code to obj files ... 5/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)iostream.cpp -o bint/obj/iostream.o $(OFLAG)

$(OUTBINT)string_manip.o :$(SRCBINT)string_manip.cpp
	@echo "compiling source code to obj files ... 6/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)string_manip.cpp -o bint/obj/string_manip.o $(OFLAG)

$(OUTBINT)sets.o :$(SRCBINT)sets.cpp
	@echo "compiling source code to obj files ... 7/7"
	@$(CC) $(CFLAGSBINT) $(SRCBINT)sets.cpp -o bint/obj/sets.o $(OFLAG)


bnumlib: $(OUTBNUM)arithmetic_operators.o $(OUTBNUM)comparison.o $(OUTBNUM)constructors.o $(OUTBNUM)integer_arithmetic.o $(OUTBNUM)iostream.o $(OUTBNUM)string_manip.o $(OUTBNUM)sets.o
	@echo "compiling static library : libbnum.a"
	@ar rvs bnum/lib/libbnum.a $(OUTBNUM)*.o

$(OUTBNUM)arithmetic_operators.o :$(SRCBNUM)arithmetic_operators.cpp
	@echo "compiling source code to obj files ... 1/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)arithmetic_operators.cpp -o bnum/obj/arithmetic_operators.o $(OFLAG)

$(OUTBNUM)comparison.o :$(SRCBNUM)comparison.cpp
	@echo "compiling source code to obj files ... 2/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)comparison.cpp -o bnum/obj/comparison.o $(OFLAG)

$(OUTBNUM)constructors.o :$(SRCBNUM)constructors.cpp
	@echo "compiling source code to obj files ... 3/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)constructors.cpp -o bnum/obj/constructors.o $(OFLAG)

$(OUTBNUM)integer_arithmetic.o :$(SRCBNUM)integer_arithmetic.cpp
	@echo "compiling source code to obj files ... 4/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)integer_arithmetic.cpp -o bnum/obj/integer_arithmetic.o $(OFLAG)

$(OUTBNUM)iostream.o :$(SRCBNUM)iostream.cpp
	@echo "compiling source code to obj files ... 5/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)iostream.cpp -o bnum/obj/iostream.o $(OFLAG)

$(OUTBNUM)string_manip.o :$(SRCBNUM)string_manip.cpp
	@echo "compiling source code to obj files ... 6/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)string_manip.cpp -o bnum/obj/string_manip.o $(OFLAG)

$(OUTBNUM)sets.o :$(SRCBNUM)sets.cpp
	@echo "compiling source code to obj files ... 7/7"
	@$(CC) $(CFLAGSBNUM) $(SRCBNUM)sets.cpp -o bnum/obj/sets.o $(OFLAG)