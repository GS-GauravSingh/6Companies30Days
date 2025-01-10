#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool isPrefixMatched(string &str, string &prefix)
    {
        if (str.length() < prefix.length())
        {
            return false;
        }

        int n = prefix.length();
        return str.substr(0, n) == prefix;
    }

public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        sort(contact, contact + n);

        // vector to store only unique contacts.
        vector<string> contacts;
        contacts.push_back(contact[0]);
        for (int i = 1; i < n; i++)
        {
            if (contacts.back() != contact[i])
            {
                contacts.push_back(contact[i]);
            }
        }

        int s_len = s.length();
        for (int i = 0; i < s_len; i++)
        {
            string prefix = s.substr(0, i + 1);
            vector<string> temp;
            for (int j = 0; j < contacts.size(); j++)
            {
                if (isPrefixMatched(contacts[j], prefix))
                {
                    temp.push_back(contacts[j]);
                }
            }

            if (temp.empty())
            {
                temp.push_back("0");
            }

            ans.push_back(temp);
        }

        return ans;
    }
};