// Given a string s, find all possible ways to partition it such that every substring in the partition is a palindrome.

// Examples:

// Input: s = "geeks"
// Output: [[g, e, e, k, s], [g, ee, k, s]]
// Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.
// Input: s = "abcba"
// Output: [[a, b, c, b, a], [a, bcb, a], [abcba]]
// Explanation: [a, b, c, b, a], [a, bcb, a] and [abcba] are the only partitions of "abcba" where each substring is a palindrome.

class Solution
{
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int idx,
                   string &s,
                   vector<string> &curr,
                   vector<vector<string>> &result)
    {
        if (idx == s.size())
        {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));

                backtrack(i + 1, s, curr, result);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s)
    {
        vector<vector<string>> result;
        vector<string> curr;

        backtrack(0, s, curr, result);
        return result;
    }
};