// Given a string s, return the length of the longest palindromic subsequence.

// A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

// A palindromic sequence is a sequence that reads the same forward and backward.

// Examples:

// Input: s = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
// Input: s = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
// Input: s = "agbdba"
// Output: 5
// Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.

class Solution
{
public:
    int dp[1001][1001];
    int LCS(string &a, string &b, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
            return dp[i][j] = 1 + LCS(a, b, i + 1, j + 1);
        else
            return dp[i][j] = max(LCS(a, b, i, j + 1), LCS(a, b, i + 1, j));
    }
    int longestPalinSubseq(string &s)
    {
        memset(dp, -1, sizeof(dp));
        string rev = s;
        reverse(rev.begin(), rev.end());
        return LCS(s, rev, 0, 0);
    }
};