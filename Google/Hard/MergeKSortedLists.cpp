#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

    // Method to merge two sorted list.
    ListNode *mergeTwoSortedLists(ListNode *A, ListNode *B)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        while (A != NULL && B != NULL)
        {
            if (A->val <= B->val)
            {
                dummyTail->next = A;
                dummyTail = dummyTail->next;

                A = A->next;
            }
            else
            {
                // B -> val < A -> val
                dummyTail->next = B;
                dummyTail = dummyTail->next;

                B = B->next;
            }
        }

        if (A != NULL)
        {
            dummyTail->next = A;
        }

        if (B != NULL)
        {
            dummyTail->next = B;
        }

        return dummyHead->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.empty())
        {
            return NULL;
        }

        ListNode *ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            ans = mergeTwoSortedLists(ans, lists[i]);
        }

        return ans;
    }
};