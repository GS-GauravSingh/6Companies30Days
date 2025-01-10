#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     const long long MOD = 1e9 + 7;
//     long long calculateJump(long long& jump)
//     {
//         if(jump == 0)
//         {
//             // 2 power 0 = 1.
//             return 1;
//         }

//         return ((jump * 2) % LLONG_MAX);
//     }

//     bool isItOkayToGoUp(int currStair, int destinationStair, long long jump){

//         int destStair = currStair + calculateJump(jump); // stair I reach If I decided to move up
//         return (destStair <= destinationStair || destStair - 1 == destinationStair);
//     }

//     // Brute force solution: TLE: 413/600 test cases passed
//     int findTotalWays(int currStair, int destinationStair, bool canGoDown, long long jump)
//     {
//         // Base Case
//         if(currStair == destinationStair)
//         {
//             // cout<<currStair<<" "<<destinationStair<<" "<<jump<<endl;
//             int down = 0, up = 0;
//             if(currStair > 0 && canGoDown)
//             {
//                 down = findTotalWays(currStair - 1, destinationStair, false, jump);
//             }

//             if(isItOkayToGoUp(currStair, destinationStair, jump))
//             {
//                 int destStair = currStair + pow(2, jump);
//                 up = findTotalWays(destStair, destinationStair, true, calculateJump(jump));
//             }

//             return (1 + down + up);
//         }

//         // Recursive Case
//         // cout<<currStair<<" "<<destinationStair<<" "<<jump<<endl;
//         // Down
//         int down = 0;
//         if(currStair > 0 && canGoDown)
//         {
//             down = findTotalWays(currStair - 1, destinationStair, false, jump);
//         }

//         int up = 0;
//         if(isItOkayToGoUp(currStair, destinationStair, jump))
//         {
//             int destStair = currStair + calculateJump(jump);
//             up = findTotalWays(destStair, destinationStair, true, calculateJump(jump));
//         }

//         // return total ways to reach the destination stair i.e., kth stair.
//         return (down + up);
//     }
// public:
//     int waysToReachStair(int k) {
//         long long jump = 0;
//         return findTotalWays(1, k, true, jump);
//     }
// };

class Solution {

    vector<long long> power;
    unordered_map<string, int> hash;
    int findTotalWays(int currStair, int destinationStair, bool canGoDown, int jump)
    {
        // Base Case
        if(currStair - 1 > destinationStair)
        {
            return 0;
        }

        // Memoization Step
        string key = to_string(currStair) + "_" + to_string(canGoDown) + "_" + to_string(jump);
        if(hash.count(key))
        {
            return hash[key];
        }

        int ways = 0;
        if(currStair == destinationStair)
        {
            ways += 1;
        }

        // Recursive Case
        // Down
        if(canGoDown)
        {
            ways += findTotalWays(currStair - 1, destinationStair, false, jump);
        }

        ways += findTotalWays(currStair + power[jump], destinationStair, true, jump + 1);

        // return total ways to reach the destination stair i.e., kth stair.
        return hash[key] = ways;
    }
public:
    int waysToReachStair(int k) {
        // precomputing the power's of 2.
        // INT_MAX = 2^31 - 1
        hash.clear();
        power.resize(32);
        for(int i = 0; i<32; i++)
        {
            power[i] = pow(2, i);
        }

        return findTotalWays(1, k, true, 0);
    }
};