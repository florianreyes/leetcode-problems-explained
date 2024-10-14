#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)
#define fore(i, s, n) forsn(i, s, n)

void dfs(int node, std::vector<vector<int>> graph, std::vector<int> &states, std::vector<int> &ts)
{
    states[node] = 1;
    for (auto neigh : graph[node])
    {
        if (states[neigh] == 1)
        {
            std::cout << "ciclo";
            return;
        }
        else if (states[neigh] == 0)
        {
            dfs(neigh, graph, states, ts);
        }
        else
        {
            continue;
        }
    }
    states[node] = 2;
    ts.push_back(node);
}

std::vector<int> TopologicalSort(std::vector<vector<int>> graph)
{

    std::vector<int> states(graph.size(), 0);
    std::vector<int> ts = {};

    dfs(1, graph, states, ts);

    // forn(i, states.size())
    // {
    //     std::cout << "ITERACION " << i << "\n";
    //     forn(j, states.size())
    //     {
    //         std::cout << states[j];
    //     }
    //     if (states[i] == 0)
    //     {
    //         dfs(i, graph, states, ts);
    //     }
    // }
    std::reverse(ts.begin(), ts.end());
    return ts;
}

int main()
{
    std::vector<vector<int>> graph = {{1, 2}, {3}, {3, 4}, {4}, {5}, {}};
    std::vector<int> result = TopologicalSort(graph);

    for (auto elem : result)
    {
        std::cout << elem << "\n";
    }
}
