// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

// Example:

// Input: heights[] = [20, 30, 40, 20]
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20 - 30| = 10
// Total Cost = 10 + 10 = 20
// Input: heights[] = [30, 20, 50, 10, 40]
// Output: 30
// Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
// jump from stair 0 to 2: cost = |50 - 30| = 20
// jump from stair 2 to 4: cost = |40 - 50| = 10
// Total Cost = 20 + 10 = 30

class Solution
{
public:
    int minCost(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> dp(n, 1e9);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = min(dp[i], abs(heights[i + 1] - heights[i]) + dp[i + 1]);
            if (i + 2 < n)
                dp[i] = min(dp[i], abs(heights[i + 2] - heights[i]) + dp[i + 2]);
        }
        return dp[0];
    }
};