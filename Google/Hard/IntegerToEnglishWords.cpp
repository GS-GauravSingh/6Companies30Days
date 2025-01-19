#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, string> belowTen = {
        {0, ""},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
    };

    unordered_map<int, string> belowTwenty = {
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
    };

    unordered_map<int, string> belowHundred = {
        {1, "Ten"},
        {2, "Twenty"},
        {3, "Thirty"},
        {4, "Forty"},
        {5, "Fifty"},
        {6, "Sixty"},
        {7, "Seventy"},
        {8, "Eighty"},
        {9, "Ninety"},
    };

    string solve(int num)
    {
        // Base Case
        if (num < 10)
        {
            return belowTen[num];
        }

        if (num < 20)
        {
            return belowTwenty[num];
        }

        if (num < 100)
        {
            // Example: num = 67
            // 67 / 10 = 6 -> Sixty
            // 67 % 10 = 7 -> Seven
            // return belowHundred[(num / 10)] + solve(num % 10); // Correct
            return belowHundred[(num / 10)] + ((num % 10 == 0) ? "" : " " + belowTen[(num % 10)]);
        }

        // Recursive Case
        if (num < 1000)
        {
            // Example: num = 567
            // 567 / 100 = 5
            // 567 % 100 = 67
            return solve(num / 100) + " Hundred" + ((num % 100 == 0) ? "" : " " + solve(num % 100));
        }

        if (num < 1000000)
        {
            return solve(num / 1000) + " Thousand" + ((num % 1000 == 0) ? "" : " " + solve(num % 1000));
        }

        if (num < 1000000000)
        {
            return solve(num / 1000000) + " Million" + ((num % 1000000 == 0) ? "" : " " + solve(num % 1000000));
        }

        return solve(num / 1000000000) + " Billion" + ((num % 1000000000 == 0) ? "" : " " + solve(num % 1000000000));
    }

public:
    string numberToWords(int num)
    {

        // Base Case
        if (num == 0)
        {
            return "Zero";
        }

        return solve(num);
    }
};