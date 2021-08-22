check: limb_check flimb_check bint_check bfloat_check
	@echo "ALL CHECK PASSED"

limb_check:
	@echo "bint : limbs - test1..."
	@echo "compiling test program"
	@g++ ./bint/limb/test/test1.cpp -O3 -march=native -fsanitize=address -o ./bint/limb/test/test1.o
	@echo "running test program, please wait.."
	@./bint/limb/test/test1.o

flimb_check:
	@echo "bfloat : limbs - test1..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test1.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test1.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test1.o

	@echo "bfloat : limbs - test2..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test2.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test2.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test2.o

	@echo "bfloat : limbs - test3..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test3.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test3.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test3.o

	@echo "bfloat : limbs - test4..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test4.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test4.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test4.o

	@echo "bfloat : limbs - test5..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test5.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test5.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test5.o

	@echo "bfloat : limbs - test6..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test6.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test6.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test6.o

	@echo "bfloat : limbs - test7..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test7.cpp -O3 -march=native -fsanitize=address -o ./bfloat/flimb/test/test7.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test7.o

bint_check:
	@echo "bint class : - test1..."
	@echo "compiling test program"
	@g++ ./bint/test/test1.cpp -O3 -march=native -fsanitize=address -o ./bint/test/test1.o
	@echo "running test program, please wait.."
	@./bint/test/test1.o

	@echo "bint class : - test2..."
	@echo "compiling test program"
	@g++ ./bint/test/test2.cpp -O3 -march=native -fsanitize=address -o ./bint/test/test2.o
	@echo "running test program, please wait.."
	@./bint/test/test2.o

	@echo "bint class : - test3..."
	@echo "compiling test program"
	@g++ ./bint/test/test3.cpp -O3 -march=native -fsanitize=address -o ./bint/test/test3.o
	@echo "running test program, please wait.."
	@./bint/test/test3.o

	@echo "bint class : - test4..."
	@echo "compiling test program"
	@g++ ./bint/test/test4.cpp -O3 -march=native -fsanitize=address -o ./bint/test/test4.o
	@echo "running test program, please wait.."
	@./bint/test/test4.o

bfloat_check:
	@echo "bfloat class : - test1..."
	@echo "compiling test program"
	@g++ ./bfloat/test/test1.cpp -O3 -march=native -fsanitize=address -o ./bfloat/test/test1.o
	@echo "running test program, please wait.."
	@./bfloat/test/test1.o

	@echo "bfloat class : - test2..."
	@echo "compiling test program"
	@g++ ./bfloat/test/test2.cpp -O3 -march=native -fsanitize=address -o ./bfloat/test/test2.o
	@echo "running test program, please wait.."
	@./bfloat/test/test2.o

	@echo "UBUNTU TEST no errors detected"


check_win: limb_check_win flimb_check_win bint_check_win bfloat_check_win
	@echo "ALL CHECK_win PASSED"

limb_check_win:
	@echo "bint : limbs - test1..."
	@echo "compiling test program"
	@g++ ./bint/limb/test/test1.cpp -O3 -march=native -o ./bint/limb/test/test1.o
	@echo "running test program, please wait.."
	@./bint/limb/test/test1.o

flimb_check_win:
	@echo "bfloat : limbs - test1..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test1.cpp -O3 -march=native -o ./bfloat/flimb/test/test1.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test1.o

	@echo "bfloat : limbs - test2..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test2.cpp -O3 -march=native -o ./bfloat/flimb/test/test2.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test2.o

	@echo "bfloat : limbs - test3..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test3.cpp -O3 -march=native -o ./bfloat/flimb/test/test3.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test3.o

	@echo "bfloat : limbs - test4..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test4.cpp -O3 -march=native -o ./bfloat/flimb/test/test4.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test4.o

	@echo "bfloat : limbs - test5..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test5.cpp -O3 -march=native -o ./bfloat/flimb/test/test5.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test5.o

	@echo "bfloat : limbs - test6..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test6.cpp -O3 -march=native -o ./bfloat/flimb/test/test6.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test6.o

	@echo "bfloat : limbs - test7..."
	@echo "compiling test program"
	@g++ ./bfloat/flimb/test/test7.cpp -O3 -march=native -o ./bfloat/flimb/test/test7.o
	@echo "running test program, please wait.."
	@./bfloat/flimb/test/test7.o

bint_check_win:
	@echo "bint class : - test1..."
	@echo "compiling test program"
	@g++ ./bint/test/test1.cpp -O3 -march=native -o ./bint/test/test1.o
	@echo "running test program, please wait.."
	@./bint/test/test1.o

	@echo "bint class : - test2..."
	@echo "compiling test program"
	@g++ ./bint/test/test2.cpp -O3 -march=native -o ./bint/test/test2.o
	@echo "running test program, please wait.."
	@./bint/test/test2.o

	@echo "bint class : - test3..."
	@echo "compiling test program"
	@g++ ./bint/test/test3.cpp -O3 -march=native -o ./bint/test/test3.o
	@echo "running test program, please wait.."
	@./bint/test/test3.o

	@echo "bint class : - test4..."
	@echo "compiling test program"
	@g++ ./bint/test/test4.cpp -O3 -march=native -o ./bint/test/test4.o
	@echo "running test program, please wait.."
	@./bint/test/test4.o

bfloat_check_win:
	@echo "bfloat class : - test1..."
	@echo "compiling test program"
	@g++ ./bfloat/test/test1.cpp -O3 -march=native -o ./bfloat/test/test1.o
	@echo "running test program, please wait.."
	@./bfloat/test/test1.o

	@echo "bfloat class : - test2..."
	@echo "compiling test program"
	@g++ ./bfloat/test/test2.cpp -O3 -march=native -o ./bfloat/test/test2.o
	@echo "running test program, please wait.."
	@./bfloat/test/test2.o

	@echo "WINDOWS TEST no errors detected"

LDFLAGS := 
CPPFLAGS := -O3 -march=native -fsanitize=address 
CXXFLAGS := -std=c++11

SRC_BINT_LIMB := bint/limb/test
SRC_BINT_CLASS := bint/test
SRC_BFLOAT_LIMB := bfloat/flimb/test
SRC_BFLOAT_CLASS := bfloat/test

SRC_FILES_BINT_LIMB := $(wildcard $(SRC_BINT_LIMB)/*.cpp)
SRC_FILES_BINT_CLASS := $(wildcard $(SRC_BINT_CLASS)/*.cpp)
SRC_FILES_BFLOAT_LIMB := $(wildcard $(SRC_BFLOAT_LIMB)/*.cpp)
SRC_FILES_BFLOAT_CLASS := $(wildcard $(SRC_BFLOAT_CLASS)/*.cpp)

OBJ_BINT_LIMB := $(patsubst $(SRC_BINT_LIMB)/%.cpp,$(SRC_BINT_LIMB)/%.o,$(SRC_FILES_BINT_LIMB))
OBJ_BINT_CLASS := $(patsubst $(SRC_BINT_CLASS)/%.cpp,$(SRC_BINT_CLASS)/%.o,$(SRC_FILES_BINT_CLASS))
OBJ_BFLOAT_LIMB := $(patsubst $(SRC_BFLOAT_LIMB)/%.cpp,$(SRC_BFLOAT_LIMB)/%.o,$(SRC_FILES_BFLOAT_LIMB))
OBJ_BFLOAT_CLASS := $(patsubst $(SRC_BFLOAT_CLASS)/%.cpp,$(SRC_BFLOAT_CLASS)/%.o,$(SRC_FILES_BFLOAT_CLASS))

# ------------------------ RUN TEST PROGRAMS ------------------------ 

# main test
run: $(OBJ_BINT_LIMB) $(OBJ_BFLOAT_LIMB) $(OBJ_BINT_CLASS) $(OBJ_BFLOAT_CLASS) 

# bint limb tests
	@echo "running bint limb test..."
	@for o in $(SRC_BINT_LIMB)/*.o; do ./$$o; done

# bfloat limb tests
	@echo "running bfloat limb test..."
	@for o in $(SRC_BFLOAT_LIMB)/*.o; do ./$$o; done

# bint class tests
	@echo "running bint class test..."
	@for o in $(SRC_BINT_CLASS)/*.o; do ./$$o; done

# bfloat class tests
	@echo "running bfloat class test..."
	@for o in $(SRC_BFLOAT_CLASS)/*.o; do ./$$o; done

	@echo "NO ERRORS IN ALL THE TEST PROGRAMS ENCOUNTERED"

# ------------------------ TEST PROGRAM COMPILATIONS ------------------------ 

# checks for bint limbs
$(SRC_BINT_LIMB)/%.o: $(SRC_BINT_LIMB)/%.cpp
	@echo "compiling bint limb test programs..."
	@g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $<


# checks for bfloat limbs
$(SRC_BFLOAT_LIMB)/%.o: $(SRC_BFLOAT_LIMB)/%.cpp
	@echo "compiling bfloat limb test programs..."
	@g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

# checks for bint class
$(SRC_BINT_CLASS)/%.o: $(SRC_BINT_CLASS)/%.cpp
	@echo "compiling bint class test programs..."
	@g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $<


# checks for bfloat class
$(SRC_BFLOAT_CLASS)/%.o: $(SRC_BFLOAT_CLASS)/%.cpp
	@echo "compiling bfloat class test programs..."
	@g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

# ----------------------------------------------------------------------------

newcheck:
	@echo "running bint limb test..."
	@echo "compiling..."
	@g++ -c ./bint/limb/test/test*.cpp
	@echo "running..."
	@./bint/limb/test/test1.o

clean:
	@echo "deleting object files"
	@rm bint/limb/test/*.o
	@rm bfloat/flimb/test/*.o
	@rm bint/test/*.o
	@rm bfloat/test/*.o
