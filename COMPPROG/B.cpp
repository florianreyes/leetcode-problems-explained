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
    int q;
    cin >> q;

    double petals = 0;
    double fl = 0;
    char curr;
    int currp;

    forn(i, q)
    {
        cin >> curr;
        if (curr == 'R')
        {
            cin >> currp;
            petals += currp;
            fl++;
        }
        else
        {
            cout << fixed;
            cout << setprecision(10) << petals / fl << endl;
        }
    }

    return 0;
}
