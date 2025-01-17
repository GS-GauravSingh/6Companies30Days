#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void traverseConnectedComponents(int src_i, int src_j, vector<vector<int>> &visited, vector<vector<char>> &board)
    {
        queue<pair<int, int>> q;

        visited[src_i][src_j] = true;
        q.push({src_i, src_j});

        // Coordinates of 4 (top, right, bottom, left) neighbors
        vector<int> rowCoordinates{-1, 0, +1, 0}, colCoordinates{0, +1, 0, -1};
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            // Neighbors
            for (int k = 0; k < 4; k++)
            {
                int neighbor_i = i + rowCoordinates[k];
                int neighbor_j = j + colCoordinates[k];

                if (
                    (neighbor_i >= 0 && neighbor_i < board.size() && neighbor_j >= 0 && neighbor_j < board[0].size()) &&
                    !visited[neighbor_i][neighbor_j] &&
                    board[neighbor_i][neighbor_j] != '.')
                {
                    q.push({neighbor_i, neighbor_j});
                    visited[neighbor_i][neighbor_j] = true;
                }
            }
        }
    }

public:
    int countBattleships(vector<vector<char>> &board)
    {
        // This problem is same as number of islands. We just have to count the numnber of connected components.

        int m = board.size(), n = board[0].size(), componentsCnt = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    // Empty cell
                    continue;
                }
                else if (!visited[i][j])
                {
                    traverseConnectedComponents(i, j, visited, board);
                    componentsCnt++;
                }
            }
        }

        return componentsCnt;
    }
};