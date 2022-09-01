BASE2_RAISED_BY=32
CC := g++
TESTFLAGS := -g -Og -D_APA_TESTING_PHASE -D_HIDE_WARNING -D_BASE2_$(BASE2_RAISED_BY)
CXXFLAGS := -std=c++11 -Wall -Wextra

OS := $(shell uname)
.PHONY: test all_test benchmark karatsuba arithmetic initandtostring style compare

ifeq ($(OS), Linux)
TESTFLAGS += -fsanitize=address
# TESTFLAGS += -fsanitize=memory -fsanitize-memory-track-origins
endif

all_test:
	@echo ===============================
	@echo Base 2^16 Test
	@$(MAKE) test BASE2_RAISED_BY=16
	@$(MAKE) clean

	@echo ===============================
	@echo Base 2^32 Test
	@$(MAKE) test BASE2_RAISED_BY=32
	@$(MAKE) clean

	@echo ===============================
	@echo Base 2^64 Test
	@$(MAKE) test BASE2_RAISED_BY=64
	@$(MAKE) clean

	@echo ===============================
	@echo      APA ALL TESTS PASSED
	@echo ===============================

SRC := tests
SRC_FILES := $(wildcard $(SRC)/*.cpp)
OBJ := $(patsubst $(SRC)/%.cpp,$(SRC)/%.out,$(SRC_FILES))

# -------------------------- run test programs ---------------------------

test: $(OBJ)
	@echo OS : $(OS)
	@echo LIMB : Base2_$(BASE2_RAISED_BY)
	@echo CPP_COMPILER : $(CC)
	@echo "----------------------------------------------------"
	@echo "Running Initial Tests..."
	
	@./$(SRC)/integer_constructor.out
	@./$(SRC)/integer_swap.out
	@./$(SRC)/integer_add.out
	@./$(SRC)/integer_add_assign.out
	@./$(SRC)/integer_sub.out
	@./$(SRC)/integer_sub_assign.out
	@./$(SRC)/integer_mul.out
	@./$(SRC)/integer_bitwise_logic.out
	@./$(SRC)/integer_relational.out
	@./$(SRC)/integer_logical.out
	@./$(SRC)/integer_shifts.out
	@./$(SRC)/integer_div.out
	@./$(SRC)/integer_div_assign.out
	@./$(SRC)/integer_base_print.out
	@./$(SRC)/integer_bases.out
	@./$(SRC)/integer_access.out
	@./$(SRC)/bint_construct.out
	@./$(SRC)/bint_logical.out
	@./$(SRC)/bint_add.out
	@./$(SRC)/bint_add_assign.out
	@./$(SRC)/bint_sub.out
	@./$(SRC)/bint_sub_assign.out
	@./$(SRC)/bint_mul.out
	@./$(SRC)/bint_div.out
	@./$(SRC)/bint_div_assign.out
	@./$(SRC)/bint_bitwise_logic.out
	@./$(SRC)/bint_shifts.out
	@./$(SRC)/bint_methods.out
	@./$(SRC)/bint_karatsuba.out
	@./$(SRC)/bint_error_handling.out
	@./$(SRC)/bint_literal_assign.out

# -------------------------- test program compilation ---------------------------

$(SRC)/%.out: $(SRC)/%.cpp
	@echo "compiling test program - compiler : $(CC)"
	@$(CC) $(TESTFLAGS) $(CXXFLAGS) -o $@ $<

clean:
ifeq ($(OS), Linux)
	@echo "deleting compiled test programs"
	@rm ./$(SRC)/*.out
else
	@echo "deleting compiled test programs"
	del tests\*.out
endif

style:
	@clang-format -i -style=file *.cpp *.hpp tests/*.hpp tests/*.cpp benchmark/*.cpp

benchmark: karatsuba arithmetic initandtostring

karatsuba:
	@echo "# Karatsuba Multiplication" > benchmark/karatsuba.md
	@echo "" >> benchmark/karatsuba.md
	@echo "Compiler : $(CC)" >> benchmark/karatsuba.md
	@echo "" >> benchmark/karatsuba.md
	@echo "Average performance of APA's karatsuba implementation (microseconds)" >> benchmark/karatsuba.md
	@echo "" >> benchmark/karatsuba.md
	@$(CC) benchmark/karatsuba.cpp -O3 -o benchmark/karatsuba.out -D_FORCE_BASE2_16
	@./benchmark/karatsuba.out >> benchmark/karatsuba.md
	@$(CC) benchmark/karatsuba.cpp -O3 -o benchmark/karatsuba.out -D_FORCE_BASE2_32
	@./benchmark/karatsuba.out >> benchmark/karatsuba.md
	@$(CC) benchmark/karatsuba.cpp -O3 -o benchmark/karatsuba.out -D_FORCE_BASE2_64
	@./benchmark/karatsuba.out >> benchmark/karatsuba.md
	@rm benchmark/karatsuba.out
	@echo "" >> benchmark/karatsuba.md
	@echo "### System Runner" >> benchmark/karatsuba.md
	@echo "" >> benchmark/karatsuba.md
	@echo "\`\`\`" >> benchmark/karatsuba.md
	@lscpu >> benchmark/karatsuba.md
	@echo "\`\`\`" >> benchmark/karatsuba.md

arithmetic:
	@echo "# Basic Arithmetic" > benchmark/basic-arithmetic.md
	@echo "" >> benchmark/basic-arithmetic.md
	@echo "Compiler : $(CC)" >> benchmark/basic-arithmetic.md
	@echo "" >> benchmark/basic-arithmetic.md
	@echo "Average performance (nanoseconds)" >> benchmark/basic-arithmetic.md
	@echo "" >> benchmark/basic-arithmetic.md
	@$(CC) benchmark/basic-arithmetic.cpp -O3 -o benchmark/basic-arithmetic.out -D_FORCE_BASE2_16
	@./benchmark/basic-arithmetic.out >> benchmark/basic-arithmetic.md
	@$(CC) benchmark/basic-arithmetic.cpp -O3 -o benchmark/basic-arithmetic.out -D_FORCE_BASE2_32
	@./benchmark/basic-arithmetic.out >> benchmark/basic-arithmetic.md
	@$(CC) benchmark/basic-arithmetic.cpp -O3 -o benchmark/basic-arithmetic.out -D_FORCE_BASE2_64
	@./benchmark/basic-arithmetic.out >> benchmark/basic-arithmetic.md
	@rm benchmark/basic-arithmetic.out
	@echo "" >> benchmark/basic-arithmetic.md
	@echo "### System Runner" >> benchmark/basic-arithmetic.md
	@echo "" >> benchmark/basic-arithmetic.md
	@echo "\`\`\`" >> benchmark/basic-arithmetic.md
	@lscpu >> benchmark/basic-arithmetic.md
	@echo "\`\`\`" >> benchmark/basic-arithmetic.md

initandtostring:
	@echo "# String Initialization and To Base 10 String" > benchmark/init-and-to-string.md
	@echo "" >> benchmark/init-and-to-string.md
	@echo "Compiler : $(CC)" >> benchmark/init-and-to-string.md
	@echo "" >> benchmark/init-and-to-string.md
	@echo "Accumulated performance (nanoseconds)" >> benchmark/init-and-to-string.md
	@echo "" >> benchmark/init-and-to-string.md
	@$(CC) benchmark/init-and-to-string.cpp -O3 -o benchmark/init-and-to-string.out -D_FORCE_BASE2_16
	@./benchmark/init-and-to-string.out >> benchmark/init-and-to-string.md
	@$(CC) benchmark/init-and-to-string.cpp -O3 -o benchmark/init-and-to-string.out -D_FORCE_BASE2_32
	@./benchmark/init-and-to-string.out >> benchmark/init-and-to-string.md
	@$(CC) benchmark/init-and-to-string.cpp -O3 -o benchmark/init-and-to-string.out -D_FORCE_BASE2_64
	@./benchmark/init-and-to-string.out >> benchmark/init-and-to-string.md
	@rm benchmark/init-and-to-string.out
	@echo "" >> benchmark/init-and-to-string.md
	@echo "### System Runner" >> benchmark/init-and-to-string.md
	@echo "" >> benchmark/init-and-to-string.md
	@echo "\`\`\`" >> benchmark/init-and-to-string.md
	@lscpu >> benchmark/init-and-to-string.md
	@echo "\`\`\`" >> benchmark/init-and-to-string.md

FTSRC:=test

focustest:
	@echo compiling $(FTSRC).cpp file base2_16...
	@$(CC) $(SRC)/$(FTSRC).cpp -o $(SRC)/$(FTSRC)_base16.out -D_APA_TESTING_PHASE -D_HIDE_WARNING -D_BASE2_16 -g -fsanitize=address -Wall -Wextra
	$(SRC)/$(FTSRC)_base16.out
	
	@echo compiling $(FTSRC).cpp file base2_32...
	@$(CC) $(SRC)/$(FTSRC).cpp -o $(SRC)/$(FTSRC)_base32.out -D_APA_TESTING_PHASE -D_HIDE_WARNING -D_BASE2_32 -g -fsanitize=address -Wall -Wextra
	$(SRC)/$(FTSRC)_base32.out
	
	@echo compiling $(FTSRC).cpp file base2_64...
	@$(CC) $(SRC)/$(FTSRC).cpp -o $(SRC)/$(FTSRC)_base64.out -D_APA_TESTING_PHASE -D_HIDE_WARNING -D_BASE2_64 -g -fsanitize=address -Wall -Wextra
	$(SRC)/$(FTSRC)_base64.out