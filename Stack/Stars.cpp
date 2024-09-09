// The idea is to us the stack to remove all the stars from the string.
// We can use the stack to remove the stars from the string.

#include <stack>
#include <string>

using namespace std;

string removeStars(string s)
{
    stack<char> chr_stck;
    string res;
    for (char c : s)
    {
        if (c != '*')
        {
            chr_stck.push(c);
        }
        else
        {
            chr_stck.pop();
        }
    }
    while (!chr_stck.empty())
    {
        res += chr_stck.top();
        chr_stck.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
