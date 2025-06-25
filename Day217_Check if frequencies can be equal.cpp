// Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

// Examples:

// Input: s = "xyyz"
// Output: true
// Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
// Input: s = "xyyzz"
// Output: true
// Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
// Input: s = "xxxxyyzz"
// Output: false
// Explanation: Frequency can not be made same by removing at most one character.

class Solution
{
public:
    bool sameFreq(string &s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        unordered_map<int, int> mp;
        for (char f : freq)
            if (f)
                mp[f]++;

        if (mp.size() == 1)
            return true;
        if (mp.size() != 2)
            return false;

        auto it = mp.begin();
        int F1 = it->first, c1 = it->second;
        it++;
        int F2 = it->first, c2 = it->second;
        if ((F1 == 1 && c1 == 1) || (F2 == 1 && c2 == 1))
            return true;
        if ((abs(F1 - F2) == 1) && ((F1 > F2 && c1 == 1) || (F2 > F1 && c2 == 1)))
            return true;

        return false;
    }
};