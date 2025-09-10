// Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

// Examples:

// Input: s = "768"
// Output: "867"
// Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
// Input: s = "333"
// Output: "333"
// Explanation: Performing any swaps gives the same result i.e "333".

class Solution
{
public:
    string largestSwap(string &s)
    {
        vector<bool> exist(10, 0);
        for (char ch : s)
            exist[ch - '0'] = 1;
        for (int i = 0; i < s.size() - 1; i++)
            for (int k = 9; k > s[i] - '0'; k--)
                if (exist[k])
                    for (int j = s.size() - 1; j > i; j--)
                        if (s[j] == k + '0')
                        {
                            swap(s[j], s[i]);
                            return s;
                        }
        return s;
    }
};