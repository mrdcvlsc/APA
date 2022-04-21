BASE2_RAISED_BY:=DEFAULT_TO_32
CC := g++
TESTFLAGS := -g -Og -D_HIDE_WARNING -D_BASE2_$(BASE2_RAISED_BY)
CXXFLAGS := -std=c++11 -Wall -Wextra

OS := $(shell uname)

ifeq ($(OS), Linux)
TESTFLAGS += -fsanitize=address
endif

all_test:
	@echo ===============================
	@echo Base 2^16 Test
	@make test BASE2_RAISED_BY=16
	@make clean

	@echo ===============================
	@echo Base 2^32 Test
	@make test BASE2_RAISED_BY=32
	@make clean

	@echo ===============================
	@echo Base 2^64 Test
	@make test BASE2_RAISED_BY=64
	@make clean

	@echo ===============================
	@echo       ALL TESTS PASSED
	@echo ===============================

SRC := tests
SRC_FILES := $(wildcard $(SRC)/*.cpp)
OBJ := $(patsubst $(SRC)/%.cpp,$(SRC)/%.out,$(SRC_FILES))

# -------------------------- run test programs ---------------------------

test: $(OBJ)
	@echo OS : $(OS)
	@echo LIMB : Base2^$(BASE2_RAISED_BY)
	@echo "----------------------------------------------------"
	@echo "Running Initial Tests..."
	@./$(SRC)/ubint_constructor.out
	@./$(SRC)/ubint_add.out
	@./$(SRC)/ubint_sub.out
	@./$(SRC)/ubint_swap.out

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
