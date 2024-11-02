#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)
#define fore(i, s, n) forsn(i, s, n)

#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define ll long long
#define e "\n"

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

template <class x>
ostream &operator<<(ostream &out, vector<x> v)
{
    out << "[ ";
    for (auto y : v)
        out << y << " ";
    out << "]";
    return out;
}

int main()
{
    int N, L, C;
    while (cin >> N >> L >> C)
    {
        vector<int>
            tests(N);
        forn(i, N)
        {
            cin >> tests[i];
        }

        sort(tests.rbegin(), tests.rend());
        int sum_first_row = 0;

        for (int i = 0; i < N; i += L)
        {
            sum_first_row += tests[i];
        }

        if (sum_first_row <= C)
        {
            cout << "S" << e;
        }
        else
        {
            cout << "N" << e;
        }
    }
}