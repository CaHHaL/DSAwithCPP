class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        while (n >= 0)
        {
            if (digits[n] != 9)
            {
                digits[n] = digits[n] + 1;
                return digits;
            }

            digits[n] = 0;
            n--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};