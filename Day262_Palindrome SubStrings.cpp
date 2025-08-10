// Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.

// Note: A substring is palindromic if it reads the same forwards and backwards.

// Examples:

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".
// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".
// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".

class Solution
{
public:
    int countPali(int i, int j, string &s)
    {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            count++, i--, j++;
        }
        return count;
    }
    int countPS(string &s)
    {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += countPali(i, i + 1, s);
            result += countPali(i, i, s);
        }
        return result - n;
    }
};