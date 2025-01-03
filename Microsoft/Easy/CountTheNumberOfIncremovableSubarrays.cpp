#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{
    bool isSubarrayIncremovable(int subarrayStartIdx, int subarrayEndIdx, vector<int> &nums)
    {
        int n = nums.size();
        int totalElementsInSubarray = subarrayEndIdx - subarrayStartIdx + 1;
        if (totalElementsInSubarray == n)
        {
            return true;
        }

        // These elements that are not part of the subarray must be in strictly increasing order
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (i >= subarrayStartIdx && i <= subarrayEndIdx)
            {
                continue;
            }

            if (!temp.empty() && temp.back() >= nums[i])
            {
                return false;
            }

            temp.push_back(nums[i]);
        }

        return true;
    }

public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        // Approach: Generate all the subarrays and check which subarray are incremovable and which are not.
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isSubarrayIncremovable(i, j, nums))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main(void)
{
    return 0;
}