#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force - Generate all pairs.
    int numFriendRequests_BruteForce(vector<int> &ages)
    {

        int n = ages.size();
        int requestCnt = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                // A Person cannot send a request to themself.
                if (x == y)
                {
                    continue;
                }

                if (ages[x] * 0.5 + 7 >= ages[y])
                    continue;
                if (ages[y] > ages[x])
                    continue;
                if (ages[y] > 100 && ages[x] < 100)
                    continue;

                requestCnt++;
            }
        }

        return requestCnt;
    }

    // Better Approach: Hashing
    int numFriendRequests(vector<int> &ages)
    {

        int n = ages.size();
        vector<int> freq(121, 0);
        for (int &val : ages)
        {
            freq[val]++;
        }

        int requestCnt = 0;
        for (int x = 1; x <= 120; x++)
        {
            for (int y = 1; y <= 120; y++)
            {
                if (x * 0.5 + 7 >= y)
                    continue;
                if (y > x)
                    continue;
                if (y > 100 && x < 100)
                    continue;

                requestCnt += freq[x] * freq[y];
                if (x == y)
                {
                    requestCnt -= freq[x]; // or you can subtract freq[y] also.
                }
            }
        }

        return requestCnt;
    }
};