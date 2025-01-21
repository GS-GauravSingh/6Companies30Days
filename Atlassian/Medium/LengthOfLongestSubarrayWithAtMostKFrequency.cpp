#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        // using Sliding Window to solved this problem.
        unordered_map<int, int> freq; // map to store frequecy of each element present in the current window.
        int start = 0, end = 0, n = nums.size(), longestLength = 0;
        while (end < n)
        {
            freq[nums[end]]++;
            while (freq[nums[end]] > k)
            {
                // shrink the window.
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                {
                    freq.erase(nums[start]);
                }

                start++;
            }

            int windowSize = end - start + 1;
            longestLength = max(longestLength, windowSize);
            end++;
        }

        return longestLength;
    }
};