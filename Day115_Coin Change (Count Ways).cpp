// Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
// Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
// Answers are guaranteed to fit into a 32-bit integer.

// Examples:

// Input: coins[] = [1, 2, 3], sum = 4
// Output: 4
// Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
// Input: coins[] = [2, 5, 3, 6], sum = 10
// Output: 5
// Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
// Input: coins[] = [5, 10], sum = 3
// Output: 0
// Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.

class Solution
{
public:
    int dp[1001][1001];
    int solve(vector<int> &coins, int sum, int i)
    {
        if (sum < 0)
            return 0;
        if (sum == 0)
            return 1;
        if (i == coins.size())
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int pick = solve(coins, sum - coins[i], i);
        int nopick = solve(coins, sum, i + 1);
        return dp[i][sum] = pick + nopick;
    }
    int count(vector<int> &coins, int sum)
    {
        memset(dp, -1, sizeof(dp));
        return solve(coins, sum, 0);
    }
};