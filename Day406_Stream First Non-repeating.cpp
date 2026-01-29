// Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

// Examples:

// Input: s = "aabc"
// Output: a#bb
// Explanation:
// At i=0 ("a"): First non-repeating character is 'a'.
// At i=1 ("aa"): No non-repeating character, so '#'.
// At i=2 ("aab"): First non-repeating character is 'b'.
// At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'.
// Input: s = "bb"
// Output: "b#"
// Explanation:
// At i=0 ("b"): First non-repeating character is 'b'.
// At i=1 ("bb"): No non-repeating character, so '#'.
// Constraints:
// 1 ≤ s.size() ≤ 105
class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        int n = s.length();
        vector<pair<int, int>> freq(26, {0, 0});
        string result = "";
        for (int i = 0; i < n; i++)
        {
            if (freq[s[i] - 'a'].first == 0)
            {
                freq[s[i] - 'a'] = {1, i};
            }
            else
                freq[s[i] - 'a'].first++;
            int minIdx = n;
            for (int j = 0; j < 26; j++)
            {
                if (freq[j].first == 1)
                {
                    minIdx = min(minIdx, freq[j].second);
                }
            }
            if (minIdx == n)
                result += "#";
            else
                result += s[minIdx];
        }
        return result;
    }
};