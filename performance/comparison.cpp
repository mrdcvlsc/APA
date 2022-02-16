// main.cpp

#include <iostream>
#include <gmpxx.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "../bint/bint.hpp"

using namespace std;

#define ITERATIONS 10
#define LIMITS 1000

typedef boost::multiprecision::cpp_int boost_int;

int main(){
    
    // cout<<"======================== Addition ========================="<<endl;
    // cout<<"======================== Subtraction ========================="<<endl;
    // cout<<"======================== Multiplication ========================="<<endl;
    // cout<<"======================== Division ========================="<<endl;

    cout<<"======================== FIBONACCI : PERFORMANCE TEST FOR ADDITION ========================="<<endl;

    size_t NthFibonacci = 100000;

    boost_int boost_base0 = 0;
    boost_int boost_base1 = 1;
    boost_int boost_nthFib = NthFibonacci;

    mpz_class gmp_base0 = 0;
    mpz_class gmp_base1 = 1;
    mpz_class gmp_nthFib = NthFibonacci;

    apa::bint bint_base0 = 0;
    apa::bint bint_base1 = 1;
    apa::bint bint_nthFib = NthFibonacci;
    
    { // GMP FIB
        auto start = chrono::high_resolution_clock::now();
        for(size_t i=2; i<NthFibonacci; ++i){
            gmp_nthFib = gmp_base0 + gmp_base1;
            gmp_base0 = gmp_base1;
            gmp_base1 = gmp_nthFib;
        }
        auto end = chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        cout << "gmp   fib(" << NthFibonacci << ") took " << dur.count() << " microseconds\n";
    }

    { // BOOST FIB
        auto start = chrono::high_resolution_clock::now();
        for(size_t i=2; i<NthFibonacci; ++i){
            boost_nthFib = boost_base0 + boost_base1;
            boost_base0 = boost_base1;
            boost_base1 = boost_nthFib;
        }
        auto end = chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        cout << "boost fib(" << NthFibonacci << ") took " << dur.count() << " microseconds\n";
    }

    { // APA FIB
        auto start = chrono::high_resolution_clock::now();
        for(size_t i=2; i<NthFibonacci; ++i){
            bint_nthFib = bint_base0 + bint_base1;
            bint_base0 = bint_base1;
            bint_base1 = bint_nthFib;
        }
        auto end = chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        cout << "apa   fib(" << NthFibonacci << ") took " << dur.count() << " microseconds\n";
    }

    if(boost_nthFib.str()!=gmp_nthFib.get_str())
        throw std::logic_error("gmp and boost fibonacci is not equal");
    else if(gmp_nthFib.get_str()!=bint_nthFib.string_form())
        throw std::logic_error("apa fibonacci is wrong");
    else
        cout << "All Fibonacci is correct\n\n";

    cout<<"======================== FACTORIAL : PERFORMANCE TEST FOR MULTIPLICATION ========================="<<endl;

    boost_int boost_limit = LIMITS;
    boost_int boost_n = LIMITS;
    boost_int boost_fac = 1;

    mpz_class gmp_limit = LIMITS;
    mpz_class gmp_n = LIMITS;
    mpz_class gmp_fac = 1;

    apa::bint limit = LIMITS;    
    apa::bint n = limit, fac("1");

    mpz_class boost_average = 0;
    mpz_class gmp_average = 0;
    mpz_class bint_average = 0;

    apa::bint correct_ans(
        "40238726007709377354370243392300398571937486421071463254379991042993851239862902059204"
        "42084869694048004799886101971960586316668729948085589013238296699445909974245040870737"
        "59918823627727188732519779505950995276120874975462497043601418278094646496291056393887"
        "43788648733711918104582578364784997701247663288983595573543251318532395846307555740911"
        "42624174743493475534286465766116677973966688202912073791438537195882498081268678383745"
        "59731746136085379534524221586593201928090878297308431392844403281231558611036976801357"
        "30421616874760967587134831202547858932076716913244842623613141250878020800026168315102"
        "73418279777047846358681701643650241536913982812648102130927612448963599287051149649754"
        "19909342221566832572080821333186116811553615836546984046708975602900950537616475847728"
        "42188967964624494516076535340819890138544248798495995331910172335555660213945039973628"
        "07501378376153071277619268490343526252000158885351473316117021039681759215109077880193"
        "93178114194545257223865541461062892187960223838971476088506276862967146674697562911234"
        "08243920816015378088989396451826324367161676217916890977991190375403127462228998800519"
        "54444142820121873617459926429565817466283029555702990243241531816172104658320367869061"
        "17260158783520751516284225540265170483304226143974286933061690897968482590125458327168"
        "22645806652676995865268227280707578139185817888965220816434834482599326604336766017699"
        "96128318607883861502794659551311565520360939881806121385586003014356945272242063446317"
        "97460594682573103790084024432438465657245014402821885252470935190620929023136493273497"
        "56551395872055965422874977401141334696271542284586237738753823048386568897646192738381"
        "49001407673104466402598994902222217659043399018860185665264850617997023561938970178600"
        "40811889729918311021171229845901641921068884387121855646124960798722908519296819372388"
        "64261483965738229112312502418664935314397013742853192664987533721894069428143411852015"
        "80141233448280150513996942901534830776445690990731524332782882698646027898643211390835"
        "06217095002597389863554277196742822248757586765752344220207573630569498825087968928162"
        "75384886339690995982628095612145099487170124451646126037902930912088908694202851064018"
        "21543994571568059418727489980942547421735824010636774045957417851608292301353580818400"
        "96996372524230560855903700624271243416909004153690105933983835777939410970027753472000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000"
    );

    for(size_t i=0; i<ITERATIONS; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(apa::bint i=1; i<=limit; ++i)
        {
            fac = fac*i;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        cout << "bint__Factorial of 1000 took : " << dur.count() << " nanoseconds\n";
        if(fac!=correct_ans) throw std::logic_error("incorrect factorial");
        fac = 1;
        bint_average += dur.count();
    }

    std::cout << "\n";

    for(size_t i=0; i<ITERATIONS; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(boost_int i=1; i<=boost_limit; ++i)
        {
            boost_fac = boost_fac*i;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        cout << "boost_Factorial of 1000 took : " << dur.count() << " nanoseconds\n";
        std::string boost_facout = boost_fac.str();
        if(boost_facout!=correct_ans.string_form()) throw std::logic_error("incorrect boost_factorial");
        boost_fac = 1;
        boost_average += dur.count();
    }

    std::cout << "\n";

    for(size_t i=0; i<ITERATIONS; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(mpz_class i=1; i<=gmp_limit; ++i)
        {
            gmp_fac = gmp_fac*i;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        cout << "gmp___Factorial of 1000 took : " << dur.count() << " nanoseconds\n";
        std::string gmp_facout = gmp_fac.get_str();
        if(gmp_facout!=correct_ans.string_form()) throw std::logic_error("incorrect gmp_factorial");
        gmp_fac = 1;
        gmp_average += dur.count();
    }

    bint_average /= ITERATIONS;
    boost_average /= ITERATIONS;
    gmp_average /= ITERATIONS;

    std::cout << "\n";

    std::cout << "bint__ave : " << bint_average  << " nanoseconds\n";
    std::cout << "boost_ave : " << boost_average << " nanoseconds\n";
    std::cout << "gmp___ave : " << gmp_average   << " nanoseconds\n";

    // 4,601,977 - 6,145,354 nanoseconds : old

    // gmp is faster than boost if you do static linking, but slower for shared
 
    return 0;
}

// g++ comparison.cpp -I /home/${USER}/Repo/boost_1_78_0/ /usr/local/lib/libgmpxx.a /usr/local/lib/libgmp.a -O3 -o perf