#include <iostream>
#include <algorithm>
#include <vector>

int main([[maybe_unused]] int argc ,[[maybe_unused]] char const *argv[] )
{
    int arr[] = { -1, 2, 2, 4, -3, 5, -5, 2 };

    int curr = 0, max = 0;
    size_t size = sizeof(arr)/sizeof(arr[0]);
    std::vector<std::vector<int>> v;

    for (size_t i = 0; i < size; i++)
    {

        /* caclulate if subarray starts at current element or continues
         * curr = std::max(arr[i], curr + arr[i]);
         * 
         * new subarray is only started when curr + arr[i] <= arr[i] ; or curr <= 0 (subtracting arr[i] on both sides)
         * so if curr < 0 ; start a new max sub array which may or may not yield the global max sum but is sure to
         * yield a local max sum
         * 
         * note: we did less than 'equal to' because we want sub array to min length giving max sum
         * e.g. : { 2, -2, 4 } and { 4 } ; both yields same sum but we need the second one ;
         * 
         * else continue sub array
         */
        if(curr <= 0 ) {
            v.push_back({arr[i]}); /* start new sub array */
            curr = arr[i];
        } else {
            v.back().push_back(arr[i]); /* push elements into old sub array */
            curr += arr[i];
        }

        /* calculate the sum of the subarrays that is maximum*/
        max = std::max(curr, max);
    }

    int sub = 0; /* sub array counter */
    for(const auto& a: v) {
        std::cout << "subarray " << sub++ << " : { ";
        for(const auto b: a) {
            std::cout << b << " " ;
        }
        std::cout << "}\n";
    }

    std::cout << "\nmax: " << max << '\n';

    return 0;
}
