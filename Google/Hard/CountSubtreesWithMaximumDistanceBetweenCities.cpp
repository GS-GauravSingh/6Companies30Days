#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxDistance(int val, vector<vector<int>> &adjMatrix, int n)
    {
        // See, subset is not equal to subtree because is is possible that there is a pair of nides in a subset that is not connected in tree.
        // It means there is no edge.
        // A valid subset is a subset that has n node and n-1 edges.
        int nodeCnt = 0, edgeCnt = 0, maxDist = 0;
        for (int i = 0; i < n; i++)
        {
            if (((val >> i) & 1) == 0)
            {
                // if we have n nodes, the we consider n bits  and bit value will tell which node is part of the subset and which one is not.
                // If the bit positioned at `ith` index is 1 - include the `ith` number in the subset. Otherwise not.
                // If node values are 1-based indexing, then `ith` index node value is `i+1`.
                // Example: 5 - in binary: 0101: subset: [2, 1].
                // 'i' node is not a part of our subset.
                continue;
            }

            nodeCnt++;

            // Now we just have to check whether the node that I've just included in my subset i.e., the `ith` node.
            // are connected or has a direct edge with the other nodes (that are part of the subset) or not.
            // If the pair of node are directly connected then the shortest distance between them is 1.
            // If the distance between them some value (not INT_MAX) greater than 1, it means there is some node through which they are connected with each other.
            for (int j = i + 1; j < n; j++)
            {
                if (((val >> j) & 1) == 0)
                {
                    // 'j' node is not a part of our subset.
                    continue;
                }

                if (adjMatrix[i][j] == 1)
                {
                    edgeCnt++;
                }

                // store the max distance.
                maxDist = max(maxDist, adjMatrix[i][j]);
            }
        }

        //  A valid subset is a subset that has n node and n-1 edges.
        if (nodeCnt == edgeCnt + 1)
            return maxDist;
        return 0;
    }

public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {

        // Use floyd warshall algorithm to find out the shortest distance between every pair of node.
        vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX));

        for (auto &edge : edges)
        {
            int u = edge[0] - 1, v = edge[1] - 1; // -1 is just for converting 1-based to 0-based indexing.
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }

        for (int via = 0; via < n; via++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (adjMatrix[u][via] == INT_MAX || adjMatrix[via][v] == INT_MAX)
                    {
                        continue;
                    }

                    adjMatrix[u][v] = min(adjMatrix[u][v], adjMatrix[u][via] + adjMatrix[via][v]);
                }
            }
        }

        vector<int> ans(n - 1, 0); // maximum distance between a pair of node(cities) can never be greater than `n-1`, where 'n' is the number of node.

        // There will be 2 power n total subsets.
        int totalSubsets = pow(2, n);

        // Generate all the subsets.
        for (int i = 0; i < totalSubsets; i++)
        {
            int d = maxDistance(i, adjMatrix, n);
            if (d > 0)
            {
                ans[d - 1] += 1; // count the subtree with maximum distance between a pair of node is `d`.
            }
        }

        return ans;
    }
};