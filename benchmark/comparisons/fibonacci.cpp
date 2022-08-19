#include <iostream>
#include <chrono>
#include <queue>

#include "BhimIntegers/BhimInteger.h"
#include "BigInt.hpp"
#include "infint/InfInt.h"
#include "BigNumber/bin/BigNumber/include/bignumber.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "./../../core.hpp"

const size_t TEST_RUNS = 30;

#ifdef _MINFIB
const size_t FIB_LEVEL = 300;
#else
const size_t FIB_LEVEL = 6000;
#endif

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
		apa::bint warmUp1 = apa::factorial(30000);
		apa::bint warmUp2 = apa::fibonacci(300000);
		apa::bint warmup3 = apa::power(500, 500);
		std::cerr << "warmup done.\n\n";
	}


	// averages
	size_t BhimIntegerF = 0, BigIntF = 0, InfIntF = 0, BigNumberF = 0, APAF = 0, BoostF = 0;

	// answer storage
	BhimInteger AnsBhimInteger;
	BigInt AnsBigInt;
	InfInt AnsInfInt;
	BigNumber AnsBigNumber(0);
	apa::bint AnsAPA;
	boost::multiprecision::cpp_int AnsBoost;

	// fibonacci - benchmarks start

	std::cerr << "benckmark started...\n\n";

	// BhimInteger - https://github.com/kothariji/BhimIntegers
	std::cerr << "fibonacci - benchmarking BhimInteger.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBhimInteger = fibonacci(FIB_LEVEL, BhimInteger(0), BhimInteger(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		BhimIntegerF += dur.count();
	}
	
	// BigInt (release - v0.5.0) https://github.com/faheel/BigInt
	std::cerr << "fibonacci - benchmarking BigInt.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBigInt = fibonacci(FIB_LEVEL, BigInt(0), BigInt(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		BigIntF += dur.count();
	}

	// InfInt - https://github.com/sercantutar/infint
	std::cerr << "fibonacci - benchmarking InfInt.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsInfInt = fibonacci(FIB_LEVEL, InfInt(0), InfInt(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		InfIntF += dur.count();
	}

	// BigNumber - https://github.com/Limeoats/BigNumber
	std::cerr << "fibonacci - benchmarking BigNumber.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBigNumber = fibonacci(FIB_LEVEL, BigNumber(0), BigNumber(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		BigNumberF += dur.count();
	}

	// APA - this repo
	std::cerr << "fibonacci - benchmarking apa::bint.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsAPA = fibonacci(FIB_LEVEL, apa::bint(0), apa::bint(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		APAF += dur.count();
	}

	// Boost - cpp_int
	std::cerr << "fibonacci - benchmarking boost::multiprecision::cpp_int.\n";
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBoost = fibonacci(FIB_LEVEL, boost::multiprecision::cpp_int(0), boost::multiprecision::cpp_int(1));
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		BoostF += dur.count();
	}

	//check correctness of output
	if(
		cout_to_string(AnsBhimInteger) == cout_to_string(AnsBigInt) &&
		cout_to_string(AnsBigInt) == cout_to_string(AnsInfInt) &&
		cout_to_string(AnsInfInt) == cout_to_string(AnsBigNumber) &&
		cout_to_string(AnsBigNumber) == cout_to_string(AnsAPA.to_base10_string()) &&
		cout_to_string(AnsAPA.to_base10_string()) == cout_to_string(AnsBoost)
	) {
		std::cerr << "All fibonaccis are correct\n";
	} else {
		throw std::logic_error("some fibonaccis are wrong\n");
	}

	std::cerr << "benckmarking done...\n\n";

	// ranking min-heap
	std::priority_queue<
		std::pair<size_t, std::string>,
		std::vector<std::pair<size_t, std::string>>,
		std::greater<std::pair<size_t, std::string>>> rank;
  
    rank.push(std::make_pair(BhimIntegerF/TEST_RUNS, "[BhimInteger](https://github.com/kothariji/BhimIntegers)"));
    rank.push(std::make_pair(BigIntF/TEST_RUNS, "[BigInt](https://github.com/faheel/BigInt)"));
    rank.push(std::make_pair(InfIntF/TEST_RUNS, "[InfInt](https://github.com/sercantutar/infint)"));
    rank.push(std::make_pair(BigNumberF/TEST_RUNS, "[BigNumber](https://github.com/Limeoats/BigNumber)"));
    rank.push(std::make_pair(APAF/TEST_RUNS, "[apa::bint](https://github.com/mrdcvlsc/APA)"));
	rank.push(std::make_pair(BoostF/TEST_RUNS, "[boost::multiprecision::cpp_int](https://github.com/boostorg/multiprecision)"));

	std::cout << "## **fibonacci of (" << FIB_LEVEL << ") - Average (less is better)**\n\n";
	std::cout << "\n";
	std::cout << "| Library | Nanoseconds |\n";
	std::cout << "| ------- | ----------- |\n";
	while(!rank.empty()) {
		std::cout << "| " << rank.top().second << " | " << rank.top().first  << " ns |\n";
        rank.pop();
    }

	std::cout << "\n";

    return 0;
}