#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Recursive Solution.
    void func(int idx, vector<int> subset, vector<int> &nums, vector<int> &largestSubset)
    {
        // Base Case
        if (idx >= nums.size())
        {
            if (largestSubset.size() < subset.size())
            {
                largestSubset = subset;
            }
            return;
        }

        // Recursive Case

        // Take
        if (subset.empty() || nums[idx] % subset.back() == 0)
        {
            subset.push_back(nums[idx]);
            func(idx + 1, subset, nums, largestSubset);
            // Backtracking Step
            subset.pop_back();
        }

        // Not Take.
        func(idx + 1, subset, nums, largestSubset);
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        // // Recursive Solution
        // vector<int> largestSubset;
        // func(0, {}, nums, largestSubset);
        // return largestSubset;

        // Below approach is based on Longest Increasing Subsequence.
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0)
                {
                    if ((1 + dp[prev]) > dp[i])
                    {
                        hash[i] = prev;
                        dp[i] = 1 + dp[prev];
                    }
                }
            }
        }

        int idx = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            if (maxi <= dp[i])
            {
                maxi = dp[i];
                idx = i;
            }
        }
        vector<int> ans;
        while (idx != hash[idx])
        {
            ans.push_back(nums[idx]);
            idx = hash[idx];
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};