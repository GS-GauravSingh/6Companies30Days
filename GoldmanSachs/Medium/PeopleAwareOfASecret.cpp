#include <bits/stdc++.h>
using namespace std;

class Solution
{

    const int MOD = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<long long> days(n, 0); // initially no one knows the secret. it represents how many people know the secret on `ith` day.
        days[0] = 1;                  // at day 0 only 1 person knows the secret.

        for (int i = 0; i < n; i++)
        {
            // 'ith' person will start telling the secret to others after delays days
            // Once `ith` persone knows the secret, then they start telling the secret to others after the delays days.
            // it means `ith` person will start spreading the secret from `i+delay`.
            // and `i+forgot` day they forgot the secret.
            for (int j = i + delay; j < n && j < i + forget; j++)
            {
                days[j] = (days[i] + days[j]) % MOD;
            }
        }

        // find the number of people who knows the secret at the end of the `nth` day.
        long long ans = 0;
        for (int i = n - forget; i < n; i++)
        {
            ans = (ans + days[i]) % MOD;
        }

        return ans;
    }
};