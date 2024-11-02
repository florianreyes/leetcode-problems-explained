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

void procesar_palabra(string curr, int &count, int &cantidad_abre, int &cantidad_cierra, int &c_abre_cierra)
{
    // -1 si nada, 0 si abre, 1 si cierra, 2 si cierra-abre, 3 si abre-cierra
    int last = -1;
    for (char c : curr)
    {
        if (c == 'D')
        {
            if (last == -1 || last == 3)
            {
                last = 0;
            }
            else if (last == 1)
            {
                last = 2;
            }
        }
        else if (c == 'R')
        {
            if (last == -1)
            {
                last = 1;
            }
            else if (last == 0)
            {
                count++;
                last = 3;
            }
            else if (last == 2)
            {
                count++;
                last = 1;
            }
        }
    }
    if (last == 2)
    {
        c_abre_cierra++;
    }
    else if (last == 1)
    {
        cantidad_cierra++;
    }
    else if (last == 0)
    {
        cantidad_abre++;
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        int count = 0;
        int c_abre = 0;
        int c_cierra = 0;
        int c_cierra_abre = 0;
        forn(i, N)
        {
            string curr;
            cin >> curr;
            procesar_palabra(curr, count, c_abre, c_cierra, c_cierra_abre);
        }
        if (c_cierra_abre)
        {
            count += c_cierra_abre - 1;
            if (c_abre or c_cierra)
            {
                c_abre++;
                c_cierra++;
            }
        }
        count += min(c_cierra, c_abre);

        cout << count << e;
    }
}