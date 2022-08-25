#include <iostream>
#include <chrono>
#include <queue>

#include "BhimIntegers/BhimInteger.h"
#include "BigInt.hpp"
#include "infint/InfInt.h"
#include "BigNumber/bin/BigNumber/include/bignumber.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "./../../core.hpp"

const size_t TEST_RUNS = 10;
const size_t FAC_LEVEL = 400;

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
		std::cerr << "warming up CPU...\n\n";
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

	// benchmarks start

	std::cerr << "factorial - benckmark started...\n\n";

	// BhimInteger - https://github.com/kothariji/BhimIntegers
	std::cerr << "factorial - benchmarking BhimInteger.\n";
	BhimInteger BhimInteger1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBhimInteger = factorial(BhimInteger1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		BhimIntegerF += dur.count();
	}
	
	// BigInt (release - v0.5.0) https://github.com/faheel/BigInt
	std::cerr << "factorial - benchmarking BigInt.\n";
	BigInt BigInt1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBigInt = factorial(BigInt1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		BigIntF += dur.count();
	}

	// InfInt - https://github.com/sercantutar/infint
	std::cerr << "factorial - benchmarking InfInt.\n";
	InfInt InfInt1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsInfInt = factorial(InfInt1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		InfIntF += dur.count();
	}

	// BigNumber - https://github.com/Limeoats/BigNumber
	std::cerr << "factorial - benchmarking BigNumber.\n";
	BigNumber BigNumber1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBigNumber = factorial(BigNumber1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		BigNumberF += dur.count();
	}

	// APA - this repo
	std::cerr << "factorial - benchmarking apa::bint.\n";
	apa::bint bint1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsAPA = factorial(bint1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		APAF += dur.count();
	}

	// Boost - cpp_int
	std::cerr << "fibonacci - benchmarking boost::multiprecision::cpp_int.\n";
	boost::multiprecision::cpp_int cpp_int1(1);
	for(size_t i=0; i<TEST_RUNS; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		AnsBoost = factorial(cpp_int1, FAC_LEVEL);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
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
		std::cerr << "All factorials are correct\n";
	} else {
		throw std::logic_error("some factorials are wrong\n");
	}

	std::cerr << "factorial - benckmarking done...\n\n";

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

	std::cout << "\napa::bint limb base = 2<sup>" << apa::BASE_BITS << "</sup>\n\n";

	std::cout << "## **Factorial of (" << FAC_LEVEL << ") - Average (less is better)**\n\n";
	std::cout << "| Library | microseconds |\n";
	std::cout << "| ------- | ----------- |\n";
	while(!rank.empty()) {
		std::cout << "| " << rank.top().second << " | " << rank.top().first  << " μs |\n";
        rank.pop();
    }

    std::cout << "\n";
	
    return 0;
}