// Given a string str consisting of lowercase english alphabets, the task is to find the number of distinct subsequences of the string
// Note: Answer can be very large, so, ouput will be answer modulo 109+7.

// Examples:

// Input: str = "gfg"
// Output: 7
// Explanation:
// The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
// Input: str = "ggg"
// Output: 4
// Explanation:
// The four distinct subsequences are "", "g", "gg", "ggg".
// Constraints:
// 1 ≤ |str| ≤ 105
// str contains lower case English alphabets
class Solution
{
public:
    int MOD = 1e9 + 7;
    int distinctSubseq(string &str)
    {
        int n = str.length();
        vector<int> dp(n + 1);
        vector<int> prev(26, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int curr = str[i - 1] - 'a';
            dp[i] = (2LL * dp[i - 1]) % MOD;
            if (prev[curr] != -1)
            {
                dp[i] = (dp[i] - dp[prev[curr]] + MOD) % MOD;
            }
            prev[curr] = i - 1;
        }
        return dp[n];
    }
};