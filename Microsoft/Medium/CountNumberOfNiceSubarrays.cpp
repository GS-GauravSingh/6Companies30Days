#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution {
    int atMost(vector<int>& nums, int k)
    {
        int start = 0, end = 0, oddCnt = 0, ans = 0;
        while(end < nums.size())
        {
            if(nums[end] & 1)
            {
                // Odd Element
                oddCnt++;
            }

            // Shrink the window - when odd element count becomes greater than 'k'.
            while(end < nums.size() && oddCnt > k)
            {
                if(nums[start] & 1)
                {
                    // Odd Element
                    oddCnt--;
                }

                start++;
            }

            int windowSize = end - start + 1;
            ans += windowSize;
            end++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Note: Normal sliding window will not work as expected. You have to modify the sliding window a little bit.
        // ans = count of subarrays that has <= k number of odd elements - count of subarrays that has <= k-1 number of odd elements.
        return atMost(nums, k) - atMost(nums, k-1);
    }
};

int main(void)
{
    return 0;
}