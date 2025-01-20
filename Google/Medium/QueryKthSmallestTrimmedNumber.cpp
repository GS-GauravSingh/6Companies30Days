#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Just simulate the process.
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int k = queries[i][0];
            int trim = queries[i][1];

            vector<pair<string, int>> temp;
            for (int j = 0; j < nums.size(); j++)
            {
                string str = nums[j];
                string trimmed = str.substr(str.length() - trim);
                temp.push_back({trimmed, j});
            }

            sort(temp.begin(), temp.end());
            ans[i] = temp[k - 1].second;
        }

        return ans;
    }
};