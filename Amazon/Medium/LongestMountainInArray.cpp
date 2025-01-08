#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool isMountainSubarray(vector<int> &arr, int start, int end)
    {
        for (int i = start + 1; i < end; i++)
        {
            bool isValid = true;
            int prev = i - 1;
            while (prev >= start)
            {
                if (arr[prev] >= arr[prev + 1])
                {
                    isValid = false;
                    break;
                }

                prev--;
            }

            if (isValid == false)
                continue;

            int next = i + 1;
            while (next <= end)
            {
                if (arr[next - 1] <= arr[next])
                {
                    isValid = false;
                    break;
                }

                next++;
            }

            if (isValid)
            {
                return true;
            }
        }

        return false;
    }

public:
    // Brute Force Solution - Generate all subarray of length >= 3 and check which subarray is a mountains subarray and which one is not.
    int longestMountain_BruteForce(vector<int> &arr)
    {

        int n = arr.size(), longest = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j - i + 1 < 3)
                {
                    continue;
                }

                if (isMountainSubarray(arr, i, j))
                {
                    longest = max(longest, j - i + 1);
                }
            }
        }

        return longest;
    }

    // Better Solution - consider every index from [1, n-2] and try to expan the window in both directions only when elements on the left and right are in decresing order.
    int longestMountain_BetterSolution(vector<int> &arr)
    {

        int n = arr.size(), longest = 0;
        if (n < 3)
        {
            return 0;
        }

        for (int i = 1; i < n - 1; i++)
        {
            // check how much you can go in left direction maintianing the decreasing order of element
            int left = i - 1;
            while (left >= 0 && arr[left] < arr[left + 1])
            {
                left--;
            }

            // check how much you can go in right direction maintianing the decreasing order of element
            int right = i + 1;
            while (right < n && arr[right - 1] > arr[right])
            {
                right++;
            }

            if (left != i - 1 && right != i + 1)
            {
                // cout<<left + 1<<", "<<right - 1<<endl;
                longest = max(longest, (right - left + 1) - 2);
            }
        }

        return longest;
    }

    // Optimized Solution - using prefix and suffix array
    int longestMountain(vector<int> &arr)
    {

        int n = arr.size(), longest = 0;
        if (n < 3)
        {
            return 0;
        }

        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] < arr[i])
            {
                prefix[i] = 1 + prefix[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] < arr[i])
            {
                suffix[i] = 1 + suffix[i + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] && suffix[i])
            {
                longest = max(longest, prefix[i] + suffix[i] + 1);
            }
        }

        return longest;
    }
};