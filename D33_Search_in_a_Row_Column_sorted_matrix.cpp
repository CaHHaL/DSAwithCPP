// Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

// Examples:

// Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
// Output: false
// Explanation: 62 is not present in the matrix, so output is false.
// Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
// Output: true
// Explanation: 55 is present in the matrix.
// Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
// Output: true
// Explanation: 3 is present in the matrix. 

#include <vector>
using namespace std;

class Solution {
public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();       // number of rows
        int m = mat[0].size();    // number of columns

        int i = 0;  // start at the top row
        int j = m - 1;  // start at the rightmost column

        // Traverse the matrix
        while (i < n && j >= 0) {
            if (mat[i][j] == x) {
                return true;  // element found
            }
            else if (mat[i][j] > x) {
                j--;  // move left if current element is greater than x
            }
            else {
                i++;  // move down if current element is smaller than x
            }
        }

        return false;  // element not found
    }
};
