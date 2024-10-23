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
    int n;
    cin >> n;

    int currf = 0;
    set<int> beds;

    forsn(i, 1, 2 * n)
    {
        currf = ((currf + i) % n);
        beds.insert(currf);
    }
    if (SZ(beds) == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
