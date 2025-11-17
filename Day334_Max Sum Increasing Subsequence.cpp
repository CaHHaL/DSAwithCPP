// Given an array of positive integers arr[], find the maximum sum of a subsequence such that the elements of the subsequence form a strictly increasing sequence.
// In other words, among all strictly increasing subsequences of the array, return the one with the largest possible sum.

// Examples:

// Input: arr[] = [1, 101, 2, 3, 100]
// Output: 106
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3, 100].
// Input: arr[] = [4, 1, 2, 3]
// Output: 6
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3].
// Input: arr[] = [4, 1, 2, 4]
// Output: 7
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 4].
class Solution
{
public:
    int maxSumIS(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = max(dp[i], arr[i]);
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] > arr[j])
                {
                    dp[i] = max(dp[i], arr[i] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};