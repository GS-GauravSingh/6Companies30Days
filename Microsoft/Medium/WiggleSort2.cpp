#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort_BruteForce(vector<int> &nums)
    {
        // Brute Force Code
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n);

        // First Put elements at odd indices
        int k = n - 1;
        for (int i = 1; i < n; i += 2)
        {
            ans[i] = nums[k--];
        }

        // Put elements at even indices.
        for (int i = 0; i < n; i += 2)
        {
            ans[i] = nums[k--];
        }

        nums = ans;
    }

    void wiggleSort(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> countingSort(5001, 0);
        for (int val : nums)
        {
            countingSort[val]++;
        }

        // First Put elements at odd indices
        int j = 1;
        for (int i = 5000; i >= 0 && j < n; i--)
        {
            if (countingSort[i] == 0)
                continue;
            while (countingSort[i] && j < n)
            {
                nums[j] = i;
                j += 2;
                countingSort[i] -= 1;
            }
        }

        // Put elements at even indices.
        j = 0;
        for (int i = 5000; i >= 0 && j < n; i--)
        {
            if (countingSort[i] == 0)
                continue;
            while (countingSort[i] && j < n)
            {
                nums[j] = i;
                j += 2;
                countingSort[i] -= 1;
            }
        }
    }
};