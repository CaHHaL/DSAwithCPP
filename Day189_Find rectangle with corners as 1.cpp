// Given an n x m binary matrix mat[][] containing only 0s and 1s, determine if there exists a rectangle within the matrix such that all four corners of the rectangle are 1. If such a rectangle exists, return true; otherwise, return false.

// Example:

// Input: mat[][] =
// [[1, 0, 0, 1, 0],
// [0, 0, 1, 0, 1],
// [0, 0, 0, 1, 0],
// [1, 0, 1, 0, 1]]
// Output: true
// Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4)
// Input: mat[][] =
// [[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
// Output: false
// Explanation: There are no valid corners.

class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int r1 = 0; r1 < m; r1++)
        {
            for (int r2 = r1 + 1; r2 < m; r2++)
            {
                for (int c1 = 0; c1 < n; c1++)
                {
                    for (int c2 = c1 + 1; c2 < n; c2++)
                    {
                        if (mat[r1][c1] == 1 && mat[r1][c2] == 1 &&
                            mat[r2][c1] == 1 && mat[r2][c2] == 1)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};