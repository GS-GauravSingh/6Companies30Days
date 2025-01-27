#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCollisions(string directions)
    {

        int collisionsCount = 0;
        stack<char> st;
        for (char &direction : directions)
        {
            if (direction == 'R')
            {
                st.push('R');
            }
            else if (direction == 'S')
            {
                // Now we need to check, is there any car before the current car which is staying where it is.
                // is there any car moving in the right direction
                // If yes, then that car will collied with this car.
                while (!st.empty() && st.top() == 'R')
                {
                    // when a moving car collides with a stayig car, then the collision count will increase by 1.
                    collisionsCount++;
                    st.pop();
                }

                st.push('S');
            }
            else if (direction == 'L')
            {
                // Now, we have to check whether there is any car present before that is moving in the right direction.
                // If yes, then a collision will happen.
                if (!st.empty() && st.top() == 'R')
                {
                    collisionsCount += 2;
                    st.pop();

                    // Now, after collision, the cars involved in the collision will no longes move and will stay at the point where they collied.
                    // Basically they become a staying car.
                    while (!st.empty() && st.top() == 'R')
                    {
                        // when a moving car collides with a stayig car, then the collision count will increase by 1.
                        collisionsCount++;
                        st.pop();
                    }

                    st.push('S');
                }
                else if (!st.empty() && st.top() == 'S')
                {
                    collisionsCount++;
                }
            }
        }

        return collisionsCount;
    }
};