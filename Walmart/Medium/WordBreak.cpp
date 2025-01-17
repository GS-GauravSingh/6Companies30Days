#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> dp;
    bool createPartitions(int idx, string &str, unordered_set<string> &dictionary)
    {
        // Base Case
        if (idx >= str.length())
        {
            return true;
        }

        // Recursive Case - Generate all partitions
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        for (int k = idx; k < str.length(); k++)
        {
            string partitionString = str.substr(idx, k - idx + 1);
            if (dictionary.count(partitionString))
            {
                if (createPartitions(k + 1, str, dictionary))
                {
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        dp.resize(s.length(), -1);
        unordered_set<string> dictionary;
        for (string &word : wordDict)
        {
            dictionary.insert(word);
        }

        return createPartitions(0, s, dictionary);
    }
};