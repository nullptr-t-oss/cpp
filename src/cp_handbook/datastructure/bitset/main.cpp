#include <iostream>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>

using ull = unsigned long long;

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    ull x{};
    std::cout << "enter a number : " ;
    std::cin >> x;
    std::bitset<10> b(x);

    /* binary representation */
    std::cout << "bit representation: " << b << "\n";
    /* LSB */
    std::cout << "LSB: " << b[0] << "\n";
    /* MSB */
    std::cout << "MSB: " << b[b.size() - 1] << "\n";
    return 0;
}
