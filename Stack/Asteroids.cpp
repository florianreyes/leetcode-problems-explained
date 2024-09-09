#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> s;
    for (auto ast : asteroids)
    {
        bool destroyed = false;

        while (!s.empty() && ast < 0 && s.top() > 0)
        {
            if (abs(s.top()) < abs(ast))
            {
                s.pop();
            }
            else if (abs(s.top()) == abs(ast))
            {
                s.pop();
                destroyed = true;
                break;
            }
            else
            {
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
        {
            s.push(ast);
        }
    }
    vector<int> res;
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }

    reverse(res.begin(), res.end());
    return res;
};