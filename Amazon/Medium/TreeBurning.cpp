#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
public:
    int amountOfTime(TreeNode *root, int start)
    {

        // unordred_map to store mapping of node to its parent.
        unordered_map<TreeNode *, TreeNode *> nodeToParent;
        nodeToParent[root] = NULL;

        // Level Order Traversal to store the mapping of node to parent.
        TreeNode *startNode = NULL;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                auto node = que.front();
                que.pop();

                if (node->val == start)
                {
                    startNode = node;
                }

                if (node->left != NULL)
                {
                    nodeToParent[node->left] = node;
                    que.push(node->left);
                }

                if (node->right != NULL)
                {
                    que.push(node->right);
                    nodeToParent[node->right] = node;
                }
            }
        }

        // unordered_map to track the visited/infected nodes.
        unordered_map<TreeNode *, bool> visited;

        // BFS
        queue<pair<TreeNode *, int>> q;
        q.push({startNode, 0});
        visited[startNode] = true;
        int maxTime = 0;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode *node = front.first;
            int time = front.second; // time this node would have taken to get infected
            maxTime = max(maxTime, time);

            // Traverse the connected nodes.
            // Left Child
            if (node->left != NULL && !visited[node->left])
            {
                q.push({node->left, time + 1});
                visited[node->left] = true;
            }

            // Right Child
            if (node->right != NULL && !visited[node->right])
            {
                q.push({node->right, time + 1});
                visited[node->right] = true;
            }

            // Parent Node
            if (nodeToParent[node] != NULL && !visited[nodeToParent[node]])
            {
                q.push({nodeToParent[node], time + 1});
                visited[nodeToParent[node]] = true;
            }
        }

        return maxTime;
    }
};