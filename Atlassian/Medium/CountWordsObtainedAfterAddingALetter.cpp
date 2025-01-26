#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        // sort startWords & the strings present in it
        for (auto &s : startWords)
        {
            // order of characters doesn't matter as we can rearrange them
            sort(s.begin(), s.end());
        }
        sort(startWords.begin(), startWords.end());

        int cnt = 0;
        for (auto &t : targetWords)
        {
            sort(t.begin(), t.end()); // sort the target string
            int n = t.size();
            for (int i = 0; i < n; i++)
            {
                string s = t.substr(0, i) + t.substr(i + 1, n - i - 1); // string excluding t[i]
                // search and count if 's' is present in 'startWords'
                // which is used to form target 't'
                if (binary_search(startWords.begin(), startWords.end(), s))
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};