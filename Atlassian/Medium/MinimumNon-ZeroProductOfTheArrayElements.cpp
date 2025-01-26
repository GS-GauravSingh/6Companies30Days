#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int MOD = 1e9 + 7;

    int power(long long x, long long n)
    {
        int res = 1;
        x = x % MOD;

        while (n)
        {
            if (n & 1)
            {
                res = (res * x) % MOD;
            }

            n = n >> 1;
            x = (x * x) % MOD;
        }

        return res;
    }

public:
    int minNonZeroProduct(int p)
    {

        if (p == 1)
        {
            return 1;
        }

        long long int value = (1LL << p) - 1; // same as pow(2, p) - 1, but this left shift approach is efficient and faster than pow().
        return ((value % MOD) * (power(value - 1, value / 2) % MOD)) % MOD;
    }
};