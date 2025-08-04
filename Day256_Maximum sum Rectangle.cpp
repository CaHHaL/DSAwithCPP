// Given a 2D matrix mat[][] with dimensions n×m. Find the maximum possible sum of any submatrix within the given matrix.

// Examples:

// Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
// Output: 29
// Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle which is equal to 29.

// Input: mat[][] = [[-1, -2], [-3, -4]]
// Output: -1
// Explanation: Taking only the first cell is the optimal choice.
class Solution
{
public:
    int maxRectSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), finalmaxi = INT_MIN;
        for (int s = 0; s < m; s++)
        {
            vector<int> temp(n, 0);
            for (int e = s; e < m; e++)
            {
                for (int i = 0; i < n; i++)
                    temp[i] += mat[i][e];

                int sum = 0, maxi = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    sum += temp[i];
                    maxi = max(maxi, sum);
                    if (sum < 0)
                        sum = 0;
                }
                finalmaxi = max(finalmaxi, maxi);
            }
        }
        return finalmaxi;
    }
};