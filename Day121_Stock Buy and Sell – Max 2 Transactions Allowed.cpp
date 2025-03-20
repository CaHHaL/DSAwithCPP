// In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

// You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).

// Examples:

// Input: prices[] = [10, 22, 5, 75, 65, 80]
// Output: 87
// Explanation:
// Trader will buy at 10 and sells at 22.
// Profit earned in 1st transaction = 22 - 10 = 12.
// Then he buys at 5 and sell at 80.
// Profit earned in 2nd transaction = 80 - 5 = 75.
// Total profit earned = 12 + 75 = 87.
// Input: prices[] = [2, 30, 15, 10, 8, 25, 80]
// Output: 100
// Explanation:
// Trader will buy at 2 and sells at 30.
// Profit earned in 1st transaction = 30 - 2 = 28.
// Then he buys at 8 and sell at 80.
// Profit earned in 2nd transaction = 80 - 8 = 72.
// Total profit earned = 28 + 72 = 100.

class Solution
{
public:
    int helper(int ind, int mode, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (ind == prices.size())
            return 0;
        if (k == 0)
            return 0;
        if (dp[ind][k][mode] != -1)
            return dp[ind][k][mode];
        if (mode == 0)
        {
            return dp[ind][k][mode] = max(helper(ind + 1, !mode, k, prices, dp) - prices[ind],
                                          helper(ind + 1, mode, k, prices, dp));
        }
        else
        {
            return dp[ind][k][mode] = max(helper(ind + 1, !mode, k - 1, prices, dp) + prices[ind],
                                          helper(ind + 1, mode, k, prices, dp));
        }
    }
    int maxProfitK(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return helper(0, 0, k, prices, dp);
    }
    int maxProfit(vector<int> &prices)
    {
        return maxProfitK(prices, 2);
    }
};