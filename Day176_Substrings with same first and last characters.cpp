// Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

// Examples:

// Input: s = "abcab"
// Output: 7
// Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
// Input: s = "aba"
// Output: 4
// Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"

class Solution
{
public:
    int countSubstring(string &s)
    {
        int ans = s.size();
        unordered_map<int, int> mp;
        for (auto c : s)
        {
            if (mp.find(c) != mp.end())
                ans += mp[c];
            mp[c]++;
        }
        return ans;
    }
};