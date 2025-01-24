#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int idx = abs(arr[i]) - 1;
            arr[idx] *= -1;
        }

        int missing = 0, repeating = 0;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                nums.push_back(i + 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i]) == nums[0])
            {
                repeating = nums[0];
                missing = nums[1];
                break;
            }

            if (abs(arr[i]) == nums[1])
            {
                repeating = nums[1];
                missing = nums[0];
                break;
            }
        }

        return {repeating, missing};
    }
};