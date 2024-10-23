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

    vector<pair<int, int>> segs;

    int i, d;
    forn(i, n)
    {
        cin >> i >> d;
        // Cada vez que empieza un segmento, voy a estar sumando uno a la cantidad de puntos que cubre
        segs.pb(mp(i, 1));
        segs.pb(mp(d + 1, -1));
    }

    sort(segs.begin(), segs.end());

    int cubre = 0;
    int ultima = segs[0].first;
    vector<int> res(n + 1, 0);

    forn(i, n)
    {
        ll pos = segs[i].first;
        ll valor = segs[i].second;

        if (pos != ultima)
        {
            ll puntos = pos - ultima;
            res[cubre] += puntos;
        }
        ultima = pos;
    }
    cubre += valor;
}