// Given a positive integer n, find the minimum number of perfect squares (square of an integer) that sum up to n.

// Note: Every positive integer can be expressed as a sum of square numbers since 1 is a perfect square, and any number can be represented as 1*1 + 1*1 + 1*1 + ....

// Examples:

// Input: n = 100
// Output: 1
// Explanation: 10 * 10 = 100
// Input: n = 6
// Output: 3
// Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

class Solution
{
public:
    int minSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }
        return dp[n];
    }
};