// You are given a wooden stick of length n, labeled from 0 to n. You are also given an integer array cuts[], where each element cuts[i] represents a position along the stick at which you can make a cut.
// Each cut costs an amount equal to the length of the stick being cut at that moment. After performing a cut, the stick is divided into two smaller sticks.
// You can perform the cuts in any order. Your task is to determine the minimum total cost required to perform all the cuts.

// Example:

// Input: n = 10, cuts[] = [2, 4, 7]
// Output: 20
// Explanation:

// If we cut the stick in the order [4, 2, 7], the cost will be 10 + 4 + 6 = 20, which is the minimum total cost.
// Input: n = 8, cuts[] = [1, 6, 3, 5]
// Output: 19
// Explanation: If we cut the stick in the order [3, 6, 1, 5], the cost will be 8 + 5 + 3 + 3 = 19, which is the minimum total cost.
class Solution
{
public:
    int minCutCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; len++)
        {
            for (int i = 0; i + len < m; i++)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
                if (dp[i][j] == INT_MAX)
                    dp[i][j] = 0;
            }
        }
        return dp[0][m - 1];
    }
};