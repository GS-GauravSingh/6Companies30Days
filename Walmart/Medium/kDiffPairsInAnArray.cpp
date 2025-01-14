#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force Approach: Generate all pairs and store it in a set to find out the unique ones.
    int findPairs_BruteForce(vector<int> &nums, int k)
    {

        int n = nums.size();

        set<pair<int, int>> uniquePairs;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (abs(nums[i] - nums[j]) == k)
                {
                    // store pairs into the set
                    // format: min element of pair, max element of pair.
                    uniquePairs.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
                }
            }
        }

        return uniquePairs.size();
    }

    // Better approach - Sorting
    int findPairs_Better(vector<int> &nums, int k)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end()); // sorting helps us to ignore duplicate values and find k-diff pairs efficiently.
        int kDiffPairsCnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[i] == k)
                {
                    cout << "(" << nums[i] << "," << nums[j] << "), ";
                    kDiffPairsCnt++;
                }

                // Ignore duplicates
                while (j + 1 < n && nums[j + 1] == nums[j])
                {
                    j++;
                }
            }

            // Ignore duplicates
            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }
        }

        return kDiffPairsCnt;
    }

    // Optimized Approach - Hashing
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int &val : nums)
        {
            freq[val]++;
        }

        int kDiffPairsCnt = 0;
        for (auto &pair : freq)
        {
            if ((k == 0 && pair.second > 1) || (k > 0 && freq.count(pair.first + k)))
            {
                kDiffPairsCnt++;
            }
        }

        return kDiffPairsCnt;
    }
};