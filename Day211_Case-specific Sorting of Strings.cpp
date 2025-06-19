// Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Examples :

// Input: s = "GEekS"
// Output: EGekS
// Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
// Input: s = "XWMSPQ"
// Output: MPQSWX
// Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.

class Solution
{
public:
    string caseSort(string &s)
    {
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                upper[s[i] - 'A']++;
            else
                lower[s[i] - 'a']++;
        }
        int u = 0, l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                while (upper[u] == 0)
                    u++;
                s[i] = char(u + 'A');
                upper[u]--;
                u = 0;
            }
            else
            {
                while (lower[l] == 0)
                    l++;
                s[i] = char(l + 'a');
                lower[l]--;
                l = 0;
            }
        }
        return s;
    }
};