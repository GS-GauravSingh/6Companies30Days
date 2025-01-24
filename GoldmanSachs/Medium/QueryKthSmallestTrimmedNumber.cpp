#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {

        vector<int> ans;
        for (auto &query : queries)
        {
            int k = query[0];
            int trim = query[1];

            vector<pair<string, int>> temp; // vector to store pair of <trimmed string, index of trimmed string>.
            for (int i = 0; i < nums.size(); i++)
            {
                string trimmedString = nums[i].substr(nums[i].length() - trim);
                temp.push_back({trimmedString, i});
            }

            // sort the temp vector to figure out the kth smallest trimmed number.
            sort(temp.begin(), temp.end(), [](pair<string, int> &a, pair<string, int> &b)
                {
                if(a.first == b.first)
                {
                    // if the strings are equal, then sort based on index in ascending order.
                    return a.second < b.second;
                }

                // if strings are not equal then sort it in ascending order.
                return a.first < b.first; });

            // store the index of kth smallest trimmed number.
            ans.push_back(temp[k - 1].second);
        }

        return ans;
    }
};