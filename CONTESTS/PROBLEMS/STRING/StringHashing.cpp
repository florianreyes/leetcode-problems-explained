#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, ThxDem = b; i < ThxDem; ++i)
using namespace std;
typedef long long ll;

const double EPS = 1e-4;

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
    string s1, s2;
    cin >> s1 >> s2;
    int sz1 = s1.size();
    int sz2 = s2.size();

    Hash H1(s1);
    Hash H2(s2);

    int count = 0;
    for (int i = 0; i <= sz1 - sz2; i++)
    {
        if (H2.get(0, sz2) == H1.get(i, i + sz2))
        {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}