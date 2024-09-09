#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    deque<pair<int, int>> q;
    int iterations = 0;
    int fresh = 0;

    int rows = grid.size();
    int columns = grid[0].size();

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (grid[r][c] == 1)
            {
                fresh++;
            }
            else if (grid[r][c] == 2)
            {
                q.emplace_back(r, c);
            }
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty() && fresh > 0)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto [r, c] = q.front();
            q.pop_front();
            for (auto [dr, dc] : directions)
            {
                int row = r + dr;
                int col = c + dc;
                if (row < 0 || row == rows || col < 0 || col == columns || grid[row][col] != 1)
                {
                    continue;
                }
                grid[row][col] = 2;
                q.emplace_back(row, col);
                fresh -= 1;
            }
        }
        iterations++;
    }
    if (fresh == 0)
    {
        return iterations;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = orangesRotting(grid);
    cout << result << endl;
    return 0;
}