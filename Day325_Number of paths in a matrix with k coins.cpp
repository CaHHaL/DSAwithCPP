// You are given a matrix mat[][] of size n x m, where each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from the top left cell of the matrix to the bottom right cell.
// From a cell (i, j), you can only move to cell (i+1, j) or (i, j+1).

// Note: It is guaranteed that the answer will not exceed 32-bit integer limits.

// Examples:

// Input: k = 12, mat[] = [[1, 2, 3],
//                       [4, 6, 5],
//                       [3, 2, 1]]
// Output: 2
// Explanation: There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
// Input: k = 16, mat[] = [[1, 2, 3],
//                       [4, 6, 5],
//                       [9, 8, 7]]
// Output: 0
// Explanation: There are no possible paths that lead to sum = 16.

class Solution
{
public:
    int n, m;
    int dp[101][101][101];
    int solve(int i, int j, int k, vector<vector<int>> &mat)
    {
        if (i >= n || j >= m || k < 0)
            return 0;
        k -= mat[i][j];
        if (k < 0)
            return 0;
        if (i == n - 1 && j == m - 1)
            return (k == 0);
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int down = solve(i + 1, j, k, mat);
        int right = solve(i, j + 1, k, mat);
        return dp[i][j][k] = down + right;
    }
    int numberOfPath(vector<vector<int>> &mat, int k)
    {
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, mat);
    }
};