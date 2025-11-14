// Given an array stones[], where the ith element represents the number of stones in the ith pile.
// In one move, you can merge exactly k consecutive piles into a single pile, and the cost of this move is equal to the total number of stones in these k piles.
// Determine the minimum total cost required to merge all the piles into one single pile. If it is not possible to merge all piles into one according to the given rules, return -1.

// Examples:

// Input: stones[] = [1, 2, 3], k = 2
// Output: 9
// Explanation: Initially the array looks like [1, 2, 3].
// First, we merge first 2 stones, i.e., 1 and 2, array becomes [3, 3] and cost is 1 + 2 = 3.
// Then, we merge remaining stones, i.e., 3 and 3, array becomes [6] and the cost = 3 + 3 = 6.
// Total cost = 3 + 6 = 9.
// Input: stones[] = [1, 5, 3, 2, 4], k = 2
// Output: 35
// Explanation: Initially the array looks like [1, 5, 3, 2, 4].
// First, we merge 1 and 5, array becomes [6, 3, 2, 4] and cost is 1 + 5 = 6.
// Then, we merge 3 and 2, array becomes [6, 5, 4] and the cost = 3 + 2 = 5.
// Then, we merge 5 and 4, array becomes [6, 9] and the cost = 5 + 4 = 9.
// Finally, we merge 6 and 9, array becomes [15] and the cost = 6 + 9 = 15.
// Total cost = 6 + 5 + 9 + 15 = 35.
// Input: stones[] = [1, 5, 3, 2, 4], k = 4
// Output: -1
// Explanation: There is no possible way to combine the stones in piles of 4 to get 1 stone in the end.
// User Template For C++

class Solution
{
private:
    int rangeSum(vector<int> &prefix, int i, int j)
    {
        return prefix[j + 1] - prefix[i];
    }

public:
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
        {
            return -1;
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = k; len <= n; len++)
        {
            for (int i = 0; i + len <= n; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int m = i; m < j; m += (k - 1))
                {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                if ((len - 1) % (k - 1) == 0)
                {
                    dp[i][j] += rangeSum(prefix, i, j);
                }
            }
        }
        return dp[0][n - 1];
    }
};