// Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.
// Examples:

// Input: s1 = "geek", s2 = "gesek"
// Output: 1
// Explanation: One operation is required, inserting 's' between two 'e' in s1.
// Input: s1 = "gfg", s2 = "gfg"
// Output: 0
// Explanation: Both strings are same.
// Input: s1 = "abcd", s2 = "bcfe"
// Output: 3
// Explanation: We can convert s1 into s2 by removing ‘a’, replacing ‘d’ with ‘f’ and inserting ‘e’ at the end.

class Solution
{
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i == s1.length())
            return s2.length() - j;
        if (j == s2.length())
            return s1.length() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        else
        {
            int insert = 1 + solve(s1, s2, i, j + 1);
            int dele = 1 + solve(s1, s2, i + 1, j);
            int replace = 1 + solve(s1, s2, i + 1, j + 1);
            return dp[i][j] = min({insert, dele, replace});
        }
    }
    int editDistance(string &s1, string &s2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};
