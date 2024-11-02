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

    // Sorteo segmetos a medida que empiezan para ir sumando al coverage
    sort(segs.begin(), segs.end());

    // Arranco cubriendo cero puntos
    int cubre = 0;
    // Empiezo en el primer inicio de segmento
    int ultima = segs[0].first;
    vector<int> res(n + 1, 0);

    forn(i, n)
    {
        // me fijo el siguiente evento, ya sea inicio o fin
        ll pos = segs[i].first;
        ll valor = segs[i].second;

        // Si avance posiciones veo cuantos puntos abarco bao este nivel de coverage
        if (pos != ultima)
        {
            ll puntos = pos - ultima;
            // Con este nivel de coverage veo cuantos puntos abarco
            res[cubre] += puntos;
        }
        // Actualizo la posicion a la ultima vista
        ultima = pos;
    }
    // Le resto(o sumo) al coverage en base a si termine un intervalo o arranque otro nuevo.
    cubre += valor;
}