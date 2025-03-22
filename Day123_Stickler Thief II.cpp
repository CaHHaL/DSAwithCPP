// You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
// Determine the maximum amount the thief can steal.

// Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

// Examples:

// Input: arr[] = [2, 3, 2]
// Output: 3
// Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.
// Input: arr[] = [1, 2, 3, 1]
// Output: 4
// Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4
// Input: arr[] = [2, 2, 3, 1, 2]
// Output: 5
// Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5

class Solution
{
public:
    int solve(vector<int> &arr, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + solve(arr, i + 2, n, dp);
        int nopick = solve(arr, i + 1, n, dp);
        return dp[i] = max(pick, nopick);
    }
    int maxValue(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        int case1 = solve(arr, 0, n - 1, dp);
        fill(dp.begin(), dp.end(), -1);
        int case2 = solve(arr, 1, n, dp);
        return max(case1, case2);
    }
};