// Given a positive integer n, return the nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

// File:PascalTriangleAnimated2.gif

// Examples:

// Input: n = 4
// Output: [1, 3, 3, 1]
// Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].
// Input: n = 5
// Output: [1, 4, 6, 4, 1]
// Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].
// Input: n = 1
// Output: [1]
// Explanation: 1st row of pascal's triangle is [1].

class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        n--;
        int prev = 1;
        vector<int> res;
        res.push_back(prev);
        for (int i = 1; i <= n; i++)
        {
            int curr = prev * (n - i + 1) / i;
            res.push_back(curr);
            prev = curr;
        }
        return res;
    }
};