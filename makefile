CPPFLAGS := -O3 -march=native 
CXXFLAGS := -std=c++11

OS := $(shell uname)

ifeq ($(OS), Linux)
CPPFLAGS += -fsanitize=address
endif

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
check: $(OBJ_BINT_LIMB) $(OBJ_BFLOAT_LIMB) $(OBJ_BINT_CLASS) $(OBJ_BFLOAT_CLASS) 

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

clean:
	@echo "deleting object files"
	@rm bint/limb/test/*.o
	@rm bfloat/flimb/test/*.o
	@rm bint/test/*.o
	@rm bfloat/test/*.o
