#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> findSubstring(string &str, string &a)
    {
        // we have to check whether the string `a` is a substring of string `str` or not.
        if (a.length() > str.length())
        {
            return {};
        }

        // Sliding Window
        int start = 0, end = 0, n = str.length();
        vector<int> indexes; // when the substring is found, this vector is used to store the index of first matched character of the substring.
        while (end < n)
        {
            int windowSize = end - start + 1;
            if (windowSize < a.length())
            {
                end++;
            }
            else if (windowSize == a.length())
            {
                string substring = str.substr(start, end - start + 1);
                if (substring == a)
                {
                    indexes.push_back(start);
                }

                // shift the window
                start++;
                end++;
            }
        }

        return indexes;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {

        vector<int> indexes_a, indexes_b;
        indexes_a = findSubstring(s, a);
        indexes_b = findSubstring(s, b);

        // for(auto& idx : indexes_a)
        // {
        //     cout<<idx<<" ";
        // }

        // cout<<endl;
        // for(auto& idx : indexes_b)
        // {
        //     cout<<idx<<" ";
        // }

        vector<int> beautifulIndices;
        for (int i = 0; i < indexes_a.size(); i++)
        {
            bool isbeautifulIndex = false;
            for (int j = 0; j < indexes_b.size(); j++)
            {
                if (abs(indexes_a[i] - indexes_b[j]) <= k)
                {
                    isbeautifulIndex = true;
                    break;
                }
            }

            if (isbeautifulIndex)
            {
                beautifulIndices.push_back(indexes_a[i]);
            }
        }

        sort(beautifulIndices.begin(), beautifulIndices.end());
        return beautifulIndices;
    }
};