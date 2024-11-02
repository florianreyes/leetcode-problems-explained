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

int main()
{
    string name;

    while (cin >> name)
    {
        bool found = false;

        for (char c : name)
        {
            if (c == 'i' || c == 'I')
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "N" << e;
        }
        else
        {
            cout << "S" << e;
        }
    }

    return 0;
}
