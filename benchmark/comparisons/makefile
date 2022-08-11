CC := g++

.PHONY: default run compile clone clean

default:
	@$(MAKE) clone
	@$(MAKE) compile
	@$(MAKE) run
	@echo ""
	@echo "Done generating a new comparison.md file"

run:
	@echo "## **APA performance comparison with other popular lightweight C++ big intger libraries in Github**" > ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "Compiler : **$(CC)**" >> ./../comparison.md
	@echo "" >> ./../comparison.md
	@echo "running comparison benchmarks"
	@./factorial.out >> ./../comparison.md
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
	@$(CC) -O3 factorial.cpp -o factorial.out -L BigNumber/build -l BigNumber
	@$(CC) -O3 division.cpp -o division.out -L BigNumber/build -l BigNumber
	@$(CC) -O3 fibonacci.cpp -o fibonacciMin.out -D_MINFIB -L BigNumber/build -l BigNumber
	@$(CC) -O3 fibonacci.cpp -o fibonacciBig.out -L BigNumber/build -l BigNumber
	@clear

clone:
	@wget https://github.com/faheel/BigInt/releases/download/v0.5.0-dev/BigInt.hpp
	@git clone https://github.com/sercantutar/infint.git
	@git clone https://github.com/kothariji/BhimIntegers.git
	@git clone https://github.com/Limeoats/BigNumber.git && cd BigNumber && mkdir build && cmake -S ./ -B ./build && cd build && $(MAKE) -C ./

# 	@git clone https://github.com/faheel/BigInt.git # cmake make is broken (kubuntu 22) (used direct release single header file instead)
# 	@git clone https://github.com/williamchanrico/biginteger-cpp.git # created with competitive programming in mind
# 	@git clone https://github.com/rfaulkner/Big-Number.git # lack necessary operation for multiplication

clean:
	rm -rf BhimIntegers infint BigNumber BigInt.hpp *.out
