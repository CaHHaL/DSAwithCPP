// Given three strings s1, s2, and s3 containing uppercase letters, lowercase letters, and digits, find the length of longest common sub-sequence in all three given strings.

// Examples:

// Input: s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common subsequence with length 5.
// Input: s1 = "abcd1e2", s2 = "bc12ea", s3 = "bd1ea"
// Output: 3
// Explanation:  Longest common subsequence is "b1e" i.e. length = 3.

class Solution
{
public:
    int dp[101][101][101];
    int solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (i >= s1.size() || j >= s2.size() || k >= s3.size())
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        if (s1[i] == s2[j] && s2[j] == s3[k])
            return 1 + solve(s1, s2, s3, i + 1, j + 1, k + 1);

        else
        {
            return dp[i][j][k] = max({solve(s1, s2, s3, i + 1, j, k),
                                      solve(s1, s2, s3, i, j + 1, k),
                                      solve(s1, s2, s3, i, j, k + 1),
                                      solve(s1, s2, s3, i + 1, j + 1, k),
                                      solve(s1, s2, s3, i, j + 1, k + 1),
                                      solve(s1, s2, s3, i + 1, j, k + 1)});
        }
    }
    int lcsOf3(string &s1, string &s2, string &s3)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};