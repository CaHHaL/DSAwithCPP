// Given a string consisting of lowercase characters and an integer k, the task is to count all possible substrings (not necessarily distinct) that have exactly k distinct characters.

// Examples :

// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]
// Input: s = "aba", k = 2
// Output: 3
// Explanation: Possible substrings are ["ab", "ba", "aba"]
// Input: s = "aa", k = 1
// Output: 3
// Explanation: Possible substrings are ["a", "a", "aa"]

class Solution
{
public:
    int countSubstr(string &s, int k)
    {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            int distinctCnt = 0;

            for (int j = i; j < n; j++)
            {
                if (freq[s[j] - 'a'] == 0)
                {
                    distinctCnt++;
                }
                freq[s[j] - 'a']++;

                if (distinctCnt == k)
                {
                    result++;
                }
                else if (distinctCnt > k)
                {
                    break;
                }
            }
        }
        return result;
    }
};