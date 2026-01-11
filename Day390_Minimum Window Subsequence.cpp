// You are given two strings, s1 and s2. Your task is to find the smallest substring in s1 such that s2 appears as a subsequence within that substring.

// The characters of s2 must appear in the same sequence within the substring of s1.
// If there are multiple valid substrings of the same minimum length, return the one that appears first in s1.
// If no such substring exists, return an empty string.
// Note: Both the strings contain only lowercase english letters.

// Examples:

// Input: s1 = "geeksforgeeks", s2 = "eksrg"
// Output: "eksforg"
// Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is smallest and leftmost among all possible valid substrings of s1.
// Input: s1 = "abcdebdde", s2 = "bde"
// Output: "bcde"
// Explanation:  "bcde" and "bdde" are two substring of s1 where s2 occurs as subsequence but "bcde" occur first so we return that.
// Input: s1 = "ad", s2 = "b"
// Output: ""
// Explanation: There is no substring exists.
// Constraints:
// 1 ≤ s1.length ≤ 104
// 1 ≤ s2.length ≤ 50
class Solution
{
public:
    string minWindow(string &s1, string &s2)
    {
        int m = s1.size(), n = s2.size();
        string res = "";
        int minLen = INT_MAX;
        for (int i = 0; i < m; ++i)
        {
            if (s1[i] == s2[0])
            {
                int j = i;
                int k = 0;
                while (j < m && k < n)
                {
                    if (s1[j] == s2[k])
                        k++;
                    j++;
                }
                if (k == n)
                {
                    int end = j - 1;
                    k = n - 1;
                    while (j >= i)
                    {
                        j--;
                        if (s1[j] == s2[k])
                            k--;
                        if (k < 0)
                            break;
                    }
                    int start = j;
                    if (end - start + 1 < minLen)
                    {
                        minLen = end - start + 1;
                        res = s1.substr(start, minLen);
                    }
                }
            }
        }
        return res;
    }
};