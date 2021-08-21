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

clean:
	@echo "deleting object files"
	@rm bint/limb/test/*.o
	@rm bfloat/flimb/test/*.o
	@rm bint/test/*.o
	@rm bfloat/test/*.o
