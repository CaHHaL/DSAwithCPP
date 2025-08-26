// Given two strings s1 and s2. You have to check that s1 is a subsequence of s2 or not.
// Note: A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

// Examples:

// Input: s1 = "AXY", s2 = "YADXCP"
// Output: false
// Explanation: s1 is not a subsequence of s2 as 'Y' appears before 'A'.
// Input: s1 = "gksrek", s2 = "geeksforgeeks"
// Output: true
// Explanation: If we combine the bold character of "geeksforgeeks", it equals to s1. So s1 is a subsequence of s2.

class Solution
{
public:
    bool isSubSeq(string &s1, string &s2)
    {
        int i1 = 0, i2 = 0;
        int n1 = s1.size(), n2 = s2.size();
        while (i1 < n1 && i2 < n2)
        {
            if (s1[i1] == s2[i2])
            {
                i1++;
                i2++;
            }
            else
            {
                i2++;
            }
        }
        return i1 == n1;
    }
};