// Explanation:
// The idea is to start with the maximum width and then move the pointer with the smaller height
// towards the other pointer, updating the area if a larger area is found.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{

    int left = 0;
    int right = height.size() - 1;
    int area = 0;

    while (left < right)
    {
        int curr_area = (right - left) * min(height[right], height[left]);
        area = max(area, curr_area);
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    std::cout << result << std::endl;
    return 0;
}