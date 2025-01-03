#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {

        int nearestX = max(x1, min(x2, xCenter));
        int nearestY = max(y1, min(y2, yCenter));
        int distX = xCenter - nearestX;
        int distY = yCenter - nearestY;
        return distX * distX + distY * distY <= radius * radius;
    }
};

int main(void)
{
    return 0;
}