// Explanation:
// The idea is to iterate through the string s and count the number of vowels in the first k characters.
// We then iterate through the rest of the string, updating the count of vowels by adding the new character
// and subtracting the character that is no longer in the window. We keep track of the maximum number of vowels

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxVowels(string s, int k)
{

    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int vowel_curr = 0;
    for (size_t i = 0; i < k; i++)
    {
        if (std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
        {
            vowel_curr++;
        }
    }
    int max_vowel = vowel_curr;
    for (size_t i = k; i < s.size(); i++)
    {
        if (std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
        {
            vowel_curr++;
        }
        if (std::find(vowels.begin(), vowels.end(), s[i - k]) != vowels.end())
        {
            vowel_curr--;
        }

        max_vowel = std::max(max_vowel, vowel_curr);
    }
    return max_vowel;
}

int main()
{
    string s = "abciiidef";
    int k = 3;
    int result = maxVowels(s, k);
    std::cout << result << std::endl;
    return 0;
}