#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        // sort all the asteroids in ascending order
        sort(asteroids.begin(), asteroids.end());

        long long planetMass = mass * 1LL;
        for (int &astMass : asteroids)
        {
            if (planetMass >= astMass)
            {
                // cout<<mass<<endl;
                planetMass += 1LL * astMass;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};