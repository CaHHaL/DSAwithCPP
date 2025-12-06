// You are given an integer array arr[] of size n(even). The array elements represent n coins of values v1, v2, ....vn.
// You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value.
// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

// Examples:

// Input: arr[] = [5, 3, 7, 10]
// Output: 15
// Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.
// Input: arr[] = [8, 15, 3, 7]
// Output: 22
// Explanation: The user collects the maximum value as 22(7 + 15). It is guaranteed that we cannot get more than 22 by any possible moves.
// Constraints:
// 2 <= n <= 103
// 1 <= arr[i] <= 106
class Solution
{
public:
    int maximumAmount(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int l = 0, r = i; r < n; l++, r++)
            {
                long long x = (l + 2 <= r) ? dp[l + 2][r] : 0;
                long long y = (l + 1 <= r - 1) ? dp[l + 1][r - 1] : 0;
                long long z = (l <= r - 2) ? dp[l][r - 2] : 0;
                dp[l][r] = max(arr[l] + min(x, y), arr[r] + min(y, z));
            }
        }
        return dp[0][n - 1];
    }
};