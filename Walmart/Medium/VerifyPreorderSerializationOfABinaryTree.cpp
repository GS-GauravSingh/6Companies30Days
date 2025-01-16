#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {

        // split the preorder string by `,`.
        vector<string> arr;
        string temp = "";
        for (char &ch : preorder)
        {
            if (ch == ',')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }

        arr.push_back(temp);

        int availableSlots = 1; // 1 slot is for the root node.
        for (int i = 0; i < arr.size(); i++)
        {
            // decrementing the slots, it represent that the node is places in its slots and now this slot is occupied.
            availableSlots--;

            // if any movement the slots become -ve, it means its a invalid serialization.
            if (availableSlots < 0)
            {
                return false;
            }

            if (arr[i] != "#")
            {
                // If is is a non-null character, it means this node can have two children (left and right) and for two child nodes we have 2 slots one for each child.
                availableSlots += 2;
            }
        }

        return availableSlots == 0;
    }
};