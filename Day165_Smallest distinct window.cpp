// Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

// Example:

// Input: str = "aabcbcdbca"
// Output: 4
// Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
// Input: str = "aaab"
// Output: 2
// Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
// Input: str = "geeksforgeeks"
// Output: 8
// Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks".

class Solution
{
public:
    int findSubString(string &str)
    {
        set<char> s;
        for (char c : str)
            s.insert(c);
        int len = s.size();
        int ans = INT_MAX;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < str.size())
        {
            mp[str[j]]++;
            if (mp.size() >= len)
            {
                while (mp[str[i]] > 1)
                {
                    mp[str[i]]--;
                    i++;
                }
                ans = min(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};