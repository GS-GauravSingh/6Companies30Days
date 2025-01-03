#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{
    int solve(int n, int k)
    {
        // Base Case
        if (n == 1)
        {
            return 0;
        }

        // Recursive Case
        int mappedIdx = solve(n - 1, k);
        return (mappedIdx + k) % n;
    }

public:
    int findTheWinner_BruteForce(int n, int k)
    {

        // Brute Force Approach - Using Deque - Just Simulate the Process.
        deque<int> dq;
        for (int i = 1; i <= n; i++)
        {
            dq.push_back(i);
        }

        int counting = 1;
        while (dq.size() > 1)
        {
            if (counting < k)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                counting++;
            }
            else
            {
                // counting == k
                dq.pop_front();
                counting = 1;
            }
        }

        return dq.front();
    }

    // Optimized Solution - Recursion
    int findTheWinner(int n, int k)
    {
        return solve(n, k) + 1;
    }
};

int main(void)
{
    return 0;
}