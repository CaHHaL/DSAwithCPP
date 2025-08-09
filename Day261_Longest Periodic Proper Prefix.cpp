// Given a string s, find the length of longest periodic proper prefix of s. If no such prefix exists, return -1.
// A periodic proper prefix is a non empty prefix of s (but not the whole string), such that repeating this prefix enough times produces a string that starts with s.

// Examples:

// Input: s = "aaaaaa"
// Output: 5
// Explanation: Repeating the proper prefix "aaaaa" forms "aaaaaaaaaa...", which contains "aaaaa" as a prefix. No longer proper prefix satisfies this.
// Input: s = "abcab"
// Output: 3
// Explanation: Repeating the proper prefix "abc" forms "abcabc., which contains "abcab" as a prefix. No longer proper prefix satisfies this.
// Input: s = "ababd"
// Output: -1
// Explanation: No proper prefix satisfying the given condition.

class Solution
{
public:
    int getLongestPrefix(string &s)
    {
        int n = s.length(), ans = -1;
        vector<int> z(n, 0);
        for (int i = 1, l = -1; i < n; i++)
        {
            if (l != -1 && i < l + z[l])
                z[i] = min(z[i - l], l + z[l] - i);
            while (s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] > l + z[l])
                l = i;
            if (i + z[i] == n)
                ans = i;
        }
        return ans;
    }
};