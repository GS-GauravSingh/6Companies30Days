#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // unordered_map<string, int> dp;
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int func(int currPos, int endPos, int k)
    {
        // Base Case
        if (k == 0)
        {
            return (currPos == endPos);
        }

        // Recursive Case
        if (dp[currPos + 1000][k] != -1)
        {
            return dp[currPos + 1000][k];
        }

        // Move Left
        int left = func(currPos - 1, endPos, k - 1);

        // Move Right
        int right = func(currPos + 1, endPos, k - 1);

        // return total number of ways to reach the `endPos` using exactly `k` steps.
        return dp[currPos + 1000][k] = (left + right) % MOD;
    }

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        dp.resize(3001, vector<int>(1001, -1));
        return func(startPos, endPos, k);
    }
};