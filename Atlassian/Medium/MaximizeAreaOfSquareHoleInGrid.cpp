#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveHorizontalBar = 1;
        int consecutiveHorizontalBar = 1;
        for (int i = 0; i < hBars.size() - 1; i++)
        {
            if (hBars[i] + 1 == hBars[i + 1])
            {
                consecutiveHorizontalBar++;
            }
            else
            {
                consecutiveHorizontalBar = 1;
            }

            maxConsecutiveHorizontalBar = max(maxConsecutiveHorizontalBar, consecutiveHorizontalBar);
        }

        int maxConsecutiveVerticalBar = 1;
        int consecutiveVerticalBar = 1;
        for (int i = 0; i < vBars.size() - 1; i++)
        {
            if (vBars[i] + 1 == vBars[i + 1])
            {
                consecutiveVerticalBar++;
            }
            else
            {
                consecutiveVerticalBar = 1;
            }

            maxConsecutiveVerticalBar = max(maxConsecutiveVerticalBar, consecutiveVerticalBar);
        }

        int squareSide = min(maxConsecutiveHorizontalBar, maxConsecutiveVerticalBar) + 1;
        return squareSide * squareSide;
    }
};