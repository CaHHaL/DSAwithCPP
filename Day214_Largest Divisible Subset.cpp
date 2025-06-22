// Given an array arr[] of distinct positive integers. Your task is to find the largest subset such that for every pair of elements (x, y) in the subset, either x divides y or y divides x.
// Note : If multiple subsets of the same maximum length exist, return the one that is lexicographically greatest, after sorting the subset in ascending order.

// Examples:

// Input: arr[] = [1, 16, 7, 8, 4]
// Output: [1, 4, 8, 16]
// Explanation: The largest divisible subset is [1, 4, 8, 16], where each element divides the next one. This subset is already the lexicographically greatest one.
// Input: arr[] = [2, 4, 3, 8]
// Output: [2, 4, 8]
// Explanation: The largest divisible subset is [2, 4, 8], where each element divides the next one. This subset is already the lexicographically greatest one.

class Solution
{
public:
    vector<int> solve(vector<int> &arr, int i, int last, vector<vector<vector<int>>> &dp)
    {
        if (i == arr.size())
            return {};

        if (!dp[i][last + 1].empty())
            return dp[i][last + 1];
        auto take = (last == -1 || arr[i] % arr[last] == 0) ? solve(arr, i + 1, i, dp) : vector<int>{};
        if (last == -1 || arr[i] % arr[last] == 0)
            take.insert(take.begin(), arr[i]);
        auto nottake = solve(arr, i + 1, last, dp);

        return dp[i][last + 1] = (nottake.size() > take.size() || (nottake.size() == take.size() && nottake > take)) ? nottake : take;
    }
    vector<int> largestSubset(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1));
        return solve(arr, 0, -1, dp);
    }
};