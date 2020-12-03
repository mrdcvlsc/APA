all: done

done: make_lib
	@echo "copilation done... cleaning working directory..."
	@rm *.o

make_lib: make_obj
	@echo "building single static library"
	@ar rvs bignum.lib *.o

make_obj:
	@echo "compiling object files"
	@g++ -std=c++14 -static-libgcc -static-libstdc++ -I ./include -c ./source/*.cpp -O2

test: build_test
	@echo "starting sample program"
	@./sample_calculator

clean:
	rm *.o bignum.lib debug
