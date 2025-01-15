#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Brute Force Solution: Using Deque - Simulate the process.
    // TC: O(n^2), where 'n' is the size of the nums array.
    // SC: O(n)
    int maxRotateFunction_BruteForce(vector<int>& nums) {
        
        deque<int> dq;
        for(int& val : nums)
        {
            dq.push_back(val);
        }

        int n = nums.size(), maxValue = INT_MIN;
        for(int shift = 0; shift<n; shift++)
        {
            int value = 0;
            for(int i = 0; i<n; i++)
            {
                value += i * dq[i];
            }

            // store the max value.
            maxValue = max(maxValue, value);

            // Perform Shifting of elements.
            dq.push_front(dq.back());
            dq.pop_back();
        }

        return maxValue;
    }

};