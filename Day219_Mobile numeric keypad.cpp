// There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.

// Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

// Examples :

// Input: n = 1
// Output: 10
// Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
// Input: n = 2
// Output: 36
// Explanation: Possible 2-digit numbers follow keypad moves -
// From 0 → 00, 08 (2),
// From 1 → 11, 12, 14 (3),
// From 3 → 33, 32, 36 (3), and so on,
// total 36 valid combinations are possible.

class Solution
{
public:
    int solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp)
    {
        if (i < 0 || j < 0 || i > 3 || j > 2 || mat[i][j] == -1)
            return 0;
        if (n == 0)
            return 1;
        if (dp[i][j][n] != -1)
            return dp[i][j][n];
        int ans = solve(i, j, n - 1, mat, dp) +
                  solve(i + 1, j, n - 1, mat, dp) + solve(i - 1, j, n - 1, mat, dp) +
                  solve(i, j + 1, n - 1, mat, dp) + solve(i, j - 1, n - 1, mat, dp);
        return dp[i][j][n] = ans;
    }
    int getCount(int n)
    {
        vector<vector<int>> mat = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {-1, 1, -1}};
        int count = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != -1)
                    count += solve(i, j, n - 1, mat, dp);
            }
        }
        return count;
    }
};