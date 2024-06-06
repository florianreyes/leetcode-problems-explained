#include <string>
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