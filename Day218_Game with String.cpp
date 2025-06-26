// Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

// The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

// Examples :

// Input: s = "abbccc", k = 2
// Output: 6
// Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
// Input: s = "aaab", k = 2
// Output: 2
// Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
class Solution
{
public:
    int minValue(string &s, int k)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int maxi = INT_MIN;
        map<int, int> mp;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
                mp[freq[i]]++;
            maxi = max(maxi, freq[i]);
        }
        while (k > 0 && maxi > 0)
        {
            int remov = min(k, mp[maxi]);
            mp[maxi] -= remov;
            mp[maxi - 1] += remov;
            if (mp[maxi] == 0)
                mp.erase(maxi--);
            k -= remov;
        }
        int value = 0;
        for (auto &it : mp)
        {
            value += it.first * it.first * it.second;
        }
        return value;
    }
};