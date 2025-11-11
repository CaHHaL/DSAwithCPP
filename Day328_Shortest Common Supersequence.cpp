// Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
// Note: s1 and s2 can have both uppercase and lowercase English letters.

// Examples:

// Input: s1 = "geek", s2 = "eke"
// Output: 5
// Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
// Input: s1 = "AGGTAB", s2 = "GXTXAYB"
// Output: 9
// Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
// Input: s1 = "geek", s2 = "ek"
// Output: 4
// Explanation: String "geek" has both string "geek" and "ek" as subsequences.


class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n + m - dp[n][m];
    }
};