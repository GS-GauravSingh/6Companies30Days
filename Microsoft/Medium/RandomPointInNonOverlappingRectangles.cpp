#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{

    vector<int> points;
    vector<vector<int>> rects;

public:
    Solution(vector<vector<int>> &rects)
    {

        this->rects = rects;
        int prefixPointsSum = 0;
        for (auto &rect : rects)
        {
            int x1 = rect[0];
            int x2 = rect[2];
            int y1 = rect[1];
            int y2 = rect[3];

            prefixPointsSum += abs(x2 - x1 + 1) * abs(y2 - y1 + 1);
            points.push_back(prefixPointsSum);
        }
    }

    vector<int> pick()
    {

        int totalPoints = points.back();
        int target = rand() % totalPoints;
        int idx = upper_bound(points.begin(), points.end(), target) - points.begin();

        vector<int> rect = rects[idx];

        int x = rand() % abs(rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % abs(rect[3] - rect[1] + 1) + rect[1];

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(void)
{

    return 0;
}