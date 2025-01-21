#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    unordered_set<TreeNode *> leafNodes;                   // set to store leaf nodes.
    unordered_map<TreeNode *, vector<TreeNode *>> adjList; // adjacency list.

    void convertBinaryTreeIntoGraph(TreeNode *curr, TreeNode *prev)
    {
        // Base Case
        if (curr == NULL)
        {
            return;
        }

        // Recursive Case - Inorder traversal - Root, Left, Right
        if (curr->left == NULL && curr->right == NULL)
        {
            leafNodes.insert(curr);
        }

        if (prev != NULL)
        {
            adjList[prev].push_back(curr);
            adjList[curr].push_back(prev);
        }

        convertBinaryTreeIntoGraph(curr->left, curr);
        convertBinaryTreeIntoGraph(curr->right, curr);
    }

public:
    // Brute Force Approach: Consider every leaf node one by one and try to find out the shortest distance to reach the other leaf nodes.
    int countPairs_BruteForce(TreeNode *root, int distance)
    {
        unordered_set<TreeNode *> leafNodes;                // set to store leaf nodes.
        unordered_map<TreeNode *, TreeNode *> nodeToParent; // map to store mapping of node with its parent node.
        nodeToParent[root] = NULL;                          // root node has no parent.

        // Level-Order Traversal - Just to store leaf nodes and create mapping of node to parent.
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // Check whether node is a leaf node or not.
            if (node->left == NULL && node->right == NULL)
            {
                leafNodes.insert(node);
            }

            // Left Child
            if (node->left != NULL)
            {
                nodeToParent[node->left] = node;
                q.push(node->left);
            }

            // Right Child
            if (node->right != NULL)
            {
                nodeToParent[node->right] = node;
                q.push(node->right);
            }
        }

        // At this point, we have node to parent mapping and leaf nodes.
        // Now, one by one pick each leaf node and calculate the minimum distance to reach other leaf nodes.
        int goodPairsCnt = 0;

        for (auto it = leafNodes.begin(); it != leafNodes.end(); it++)
        {
            TreeNode *leafNode = *it; // dereference the iterator to get the node.
            queue<pair<TreeNode *, int>> q;
            q.push({leafNode, 0});

            unordered_map<TreeNode *, bool> visited;

            // BFS
            while (!q.empty())
            {
                auto front = q.front();
                q.pop();

                TreeNode *node = front.first;
                int dist = front.second;

                // Reached the leaf node.
                if (leafNodes.count(node) && dist <= distance && node != leafNode)
                {
                    goodPairsCnt++;
                }

                // Left Child
                if (node->left != NULL && !visited[node->left])
                {
                    q.push({node->left, dist + 1});
                    visited[node->left] = true;
                }

                // Right Child
                if (node->right != NULL && !visited[node->right])
                {
                    q.push({node->right, dist + 1});
                    visited[node->right] = true;
                }

                // Parent Node
                TreeNode *parent = nodeToParent[node];
                if (parent != NULL && !visited[parent])
                {
                    q.push({parent, dist + 1});
                    visited[parent] = true;
                }
            }
        }

        return goodPairsCnt / 2;
    }

    // Optimized Approach: Store all the leaf node into a set and Convert the given binary tree into a graph. Now, consider every leaf node one by one and try to find out the shortest distance to reach the other leaf nodes.
    int countPairs(TreeNode *root, int distance)
    {

        leafNodes.clear();
        adjList.clear();

        convertBinaryTreeIntoGraph(root, NULL); // convert Binary Tree into Graph.

        int goodPairsCnt = 0;

        for (auto it = leafNodes.begin(); it != leafNodes.end(); it++)
        {
            TreeNode *currLeafNode = *it; // dereference the iterator the get the node.
            queue<TreeNode *> q;
            unordered_set<TreeNode *> visited;

            q.push(currLeafNode);
            visited.insert(currLeafNode);

            // Visit all the nodes withing the given distance.
            for (int i = 0; i <= distance; i++)
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    auto node = q.front();
                    q.pop();

                    if (leafNodes.count(node) && node != currLeafNode)
                    {
                        goodPairsCnt++;
                    }

                    for (auto neighbor : adjList[node])
                    {
                        if (!visited.count(neighbor))
                        {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
        }

        return goodPairsCnt / 2;
    }
};