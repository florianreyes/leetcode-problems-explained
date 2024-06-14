// Explanation:
// The idea is to initialize a left pointer and iterate with the right one
// While the amount of zeros within our array is less than k, we increment the right pointer
// If the amount of zeros is greater than k, we increment the left pointer while subtracting from the zero counter until we cna continue
// We keep track of the maximum count as (right - left + 1) and return it

#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int> &nums, int k)
{

    int left = 0;
    int max_count = 0;
    int zero_count = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
        {
            zero_count++;
        }
        while (zero_count > k)
        {
            if (nums[left] == 0)
            {
                zero_count--;
            }
            left++;
        }
        max_count = std::max(max_count, right - left + 1);
    }
    return max_count;
}

int main()
{

    vector<int> nums = {1, 0, 1, 1, 0, 1};
    int k = 2;
    int result = longestOnes(nums, k);
    std::cout << result << std::endl;

    return 0;
}
