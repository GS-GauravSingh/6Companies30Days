#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{

    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, vector<pair<int, int>>> &adjList)
    {
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int edgeWeight = edge[2];

            // Bi-Directional Edge
            adjList[u].push_back({v, edgeWeight});
            adjList[v].push_back({u, edgeWeight});
        }
    }

    int dijkstraAlgorithm(int src, int n, int distanceThreshold, unordered_map<int, vector<pair<int, int>>> &adjList)
    {
        // Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance Vector
        vector<int> distance(n, INT_MAX);

        distance[src] = 0;
        pq.push({distance[src], src});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int dist = top.first;

            // Neighbors
            for (auto &pair : adjList[node])
            {
                int neighbor = pair.first;
                int edgeWeight = pair.second;
                if (dist + edgeWeight < distance[neighbor])
                {
                    distance[neighbor] = dist + edgeWeight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        int cnt = 0; // count of cities that reachable with at most `distanceThreshold` distance.
        for (int &dist : distance)
        {
            if (dist <= distanceThreshold)
                cnt++;
        }

        return cnt - 1; // excluding the source `src` node.
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        unordered_map<int, vector<pair<int, int>>> adjList;
        createAdjacencyList(edges, adjList); // prepare adjacency list.

        unordered_map<int, int> nodeToReachableCities;
        int minReachableCities = INT_MAX;
        for (int node = 0; node < n; node++)
        {
            int reachableCitiesCnt = dijkstraAlgorithm(node, n, distanceThreshold, adjList);
            nodeToReachableCities[node] = reachableCitiesCnt;
            minReachableCities = min(minReachableCities, reachableCitiesCnt);
        }

        int ansNode = 0;
        for (auto it : nodeToReachableCities)
        {
            if (it.second == minReachableCities)
            {
                ansNode = max(ansNode, it.first);
            }
        }

        return ansNode;
    }
};

int main(void)
{
    return 0;
}