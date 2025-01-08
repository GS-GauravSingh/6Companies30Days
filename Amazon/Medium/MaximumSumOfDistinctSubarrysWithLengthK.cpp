#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {

        // Optimized Soluting  - Sliding Window
        int start = 0, end = 0, n = nums.size();

        // map to check for duplicates in an subarray of size 'k'.
        unordered_map<int, int> hash;
        long long sum = 0, maxSum = 0;
        while (end < n)
        {
            sum += 1ll * nums[end];

            // shrink the window if any element in the current window has frequency greater than 1.
            hash[nums[end]]++;
            while (hash[nums[end]] > 1)
            {
                hash[nums[start]]--;
                if (hash[nums[start]] == 0)
                {
                    hash.erase(nums[start]);
                }

                sum -= nums[start];
                start++;
            }

            int windowSize = end - start + 1;
            if (windowSize < k)
            {
                end++;
            }
            else if (windowSize == k)
            {
                maxSum = max(maxSum, sum);
                cout << sum << endl;

                // Shift the window
                sum -= nums[start];
                hash[nums[start]]--;
                if (hash[nums[start]] == 0)
                {
                    hash.erase(nums[start]);
                }

                start++;
                end++;
            }
        }

        return maxSum;
    }
};