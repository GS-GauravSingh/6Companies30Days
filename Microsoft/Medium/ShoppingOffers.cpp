#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void func(int idx, int n, vector<int> &products, vector<vector<int>> &allProducts, vector<vector<int>> &offers)
    {
        // Base Case
        if (idx >= offers.size())
        {
            allProducts.push_back(products);
            return;
        }

        // Recursive Case
        // Consider the 'ith' offer.
        // We can only consider this offer if the number of items of any particular product is <= the need of that product.
        bool canConsider = true;
        for (int i = 0; i < n; i++)
        {
            // if the quantity of 'ith' product in the offer is greater than the requirement. Then we cannot consider this offer.
            if (offers[idx][i] > products[i])
            {
                canConsider = false;
                break;
            }
        }

        if (canConsider)
        {
            for (int i = 0; i < n; i++)
            {
                products[i] -= offers[idx][i];
            }

            products[n] += offers[idx][n]; // update the price spent to buy the products.

            func(idx, n, products, allProducts, offers); // Recursive Call

            // Backtracking Steps
            for (int i = 0; i < n; i++)
            {
                products[i] += offers[idx][i];
            }

            products[n] -= offers[idx][n];
        }

        // Skip the 'ith' offer.
        func(idx + 1, n, products, allProducts, offers);
    }

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {

        int n = price.size();
        vector<int> products(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            products[i] = needs[i];
        }

        vector<vector<int>> allProducts;
        func(0, n, products, allProducts, special);

        // calculate the total price you need to spent if you decided to buy all products on their original price.
        int originalTotalPrice = 0;
        for (int i = 0; i < n; i++)
        {
            originalTotalPrice += price[i] * needs[i];
        }

        // to store the lowest price.
        int lowestPrice = INT_MAX;

        for (int i = 0; i < allProducts.size(); i++)
        {
            int totalPrice = 0;
            for (int j = 0; j < allProducts[0].size() - 1; j++)
            {
                // buy all the remaining products on their original price.
                if (allProducts[i][j] != 0)
                {
                    totalPrice += allProducts[i][j] * price[j];
                }
            }

            totalPrice += allProducts[i].back(); // add up the price you spent to buy product from the offers.

            // compare the price.
            lowestPrice = min(lowestPrice, totalPrice);
        }

        return lowestPrice;
    }
};