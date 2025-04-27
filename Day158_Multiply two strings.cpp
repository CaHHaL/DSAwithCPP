// Given two numbers as strings s1 and s2. Calculate their Product.
// Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

// Examples:

// Input: s1 = "0033", s2 = "2"
// Output: "66"
// Explanation: 33 * 2 = 66
// Input: s1 = "11", s2 = "23"
// Output: "253"
// Explanation: 11 * 23  = 253
// Input: s1 = "123", s2 = "0"
// Output: "0"
// Explanation: Anything multiplied by 0 is equal to 0.

class Solution
{
public:
    string multiplyStrings(string &s1, string &s2)
    {
        bool negative = false;
        if (s1[0] == '-')
        {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-')
        {
            negative = !negative;
            s2 = s2.substr(1);
        }
        int l1 = s1.length();
        int l2 = s2.length();
        vector<int> result(l1 + l2, 0);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                result[i + j] += (s1[i] - '0') * (s2[j] - '0');
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        string ans = "";
        bool zeros = true;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            if (result[i] != 0)
                zeros = false;
            if (zeros == false)
                ans += (result[i] + '0');
        }
        if (ans.empty())
            return "0";
        if (negative)
            ans = "-" + ans;
        return ans;
    }
};