#include <iostream>
#include <vector>
#include <map>
#include <sstream>

template <typename T>
void print_vector(const std::vector<std::vector<T>>& v)
{  
    std::stringstream ss;
    ss << "{ ";
    for (const auto& a : v)
    {
        ss << "{ ";
        for(const auto& b: a)
            ss << b << " ";
        ss << "} ";
    }
    ss << "} ";
    std::cout << ss.str() << "\n";
    
}

int main([[maybe_unused]] int argc,[[maybe_unused]] char const *argv[])
{
    std::vector<int> v = { 0, 1, 3 };
    std::vector<std::vector<int>> subsets;
    std::map<int, int> m;

    for (size_t i = 0; i < v.size(); i++)
    {
        m[i] = v[i];
    }

    /* with n bits we can represent 2^n different combinations 
     * which is exactly equal to the number of subsets
     *
     * also note that numbers from 1..2^n are unique, and hence
     * each must represent an unique combination of 1's and 0's in
     * binary
     * 
     * also for each subset, for each element, we have two choices
     * either include that element or exclude it ; and in the set of
     * all possible subsets we must have a unique comination of this
     * inclusion and exclusion of all elements
     * 
     * which is exactly like bit representation of a number; a number
     * in binary is composed of bits, which can be either 1 or 0, we
     * can map it to whether we should include or exclude a specific
     * element
     * 
     * since we noted earlier that every number from 1...2^n has a unique
     * combination of 1's and 0's, each number forms an unique subset
     */
    for (size_t i = 0; i < (1 << v.size()); i++) 
    {
        std::vector<int> s;

        /* sweep through all n bits and decide whether to include 
         * or exclude b'th element dictated by the bit value at index
         * b; could have used bitset ? 
         * then :
         *   std::bitset<32> b(i);
         *   for (size_t bit = 0; bit < v.size(); bit++)
         *      if (b[bit]) s.push(m[bit]);
         */
        for(size_t b = 0; b < v.size(); b++)
            if (i & (1 << b)) s.push_back(m[b]);
        
        subsets.push_back(s);
    }

    print_vector(subsets);
    
    return 0;
}
