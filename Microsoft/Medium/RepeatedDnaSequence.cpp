#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        // Sliding Window
        unordered_map<string, int> sequence;
        int start = 0, end = 0;
        while (end < s.length())
        {
            int windowSize = end - start + 1;
            if (windowSize == 10)
            {
                sequence[s.substr(start, 10)]++;
            }

            if (windowSize < 10)
            {
                end++;
            }
            else
            {
                // windowSize > 10
                // shift the window
                start++;
                end++;
            }
        }

        vector<string> ans;
        for (auto &it : sequence)
        {
            if (it.second > 1)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

int main(void)
{
    Solution S;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = S.findRepeatedDnaSequences(s);
    for (auto val : ans)
        cout << val << endl;
    return 0;
}