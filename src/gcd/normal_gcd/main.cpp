#include <iostream>
#include <string>
#include <numeric>

int main(int argc __attribute_maybe_unused__, char const *argv[])
{
    std::cout << std::gcd(static_cast<unsigned int>(std::stoul(argv[1])), static_cast<unsigned int>(std::stoul(argv[2])));
    return 0;
}
