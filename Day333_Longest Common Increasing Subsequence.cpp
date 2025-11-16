// Given two arrays, a[] and b[], find the length of the longest common increasing subsequence(LCIS).

// Note:  LCIS refers to a subsequence that is present in both arrays and strictly increases.

// Examples:

// Input: a[] = [3, 4, 9, 1], b[] = [5, 3, 8, 9, 10, 2, 1]
// Output: 2
// Explanation: The longest increasing subsequence that is common is [3, 9] and its length is 2.
// Input: a[] = [1, 1, 4, 3], b[] = [1, 1, 3, 4]
// Output: 2
// Explanation: There are two common subsequences [1, 4] and [1, 3] both of length 2.
// Constraints:
// 1 ≤ a.size(), b.size() ≤ 103
// 1 ≤ a[i], b[i] ≤ 104
class Solution
{
public:
    int LCIS(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++)
        {
            int currMax = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    dp[j] = currMax + 1;
                }
                if (a[i] > b[j])
                {
                    currMax = max(currMax, dp[j]);
                }
            }
        }
        int ans = 0;
        for (int x : dp)
        {
            ans = max(ans, x);
        }
        return ans;
    }
};