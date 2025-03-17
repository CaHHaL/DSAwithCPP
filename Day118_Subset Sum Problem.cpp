// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

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
};