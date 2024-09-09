// The idea is the following, we have each province with an adjacency matrix. We need to find the number of provinces.
// We can use a dfs to visit all provinces and then check if we visited all provinces.
// we call dfs on a province if it hasn't been visited and check all the nodes that province covers.
// then we repeat for each non visited node after the dfs and increment the number of provinces.

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

void dfs(std::vector<std::vector<int>> connected, int node, std::vector<bool> &visited)
{
    visited[node] = true;
    for (int j = 0; j < connected[node].size(); j++)
    {
        if (connected[node][j] && !visited[j])
        {
            dfs(connected, j, visited);
        }
    }
}
int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    std::vector<bool> visited(isConnected.size(), false);
    int comps = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            dfs(isConnected, i, visited);
            comps++;
        }
    }
    return comps;
}

int main()
{
    std::vector<std::vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    std::cout << findCircleNum(isConnected) << std::endl;
    return 0;
}

// A more oprimal solution:

void dfs(int node, int vis[], vector<int> adjLs[])
{
    vis[node] = 1;
    for (auto it : adjLs[node])
    {
        if (!vis[it])
            dfs(it, vis, adjLs);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected[0].size();
    int vis[V];
    for (int i = 0; i < V; i++)
        vis[i] = 0;
    vector<int> adjLs[V + 1];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (isConnected[i][j] == 1)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int cnt = 0;

    // Using dfs

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, vis, adjLs);
        }
    }
    return cnt;
};