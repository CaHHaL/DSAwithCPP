// Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.

// Examples :

// Input: s = "1234567", k = 4
// Output: 7654321
// Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
// Input: s = "3435335", k = 3
// Output: 5543333
// Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4.
// Input: s = "1034", k = 2
// Output: 4301
// Explanation: Two swaps can make the input 1034 to 4301, swapping 1 with 4 and finally 0 with 3.
class Solution
{
public:
    string ans = "";
    void solve(int idx, int n, string str, int k)
    {
        if (k == 0 || idx >= n)
        {
            ans = max(ans, str);
            return;
        }
        for (int i = idx + 1; i < n; i++)
        {
            if (str[i] > str[idx])
            {
                swap(str[i], str[idx]);
                solve(idx + 1, n, str, k - 1);
                swap(str[i], str[idx]);
            }
        }

        solve(idx + 1, n, str, k);
    }
    string findMaximumNum(string str, int k)
    {
        int n = str.length();
        solve(0, n, str, k);
        return ans;
    }
};