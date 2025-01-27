#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        sort(access_times.begin(), access_times.end(), [](vector<string> &a, vector<string> &b)
             {

            // sort in ascending order based on access time of an employee..
            return a[1] < b[1]; });

        // map will tell you how many time a persone access their system.
        unordered_map<string, vector<int>> mp;
        for (auto &row : access_times)
        {
            mp[row[0]].push_back(stoi(row[1]));
        }

        vector<string> ans;
        for (auto &it : mp)
        {
            if (it.second.size() < 3)
            {
                continue;
            }

            bool flag = false;
            for (int i = 0; i + 3 <= it.second.size(); i++)
            {
                // 5:30 to 6:30, when converted into integer, 530 and 630
                // and the difference between them is 100.
                // if in time, then the difference between them is 1hour i.e., 60 minutes.
                flag = flag || it.second[i + 2] < (it.second[i] + 100);
            }

            if (flag)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};