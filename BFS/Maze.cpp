#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    int rows = maze.size();
    int cols = maze[0].size();
    int exits = 0;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<pair<int, int>, int>> q;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    q.push({{entrance[0], entrance[1]}, 0});
    visited[entrance[0]][entrance[1]] = true;
    while (!q.empty())
    {
        auto [newcoords, steps] = q.front();
        auto [x, y] = newcoords;
        q.pop();

        for (auto [dx, dy] : directions)
        {
            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY])
            {
                if (maze[newX][newY] == '.')
                {
                    visited[newX][newY] = true;

                    if ((newX == 0 || newX == rows - 1 || newY == 0 || newY == cols - 1))
                    {
                        return steps + 1;
                    }
                    else
                    {
                        q.push({{newX, newY}, steps + 1});
                    }
                }
            }
        }
    }
    return -1;
}