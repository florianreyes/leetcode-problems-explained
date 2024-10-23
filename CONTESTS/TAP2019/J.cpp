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

#define e "\n"

int main()
{
    int N, D;
    cin >> N >> D;

    vector<int> roquefort(N);
    vector<int> caminos(N);

    // Read roquefort availability
    forn(i, N)
    {
        cin >> roquefort[i];
    }

    // Read caminos (paths)
    forn(i, N)
    {
        cin >> caminos[i];
        caminos[i]--; // Converting 1-based indexing to 0-based indexing
    }

    // Initialize a string to hold the maximum binary value found
    string max_binary(D, '0');

    // Traverse each starting table
    forn(i, N)
    {
        int current = i;
        string current_binary(D, '0');
        int d = 0;

        // Traverse the path of length exactly D
        while (d < D && current != -1)
        {
            current_binary[d] = (roquefort[current] == 1) ? '1' : '0';
            current = caminos[current];
            d++;
        }

        // If we successfully created a path of length D, compare binary values
        if (d == D && current_binary > max_binary)
        {
            max_binary = current_binary;
        }
    }

    // Print the result
    cout << max_binary << e;
}
