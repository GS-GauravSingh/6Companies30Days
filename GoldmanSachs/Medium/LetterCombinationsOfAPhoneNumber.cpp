#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void generate(int idx, string currCombination, string &digit, unordered_map<char, string> &digitToLetters, vector<string> &allCombinations)
    {
        // Base Case
        if (idx >= digit.length())
        {
            allCombinations.push_back(currCombination);
            return;
        }

        // Recursive Case - Generate all combinations.
        for (auto &letter : digitToLetters[digit[idx]])
        {
            generate(idx + 1, currCombination + letter, digit, digitToLetters, allCombinations);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {

        if (digits.empty())
        {
            return {};
        }

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        vector<string> allCombinations;
        generate(0, "", digits, digitToLetters, allCombinations);
        return allCombinations;
    }
};