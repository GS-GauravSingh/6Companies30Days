#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> freq, primes;
    const int MOD = 1e9 + 7;
    long long ans = 0;

    void generate(int idx, int n, vector<int> &subset, vector<int> &nums)
    {
        // Base Case
        if (idx >= n)
        {
            // Ignore empty subset.
            if (subset.size() == 0)
            {
                return;
            }

            // Now, we have to check the frequency of primes in the prime factorization of all the number.
            // If any prime number appear more than once in the prime factorization of all the numbers. Then it's not a square free subset.
            vector<int> primesCnt(30, 0);
            for (int &val : subset)
            {
                for (int &prime : primes)
                {
                    if (val % prime == 0)
                    {
                        // It means this prime number `prime` is one of the factor of this value `val`.
                        primesCnt[prime]++;
                        if (primesCnt[prime] > 1)
                        {
                            // if frequency of prime is greater than 1, then it will form a sqaure and this square is divisible by the prime's square.
                            return;
                        }
                    }
                }
            }

            // If we reach this line, it means there is no prime having frequency greater than 1.
            // Now, we can simply compute the total number of ways to gnerate this subset.
            long long currAns = 1;
            for (int &val : subset)
            {
                currAns = (currAns * freq[val]) % MOD;
            }

            ans = (ans + currAns) % MOD;
            return;
        }

        // Recursive Case
        // Take
        subset.push_back(nums[idx]);
        generate(idx + 1, n, subset, nums);
        subset.pop_back(); // Backtracking step.

        // Not Take
        generate(idx + 1, n, subset, nums);
    }

    long long power(long long x, long long n)
    {
        // Base Case
        if (n == 0)
        {
            return 1;
        }

        if (n == 1)
        {
            return x;
        }

        // // Recursive Case
        // long long ans = power(x, n/2);
        // if(n&1)
        // {
        //     // Odd Power
        //     return ((ans * ans) % MOD * x) % MOD;
        // }

        // return (ans * ans) % MOD;

        // Iterative Code.
        long long res = 1;
        while (n)
        {
            int lastBit = n & 1;
            if (lastBit)
            {
                res = (res * x) % MOD;
            }

            x = (x * x) % MOD;
            n = n >> 1;
        }

        return res;
    }

public:
    int squareFreeSubsets(vector<int> &nums)
    {

        // Important Observations:
        // 1. The square free subset doesn't contains any duplicate values because value form a square. Example: [2, 2]: Product: 4, 4 is divisible by 4 and 4 is a perfect square i.e., 2*2 = 4.
        // 2. Square free subset cannot contains any number that is divisible by a sqaure of any other number.
        // 3. The count of each prime in the product of square free subset should be 1 , else the product is divisible by that prime's square.
        // In other words, For a subset to be square-free, no prime number should appear more than once in the prime factorization of all the numbers in the subset.
        // Example: [6, 10]: Prime Factorization of 6: 2*3, Prime Factorization of 10: 2*5. Here, prime number 2 appears more than once. Hence it will form a square and the overall product (i.e., 60) is divisible with the prime's square (i.e., 2*2 = 4). 60/4 = Quotinet is 15 and Remainder is 0.

        // `freq` vector stores the frequency of each element in `nums` array.
        freq.resize(31, 0);
        for (int &val : nums)
        {
            freq[val]++;
        }

        // List of numbers/integers that are square-free, meaning these numbers are notdivisible by square of any number.
        // Not including 1, because we can add 1 to a square free subset any number of times, adding 1 doesn't affect the square free subset. That's why we handle this case separately.
        vector<int> valid{2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30};

        // List to store prime numbers less than 30. There will be total 10 prime number less than 30.
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        vector<int> subset;
        generate(0, valid.size(), subset, valid); // generate all subsets.

        // Considering the case of 1.
        // Example: [1], frequency of 1 is 1. Therefore, 2 power freq[1] is the total number of subset that contains 1 (including empty subset).
        // 2^1 = 2. Subsets: {1}, {}. Total 2 subsets.

        // Example: [1,1,1], 2 power freq[1], 2^3 = 8. Total 8 subsets: {}, {1}, {1}, {1}, {1,1}, {1,1}, {1,1}, {1,1,1}.
        long long subsetsContainsOne = power(2LL, (long long)freq[1]) - 1; // -1 is for excluding the empty subset.
        if (subsetsContainsOne)
        {
            ans = (ans + ans * subsetsContainsOne) % MOD; // adding 1 to the subsets that are generated without 1.
            ans = (ans + subsetsContainsOne) % MOD;       // adding the count of subsets that contains only 1's.
        }

        return ans;
    }
};