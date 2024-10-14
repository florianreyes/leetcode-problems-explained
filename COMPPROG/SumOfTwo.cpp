#include <iostream>
#include <vector>
#include <string>
using namespace std;

string SumOfTwo()
{
    int n, s;
    cin >> n >> s;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (n == 1)
    {
        if (nums[0] == s)
        {
            return "1";
        }
        return "-1";
    }

    vector<int> ncop = nums;
    sort(ncop.begin(), ncop.end());

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        if (nums[l] + nums[r] > s)
        {
            r--;
        }
        else if (nums[l] + nums[r] < s)
        {
            l++;
        }
        else
        {
            cout << nums[l] << nums[r];
            return to_string(nums.at(ncop[])) + " " + to_string(r);
        }
    }

    return "IMPOSSIBLE";
}

int main()
{
    cout << SumOfTwo() << endl;
    return 0;
}