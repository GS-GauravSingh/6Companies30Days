#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {

        int n = s.length();
        int maxLen = 0;

        int start = 0, end = 0, cost = 0;
        while (end < n)
        {
            cost += abs(s[end] - t[end]);

            while (start <= end && cost > maxCost)
            {
                cost = cost - abs(s[start] - t[start]);
                start++;
            }

            int windowSize = end - start + 1;
            maxLen = max(maxLen, windowSize);
            end++;
        }

        return maxLen;
    }
};