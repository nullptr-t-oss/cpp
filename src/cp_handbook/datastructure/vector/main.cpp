#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
void print_vec(const std::vector<T>& v)
{
    std::stringstream ss;
    ss << "{ ";
    for(const auto& a: v)
    {
        ss << a << " ";
    }

    std::cout << ss.str() << "}\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::vector<int> v(10, 2); /* vector of 10 elements with default value of 2 */
    print_vec(v);
    return 0;
}
