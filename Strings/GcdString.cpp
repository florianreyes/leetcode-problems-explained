#include <string>
using namespace std;

int gcd_st(int s1, int s2)
{
    if (s2 == 0)
    {
        return s1;
    }
    return gcd_st(s2, s1 % s2);
}
string gcdOfStrings(string str1, string str2)
{
    size_t gcd_size{};
    if ((str1 + str2) != (str2 + str1))
    {
        return "";
    }
    else
    {
        size_t s1 = str1.size();
        size_t s2 = str2.size();

        if (s1 > s2)
        {
            gcd_size = gcd_st(s1, s2);
        }
        else
        {
            gcd_size = gcd_st(s2, s1);
        }
    }
    return str1.substr(0, gcd_size);
}

int main()
{
    string str1 = "ABCABC";
    string str2 = "ABC";
    string result = gcdOfStrings(str1, str2);
    return 0;
}

// The idea is to find the greatest common divisor of the lengths of the two strings
// If the two strings concatenated are not equal to each other, then return an empty string
// Otherwise, return the substring of the first string from 0 to the gcd of the lengths of the two strings
// The time complexity is O(n) where n is the length of the first string