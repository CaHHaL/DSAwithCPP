// In the stock market, a person buys a stock and sells it on some future date. You are given an array prices[] representing stock prices on different days and a positive integer k, find out the maximum profit a person can make in at-most k transactions.

// A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.

// Examples :

// Input: prices[] = [10, 22, 5, 80], k = 2
// Output: 87
// Explaination:
// 1st transaction: Buy at 10 and sell at 22.
// 2nd transaction : Buy at 5 and sell at 80.
// Total Profit will be 12 + 75 = 87.
// Input: prices[] = [20, 580, 420, 900], k = 3
// Output: 1040
// Explaination:
// 1st transaction: Buy at 20 and sell at 580.
// 2nd transaction : Buy at 420 and sell at 900.
// Total Profit will be 560 + 480 = 1040.
// Input: prices[] = [100, 90, 80, 50, 25],  k = 1
// Output: 0
// Explaination: Selling price is decreasing continuously
// leading to loss. So seller cannot have any profit.

class Solution
{
public:
    int solve(vector<int> &prices, int k, int i, bool canBuy, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || k == 0)
            return 0;
        if (dp[i][k][canBuy] != -1)
            return dp[i][k][canBuy];
        int involve = 0, ignore = 0;
        if (canBuy == true)
        {
            involve = -prices[i] + solve(prices, k, i + 1, false, dp);
            ignore = solve(prices, k, i + 1, true, dp);
        }
        else
        {
            involve = prices[i] + solve(prices, k - 1, i + 1, true, dp);
            ignore = solve(prices, k, i + 1, false, dp);
        }
        return dp[i][k][canBuy] = max(involve, ignore);
    }
    int maxProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(prices, k, 0, true, dp);
    }
};