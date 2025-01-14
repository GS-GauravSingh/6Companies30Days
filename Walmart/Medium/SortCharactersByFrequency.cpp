#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {

        // 0 to 9 i.e., 10 digits, 26 - lowercase characters and 26 - uppercase characters.
        // Index 0 - 9: reserved for storing the frequency of digits.
        // Index: 10 - 35: reserved for storing frequency of uppercase characters.
        // Index: 36 - 62: reserved for storing frequency of lowercase characters.
        vector<pair<char, int>> freq(63, {'#', -1});
        for (char &ch : s)
        {
            int idx;
            if (ch >= '0' && ch <= '9')
            {
                idx = ch - '0';
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                idx = ch - 'A' + 10;
            }
            else
            {
                // ch >= 'a' && ch <= 'z'
                idx = ch - 'a' + 36;
            }

            if (freq[idx].first == '#')
            {
                freq[idx].first = ch;
                freq[idx].second = 1;
            }
            else
            {
                freq[idx].second += 1;
            }
        }

        sort(freq.begin(), freq.end(), [](pair<char, int> &a, pair<char, int> &b)
            { return a.second > b.second; });

        string ans = "";
        for (int i = 0; i < 63; i++)
        {
            while (freq[i].second > 0)
            {

                ans += freq[i].first;
                freq[i].second--;
            }
        }

        return ans;
    }
};