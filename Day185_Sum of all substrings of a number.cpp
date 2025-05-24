// Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.

// Note: The number may have leading zeros.
// It is guaranteed that the total sum will fit within a 32-bit signed integer.

// Examples:

// Input: s = "6759"
// Output: 8421
// Explanation:
// Sum = 6 + 7 + 5 + 9 + 67 + 75 + 59 + 675 + 759 + 6759 = 8421
// Input: s = "421"
// Output: 491
// Explanation:
// Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491

class Solution
{
public:
    int sumSubstrings(string &s)
    {
        long long int sum = 0;
        long long int mf = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            sum += (s[i] - '0') * (i + 1) * mf;
            mf = mf * 10 + 1;
        }
        return sum;
    }
};