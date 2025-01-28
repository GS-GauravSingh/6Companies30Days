#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int totalElements;
    int row, col;
    unordered_set<int> st;

public:
    Solution(int m, int n)
    {
        row = m;
        col = n;
        totalElements = row * col;
    }

    vector<int> flip()
    {

        if (st.size() >= totalElements)
        {
            // No elements remaining to be flipped.
            return {};
        }

        int randomIdx = rand() % totalElements;
        while (st.count(randomIdx))
        {
            randomIdx = (randomIdx + 1) % totalElements;
        }

        st.insert(randomIdx);
        return {randomIdx / col, randomIdx % col};
    }

    void reset()
    {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */