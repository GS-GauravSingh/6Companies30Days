#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        // This problem is same as 01 Matrix.
        // We just have to find the distance of nearest land cell form each cell. That's it. Simple BFS.
        int m = isWater.size(), n = isWater[0].size();

        // Use dijkstra algorithm to find out the shortest path from 1 (land cell) to every other node (i, j).
        // Min-Heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Distance Vector.
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX)); // Initially all nodes (i, j) are un-reachable.

        // Initialize Distance vector and push the coordinates of all 1's into the min-heap.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    distance[i][j] = 0; // if the cell already contains 1, then the distance of nearest 1 from the cell that already has 1 is 0.
                    pq.push({0, {i, j}});
                }
            }
        }

        // 4-Directions Neighbors coordinates. Order - Top, Right, Bottom, and Left.
        vector<vector<int>> directions = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int dist = top.first;
            int i = top.second.first;
            int j = top.second.second;

            // Neighbors
            for (auto &dir : directions)
            {
                int neighbor_i = i + dir[0];
                int neighbor_j = j + dir[1];

                if (
                    (neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 && neighbor_j < n) && /* check for out of bound */
                    dist + 1 < distance[neighbor_i][neighbor_j]                                 /* if we found another path that takes less distance to reach this node (i, j) as compare to previous distance, then we consider this path. */
                )
                {
                    distance[neighbor_i][neighbor_j] = dist + 1;
                    pq.push({distance[neighbor_i][neighbor_j], {neighbor_i, neighbor_j}});
                }
            }
        }

        // return the distance vector.
        return distance;
    }
};