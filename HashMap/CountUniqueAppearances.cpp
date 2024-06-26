// The idea is to iterate over the array and count the appearances of each number using tha hashmap
// Then we iterate over the hashmap and check if the number of appearances is already in the set of unique appearances

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool uniqueOccurrences(std::vector<int> &arr)
{

    std::unordered_map<int, int> apps;
    std::unordered_set<int> uniques;
    for (int &num : arr)
    {
        apps[num]++;
    }
    for (std::pair<int, int> appearances : apps)
    {
        if (std::find(uniques.begin(), uniques.end(), appearances.second) != uniques.end())
        {
            return false;
        }
        uniques.insert(appearances.second);
    }
    return true;
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 1, 1, 3};
    uniqueOccurrences(arr);
    return 0;
}
