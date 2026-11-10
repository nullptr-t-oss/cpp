#include <iostream>
#include <vector>
#include <algorithm>

int main([[maybe_umused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::vector<int> a = { 5, 2, 8, 9, 4 };
    std::vector<int> b = { 3, 2, 9, 5 };

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i{0}, j{0}, c{0};
    for (; i < a.size() && j < b.size() ;)
    {
        if (a[i] == b[j]) {
            c++;
            i++;
            j++;
        } else if ( a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
            
    }

    std::cout << c << "\n";
    
    return 0;
}
