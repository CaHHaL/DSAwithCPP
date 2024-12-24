// Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
// Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

// Examples:

// Input: mat[][] = [[1, 5, 9], [14, 20, 21], [30, 34, 43]], x = 14
// Output: true
// Explanation: 14 is present in the matrix, so output is true.
// Input: mat[][] = [[1, 5, 9, 11], [14, 20, 21, 26], [30, 34, 43, 50]], x = 42
// Output: false
// Explanation: 42 is not present in the matrix.
// Input: mat[][] = [[87, 96, 99], [101, 103, 111]], x = 101
// Output: true
// Explanation: 101 is present in the matrix.

#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();    // number of rows
        int m = mat[0].size(); // number of columns

        // Initialize start and end pointers for binary search
        int start = 0, end = n * m - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int midElement = mat[mid / m][mid % m]; // Convert mid to 2D indices

            if (midElement == x)
            {
                return true; // x found
            }
            else if (midElement < x)
            {
                start = mid + 1; // Move to the right half
            }
            else
            {
                end = mid - 1; // Move to the left half
            }
        }

        return false; // x not found
    }
};
