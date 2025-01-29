#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string str)
    {

        int n = str.length();
        string pattern = "";
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            st.push(i + 1);

            if (i == n || str[i] == 'I')
            {
                while (!st.empty())
                {
                    pattern += to_string(st.top());
                    st.pop();
                }
            }
        }

        return pattern;
    }
};