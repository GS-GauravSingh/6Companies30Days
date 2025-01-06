#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Longest Increasing Subsequence
    int maxEnvelopes_BruteForce(vector<vector<int>> &envelopes)
    {

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> lis(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] && lis[j] + 1 > lis[i])
                {
                    lis[i] = 1 + lis[j];
                }
            }
        }

        int ans = 0;
        for (int val : lis)
            ans = max(ans, val);
        return ans;
    }

    // Longest Increasing Subsequence using Binary Search
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b)
             {
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0]; });

        vector<int> lis;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                lis.push_back(envelopes[0][1]);
            }
            else if (lis.back() < envelopes[i][1])
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                if (it == lis.end())
                {
                    lis.push_back(envelopes[i][1]);
                }
                else
                {
                    *it = envelopes[i][1];
                }
            }
        }

        return lis.size();
    }
};