#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void createAdjacencyMatrix(vector<vector<int>> &edges, vector<vector<int>> &adjMatrix)
    {
        for (auto &row : edges)
        {
            int u = row[0];
            int v = row[1];
            int edgeWeight = row[2];

            // Un-directed Graph
            adjMatrix[u][v] = edgeWeight;
            adjMatrix[v][u] = edgeWeight;
        }
    }

    int floydWarshallAlgorithm(vector<vector<int>> &adjMatrix, int V, int distanceThreshold)
    {
        for (int via = 0; via < V; via++)
        {
            for (int u = 0; u < V; u++)
            {
                for (int v = 0; v < V; v++)
                {
                    if (adjMatrix[u][via] == INT_MAX || adjMatrix[via][v] == INT_MAX)
                    {
                        continue;
                    }

                    adjMatrix[u][v] = min(adjMatrix[u][v], adjMatrix[u][via] + adjMatrix[via][v]);
                }
            }
        }

        int ansCity = 0;
        int minReachableCities = INT_MAX;
        for (int u = 0; u < V; u++)
        {
            int cntReachableCities = 0; // to count reachable cities within `threshold` distance.
            for (int v = 0; v < V; v++)
            {
                if (u == v)
                {
                    continue;
                }

                if (adjMatrix[u][v] <= distanceThreshold)
                {
                    cntReachableCities++;
                }
            }

            if (cntReachableCities <= minReachableCities)
            {
                minReachableCities = cntReachableCities;
                ansCity = u;
            }
        }

        return ansCity;
    }

public:
    int findTheCity(int V, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> adjMatrix(V, vector<int>(V, INT_MAX));
        createAdjacencyMatrix(edges, adjMatrix);

        // Initialize Diagonal elements in adjacency matrix
        for (int i = 0; i < V; i++)
        {
            // Cost needed to reach a node from itself (source = destination) is 0.
            adjMatrix[i][i] = 0;
        }

        return floydWarshallAlgorithm(adjMatrix, V, distanceThreshold);
    }
};