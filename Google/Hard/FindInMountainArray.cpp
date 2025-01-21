#include <bits/stdc++.h>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{

    int findPeakIdx(MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        // // Corner Case
        // if(mountainArr.get(0) > mountainArr.get(1))
        // {
        //     return 0;
        // }
        // if(mountainArr.get(n-1) > mountainArr.get(n-1))
        // {
        //     return n-1;
        // }

        int low = 1, high = n - 2;

        while (low != high)
        {
            int mid = low + (high - low) / 2;

            // Upward Slope
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                low = mid + 1;
            }

            // downward Slope
            else
            {
                high = mid;
            }
        }

        return low;
    }

    int firstOccOnIncreasingArray(MountainArray &mountainArr, int start, int end, int target)
    {
        int idx = -1;
        int low = start, high = end;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) == target)
            {
                idx = mid;
                high = mid - 1;
            }
            else if (mountainArr.get(mid) < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return idx;
    }

    int firstOccOnDecreasingArray(MountainArray &mountainArr, int start, int end, int target)
    {
        int idx = -1;
        int low = start, high = end;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) == target)
            {
                idx = mid;
                low = mid + 1;
            }
            else if (mountainArr.get(mid) < target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return idx;
    }

public:
    // Brute Force: Using Linear Search
    // At max 100 calls are allowed to MountainArray.get() method. The maximum length of array is 10^4.
    // and for each element we are calling MountainArray.get() method. Hence it results in more than 100 calls to MountainArray.get() method.
    // and submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.
    int findInMountainArray_BruteForce(int target, MountainArray &mountainArr)
    {

        int n = mountainArr.length();
        for (int i = 0; i < n; i++)
        {
            if (mountainArr.get(i) == target)
            {
                return i;
            }
        }

        return -1;
    }

    // Optimized Approach: Using Binary Search
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int peakIdx = findPeakIdx(mountainArr);

        int l = firstOccOnIncreasingArray(mountainArr, 0, peakIdx, target);
        if (l != -1)
        {
            return l;
        }

        int r = firstOccOnDecreasingArray(mountainArr, peakIdx + 1, n - 1, target);
        return r;
    }
};