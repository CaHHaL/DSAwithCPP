// Given a string s consisting of digits, determine whether it can be classified as a sum-string.

// A sum-string is a string that can be split into more than two non-empty substrings such that:

// The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

// This condition must apply recursively to the substrings before it.

// The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

// Examples:

// Input: s = "12243660"
// Output: true
// Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
// 36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
// Input: s = "1111112223"
// Output: true
// Explanation: Split the string as {"1", "111", "112", "223"}, where:
// 112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
// Input: s = "123456"
// Output: false
// Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.

class Solution
{
public:
    string addStrings(string &num1, string &num2)
    {
        if (num1.length() < num2.length())
        {
            swap(num1, num2);
        }

        int len1 = num1.length();
        int len2 = num2.length();
        string sum = "";
        int carry = 0;
        for (int i = 0; i < len2; i++)
        {
            int d1 = num1[len1 - 1 - i] - '0';
            int d2 = num2[len2 - 1 - i] - '0';
            int digit = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            sum = char(digit + '0') + sum;
        }
        for (int i = len2; i < len1; i++)
        {
            int d = num1[len1 - 1 - i] - '0';
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;
            sum = char(digit + '0') + sum;
        }
        if (carry)
        {
            sum = char(carry + '0') + sum;
        }

        return sum;
    }
    bool checkSequence(string &s, int start, int len1, int len2)
    {
        string part1 = s.substr(start, len1);
        string part2 = s.substr(start + len1, len2);
        string part3 = addStrings(part1, part2);

        int len3 = part3.length();
        if (start + len1 + len2 + len3 > s.length())
        {
            return false;
        }
        if (part3 == s.substr(start + len1 + len2, len3))
        {
            if (start + len1 + len2 + len3 == s.length())
            {
                return true;
            }
            return checkSequence(s, start + len1, len2, len3);
        }
        return false;
    }
    bool isSumString(string &s)
    {
        int n = s.length();
        for (int len1 = 1; len1 < n; len1++)
        {
            for (int len2 = 1; len1 + len2 < n; len2++)
            {
                if (checkSequence(s, 0, len1, len2))
                {
                    return true;
                }
            }
        }

        return false;
    }
};