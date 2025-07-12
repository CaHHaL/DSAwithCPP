// Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

// to the cell diagonally up towards the right
// to the right
// to the cell diagonally down towards the right
// Find out the maximum amount of gold that he can collect until he can no longer move.

// Examples:

// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
// Output: 12
// Explaination: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.
// Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
// Output: 16
// Explaination: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3).
// Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.
// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
// Output: 14
// Explaination: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        int n = mat.size(), m = mat[0].size();
        if (i < 0 || i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int dir1 = solve(i - 1, j + 1, mat, dp);
        int dir2 = solve(i, j + 1, mat, dp);
        int dir3 = solve(i + 1, j + 1, mat, dp);
        return dp[i][j] = mat[i][j] + max({dir1, dir2, dir3});
    }

    int maxGold(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            res = max(res, solve(i, 0, mat, dp));
        return res;
    }
};