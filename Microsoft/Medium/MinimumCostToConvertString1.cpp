#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void createAdjacencyList(vector<char> &original, vector<char> &changed, vector<int> &cost, unordered_map<int, vector<pair<int, int>>> &adjList)
    {
        int n = original.size();
        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int edgeWeight = cost[i];

            // Directed Edge
            adjList[u].push_back({v, edgeWeight});
        }
    }

    void createAdjacencyMatrix(vector<char> &original, vector<char> &changed, vector<int> &cost, vector<vector<long long>> &adjMatrix)
    {
        int n = original.size();
        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int edgeWeight = cost[i];

            // Directed Edge
            adjMatrix[u][v] = min(adjMatrix[u][v], (long long)edgeWeight);
        }
    }

    void dijkstraAlgorithm(int src, vector<int> &distance, unordered_map<int, vector<pair<int, int>>> &adjList)
    {
        // Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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

                if (dist + edgeWeight <= distance[neighbor])
                {
                    distance[neighbor] = dist + edgeWeight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
    }

    void floydWarshallAlgorithm(vector<vector<long long>> &adjMatrix)
    {
        for (int via = 0; via < 26; via++)
        {
            for (int u = 0; u < 26; u++)
            {
                for (int v = 0; v < 26; v++)
                {
                    if (adjMatrix[u][via] == INT_MAX)
                    {
                        continue;
                    }

                    adjMatrix[u][v] = min(adjMatrix[u][v], adjMatrix[u][via] + adjMatrix[via][v]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // unordered_map<int, vector<pair<int, int>>> adjList;
        // createAdjacencyList(original, changed, cost, adjList);

        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));
        createAdjacencyMatrix(original, changed, cost, adjMatrix);
        floydWarshallAlgorithm(adjMatrix);

        long long ans = 0;
        for (int i = 0; i < source.length(); i++)
        {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (s == t)
                continue;

            // vector<int> distance(26, INT_MAX);
            // dijkstraAlgorithm(s, distance, adjList);

            // if(distance[t] == INT_MAX) return -1;

            long long distance = adjMatrix[s][t];
            if (distance == INT_MAX)
                return -1;
            ans += distance;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};