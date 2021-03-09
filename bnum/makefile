CC= g++
CFLAGS= -I ./include -c
SRC= ./src/
OUT= ./obj/
PRO= -static-libgcc -static-libstdc++ $(OFLAG)
DEV= -Wall -Wextra -Wshadow -Wpedantic
OFLAG= -O3

direct:
	@echo "direct integration, for faster performance, but slow compilation"
	@g++ -o calculator.exe test/calculator.cpp src/*.cpp -I ./include
	@echo "compilation done."

sample1: $(OUT)arithmetic_operators.o $(OUT)comparison.o $(OUT)constructors.o $(OUT)integer_arithmetic.o $(OUT)iostream.o $(OUT)string_manip.o $(OUT)sets.o
	@echo "compiling static library"
	@ar rvs lib/bnum.lib $(OUT)*.o
	@echo "compiling sample 1 - calculator program"
	@g++ -o test/test.exe test/calculator.cpp lib/bnum.lib -I ./include
	@echo "running program test"
	@./test/test.exe

sample2: $(OUT)arithmetic_operators.o $(OUT)comparison.o $(OUT)constructors.o $(OUT)integer_arithmetic.o $(OUT)iostream.o $(OUT)string_manip.o $(OUT)sets.o
	@echo "compiling static library"
	@ar rvs lib/bnum.lib $(OUT)*.o
	@echo "compiling sample 2 - performance program"
	@g++ -o test/test.exe test/performance.cpp lib/bnum.lib -I ./include
	@echo "running program test"
	@./test/test.exe

library: $(OUT)arithmetic_operators.o $(OUT)comparison.o $(OUT)constructors.o $(OUT)integer_arithmetic.o $(OUT)iostream.o $(OUT)string_manip.o $(OUT)sets.o
	@echo "compiling static library : bnum.lib"
	@ar rvs lib/bnum.lib $(OUT)*.o

$(OUT)arithmetic_operators.o :$(SRC)arithmetic_operators.cpp
	@echo "compiling source code to obj files ... 1/7"
	@$(CC) $(CFLAGS) $(SRC)arithmetic_operators.cpp -o obj/arithmetic_operators.o $(OFLAG)

$(OUT)comparison.o :$(SRC)comparison.cpp
	@echo "compiling source code to obj files ... 2/7"
	@$(CC) $(CFLAGS) $(SRC)comparison.cpp -o obj/comparison.o $(OFLAG)

$(OUT)constructors.o :$(SRC)constructors.cpp
	@echo "compiling source code to obj files ... 3/7"
	@$(CC) $(CFLAGS) $(SRC)constructors.cpp -o obj/constructors.o $(OFLAG)

$(OUT)integer_arithmetic.o :$(SRC)integer_arithmetic.cpp
	@echo "compiling source code to obj files ... 4/7"
	@$(CC) $(CFLAGS) $(SRC)integer_arithmetic.cpp -o obj/integer_arithmetic.o $(OFLAG)

$(OUT)iostream.o :$(SRC)iostream.cpp
	@echo "compiling source code to obj files ... 5/7"
	@$(CC) $(CFLAGS) $(SRC)iostream.cpp -o obj/iostream.o $(OFLAG)

$(OUT)string_manip.o :$(SRC)string_manip.cpp
	@echo "compiling source code to obj files ... 6/7"
	@$(CC) $(CFLAGS) $(SRC)string_manip.cpp -o obj/string_manip.o $(OFLAG)

$(OUT)sets.o :$(SRC)sets.cpp
	@echo "compiling source code to obj files ... 7/7"
	@$(CC) $(CFLAGS) $(SRC)sets.cpp -o obj/sets.o $(OFLAG)
