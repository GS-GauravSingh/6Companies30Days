#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        if (m == 1 && n == 1)
        {
            if (grid[0][0] == 0 || grid[0][0] == 2)
                return 0;
            return -1;
        }

        // BFS on Grid
        // Index 0 and 1 represents the coordinates of the cell and index 2 represent the time in which this cell has rotten.
        queue<vector<int>> q;

        // visited vector
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Initially, push all the rotten oranges into the queue with time 0.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    // Rotten Orange
                    q.push({i, j, 0}); // this ornage is already rotten that's why the time taken to rotten this orange is 0.
                    visited[i][j] = 1; // Mark this cell as visited
                }
            }
        }

        vector<int> rowCoordinates{-1, 0, +1, 0};
        vector<int> colCoordinates{0, +1, 0, -1};
        int minMinutes = 0;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int i = front[0];
            int j = front[1];
            int minutes = front[2];
            minMinutes = max(minMinutes, minutes);

            // 4-Neighbors
            for (int k = 0; k < 4; k++)
            {
                int neighbor_i = i + rowCoordinates[k];
                int neighbor_j = j + colCoordinates[k];

                if (
                    (neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 && neighbor_j < n) /* check for a valid neighbor */ &&
                    !visited[neighbor_i][neighbor_j] &&
                    grid[neighbor_i][neighbor_j] == 1)
                {
                    q.push({neighbor_i, neighbor_j, minutes + 1});
                    visited[neighbor_i][neighbor_j] = 1;
                }
            }
        }

        // check whether all fresh oranges has rotten or not.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    return -1;
                }
            }
        }

        return minMinutes;
    }
};