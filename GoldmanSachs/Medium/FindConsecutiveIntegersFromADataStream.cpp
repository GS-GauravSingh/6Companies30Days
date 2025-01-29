#include <bits/stdc++.h>
using namespace std;

class DataStream
{

    int consecutiveCnt;
    int value;
    int k;

public:
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
        consecutiveCnt = 0;
    }

    bool consec(int num)
    {

        if (num == value)
        {
            consecutiveCnt++;
        }
        else
        {
            consecutiveCnt = 0;
        }

        return (consecutiveCnt >= k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */