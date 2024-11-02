// // #include <bits/stdc++.h>
// // using namespace std;

// // #define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
// // #define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
// // #define forn(i, n) forsn(i, 0, n)
// // #define dforn(i, n) dforsn(i, 0, n)
// // #define fore(i, s, n) forsn(i, s, n)

// // void dfs(int node, std::vector<vector<int>> graph, std::vector<int> &states, std::vector<int> &ts)
// // {
// //     states[node] = 1;
// //     for (auto neigh : graph[node])
// //     {
// //         if (states[neigh] == 1)
// //         {
// //             std::cout << "ciclo";
// //             return;
// //         }
// //         else if (states[neigh] == 0)
// //         {
// //             dfs(neigh, graph, states, ts);
// //         }
// //         else
// //         {
// //             continue;
// //         }
// //     }
// //     states[node] = 2;
// //     ts.push_back(node);
// // }

// // std::vector<int> TopologicalSort(std::vector<vector<int>> graph)
// // {

// //     std::vector<int> states(graph.size(), 0);
// //     std::vector<int> ts = {};

// //     forn(i, states.size())
// //     {
// //         forn(j, states.size())
// //         {
// //             std::cout << states[j];
// //         }
// //         if (states[i] == 0)
// //         {
// //             dfs(i, graph, states, ts);
// //         }
// //     }
// //     std::reverse(ts.begin(), ts.end());
// //     return ts;
// // }

// // int main()
// // {
// //     std::vector<vector<int>> graph = {{1, 2}, {3}, {3, 4}, {4}, {5}, {}};
// //     std::vector<int> result = TopologicalSort(graph);

// //     for (auto elem : result)
// //     {
// //         std::cout << elem << "\n";
// //     }
// // }

#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)
#define fore(i, s, n) forsn(i, s, n)

bool hasCycle = false;

void dfs(int node, const vector<vector<int>> &graph, vector<int> &states, vector<int> &ts)
{
    states[node] = 1;
    for (int neigh : graph[node])
    {
        if (states[neigh] == 1)
        {
            hasCycle = true;
            return;
        }
        if (states[neigh] == 0)
        {
            dfs(neigh, graph, states, ts);
        }
    }
    states[node] = 2;
    ts.push_back(node);
}

vector<int> TopologicalSort(const vector<vector<int>> &graph)
{
    vector<int> states(graph.size(), 0);
    vector<int> ts;

    forn(i, graph.size())
    {
        if (states[i] == 0)
        {
            dfs(i, graph, states, ts);
            if (hasCycle)
            {
                cout << "Cycle detected.\n";
                return {};
            }
        }
    }
    reverse(ts.begin(), ts.end());
    return ts;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
// #define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
// #define forn(i, n) forsn(i, 0, n)
// #define dforn(i, n) dforsn(i, 0, n)
// #define fore(i, s, n) forsn(i, s, n)

// const int kMaxN = 100010; // Define a value for kMaxN
// vector<int> g(kMaxN);
// vector<int> states(kMaxN, 0);
// vector<int> ts;

// bool hasCycle = false;

// void dfs(int node, const vector<vector<int>> &graph, vector<int> &states, vector<int> &ts)
// {
//     states[node] = 1;
//     for (int neigh : graph[node])
//     {
//         if (states[neigh] == 1)
//             hasCycle = true; // Check for cycles here
//         if (states[neigh] == 0)
//             dfs(neigh, graph, states, ts);
//     }
//     states[node] = 2; // Push the node to the result vector here
//     ts.push_back(node);
// }

// vector<int> TopologicalSort(const vector<vector<int>> &graph)
// {
//     vector<int> states(graph.size(), 0);
//     vector<int> ts;

//     forsn(i, 0, graph.size())
//     {
//         if (states[i] == 0)
//         {
//             dfs(i, graph, states, ts);
//             if (hasCycle)
//             {
//                 cout << "Cycle detected.\n";
//                 return {};
//             }
//         }
//     }
//     return reversed(ts); // The resulting topological sort is stored in reversed order
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
// #define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
// #define forn(i, n) forsn(i, 0, n)
// #define dforn(i, n) dforsn(i, 0, n)
// #define fore(i, s, n) forsn(i, s, n)

// bool hasCycle = false;

// void dfs(int node, const vector<vector<int>> &graph, vector<int> &states, vector<int> &ts)
// {
//     states[node] = 1;
//     for (int neigh : graph[node])
//     {
//         if (states[neigh] == 1)
//         {
//             return;
//         }
//         if (states[neigh] == 0)
//         {
//             dfs(neigh, graph, states, ts);
//             if (hasCycle)
//                 return;
//         }
//     }
//     states[node] = 2;
//     ts.push_back(node);
// }

// vector<int> TopologicalSort(const vector<vector<int>> &graph)
// {
//     vector<int> states(graph.size(), 0);
//     vector<int> ts;

//     dforn(i, graph.size())
//     {
//         if (states[i] == 0)
//         {
//             dfs(i, graph, states, ts);
//             if (hasCycle)
//             {
//                 cout << "Cycle detected.\n";
//                 return {};
//             }
//         }
//     }
//     return ts;
// }

// dforn en vez de forn(168)
// no hasCycle seteado (149)
// no reversea (179)

// I'm joining a competitive programming tournament and have a doubt with my topological sort code, could you help me debug it?

// #include <bits/stdc++.h>
//     using namespace std;

// #define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
// #define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
// #define forn(i, n) forsn(i, 0, n)
// #define dforn(i, n) dforsn(i, 0, n)
// #define fore(i, s, n) forsn(i, s, n)

// bool hasCycle = false;

// void dfs(int node, const vector<vector<int>> &graph, vector<int> &states, vector<int> &ts)
// {
//     states[node] = 1;
//     for (int neigh : graph[node])
//     {
//         if (states[neigh] == 1)
//         {
//             return;
//         }
//         if (states[neigh] == 0)
//         {
//             dfs(neigh, graph, states, ts);
//             if (hasCycle)
//                 return;
//         }
//     }
//     states[node] = 2;
//     ts.push_back(node);
// }

// vector<int> TopologicalSort(const vector<vector<int>> &graph)
// {
//     vector<int> states(graph.size(), 0);
//     vector<int> ts;

//     dforn(i, graph.size())
//     {
//         if (states[i] == 0)
//         {
//             dfs(i, graph, states, ts);
//             if (hasCycle)
//             {
//                 cout << "Cycle detected.\n";
//                 return {};
//             }
//         }
//     }
//     return ts;
// }

// RA

// - The "reversed(ts)" function does not exist in C++, change for reverse(ts.begin(), ts.end())
// - After detecting a cycle, return to avoid re-computing inefficiently, especially in competitive programming since time constraints are crucial.
// - Use a forn() instead of forsn()
// - states and g should not be defined above.

// #include <bits/stdc++.h>
// using namespace std;

// #define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
// #define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
// #define forn(i, n) forsn(i, 0, n)
// #define dforn(i, n) dforsn(i, 0, n)
// #define fore(i, s, n) forsn(i, s, n)

// bool hasCycle = false;

// void dfs(int node, const vector<vector<int>> &graph, vector<int> &states, vector<int> &ts)
// {
//     states[node] = 1;
//     for (int neigh : graph[node])
//     {
//         if (states[neigh] == 1)
//         {
//             hasCycle = true;
//             return;
//         }
//         if (states[neigh] == 0)
//         {
//             dfs(neigh, graph, states, ts);
//         }
//     }
//     states[node] = 2;
//     ts.push_back(node);
// }

// vector<int> TopologicalSort(const vector<vector<int>> &graph)
// {
//     vector<int> states(graph.size(), 0);
//     vector<int> ts;

//     dforn(i, graph.size())
//     {
//         if (states[i] == 0)
//         {
//             dfs(i, graph, states, ts);
//             if (hasCycle)
//             {
//                 cout << "Cycle detected.\n";
//                 return {};
//             }
//         }
//     }
//     return ts;
// }
// int main()
// {
//     vector<vector<int>> graph = {{1, 2}, {3, 4}, {3, 5}, {4, 5}, {}, {}};
//     vector<vector<int>> graph_cyc = {{1}, {2}, {3}, {0}};
//     vector<int> result = TopologicalSort(graph);

//     if (!result.empty())
//     {
//         for (int elem : result)
//         {
//             cout << elem << "\n";
//         }
//     }
// }

#include <cassert>

int main()
{
    // Test case 1: Simple acyclic graph
    cout << "Test Case 1: Simple Acyclic Graph\n";
    vector<vector<int>> graph1 = {{1, 2}, {3, 4}, {3, 5}, {4, 5}, {}, {}};
    vector<int> result = TopologicalSort(graph1);
    assert(!result.empty()); // There should be no cycle
    cout << "Topological Sort Order: ";
    for (int elem : result)
        cout << elem << " ";
    cout << "\n";

    // Test case 2: Cyclic graph
    cout << "\nTest Case 2: Cyclic Graph\n";
    vector<vector<int>> graph2 = {{1}, {2}, {3}, {0}};
    result = TopologicalSort(graph2);
    assert(result.empty()); // There should be a cycle
    cout << "Cycle detected. No topological ordering possible.\n";

    // Test case 3: Disconnected acyclic graph
    cout << "\nTest Case 3: Disconnected Acyclic Graph\n";
    vector<vector<int>> graph3 = {{1}, {}, {3}, {4}, {}, {}};
    result = TopologicalSort(graph3);
    assert(!result.empty()); // There should be no cycle
    cout << "Topological Sort Order: ";
    for (int elem : result)
        cout << elem << " ";
    cout << "\n";

    // Test case 4: Single node graph
    cout << "\nTest Case 4: Single Node Graph\n";
    vector<vector<int>> graph4 = {{}};
    result = TopologicalSort(graph4);
    assert(!result.empty() && result == vector<int>{0}); // Should return only one node
    cout << "Topological Sort Order: ";
    for (int elem : result)
        cout << elem << " ";
    cout << "\n";

    // Test case 5: Linear acyclic graph
    cout << "\nTest Case 5: Linear Acyclic Graph\n";
    vector<vector<int>> graph5 = {{1}, {2}, {3}, {4}, {}};
    result = TopologicalSort(graph5);
    assert(!result.empty() && result == vector<int>{0, 1, 2, 3, 4}); // Should be a straightforward sequence
    cout << "Topological Sort Order: ";
    for (int elem : result)
        cout << elem << " ";
    cout << "\n";

    cout << "\nAll test cases passed.\n";
    return 0;
}
