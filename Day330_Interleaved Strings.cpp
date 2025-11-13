// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
// Interleaving of two strings s1 and s2 is a way to mix their characters to form a new string s3, while maintaining the relative order of characters from s1 and s2. Conditions for interleaving:

// Characters from s1 must appear in the same order in s3 as they are in s1.
// Characters from s2 must appear in the same order in s3 as they are in s2.
// The length of s3 must be equal to the combined length of s1 and s2.
// Examples :

// Input: s1 = "AAB", s2 = "AAC", s3 = "AAAABC"
// Output: true
// Explanation: The string "AAAABC" has all characters of the other two strings and in the same order.
// Input: s1 = "AB", s2 = "C", s3 = "ACB"
// Output: true
// Explanation: s3 has all characters of s1 and s2 and retains order of characters of s1.
// Input: s1 = "YX", s2 = "X", s3 = "XXY"
// Output: false
// Explanation: "XXY " is not interleaved of "YX" and "X". The strings that can be formed are YXX and XYX
// Constraints:
// 1 ≤ s1.length, s2.length ≤ 300
// 1 ≤ s3.length ≤ 600

class Solution
{
public:
    bool isInterleave(string &s1, string &s2, string &s3)
    {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (n + m != l)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                bool fromS1 = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                bool fromS2 = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                dp[i][j] = fromS1 || fromS2;
            }
        }

        return dp[n][m];
    }
};