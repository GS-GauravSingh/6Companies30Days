#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int result = 0;
    bool isPalindrome(string &str)
    {
        int start = 0, end = str.length() - 1;
        while (start <= end)
        {
            if (str[start] != str[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void generateAllPalindromicSubsequences(int i, int n, string s1, string s2, string &str)
    {
        // Base Case
        if (i >= n)
        {
            if (isPalindrome(s1) && isPalindrome(s2))
            {
                result = max(result, (int)s1.length() * (int)s2.length());
            }

            return;
        }

        // Recursive Case
        // Pick
        s1.push_back(str[i]);
        generateAllPalindromicSubsequences(i + 1, n, s1, s2, str);
        s1.pop_back(); // Backtracking step

        // Pick
        s2.push_back(str[i]);
        generateAllPalindromicSubsequences(i + 1, n, s1, s2, str);
        s2.pop_back(); // Backtracking step

        // Not Pick
        generateAllPalindromicSubsequences(i + 1, n, s1, s2, str);
    }

public:
    int maxProduct(string s)
    {

        generateAllPalindromicSubsequences(0, s.length(), "", "", s);
        return result;
    }
};