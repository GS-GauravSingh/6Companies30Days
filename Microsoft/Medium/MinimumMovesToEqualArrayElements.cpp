#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        // sort the array and take the middle element of the array because middle element is closest to all the other element.
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        int moves = 0;
        for(int& val : nums)
        {
            moves += abs(val - mid);
        }
        return moves;
    }
};

int main(void)
{
    return 0;
}