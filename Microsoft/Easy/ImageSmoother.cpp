#include <bits/stdc++.h>
using namespace std;

// Solution Class
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {

        // Question: We have to create a new image where each cell in the image is equal to the average of itself and all its 8 neighbors i.e., top-left, top, top-right, left, right, bottom-left, bottom, and bottom-right. However, if the cell doesn't have a neighbor in any direction (because it's on the edge), just ignore that non-existing neighbor when computing the average.
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ansImg(m, vector<int>(n));
        vector<int> rowCoordinates{-1, -1, -1, 0, 0, 0, +1, +1, +1}, colCoordinates{-1, 0, +1, -1, 0, +1, -1, 0, +1};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                int validNeighborsCnt = 0;

                // Neighbors
                for (int k = 0; k < 9; k++)
                {
                    int neighbor_i = i + rowCoordinates[k];
                    int neighbor_j = j + colCoordinates[k];

                    if (neighbor_i < 0 || neighbor_i >= m || neighbor_j < 0 || neighbor_j >= n)
                    {
                        // Invalid Neighbor
                        continue;
                    }

                    validNeighborsCnt++;
                    sum += img[neighbor_i][neighbor_j];
                }

                ansImg[i][j] = sum / validNeighborsCnt;
            }
        }

        return ansImg;
    }
};

int main(void)
{
    return 0;
}