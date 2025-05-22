// Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

// Examples:

// Input: s = "aebcbda"
// Output: 2
// Explanation: Remove characters 'e' and 'd'.
// Input: s = "geeksforgeeks"
// Output: 8
// Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
// 13 (length of s) - 5 = 8.

class Solution
{
public:
    int solve(string &s, string &r, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s.size() || j >= r.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int take = 0, nottake = 0;
        if (s[i] == r[j])
            take = 1 + solve(s, r, i + 1, j + 1, dp);
        nottake = max(solve(s, r, i, j + 1, dp), solve(s, r, i + 1, j, dp));

        return dp[i][j] = max(take, nottake);
    }
    int minDeletions(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return s.size() - solve(s, r, 0, 0, dp);
    }
};