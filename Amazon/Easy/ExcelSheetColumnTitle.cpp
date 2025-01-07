#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            int rem = columnNumber % 26;
            char ch = rem + 'A';
            ans.push_back(ch);

            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};