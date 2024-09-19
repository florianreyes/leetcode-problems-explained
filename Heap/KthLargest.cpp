#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{

    make_heap(nums.begin(), nums.end());
    int curr_biggest_elem{};
    for (size_t i = 0; i < k; i++)
    {
        curr_biggest_elem = nums.front();
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return curr_biggest_elem;
}

int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = findKthLargest(nums, k);
    return 0;
}

// The idea is to use the make_heap function to create a max heap from the vector
// Then we iterate k times and pop the top element from the heap
// The top element of the heap is the largest element in the heap
// After popping the top element, we pop the element from the vector
// Finally, we return the kth largest element