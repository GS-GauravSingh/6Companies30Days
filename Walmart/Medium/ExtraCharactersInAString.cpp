#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> dp;
    int func(int idx, string &str, unordered_set<string> &dictionary)
    {
        // Base Case
        if (idx >= str.length())
        {
            return 0;
        }

        // Recursive Case
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        // Option 1: Do not include the current character into our partition and in this case this character can be count as an extra character.
        int result = 1 + func(idx + 1, str, dictionary);

        for (int k = idx; k < str.length(); k++)
        {
            string partitionString = str.substr(idx, k - idx + 1);
            if (dictionary.count(partitionString))
            {
                int include = func(k + 1, str, dictionary);
                result = min(result, include);
            }
        }

        return dp[idx] = result;
    }

public:
    int minExtraChar(string s, vector<string> &wordDict)
    {
        dp.resize(s.length(), -1);
        unordered_set<string> dictionary;
        for (string &word : wordDict)
        {
            dictionary.insert(word);
        }

        return func(0, s, dictionary);
    }
};