// The idea is the following: There is a room with keys to other rooms. We need to check if we can visit all rooms.
// We can use a dfs to visit all rooms and then check if we visited all rooms.
// The time complexity is O(n + m) where n is the number of rooms and m is the number of keys.

#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>
void dfs(int node, std::vector<bool> &visited, std::vector<std::vector<int>> &rooms)
{
    visited[node] = true;
    for (int neighbour : rooms[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, rooms);
        }
    }
}

bool canVisitAllRooms(std::vector<std::vector<int>> &rooms)
{
    std::vector<bool> visited(rooms.size());
    dfs(0, visited, rooms);
    int amt_visited = std::accumulate(visited.begin(), visited.end(), 0);
    if (rooms.size() != amt_visited)
    {
        return false;
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    std::cout << canVisitAllRooms(rooms) << std::endl;
    return 0;
}