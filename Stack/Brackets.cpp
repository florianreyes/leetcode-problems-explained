#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<int> num_s;
    stack<string> str_s;
    string curr_str = "";
    int cur_num;
    for (auto elem : s)
    {
        if (isdigit(elem))
        {
            cur_num = cur_num * 10 + (elem - '0');
        }
        else if (elem == '[')
        {
            num_s.push(cur_num);
            str_s.push(curr_str);

            cur_num = 0;
            curr_str = "";
        }
        else if (elem == ']')
        {
            int amount_times = num_s.top();
            num_s.pop();

            string temp = curr_str;
            curr_str = str_s.top();
            str_s.pop();

            while (amount_times > 0)
            {
                curr_str += temp;
                amount_times--;
            }
        }
        else
        {
            curr_str += elem;
        }
    }
    return curr_str;
}

int main()
{
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;
    return 0;
}