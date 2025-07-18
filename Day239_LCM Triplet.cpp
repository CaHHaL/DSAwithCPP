// Given a number n, find the maximum possible LCM that can be obtained by selecting three numbers less than or equal to n.
// Note : LCM stands for Lowest Common Multiple.

// Examples:

// Input: n = 9
// Output: 504
// Explanation: 504 is the maximum LCM that can be attained by any triplet of numbers less than or equal 9. The triplet which has this LCM is {7, 8, 9}.
// Input: n = 7
// Output: 210
// Explanation: 210 is the maximum LCM that can be attained by any triplet of numbers less than or equal 7. The triplet which has this LCM is {5, 6, 7}.

class Solution
{
    long lcmTriplets(long N)
    {
        if (N <= 2)
            return N;
        if ((N & 1) == 1)
            return N * (N - 1) * (N - 2);
        if (N % 3 == 0)
            return (N - 1) * (N - 3) * (N - 2);
        return N * (N - 1) * (N - 3);
    }
}