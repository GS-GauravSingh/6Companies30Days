#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> allSubsets;
    void generateAllCombinations(int val, int k, int currSum, int targetSum, vector<int> subset)
    {
        // Base Case
        if (val >= 10)
        {
            // we can only consider values from 1 to 9 (both inclusive).
            if (subset.size() == k && currSum == targetSum)
            {
                allSubsets.push_back(subset);
            }

            return;
        }

        // Recursive Case
        // Take

        if (currSum + val <= targetSum || subset.size() < k)
        {
            subset.push_back(val);
            generateAllCombinations(val + 1, k, currSum + val, targetSum, subset);
            subset.pop_back(); // Backtracking step.
        }

        // Not Take
        generateAllCombinations(val + 1, k, currSum, targetSum, subset);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        generateAllCombinations(1, k, 0, n, {});
        return allSubsets;
    }
};