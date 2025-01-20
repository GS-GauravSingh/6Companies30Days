#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVI(vector<int> &alice, vector<int> &bob)
    {

        int n = alice.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({alice[i] + bob[i], alice[i], bob[i]});
        }

        sort(v.begin(), v.end(), greater<vector<int>>());

        int alicePoints = 0, bobPoints = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                bobPoints += v[i][2];
            }
            else
            {
                alicePoints += v[i][1];
            }
        }

        if (alicePoints == bobPoints)
            return 0;
        else if (alicePoints < bobPoints)
            return -1;
        return 1;
    }
};