CC= g++
SRC= ./src/
OUT= ./obj/
PRO= -static-libgcc -static-libstdc++
DEV= -Wall -Wextra -Wshadow -Wpedantic
OFLAG= -O3 -march=native

build:
	mkdir build
	mkdir build/include
	mkdir build/lib
	mkdir build/obj

	@echo compiling source code, please wait...

	$(CC) -c io.cpp $(OFLAG) -o build/obj/io.o
	$(CC) -c constructors.cpp $(OFLAG) -o build/obj/constructors.o
	$(CC) -c comparison.cpp $(OFLAG) -o build/obj/comparison.o

	$(CC) -c helpers/string_formatters.cpp $(OFLAG) -o build/obj/string_formatters.o

	$(CC) -c arithmetic/limb_addition.cpp $(OFLAG) -o build/obj/limb_addition.o
	$(CC) -c arithmetic/limb_division_by_1limb.cpp $(OFLAG) -o build/obj/limb_division_by_1limb.o
	$(CC) -c arithmetic/limb_division_by_10.cpp $(OFLAG) -o build/obj/limb_division_by_10.o
	$(CC) -c arithmetic/limb_division.cpp $(OFLAG) -o build/obj/limb_division.o
	$(CC) -c arithmetic/limb_multiply_by_int.cpp $(OFLAG) -o build/obj/limb_multiply_by_int.o
	$(CC) -c arithmetic/limb_multiply.cpp $(OFLAG) -o build/obj/limb_multiply.o
	$(CC) -c arithmetic/limb_subtraction.cpp $(OFLAG) -o build/obj/limb_subtraction.o

	ar rs build/lib/liblimbint.a build/obj/*.o