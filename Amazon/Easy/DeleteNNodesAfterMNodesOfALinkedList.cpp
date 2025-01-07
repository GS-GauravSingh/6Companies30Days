#include <bits/stdc++.h>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {

        Node *dummy = new Node(-1);
        dummy->next = head;

        Node *curr = head;
        Node *prev = dummy;

        int skipCnt = m;
        int deleteCnt = n;

        // skipping the first 'm' nodes.
        while (skipCnt > 0 && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            skipCnt--;
        }

        // after skipping the 'm' node. Check whether 'curr' points to null or not.
        if (curr == NULL)
        {
            return dummy->next;
        }

        // delete 'n' node.
        Node *deleteNode = prev;
        while (deleteCnt > 0 && curr != NULL)
        {
            deleteNode = curr;
            curr = curr->next;

            deleteNode->next = NULL;
            delete deleteNode;

            deleteCnt--;
        }

        Node *recursiveHead = linkdelete(curr, n, m); // Recursive call
        prev->next = recursiveHead;
        return dummy->next;
    }
};