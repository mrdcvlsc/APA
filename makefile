all: done

done: make_lib
	rm *.o

make_lib: make_obj
	ar rvs bignum.lib *.o

make_obj:
	g++ -std=c++14 -static-libgcc -static-libstdc++ -I ./include -c ./source/*.cpp -O2

test: build_test
	./sample_calculator

build_test: 
	g++ -I ./include -o sample_calculator sample_program_calculator.cpp bignum.lib

dbug:
	g++ -Wall -I ./include sample_program_calculator.cpp ./source/*.cpp -o debug
	./debug

clean:
	rm *.o bignum.lib debug