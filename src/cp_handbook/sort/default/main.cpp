#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct vec2 {
    int i, j;
    friend bool operator<(const vec2& curr, const vec2& next) {
        return std::sqrt(std::pow(curr.i, 2) + std::pow(curr.j, 2)) <= std::sqrt(std::pow(next.i, 2) + std::pow(next.j, 2));
    }

    friend std::ostream& operator<<(std::ostream& os, const vec2& v) {
        os << "(" <<  v.i << ", " << v.j << ")";
        return os;
    }
};

template <typename T>
void print_vec(const std::vector<T>& v) {
    std::cout << "{ ";
    for (const auto& a: v)
    {
        std::cout << a << " ";
    }
    std::cout << "}\n";
    
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::vector<int> v = {4,2,5,3,5,8,3};

    std::sort(v.begin(), v.end());
    print_vec(v);

    /* reverse */
    std::sort(v.rbegin(), v.rend());
    print_vec(v);

    /* array sorting */
    int arr[] = {4,2,5,3,5,8,3};
    int n = 7;

    std::sort(arr, arr + n);
    std::cout << "{ ";
    for(size_t i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << "}\n";

    /* reverse */
    /* std::reverse(arr, arr + n) */
    std::sort(arr, arr + n, std::greater<int>());
    print_vec(v);

    std::vector<vec2> vecs = {{1, 0}, {1, 2}};
    std::sort(vecs.begin(), vecs.end());
    print_vec(vecs);

    return 0;
}
