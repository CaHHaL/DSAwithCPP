// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

// Note: Each element must be in exactly one subset.

// Examples:

// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].
// Input: arr = [1, 3, 5]
// Output: false
// Explanation: This array can never be partitioned into two such parts.

class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (i == arr.size())
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        bool pick = false, nopick = false;
        if (arr[i] <= sum)
            pick = solve(arr, sum - arr[i], i + 1, dp);
        nopick = solve(arr, sum, i + 1, dp);
        return dp[i][sum] = (pick || nopick);
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }

    bool equalPartition(vector<int> &arr)
    {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];
        if (total % 2 != 0)
            return false;
        return isSubsetSum(arr, total / 2);
    }
};