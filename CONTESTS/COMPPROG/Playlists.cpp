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

ll Playlists()
{
    ll n;
    cin >> n;

    vector<ll> playlists(n);

    forn(i, n)
    {
        cin >> playlists[i];
    }

    set<ll> seen;
    ll i = 0;
    ll max_len = 0;

    forn(j, n)
    {
        while (seen.count(playlists[j]))
        {
            seen.erase(playlists[i]);
            i++;
        }

        seen.insert(playlists[j]);
        max_len = max(max_len, j - i + 1);
    }

    cout << max_len;
    return max_len;
}

int main()
{
    Playlists();
    return 0;
}
