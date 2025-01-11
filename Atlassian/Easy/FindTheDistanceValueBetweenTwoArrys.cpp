#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force Approach: Using nested loops
    int findTheDistanceValue_BruteForce(vector<int> &arr1, vector<int> &arr2, int d)
    {

        int cnt = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            bool isValid = true;
            for (int j = 0; j < arr2.size(); j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
                cnt++;
        }

        return cnt;
    }

    bool binarySearch(int num, int d, vector<int> &arr)
    {

        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (abs(arr[mid] - num) <= d)
            {
                return false;
            }
            else if (arr[mid] < num)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return true;
    }

    // Optimized Approach: Using Binary Search
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        int cnt = 0;
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++)
        {
            if (binarySearch(arr1[i], d, arr2))
                cnt++;
        }

        return cnt;
    }
};