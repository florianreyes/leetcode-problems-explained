// Explanation:
// The idea is to iterate through the string t and check if the current character is equal to the character
// in the string s. If it is, we increment the pointer for s. If the pointer for s reaches the end of the string,
// we return true. If we reach the end of the string t, we return false.
// This is because if we reach the end of t, we have not found all the characters in s.

#include <string>
#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{

    if (s.size() == 0)
    {
        return true;
    }

    size_t ptrs = 0;
    size_t ptrt = 0;

    while (ptrt < t.size())
    {
        if (t[ptrt] == s[ptrs])
        {
            ptrs++;

            if (ptrs == s.length())
            {
                return true;
            }
        }
        ptrt++;
    }
    return false;
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";
    bool result = isSubsequence(s, t);
    std::cout << result << std::endl;
    return 0;
}