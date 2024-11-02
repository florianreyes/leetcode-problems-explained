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

int find_largest_pos(vector<int> v)
{
    int index = 0;
    forn(i, v.size())
    {
        if (v[index] < v[i])
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    int N, K;
    while (cin >> N >> K)
    {
        vector<int> camino(K);
        forn(i, K)
        {
            cin >> camino[i];
        }

        int raiz = find_largest_pos(camino);
        bool vr = true;
        for (int i = raiz; i < K - 1; i++)
        {
            if (camino[i] == 2 || camino[i] == 1)
            {
                vr = false;
            }
            if (camino[i + 1] != camino[i] - 1 && camino[i + 1] != camino[i] - 2)
            {
                vr = false;
            }
        }

        for (int i = raiz; i > 0; i--)
        {
            if (camino[i] == 2 || camino[i] == 1)
            {
                vr = false;
            }
            if (camino[i - 1] != camino[i] - 1 && camino[i - 1] != camino[i] - 2)
            {
                vr = false;
            }
        }

        if (raiz < K - 1 && raiz > 0 && vr)
        {
            vr = camino[raiz - 1] != camino[raiz + 1];
        }

        if (vr)
        {
            cout << "S" << e;
        }
        else
        {
            cout << "N" << e;
        }
    }
}