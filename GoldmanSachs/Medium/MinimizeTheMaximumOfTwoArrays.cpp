#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long GCD(long long a, long long b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        while (a != b)
        {
            if (a < b)
            {
                b = b - a;
            }
            else
            {
                // b < a
                a = a - b;
            }
        }

        return a;
    }

    long long LCM(long long a, long long b)
    {
        return ((a * b) / GCD(a, b));
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {

        long long low = 1, high = INT_MAX;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            /*
            if we divide a number `num` from a number `x`. Then the result of `num/x` will tell you the count of numbers
            that are divisible by `x`.

            For example:
            num = 15, x = 3
            num / x = 15 / 3 = 5, there are 5 number in the range of 1 to 15 (num = 15) that are divisible by 3 (x = 3).
            These 5 numbers are: 3, 6, 9, 12, 15.

            And if you subtract the count of number that are divisible by `x` from `num`.
            `num - (num / x)` => will give you the count of numbers that are not divisible by `x`.

            = num - (num / x)
            = 15 - (15 / 3)
            = 15 - 5 = 10
            There are 10 number in the range of 1 to 15 (num = 15) that are not divisible by 3 (x = 3).
            These 10 numbers are: 1, 2, 4, 5, 7, 8, 10, 11, 13, 14

            Another example:
            Let's take num = 15 and we have to find out the numbers in the range of 1 to 15 (num = 15),
            that are not divisible by x and y, where x = 3 and y = 5.

            num = 15, x = 3
            num / x = 15 / 3 = 5, there are 5 number in the range of 1 to 15 (num = 15) that are divisible by 3 (x = 3).
            These 5 numbers are: 3, 6, 9, 12, 15.

            num = 15, y = 5
            num / y = 15 / 5 = 3, there are 3 number in the range of 1 to 15 (num = 15) that are divisible by 5 (y = 5).
            These 3 numbers are: 5, 10, 15.

            If you noticed that there is a number `15` which is divisible by both x (x = 3) and y (y = 5).

            There are some numbers that are divisible by both `x` and `y`. When you subtract the count from mid
            to find the count of numbers that divisible by both `x` and `y`. Those numbers that are divisble by both `x` and `y`
            the count of such number are subtracted twice because they are divisible by both `x` and `y`.

            So, you have to add the count of such number once to correct the double subtraction.

            Formula: num - (num/x) - (num/y) + num/lcm(x, y), this will give you the count of numbers that are divisible by both `x` and `y`.

            See, LCM is the Lowest Common Multiple (LCM) and if a number is divisible by both `x` and `y`. Then it should by divisible by LCM(x, y).
            and when we do `num / LCM(x, y)` we get the count of numbers that are divisible by both `x` and `y`.
            */

            long long cntOne = mid - (mid / divisor1);                                                                    // count of number that are not divisible by `divisor1`.
            long long cntTwo = mid - (mid / divisor2);                                                                    // count of number that are not divisible by `divisor2`.
            long long cntThree = mid - (mid / divisor1) - (mid / divisor2) + (mid / LCM(1LL * divisor1, 1LL * divisor2)); // count of numbers thare not divisible by either `divisor1` and `divisor2`.

            if (cntOne >= uniqueCnt1 && cntTwo >= uniqueCnt2 && cntOne + cntTwo - cntThree >= uniqueCnt1 + uniqueCnt2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};