// You are given a square matrix mat[][] of size n × n, where each cell represents either a blocked cell or a cell containing some chocolates. If mat[i][j] equals -1, then the cell is blocked and cannot be visited. Otherwise, mat[i][j] represents the number of chocolates present in that cell.
// The task is to determine the maximum number of chocolates a robot can collected by starting from the top-left cell (0, 0), moving to the bottom-right cell (n-1, n-1), and then returning back to (0, 0).
// While moving from (0, 0) to (n-1, n-1), the robot can move only in the right (i, j+1) or downward (i+1, j) directions. On the return journey from (n-1, n-1) to (0, 0), it can move only in the left (i, j-1) or upward (i-1, j) directions.

// Note: After collecting chocolates from a cell (i, j), that cell becomes empty, meaning mat[i][j] becomes 0 for next visit. If there is no valid path from (0, 0) to (n-1, n-1) or for the return trip, the result should be 0.

// Example:

// Input: mat[][] = [[0, 1, -1],
//                 [1, 1, -1],
//                 [1, 1, 2]]
// Output: 7
// Explanation:

// One of the optimal paths is to move from (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2) while going forward, and then from (2,2) -> (2,1) -> (1,1) -> (0,1) -> (0,0) while coming back. The total number of chocolates collected is 7.
// Input: mat[][] = [[1, 1, 0],
//                [1, 1, 1],
//                [0, 1, 1]]
// Output: 7
// Explanation:

// One of the optimal paths is to move from (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2) while going forward, and then from (2,2) -> (1,2) -> (1,1) -> (0,1) -> (0,0) while coming back. The total number of chocolates collected is 7.
// Input: mat[][] = [[1, 0, -1],
//                 [2, -1, -1],
//                 [1, -1, 3]]
// Output: 0
// Explanation:

// It is impossible to reach the bottom-right cell (2,2) from (0,0) because every route is blocked. Since the destination cannot be reached, the total chocolates collected is 0.
class Solution
{
public:
    int chocolatePickup(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
        {
            return 0;
        }
        vector<vector<vector<int>>> dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, -1e9)));
        dp[0][0][0] = mat[0][0];
        for (int k = 1; k < 2 * n - 1; k++)
        {
            for (int i1 = 0; i1 < n; i1++)
            {
                for (int i2 = 0; i2 < n; i2++)
                {
                    int j1 = k - i1;
                    int j2 = k - i2;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
                    {
                        continue;
                    }
                    if (mat[i1][j1] == -1 || mat[i2][j2] == -1)
                    {
                        continue;
                    }
                    int val = mat[i1][j1];
                    if (i1 != i2)
                    {
                        val += mat[i2][j2];
                    }
                    int best = -1e9;
                    if (i1 > 0 && i2 > 0)
                        best = max(best, dp[k - 1][i1 - 1][i2 - 1]);
                    if (i1 > 0 && j2 > 0)
                        best = max(best, dp[k - 1][i1 - 1][i2]);
                    if (j1 > 0 && i2 > 0)
                        best = max(best, dp[k - 1][i1][i2 - 1]);
                    if (j1 > 0 && j2 > 0)
                        best = max(best, dp[k - 1][i1][i2]);
                    if (best != -1e9)
                    {
                        dp[k][i1][i2] = best + val;
                    }
                }
            }
        }
        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};