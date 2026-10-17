#include <iostream>
#include <string>

long long fast_exp(long long a, long long b)
{
    if(!b)
        return 1;
    
    long long res {1};

    while(b){
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
    
}

int main([[maybe_unused]] int argc, char const *argv[])
{
    std::cout << fast_exp(std::stoll(argv[1]), std::stoll(argv[2]));
    return 0;
}
