#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // dp vector for memoization and storing the sequence of matrix multiplication.
    vector<vector<pair<string, int>>> dp;

    // Matrix Chain Multiplication Code
    pair<string, int> matrixChainMultiplication(int i, int j, vector<int> &arr)
    {
        // Base Case
        if (i == j)
        {
            string matrixName = "";
            matrixName += 'A' + i - 1;
            return {matrixName, 0};
        }

        // Recursive Case - Try all possible partitions
        if (dp[i][j].second != -1)
        {
            return dp[i][j];
        }

        int minSteps = INT_MAX;
        string sequence = "";
        for (int k = i; k <= j - 1; k++)
        {
            pair<string, int> partitionOne = matrixChainMultiplication(i, k, arr);
            pair<string, int> partitionTwo = matrixChainMultiplication(k + 1, j, arr);
            int steps = arr[i - 1] * arr[k] * arr[j] + partitionOne.second + partitionTwo.second;

            string currSequence = "";
            currSequence = "(" + partitionOne.first + partitionTwo.first + ")";
            if (steps < minSteps)
            {
                minSteps = steps;
                sequence = currSequence;
            }
        }

        return dp[i][j] = {sequence, minSteps};
    }

public:
    string matrixChainOrder(vector<int> &arr)
    {

        int n = arr.size();
        dp.resize(n, vector<pair<string, int>>(n, {"", -1}));
        auto ans = matrixChainMultiplication(1, n - 1, arr);
        // cout<<ans.second<<endl;
        return ans.first;
    }
};