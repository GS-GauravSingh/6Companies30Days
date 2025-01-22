#include <bits/stdc++.h>
using namespace std;

// Disjoint Set
class DisjointSet
{
public:
    vector<int> size;
    vector<int> parent; // parent[i] represent ultimate parent of `ith` node.

    // Constructor.
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            // Initially the ultimate parent of every node is the node itself.
            parent[i] = i;
        }
    }

    // Method to find ultimate parent of any node With Path Compression.
    int findUltimateParent(int node)
    {
        // Base Case
        if (parent[node] == node)
        {
            return node;
        }

        // RecursiveC Case
        return parent[node] = findUltimateParent(parent[node]);
    }

    // Method to Union By Size.
    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u); // ultimate parent of `u`.
        int ulp_v = findUltimateParent(v); // ultimate parent of `v`.

        // If both the nodes have the same ultimate parent, it means both the node are already connected, meaning both the node are part of the same component.
        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] <= size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            // size[ulp_u] > size[ulp_v]
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{

    // 4-Directions neighbors. Order - top, right, bottom and left.
    vector<vector<int>> directions = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

    // Method to count total number of connected components.
    int findCountOfConnectedComponents(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int totalNodes = m * n;
        DisjointSet *ds = new DisjointSet(totalNodes); // dynamically creating instance of DisjointSet class.

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                int currentCellNumber = n * i + j;

                // If current cell is a land cell then check its neighbors in 4-directions i.e., top, right, bottom, and left.
                // If there is any land cell present then connect both of them together, so that thay become part of the same component.
                for (auto &dir : directions)
                {
                    int neighbor_i = i + dir[0];
                    int neighbor_j = j + dir[1];
                    int neighborCellNumber = n * neighbor_i + neighbor_j;

                    if (
                        (neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 && neighbor_j < n) &&               /* check for valid neighbor */
                        (grid[neighbor_i][neighbor_j] != 0) &&                                                    /* neighbor has to be a land cell */
                        (ds->findUltimateParent(currentCellNumber) != ds->findUltimateParent(neighborCellNumber)) /* we only connect both the node together only if they are not belong to the same component */
                    )
                    {
                        ds->unionBySize(currentCellNumber, neighborCellNumber);
                    }
                }
            }
        }

        // finding number of connected components.
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 0)
                {
                    continue;
                }

                int currentCellNumber = n * i + j;
                if (ds->findUltimateParent(currentCellNumber) == currentCellNumber)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int connectedComponentsCount = findCountOfConnectedComponents(grid);

        if (connectedComponentsCount != 1)
        {
            // if the count of connected components is 0, then there is no island to diconnect. Hence the answer is 0.
            // if the count of connected components is greater than 1, then the gird is already disconnected. Hence. then answer is 0.
            return 0;
        }

        // So, we have only one connected component.
        // Now, we just iterate through all the 1's in the connected component and we simply check if we deleted this node (convert to water cell), then the count of connected components becomes greater than 1 or not.
        // If yes, then we simple return 1.
        // If the count of connected components is unaffected, when you try to delete each land cell one by one. Then the answer is 2 always.
        // Just try to draw a single components with any number of node, you will be able to split the component just deleting 2 nodes.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 0)
                {
                    continue;
                }

                // delete the land cell (convert it to water cell i.e., 0)
                grid[i][j] = 0;

                int count = findCountOfConnectedComponents(grid); // count of connected components.
                if (count != 1)
                {
                    return 1;
                }

                // undo the changes
                grid[i][j] = 1;
            }
        }

        return 2;
    }
};