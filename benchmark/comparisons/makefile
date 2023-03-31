CXX:=g++

INCLUDE_PATH:=-I "./multiprecision-1.79/include/"
LIB_PATH:=-L BigNumber/build
LIBS:=-l BigNumber
DFLAGS:= 
OFLAG:=-O3

.PHONY: default run compile clone clean

default:
	@$(MAKE) clone
	@$(MAKE) compile
	@$(MAKE) run
	@echo ""
	@echo "Done generating a new comparison.md file"

run:
	@echo "## **APA performance comparison with other popular lightweight C++ big integer libraries in Github**" > ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "Compiler : **$(CXX)**" >> ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "running comparison benchmarks"
	@./factorial_all.out >> ./../comparison.md
	@./factorial_exclude.out >> ./../comparison.md
	@./fibonacciMin.out >> ./../comparison.md
	@./fibonacciBig.out >> ./../comparison.md
	@./division.out >> ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "## System Runner" >> ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "\`\`\`" >> ./../comparison.md
	@lscpu >> ./../comparison.md
	@echo "\`\`\`" >> ./../comparison.md

compile: factorial.cpp fibonacci.cpp division.cpp
	@echo "compiling benchmark comparison programs"
	@$(CXX) $(OFLAG) factorial.cpp -o factorial_all.out $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(DFLAGS)
	@$(CXX) $(OFLAG) factorial.cpp -o factorial_exclude.out -DEXCLUDE_SLOW $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(DFLAGS)
	@$(CXX) $(OFLAG) division.cpp -o division.out $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(DFLAGS)
	@$(CXX) $(OFLAG) fibonacci.cpp -o fibonacciMin.out $(INCLUDE_PATH) -D_MINFIB $(LIB_PATH) $(LIBS) $(DFLAGS)
	@$(CXX) $(OFLAG) fibonacci.cpp -o fibonacciBig.out $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(DFLAGS)
	@clear

clone:
	@wget https://github.com/boostorg/multiprecision/archive/refs/tags/v1.79.tar.gz
	@tar -xvzf v1.79.tar.gz
	@wget https://github.com/faheel/BigInt/releases/download/v0.5.0-dev/BigInt.hpp
	@git clone https://github.com/sercantutar/infint.git
	@git clone https://github.com/kothariji/BhimIntegers.git
	@git clone https://github.com/Limeoats/BigNumber.git && cd BigNumber && mkdir build && cmake -S ./ -B ./build && cd build && $(MAKE) -C ./

# 	@git clone https://github.com/faheel/BigInt.git # cmake make is broken (kubuntu 22) (used direct release single header file instead)
# 	@git clone https://github.com/williamchanrico/biginteger-cpp.git # created with competitive programming in mind
# 	@git clone https://github.com/rfaulkner/Big-Number.git # lack necessary operation for multiplication

clean:
	rm -rf BhimIntegers infint BigNumber BigInt.hpp *.out v1.79.tar.gz multiprecision-1.79
