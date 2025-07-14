// Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.

// Examples:

// Input : s = "2911285"
// Output : true
// Explanation: 2911285 ÷ 13 = 223945, which is a whole number with no remainder.
// Input : s = "27"
// Output : false
// Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).

class Solution
{
public:
    bool divby13(string &s)
    {
        int rem = 0;
        for (char c : s)
        {
            int digit = c - '0';
            rem = (rem * 10 + digit) % 13;
        }
        return rem == 0;
    }
};