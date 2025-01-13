#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Max-Heap
        priority_queue<pair<int, int>> pq;

        // Insert all elements along with its indexs into the max-heap.
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        // Take out k elements from the max heap.
        vector<pair<int, int>> pairs;
        while (k--)
        {
            pairs.push_back(pq.top());
            pq.pop();
        }

        // sort the elements based on their indexes.
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b)
            {

            // sort the elements in ascending order based on their indexes.
            return a.second < b.second; });

        // return the subsequence.
        vector<int> subsequence;
        for (auto &p : pairs)
        {
            subsequence.push_back(p.first);
        }

        return subsequence;
    }
};