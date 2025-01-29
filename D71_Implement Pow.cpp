// Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

// Examples:

// Input: b = 3.00000, e = 5
// Output: 243.00000
// Input: b = 0.55000, e = 3
// Output: 0.16638
// Input: b = -0.67000, e = -7
// Output: -16.49971

class Solution
{
public:
    double power(double b, int e)
    {
        // Handle the case when exponent is 0
        if (e == 0)
        {
            return 1.0;
        }

        // Handling the case of negative exponent
        if (e < 0)
        {
            b = 1 / b;
            e = -e; // Make exponent positive
        }

        // Perform exponentiation by squaring
        double result = 1.0;
        while (e > 0)
        {
            if (e % 2 == 1)
            { // If e is odd
                result *= b;
            }
            b *= b; // Square the base
            e /= 2; // Divide exponent by 2
        }

        return result;
    }
};
