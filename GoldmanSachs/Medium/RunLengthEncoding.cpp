#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(string s)
    {

        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            while (j < s.length() && s[j] == s[i])
            {
                j++;
            }

            ans += s[i] + to_string((j - i));
            i = j - 1;
        }

        return ans;
    }
};
