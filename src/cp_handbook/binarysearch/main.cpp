#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    std::vector<int> v = { 2, 3, 3, 4, 5, 5, 8 };

    int key = 3, idx = 0;

    /*
     * here i acts as a step size, like in the typical implementation where we
     * discard half of our search space at each iteration, here i acts as the step
     * size that discard half of our search space every time;
     * 
     * here idx itself acts as the final answer and the left limit of our search space
     * the right bound is virtual/implicit
     * 
     * because lets say our array is [a...k...b] where a, k and b are the starting, middle
     * and ending elemnts respectively, lets say our answer(key) lies in the region [a...k]
     * then in our first iteration right bound should be {(index of k) - 1}
     * and l should remain as is
     * 
     * in first iteration our step size (i) is half the size of array
     * notice that arr[idx + i] > key since idx + i in this iteration equals to k and from our
     * first assumption key lies in region a...k
     * 
     * so idx(left bound) is never incremented;
     * also note that now step size reduces to 1/4 th; hence no matter what we wont cross k
     * 
     * reasion: lets say [a...m...k] , and our key lies in region [m...k]
     * then in our first iteration of while loop and 2nd iteration of for loop , we increment by 
     * idx + 1/4th size of array and we cross m (arr[idx + i] <= key is true since idx + i now points
     * to m and we have already assumed that anwer lies in reion [m...k])
     * 
     * hence idx is now at index of element m; not we try to add i again to idx, the check arr[idx + i] <= key
     * will fail since now idx + i will point to k and we know that k >= arr[idx + i] and hence we never crossed
     * the right bound
     * 
     * one disadvantage, after calculating idx, if we want -1 for not found, we need to manually check and modify
     * idx after idx is calculated
     * 
     * also note that this is not an O(n^2) algorithm, since in while loop we do at most 2 iterations
     */
    for (size_t i = v.size()>>1; i >= 1; i >>= 1)
    {
        while (v[idx + i] <= key && idx + i < v.size())
        {
            idx += i;
        }
        
    }

    std::cout << idx ;
    

    return 0;
}
