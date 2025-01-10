#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        string encode = "";
        if (root == NULL)
        {
            return encode;
        }

        // Level-Order Traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node == NULL)
            {
                encode.append("N,"); // N means NULL and comma(,) is used for separation.
            }
            else
            {
                // node != NULL
                encode.append((to_string(node->val) + ","));
            }

            if (node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }

        cout << encode << endl;
        return encode;
    }

    int getNodeData(string &data, int &start)
    {
        int j = start;
        bool isNegative = false;
        int nodeVal = 0;
        while (data[j] != ',')
        {
            if (j == start && data[j] == '-')
            {
                isNegative = true;
                j++;
                continue;
            }

            int digit = data[j] - '0';
            nodeVal = nodeVal * 10 + digit;
            j++;
        }

        start = j + 1;
        if (isNegative)
        {
            nodeVal = -nodeVal;
        }

        return nodeVal;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        if (data.empty() || data[0] == 'N')
        {
            return NULL;
        }

        int i = 0;
        int dataForRoot = getNodeData(data, i);
        TreeNode *root = new TreeNode(dataForRoot);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty() && i <= data.length())
        {
            auto node = q.front();
            q.pop();

            if (data[i] == 'N')
            {
                i += 2;
            }
            else
            {
                int nodeVal = getNodeData(data, i);
                cout << nodeVal << " ";
                node->left = new TreeNode(nodeVal);
                q.push(node->left);
            }

            if (i >= data.length())
            {
                break;
            }

            if (data[i] == 'N')
            {
                i += 2;
            }
            else
            {
                int nodeVal = getNodeData(data, i);
                cout << nodeVal << " ";
                node->right = new TreeNode(nodeVal);
                q.push(node->right);
            }
        }

        return root;
    }
};