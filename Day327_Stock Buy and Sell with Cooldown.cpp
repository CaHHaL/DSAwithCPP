// Given an array arr[], where the ith element of arr[] represents the price of a stock on the ith day (all prices are non-negative integers). Find the maximum profit you can make by buying and selling stocks such that after selling a stock, you cannot buy again on the next day (i.e., there is a one-day cooldown).

// Examples:

// Input: arr[] = [0, 2, 1, 2, 3]
// Output: 3
// Explanation: You first buy on day 1, sell on day 2 then cool down, then buy on day 4, and sell on day 5. The total profit earned is (2-0) + (3-2) = 3, which is the maximum achievable profit.
// Input:  arr[] = [3, 1, 6, 1, 2, 4]
// Output: 7
// Explanation: You first buy on day 2 and sell on day 3 then cool down, then again you buy on day 5 and then sell on day 6. Clearly, the total profit earned is (6-1) + (4-2) = 7, which is the maximum achievable profit.
// Constraint:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -1 * arr[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - arr[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + arr[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};