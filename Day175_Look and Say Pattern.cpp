// Given an integer n. Return the nth row of the following look-and-say pattern.
// 1
// 11
// 21
// 1211
// 111221
// Look-and-Say Pattern:

// To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// 1211 is read off as "one 1, one 2, then two 1s" or 111221.
// 111221 is read off as "three 1s, two 2s, then one 1" or 312211.
// Examples:

// Input: n = 5
// Output: 111221
// Explanation: The 5th row of the given pattern will be 111221.
// Input: n = 3
// Output: 21
// Explanation: The 3rd row of the given pattern will be 21.

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string curr = "1";
        for (int i = 2; i <= n; i++)
        {
            string curr_i = "";
            int count = 1;
            for (int j = 1; j < curr.length(); j++)
            {
                if (curr[j] == curr[j - 1])
                    count++;
                else
                {
                    curr_i += to_string(count) + curr[j - 1];
                    count = 1;
                }
            }
            curr_i += to_string(count) + curr.back();
            curr = curr_i;
        }
        return curr;
    }
};