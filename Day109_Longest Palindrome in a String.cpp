// Given a string s, your task is to find the longest palindromic substring within s.

// A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

// A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

// Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

// Examples :

// Input: s = “forgeeksskeegfor”
// Output: “geeksskeeg”
// Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
// Input: s = “Geeks”
// Output: “ee”
// Explanation: "ee" is the longest palindromic substring of "Geeks".
// Input: s = “abc”
// Output: “a”
// Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.

class Solution
{
public:
    int length(int left, int right, string &s)
    {
        int len = 0;
        while (left >= 0 && right < s.size())
        {
            if (s[left] == s[right])
            {
                len += 2;
                left--;
                right++;
            }
            else
                break;
        }
        return len;
    }
    string longestPalindrome(string &s)
    {
        int n = s.size();
        int maxlen = 1;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            int len = 1 + length(i - 1, i + 1, s);
            if (len > maxlen)
            {
                maxlen = len;
                start = i - len / 2;
            }
        }
        for (int i = 1; i < n; i++)
        {
            int len = length(i - 1, i, s);
            if (len > maxlen)
            {
                maxlen = len;
                start = i - len / 2;
            }
        }
        return s.substr(start, maxlen);
    }
};