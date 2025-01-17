#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> wordsFreq;
        for (string &word : words)
        {
            wordsFreq[word]++;
        }

        vector<pair<string, int>> wordsArr;
        for (auto &it : wordsFreq)
        {
            wordsArr.push_back({it.first, it.second});
        }

        sort(wordsArr.begin(), wordsArr.end(), [](pair<string, int> &a, pair<string, int> &b)
            {
            if(a.second == b.second)
            {
                // same frequency
                return a.first < b.first;
            }
            else{
                // if frequency is not same, then sort based on the frequency of words in descending order.
                return a.second > b.second;
            } });

        // return the first k strings from the wordsArr vector.
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(wordsArr[i].first);
        }

        return ans;
    }
};