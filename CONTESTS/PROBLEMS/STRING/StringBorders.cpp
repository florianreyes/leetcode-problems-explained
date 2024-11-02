#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, ThxDem = b; i < ThxDem; ++i)
using namespace std;
typedef long long ll;

const double EPS = 1e-4;

template <class x>
ostream &operator<<(ostream &out, vector<x> v)
{
    // out << "[ ";
    for (auto y : v)
        out << y << " ";
    // out << "]";
    return out;
}

struct Hash
{
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash(string &s)
    {
        MOD[0] = 999727999;
        MOD[1] = 1070777777;
        PI[0] = 325255434;
        PI[1] = 10018302;
        fore(k, 0, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        fore(k, 0, 2)
        {
            h[k][0] = 0;
            pi[k][0] = 1;
            ll p = 1;
            fore(i, 1, s.size() + 1)
            {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    ll get(int s, int e)
    {
        ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        return (h0 << 32) | h1;
    }
};

int main()
{
    string s1;
    cin >> s1;
    int sz1 = s1.size();

    Hash H1(s1);
    vector<int> lengths;
    for (int i = 1; i < sz1; i++)
    {
        if (H1.get(0, i) == H1.get(sz1 - i, sz1))
        {
            lengths.pb(i);
        }
    }
    cout << lengths;
    return 0;
}
