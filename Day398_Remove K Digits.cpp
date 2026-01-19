// Given a non-negative integer s represented as a string and an integer k, remove exactly k digits from the string so that the resulting number is the smallest possible, while maintaining the relative order of the remaining digits.

// Note : The resulting number must not contain any leading zeros.
// If the resulting number is an empty string after the removal, return "0".

// Examples:

// Input: s = "4325043", k = 3
// Output: 2043
// Explanation: Remove the three digits 4, 3, and 5 to form the new number "2043" which is smallest among all possible removal.
// Input: s = "765028321", k = 5
// Output: 221
// Explanation: Remove the five digits 7, 6, 5, 8 and 3 to form the new number "0221". Since we are not supposed to keep leading 0s, we get "221".
// Constraints:
// 1 ≤ k ≤ |s| ≤ 106
class Solution
{
public:
    virtual string removeKdig(string &s, int k)
    {
        string ans;
        stack<char> st;
        for (char &ch : s)
        {
            while (k > 0 && (!st.empty()) && (ch < st.top()))
            {
                st.pop();
                k--;
            }
            if (st.empty() && ch == '0')
                continue;
            st.push(ch);
        }
        while (k > 0 && (!st.empty()))
        {
            st.pop();
            k--;
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if (ans == "")
            return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};