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

void dfs(int materia, vector<vector<int>> &desbloquea, vector<bool> &aprobadas, vector<int> &indeg, int &couteadas)
{
    couteadas++;
    for (auto neigh : desbloquea[materia])
    {
        indeg[neigh]--;
        if (indeg[neigh] == 0 && aprobadas[neigh])
        {
            dfs(neigh, desbloquea, aprobadas, indeg, couteadas);
        }
    }

    return;
}

int main()
{
    int N, M;
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (cin >> N >> M)
    {

        vector<int> indeg(N, 0);
        vector<vector<int>> desbloquea(N);
        forn(i, M)
        {
            int a, b;
            cin >> a >> b;
            indeg[b - 1]++;
            desbloquea[a - 1].push_back(b - 1);
        }
        vector<bool> aprobada(N, false);
        int couteadas = 0;

        forn(i, N)
        {
            int materia;
            cin >> materia;
            materia--;

            aprobada[materia] = 1;
            if (indeg[materia] == 0)
            {
                dfs(materia, desbloquea, aprobada, indeg, couteadas);
            }
            cout << couteadas << e;
        }
    }

    return 0;
}
