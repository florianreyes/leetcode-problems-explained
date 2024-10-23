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

float eucdist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> circs(n, vector<int>(3));
    forn(i, n)
    {
        cin >> circs[i][0] >> circs[i][1] >> circs[i][2];
    }
    bool yes = true;

    forn(i, n)
    {
        forsn(j, i + 1, n)
        {
            float euc = eucdist(circs[i][0], circs[i][1], circs[j][0], circs[j][1]);

            if (euc - circs[i][2] - circs[j][2] <= 0)
            {
                // si radio del prim es mas chico
                if (circs[i][2] < circs[j][2])
                {
                    if (euc + circs[i][2] >= circs[j][2])
                    {
                        yes = false;
                        break;
                    }
                }
                // si radio del seg es mas chico
                else if (circs[j][2] < circs[i][2])
                {
                    // Si no esta adentro
                    if (euc + circs[j][2] >= circs[i][2])
                    {
                        yes = false;
                        break;
                    }
                }
                else
                {
                    yes = false;
                    break;
                }
            }
        }
        if (!yes)
        {
            break;
        }
    }
    if (yes)
    {
        cout << "SI" << e;
    }
    else
    {
        cout << "NO" << e;
    }
}
