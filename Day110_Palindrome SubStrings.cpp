// Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.

// Examples

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings are : "aa", "aa", "aaa".
// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".

class Solution
{
public:
    int palinCount(int left, int right, string &s)
    {
        int count = 0;
        while (left >= 0 && right < s.size())
        {
            if (s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
            else
                break;
        }
        return count;
    }
    int countPS(string &s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += palinCount(i - 1, i + 1, s);
        }
        for (int i = 1; i < n; i++)
        {
            count += palinCount(i - 1, i, s);
        }
        return count;
    }
};
