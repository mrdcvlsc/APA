#include <iostream>
#include <chrono>
#include <queue>

#include "BhimIntegers/BhimInteger.h"
#include "BigInt.hpp"
#include "infint/InfInt.h"
// #include "BigNumber/bin/BigNumber/include/bignumber.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "./../../core.hpp"

const size_t TEST_RUNS = 20;

const size_t FAC_LEVEL = 1537;
const size_t FIB_LEVEL = 713;

template<class T>
T fibonacci(size_t nth, T b0, T b1) {
	T base0 = b0, base1 = b1;
	T nthfib = 0;
	for(size_t i=2; i<nth; ++i) {
		nthfib = base0 + base1;
		base0 = std::move(base1);
		base1 = std::move(nthfib);
	}
	return base0 + base1;
}

template<class T>
T factorial(const T& one, size_t n) {
    T factorial = one;
    T iter = factorial;

    for(size_t i=1; i<=n; ++i) {
        factorial = factorial * iter;
        iter++;
    }

    return factorial;
}

// ref: https://stackoverflow.com/questions/5419356/redirect-stdout-stderr-to-a-string
template<class T>
std::string cout_to_string(const T& input) {
	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
	std::cout << input << std::endl;
	std::cout.rdbuf(old);
	return buffer.str();
}

int main() {
	{ // warm-up CPU
		std::cerr << "\n\nwarming up CPU...\n\n";
		apa::bint warmUp1 = apa::factorial(12000);
		apa::bint warmUp2 = apa::fibonacci(120000);
		apa::bint warmup3 = apa::power(500, 500);
		std::cerr << "warmup done.\n\n";
	}


	// averages
	size_t BhimIntegerF = 0, BigIntF = 0, InfIntF = 0, APAF = 0, BoostF = 0;

	// answer storage
	apa::bint
		APAFac = factorial(apa::bint(1), FAC_LEVEL),
		APAFib = fibonacci(FIB_LEVEL, apa::bint(0), apa::bint(1)),
		APAAns;

	BhimInteger
		BhimIntegerFac = APAFac.to_base10_string(),
		BhimIntegerFib = APAFib.to_base10_string(),
		BhimIntegerAns;

	BigInt
		BigIntFac = APAFac.to_base10_string(),
		BigIntFib = APAFib.to_base10_string(),
		BigIntAns;

	InfInt
		InfIntFac = APAFac.to_base10_string(),
		InfIntFib = APAFib.to_base10_string(),
		InfIntAns;

	// BigNumber
		// BigNumberFac = APAFac.to_base10_string(),
		// BigNumberFib = APAFib.to_base10_string(),
		// BigNumberAns(0);

	boost::multiprecision::cpp_int
		BoostFac(APAFac.to_base10_string()),
		BoostFib(APAFib.to_base10_string()),
		BoostAns;

	// fibonacci - benchmarks start

	std::cerr << "benckmark started...\n\n";

	// // BhimInteger - https://github.com/kothariji/BhimIntegers
	// std::cerr << "division - benchmarking BhimInteger.\n";
	// for(size_t i=0; i<TEST_RUNS; ++i) {
	// 	auto start = std::chrono::high_resolution_clock::now();
	// 	BhimIntegerAns = BhimIntegerFac / BhimIntegerFib;
	// 	auto end = std::chrono::high_resolution_clock::now();
	// 	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	// 	BhimIntegerF += dur.count();
	// }
	
	// BigInt (release - v0.5.0) https://github.com/faheel/BigInt
	std::cerr << "division - benchmarking BigInt.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		BigIntAns = BigIntFac / BigIntFib;
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		BigIntF += dur.count();
	}

	// InfInt - https://github.com/sercantutar/infint
	std::cerr << "division - benchmarking InfInt.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		InfIntAns = InfIntFac / InfIntFib;
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		InfIntF += dur.count();
	}

	// BigNumber - https://github.com/Limeoats/BigNumber
	// std::cerr << "division - benchmarking BigNumber.\n";
	// for(size_t i=0; i<TEST_RUNS; ++i) {
	// 	auto start = std::chrono::high_resolution_clock::now();
	// 	BigNumberAns = BigNumberFac / BigNumberFib;
	// 	auto end = std::chrono::high_resolution_clock::now();
	// 	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	// 	BigNumberF += dur.count();
	// }

	// APA - this repo
	std::cerr << "division - benchmarking apa::bint.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		APAAns = APAFac / APAFib;
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		APAF += dur.count();
	}

	// Boost - cpp_int
	std::cerr << "division - benchmarking apa::bint.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		BoostAns = BoostFac / BoostFib;
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		BoostF += dur.count();
	}

	//check correctness of output
	if(
		// cout_to_string(BhimIntegerAns) == cout_to_string(BigIntAns) &&
		cout_to_string(BigIntAns) == cout_to_string(InfIntAns) &&
		// cout_to_string(InfIntAns) == cout_to_string(BigNumberAns) &&
		cout_to_string(InfIntAns) == cout_to_string(APAAns.to_base10_string()) &&
		cout_to_string(APAAns.to_base10_string()) == cout_to_string(BoostAns)
	) {
		std::cerr << "All divisions are correct\n";
	} else {
		// std::cerr << "\n\nBhimIntegerAns = " << BhimIntegerAns << "\n\n";
		std::cerr << "BigIntAns = " << BigIntAns << "\n\n";
		std::cerr << "InfIntAns = " << InfIntAns << "\n\n";
		// // std::cerr << "BigNumberAns = " << BigNumberAns << "\n\n";
		std::cerr << "APAAns = " << APAAns.to_base10_string() << "\n\n";

		throw std::logic_error("some divisions are wrong\n");
	}

	std::cerr << "benckmarking done...\n\n";

	// ranking min-heap
	std::priority_queue<
		std::pair<size_t, std::string>,
		std::vector<std::pair<size_t, std::string>>,
		std::greater<std::pair<size_t, std::string>>> rank;
  
    // rank.push(std::make_pair(BhimIntegerF/TEST_RUNS, "[BhimInteger](https://github.com/kothariji/BhimIntegers)"));
    rank.push(std::make_pair(BigIntF/TEST_RUNS, "[BigInt](https://github.com/faheel/BigInt)"));
    rank.push(std::make_pair(InfIntF/TEST_RUNS, "[InfInt](https://github.com/sercantutar/infint)"));
    // // // rank.push(std::make_pair(BigNumberF/TEST_RUNS, "[BigNumber](https://github.com/Limeoats/BigNumber)"));
    rank.push(std::make_pair(APAF/TEST_RUNS, "[apa::bint](https://github.com/mrdcvlsc/APA)"));
	rank.push(std::make_pair(BoostF/TEST_RUNS, "[boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision)"));

	std::cout << "## Division : **fac(" << FAC_LEVEL << ") / fib(" << FIB_LEVEL << ") - Average (less is better)**\n\n";
	std::cout << "\n";
	std::cout << "| Library | microseconds |\n";
	std::cout << "| ------- | ----------- |\n";
	while(!rank.empty()) {
		std::cout << "| " << rank.top().second << " | " << rank.top().first  << " μs |\n";
        rank.pop();
    }

	std::cout << "\n- **[BigNumber](https://github.com/Limeoats/BigNumber)** - not included, division is taking too long\n";
	std::cout << "- **[BhimInteger](https://github.com/kothariji/BhimIntegers)** - not included, producing zero quotients\n";
	std::cout << "\n";

    return 0;
}