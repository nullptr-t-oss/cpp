#include <iostream>
#include <cmath>

int main([[maybe_unused]] int argc, char const *argv[])
{
    std::cout << std::pow(std::stoll(argv[1]), std::stoll(argv[2]));
    return 0;
}
