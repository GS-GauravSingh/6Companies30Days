#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Recursive Code
    int func(int idx, bool canBuy, int transactions, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        // All Transacions Complete.
        if (transactions == 0)
        {
            return 0;
        }

        // Base Case
        if (idx >= prices.size())
        {
            return 0;
        }

        // Recursive Case
        if (dp[idx][canBuy][transactions] != -1)
        {
            return dp[idx][canBuy][transactions];
        }

        // Buy
        if (canBuy)
        {
            // Option 1: Buy the stock at this index.
            int op1 = -prices[idx] + func(idx + 1, false, transactions, prices, dp);

            // Option 2: Not Buy the stock at this index.
            int op2 = 0 + func(idx + 1, canBuy, transactions, prices, dp);

            return dp[idx][canBuy][transactions] = max(op1, op2);
        }

        // Sell
        else
        {

            // Option 1: Sell the stock at this index.
            int op1 = +prices[idx] + func(idx + 1, true, transactions - 1, prices, dp);

            // Option 2: Not Sell the stock at this index.
            int op2 = 0 + func(idx + 1, canBuy, transactions, prices, dp);

            return dp[idx][canBuy][transactions] = max(op1, op2);
        }
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        // // Recursive and Memoized Solution
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        // return func(0, true, k, prices, dp);

        // // DP - Tabulation Solution
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

        // for(int idx = prices.size() - 1; idx >= 0; idx--)
        // {
        //     for(int canBuy = 0; canBuy <= 1; canBuy++)
        //     {
        //         for(int transactions = 1; transactions <= k; transactions++)
        //         {

        //             // Buy
        //             if(canBuy)
        //             {
        //                 // Option 1: Buy the stock at this index.
        //                 int op1 = -prices[idx] + dp[idx + 1][0][transactions];

        //                 // Option 2: Not Buy the stock at this index.
        //                 int op2 = 0 + dp[idx + 1][canBuy][transactions];

        //                 dp[idx][canBuy][transactions] = max(op1, op2);
        //             }

        //             // Sell
        //             else{

        //                 // Option 1: Sell the stock at this index.
        //                 int op1 = +prices[idx] + dp[idx + 1][1][transactions - 1];

        //                 // Option 2: Not Sell the stock at this index.
        //                 int op2 = 0 + dp[idx + 1][canBuy][transactions];

        //                 dp[idx][canBuy][transactions] = max(op1, op2);
        //             }
        //         }
        //     }
        // }

        // return dp[0][1][k];

        // DP - Space Optimized Solution - 2D
        vector<vector<int>> nextRow(2, vector<int>(k + 1, 0));
        vector<vector<int>> currRow(2, vector<int>(k + 1, 0));
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int transactions = 1; transactions <= k; transactions++)
                {

                    // Buy
                    if (canBuy)
                    {
                        // Option 1: Buy the stock at this index.
                        int op1 = -prices[idx] + nextRow[0][transactions];

                        // Option 2: Not Buy the stock at this index.
                        int op2 = 0 + nextRow[canBuy][transactions];

                        currRow[canBuy][transactions] = max(op1, op2);
                    }

                    // Sell
                    else
                    {

                        // Option 1: Sell the stock at this index.
                        int op1 = +prices[idx] + nextRow[1][transactions - 1];

                        // Option 2: Not Sell the stock at this index.
                        int op2 = 0 + nextRow[canBuy][transactions];

                        currRow[canBuy][transactions] = max(op1, op2);
                    }
                }
            }

            nextRow = currRow;
        }

        return nextRow[1][k];
    }
};