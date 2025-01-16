#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<vector<int>>> dp;
    int func(int i, int j, int len, vector<int> &nums1, vector<int> &nums2)
    {
        // Base Case
        if (i >= nums1.size() || j >= nums2.size())
        {
            return len;
        }

        // Recursive Case
        if (dp[i][j][len] != -1)
        {
            return dp[i][j][len];
        }

        int same = 0;
        if (nums1[i] == nums2[j])
        {
            same = func(i + 1, j + 1, len + 1, nums1, nums2);
        }

        int excludeJ = func(i, j + 1, 0, nums1, nums2);
        int excludeI = func(i + 1, j, 0, nums1, nums2);

        return dp[i][j][len] = max(len, max(same, max(excludeJ, excludeI)));
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {

        // int maxLen = min(nums1.size(), nums2.size()); // max len of common subarray.
        // dp.resize(nums1.size(), vector<vector<int>> (nums2.size(), vector<int> (maxLen + 1, -1)));
        // return func(0, 0, 0, nums1, nums2);

        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ans = 0;
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};