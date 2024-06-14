// Explanation: Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array.
// Return 0 if there is no such subarray.

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int longestSubarray(vector<int> &nums)
{
    int left = 0;
    int max_len = 0;
    int curr_zeros = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
        {
            curr_zeros++;
        }
        while (curr_zeros > 1)
        {
            if (nums[left] == 0)
            {
                curr_zeros--;
            }
            left++;
        }
        max_len = std::max(max_len, (right - left));
    }
    return max_len;
}

int main()
{
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int result = longestSubarray(nums);
    std::cout << result << std::endl;
    return 0;
}