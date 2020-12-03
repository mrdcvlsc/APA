all: done

done: make_lib
	@echo "copilation done... cleaning working directory..."
	@rm *.o
	@echo "done end of compilation."

make_lib: make_obj
	@echo "building single static library"
	@ar rvs bignum.lib *.o

make_obj:
	@echo "compiling object files"
	@g++ -std=c++14 -static-libgcc -static-libstdc++ -I ./include -c ./source/*.cpp -O2

test: build_test
	@echo "starting sample program"
	@./sample_calculator.exe
	
build_test:
	@echo "compiling sample program"
	@g++ -std=c++14 -o sample_calculator.exe -I ./include sample_program_calculator.cpp bignum.lib

clean:
	@echo "removing : bignum.lib and sample_calculator.exe"
	@rm *.o bignum.lib sample_calculator.exe
