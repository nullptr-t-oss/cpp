#include <iostream>
#include <set>
#include <sstream>

template <typename T>
void print_set(const std::set<T>& s)
{
    std::stringstream ss;
    ss << "{ ";
    for(const auto& a: s)
    {
        ss << a << " ";
    }
    ss << "}";
    std::cout << ss.str() << "\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::set<int> s;
    std::multiset<int> ms;

    s.insert(1);
    s.insert(2);
    s.insert(3);

    s.erase(2); /* this is safe */

    /* this is not safe since find() returns an iterator, when element to be removed not in  set
     * it returns s.end() which is the memory region after last element of set; and erase expects
     * a valid pointer, so doing this will result in undefined behaviour and crash the program
     */
    /* s.erase(s.find(9));   */

    auto it = s.find(9);
    if(it != s.end())
        s.erase(it);
    else
        std::cout << "elm not present\n";

    print_set(s);


    return 0;
}
