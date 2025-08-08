// Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
// Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input: s = "abab"
// Output: 2
// Explanation: The string "ab" is the longest prefix and suffix.
// Input: s = "aabcdaabc"
// Output: 4
// Explanation: The string "aabc" is the longest prefix and suffix.
// Input: s = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest prefix and suffix.

class Solution
{
public:
    int getLPSLength(string &s)
    {
        int n = s.length();
        vector<int> lps(n, 0);
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len == 0)
                {
                    lps[i] = len;
                    i++;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }
        return lps[n - 1];
    }
};