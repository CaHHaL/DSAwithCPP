// Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
// If there are multiple such substring of the same length found, return the one with the least starting index.

// Examples:

// Input: s = "timetopractice", p = "toc"
// Output: "toprac"
// Explanation: "toprac" is the smallest substring in which "toc" can be found.
// Input: s = "zoomlazapzo", p = "oza"
// Output: "apzo"
// Explanation: "apzo" is the smallest substring in which "oza" can be found.
// Input: s = "zoom", p = "zooe"
// Output: ""
// Explanation: No substring is present containing all characters of p.

class Solution
{
public:
    string smallestWindow(string &s, string &p)
    {
        vector<int> mp(256, 0);
        int sIndex = -1;
        int minLen = INT_MAX;
        for (int i = 0; i < p.size(); i++)
        {
            mp[p[i]]++;
        }
        int c = 0;
        int m = p.size();
        for (int j = 0, i = 0; j < s.size(); j++)
        {
            if (mp[s[j]] > 0)
                c++;
            mp[s[j]]--;
            while (c == m)
            {
                if (j - i + 1 < minLen)
                {
                    sIndex = i;
                    minLen = j - i + 1;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    c--;
                i++;
            }
        }
        if (sIndex == -1)
            return "";
        else
            return s.substr(sIndex, minLen);
    }
};