// A message containing letters A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// You are given a string digits. You have to determine the total number of ways that message can be decoded.

// Examples:

// Input: digits = "123"
// Output: 3
// Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
// Input: digits = "90"
// Output: 0
// Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.
// Input: digits = "05"
// Output: 0
// Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.

class Solution
{
public:
    int solve(string &digits, int n, int i, vector<int> &dp)
    {
        if (i == n)
            return 1;
        if (digits[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int one = solve(digits, n, i + 1, dp);
        int two = 0;
        if (i != n - 1 && (digits[i] == '1' || digits[i] == '2' && digits[i + 1] <= '6'))
            two = solve(digits, n, i + 2, dp);
        return dp[i] = one + two;
    }
    int countWays(string &digits)
    {
        int n = digits.size();
        vector<int> dp(n + 1, -1);
        return solve(digits, n, 0, dp);
    }
};