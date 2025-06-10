// Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

// Examples:

// Input: s = "geek"
// Output: 6
// Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg")
// Input: s = "aaaa"
// Output: 1
// Explanation: Only one distinct string is possible after one swap(i.e "aaaa")

class Solution
{
public:
    int countStrings(string &s)
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }

        int ans = 0;
        int len = s.length();
        bool flag = false;

        for (char ch : s)
        {
            if (freq[ch] > 1)
            {
                flag = true;
            }
            ans += len - freq[ch];
        }

        ans /= 2;
        if (flag)
        {
            ans += 1;
        }

        return ans;
    }
};