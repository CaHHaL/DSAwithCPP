// Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

// Example:

// Input: m = 6, n = 3, x = 12
// Output: 25
// Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
// Input: m = 2, n = 3, x = 6
// Output: 1
// Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.

class Solution
{
public:
    int solve(int m, int n, int x, int sum, vector<vector<int>> &dp)
    {
        if (n == 0)
            return (sum == x) ? 1 : 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        int ways = 0;
        for (int i = 1; i <= m; i++)
        {
            if (sum + i <= x)
            {
                ways += solve(m, n - 1, x, sum + i, dp);
            }
        }
        return dp[n][sum] = ways;
    }
    int noOfWays(int m, int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return solve(m, n, x, 0, dp);
    }
};