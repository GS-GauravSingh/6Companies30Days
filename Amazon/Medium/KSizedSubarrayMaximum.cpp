#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        deque<int> dq;
        int n = arr.size();
        vector<int> ans;

        int start = 0, end = 0;
        while (end < n)
        {
            // with this loop I'm popping all the maximum elements that are not a part of the current window.
            while (!dq.empty() && dq.front() < start)
            {
                dq.pop_front();
            }

            // This loop maintains elements in descresing order. Therefore, the maximum element of current windows is always present at the front of the deque.
            while (!dq.empty() && arr[dq.back()] < arr[end])
            {
                dq.pop_back();
            }

            dq.push_back(end);

            int windowSize = end - start + 1;
            if (windowSize < k)
            {
                end++;
            }
            else if (windowSize == k)
            {
                ans.push_back(arr[dq.front()]);

                // shift the window
                start++;
                end++;
            }
        }

        return ans;
    }
};