// Given two matrices mat1[][] and mat2[][] of size n x n, where the elements in each matrix are arranged in strictly ascending order. Specifically, each row is sorted from left to right, and the last element of a row is smaller than the first element of the next row.
// You're given a target value x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where the sum of a + b is equal to x.

// Examples:

// Input: n = 3, x = 21,
// mat1[][] = [[1, 5, 6], [8, 10, 11], [15, 16, 18]],
// mat2[][] = [[2, 4, 7], [9, 10, 12], [13, 16, 20]]
// OUTPUT: 4
// Explanation: The pairs whose sum is found to be 21 are (1, 20), (5, 16), (8, 13) and (11, 10).
// Input: n = 2, x = 10,
// mat1[][] = [[1, 2], [3, 4]]
// mat2[][] = [[4, 5], [6, 7]]
// Output: 2
// Explanation: The pairs whose sum found to be 10 are (4, 6) and (3, 7).

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x)
    {
        int n = mat1.size();
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
        int count = 0;
        while (r1 < n && r2 >= 0)
        {
            int ele1 = mat1[r1][c1];
            int ele2 = mat2[r2][c2];
            if (ele1 + ele2 == x)
            {
                count++;
                c1++;
                c2--;
            }
            else if (ele1 + ele2 < x)
                c1++;
            else
                c2--;

            if (c1 == n)
            {
                c1 = 0;
                r1++;
            }
            if (c2 == -1)
            {
                c2 = n - 1;
                r2--;
            }
        }
        return count;
    }
};