#include <iostream>
#include "../bint.hpp"

template<typename T>
T Fibonacci(T n)
{
    if(n==0) return 0;

    T base0 = -1;
    T base1 = -1;

    for(long i=-2; i>=n; --i)
    {
        T next = base1 + base0;
        base0 = base1;
        base1 = next;
    }

    return base1;
}

// Fibonacci test

int main()
{
    apa::bint fiba = Fibonacci<apa::bint>(0);
    std::cout<<"fib of 0th term   = "<<fiba<<"\n";
    std::cout<<"string form       = "<<fiba.string_form()<<"\n\n";
    if(fiba.string_form()!="0")
    {
        throw std::logic_error("the fib of -0th term is wrong");
    }

    apa::bint fibb = Fibonacci<apa::bint>(-1);
    std::cout<<"fib of -1th term   = "<<fibb<<"\n";
    std::cout<<"string form        = "<<fibb.string_form()<<"\n\n";
    if(fibb.string_form()!="-1")
    {
        throw std::logic_error("the fib of -1th term is wrong");
    }

    apa::bint fibc = Fibonacci<apa::bint>(-50);
    std::cout<<"fib of -50th term  = "<<fibc<<"\n";
    std::cout<<"string form        = "<<fibc.string_form()<<"\n\n";
    if(fibc.string_form()!="-12586269025")
    {
        throw std::logic_error("the fib of -50th term is wrong");
    }

    apa::bint fibd = Fibonacci<apa::bint>(-125);
    std::cout<<"fib of -125th term = "<<fibd<<"\n";
    std::cout<<"string form        = "<<fibd.string_form()<<"\n\n";
    if(fibd.string_form()!="-59425114757512643212875125")
    {
        throw std::logic_error("the fib of -0th term is wrong");
    }

    apa::bint fibe = Fibonacci<apa::bint>(-250);
    std::cout<<"fib of -250th term = "<<fibe<<"\n";
    std::cout<<"string form        = "<<fibe.string_form()<<"\n\n";
    if(fibe.string_form()!="-7896325826131730509282738943634332893686268675876375")
    {
        throw std::logic_error("the fib of -250th term is wrong");
    }

    apa::bint fibf = Fibonacci<apa::bint>(-4791);
    std::cout<<"fib of -4791th term = "<<fibf<<"\n";
    std::cout<<"\nstring form         = "<<fibf.string_form()<<"\n\n";
    if(fibf.string_form()!="-81339113627586038220075190055247789192880568618630451707018330137861517389158662600956996694846174589801469761512161313215689806905310862985024337939085870965238560635970957792660824904392047271094122294793272484563464072049275313738096650483261684061366405464337657087693955674365623243244313144555525734930847697924533371594078067471044085863078048666920758081314479926308697764627559698033104575510557171344869183739238830679557713527392771191576405457289994077481332719403213634424769607167748620818075825244885846435557980209966356282547711846517397448804387979462291291567084251103673083221868154825314856311929454870166455136775912287273068264359301319801383022153785801110046531437989315467648852308299147172496144333940023447276613167612884771436229672376790405385432747154491541992332127813197768675502425697687895826665267674543412303600098536011986692552057857548702420851052304543203400542443453837366673606205740550355224688965493278830040099542233431719451611889064817728030544594803234")
    {
        throw std::logic_error("the fib of -4791th term is wrong");
    }

    std::cout<<"ALL OUTPUTS ARE CORRECT\n\n";

    return 0;
}