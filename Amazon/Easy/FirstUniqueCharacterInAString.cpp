#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force Approach - Using Nested Loops.
    int firstUniqChar_BruteForce(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            bool isNonRepeating = true;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (s[i] == s[j])
                {
                    isNonRepeating = false;
                    break;
                }
            }

            if (isNonRepeating)
            {
                return i;
            }
        }

        return -1;
    }

    // Optimized Approach - Using Hashing
    int firstUniqChar(string s)
    {

        int n = s.length();
        vector<int> charToFreq(26, 0);
        for (char &ch : s)
        {
            charToFreq[ch - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (charToFreq[ch - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};