// Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

// A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

// Examples:

// Input: s1 = "ABCDGH", s2 = "AEDFHR"
// Output: 3
// Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
// Input: s1 = "ABC", s2 = "AC"
// Output: 2
// Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
// Input: s1 = "XYZW", s2 = "XYWZ"
// Output: 3
// Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
class Solution
{
public:
    int dp[1001][1001];
    int LCS(int i, int j, string &s1, string &s2)
    {
        if (i == s1.size() || j == s2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);
        else
            return dp[i][j] = max(LCS(i, j + 1, s1, s2), LCS(i + 1, j, s1, s2));
    }
    int lcs(string &s1, string &s2)
    {
        memset(dp, -1, sizeof(dp));
        return LCS(0, 0, s1, s2);
    }
};