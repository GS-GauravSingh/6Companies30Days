#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int maximumProduct(vector<int> &nums, int k)
    {

        // Min-Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int &val : nums)
            pq.push(val);

        while (k > 0)
        {
            pq.push((pq.top() + 1) % MOD);
            pq.pop();
            k--;
        }

        long long int product = 1;
        while (!pq.empty())
        {
            product = product * pq.top() % MOD;
            pq.pop();
        }

        return product;
    }
};