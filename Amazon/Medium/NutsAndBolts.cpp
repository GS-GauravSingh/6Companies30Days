#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        if (n == 1)
        {
            return;
        }

        vector<char> order{'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        unordered_map<char, int> hash;

        int i;
        for (i = 0; i < n; i++)
        {
            hash[nuts[i]]++;
        }

        i = 0;
        for (int j = 0; j < order.size(); j++)
        {
            if (hash.count(order[j]))
            {
                nuts[i] = order[j];
                bolts[i] = order[j];
                i++;
            }
        }
    }
};