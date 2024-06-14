// Explanation:
// The idea is to iterate through the vector nums and calculate the sum of the first k elements.
// We then iterate through the rest of the vector, updating the sum by adding the new element and subtracting
// the element that is no longer in the window. We keep track of the maximum sum and return the average.

#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{

    if (nums.size() < k)
    {
        return 0;
    }

    int curr_sum = 0;
    for (size_t i = 0; i < k; i++)
    {
        curr_sum += nums[i];
    }

    int max_sum = curr_sum;
    for (size_t i = k; i < nums.size(); i++)
    {
        curr_sum -= nums[i - k];
        curr_sum += nums[i];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum / (double)k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, k);
    std::cout << result << std::endl;
    return 0;
}