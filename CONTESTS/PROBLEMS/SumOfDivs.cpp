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
    ll MOD = 1e9 + 7;

    ll n;
    cin >> n;

    ll sum = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                sum += i;
                sum += n / i;
            }
            else
            {

                sum += i;
            }
        }
    }
    cout << sum % MOD;
}