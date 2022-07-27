BASE2_RAISED_BY=32
CC := g++
TESTFLAGS := -g -Og -D_APA_TESTING_PHASE -D_HIDE_WARNING -D_BASE2_$(BASE2_RAISED_BY)
CXXFLAGS := -std=c++11 -Wall -Wextra

OS := $(shell uname)

ifeq ($(OS), Linux)
TESTFLAGS += -fsanitize=address
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
	@echo "----------------------------------------------------"
	@echo "Running Initial Tests..."
	
	@./$(SRC)/ubint_constructor.out
	@./$(SRC)/ubint_swap.out
	@./$(SRC)/ubint_add.out
	@./$(SRC)/ubint_sub.out
	@./$(SRC)/ubint_mul.out
	@./$(SRC)/ubint_bitwise_logic.out
	@./$(SRC)/ubint_relational.out
	@./$(SRC)/ubint_logical.out
	@./$(SRC)/ubint_shifts.out
	@./$(SRC)/ubint_div.out
	@./$(SRC)/ubint_base_print.out
	@./$(SRC)/ubint_bases.out
	@./$(SRC)/ubint_access.out
	
	@./$(SRC)/bint_construct.out
	@./$(SRC)/bint_logical.out
	@./$(SRC)/bint_add.out
	@./$(SRC)/bint_sub.out
	@./$(SRC)/bint_mul.out
	@./$(SRC)/bint_div.out
	@./$(SRC)/bint_bitwise_logic.out
	@./$(SRC)/bint_shifts.out
	@./$(SRC)/bint_methods.out

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
