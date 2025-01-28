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

    // Method to check whether a tree is a Binart Search Tree or not.
    bool isBST(TreeNode *root, int minRange, int maxRange)
    {
        // Base Case
        if (root == NULL)
        {
            // Empty tree is a value BST.
            return true;
        }

        if (root->val <= minRange || root->val >= maxRange)
        {
            // According to question:
            // left subtree nodes value < root value
            // right subtree nodes value > root value
            return false;
        }

        // Recursive Case
        bool left = isBST(root->left, minRange, root->val);
        bool right = isBST(root->right, root->val, maxRange);
        return (left && right);
    }

    // Method to calculate the sum of nodes in the binary tree
    int calculateSum(TreeNode *root)
    {
        // Level-Order Traversal
        queue<TreeNode *> q;
        q.push(root);

        int sum = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            sum += node->val;

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }

        return sum;
    }

    // Method to check whether the tree is a BST or node and also it computes the sum of nodes in the tree.
    pair<bool, int> isBSTAndCalculateSum(TreeNode *root, int minRange, int maxRange)
    {

        // Base Case
        if (root == NULL)
        {
            // Empty tree is a valid BST.
            // There is no node, so the sum is 0.
            return {true, 0};
        }

        if (root->val <= minRange || root->val >= maxRange)
        {
            // According to question:
            // left subtree nodes value < root value
            // right subtree nodes value > root value
            // If the tree is not a BST, then no need to calculate the sum, just return 0.
            return {false, 0};
        }

        // Recursive Case
        pair<bool, int> left = isBSTAndCalculateSum(root->left, minRange, root->val);
        pair<bool, int> right = isBSTAndCalculateSum(root->right, root->val, maxRange);

        if (left.first == false || right.first == false)
        {
            return {false, 0};
        }

        // left.first == true && right.first == true -> it's a valid BST (till this point).
        return {true, left.second + right.second + root->val};
    }

public:
    int maxSumBST_BruteForce(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Case
        int left = maxSumBST(root->left);
        int right = maxSumBST(root->right);

        int sum = 0;

        // if the tree starting from this node (root) is a valid BST. Then compute the sum of nodes.
        // if(isBST(root, INT_MIN, INT_MAX))
        // {
        //     sum += calculateSum(root);
        // }

        // if the tree is a valid BST, then temp.second will have the sum of all the node in the BST. Otherwise, it contains 0.
        pair<bool, int> temp = isBSTAndCalculateSum(root, INT_MIN, INT_MAX);

        return max(temp.second, max(left, right));
    }

    // Optimized Approach.
    int ans = 0;
    vector<int> findMaxSumBST(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {INT_MAX, INT_MIN, 0};
        }

        // Recursive Case
        auto left = findMaxSumBST(root->left);
        auto right = findMaxSumBST(root->right);

        // check if current subtree is a valid BST or not.
        if (root->val > left[1] && root->val < right[0])
        {
            // subtree starting for this root is a valid BST.
            ans = max(ans, left[2] + right[2] + root->val);
            return {min(root->val, left[0]), max(root->val, right[1]), (left[2] + right[2] + root->val)};
        }

        return {INT_MIN, INT_MAX, max(left[2], right[2])};
    }

    int maxSumBST(TreeNode *root)
    {
        findMaxSumBST(root);
        return ans;
    }
};