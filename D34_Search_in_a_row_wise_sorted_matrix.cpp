// Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
// Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

// Examples :

// Input: mat[][] = [[3, 4, 9],[2, 5, 6],[9, 25, 27]], x = 9
// Output: true
// Explanation: 9 is present in the matrix, so the output is true.
// Input: mat[][] = [[19, 22, 27, 38, 55, 67]], x = 56
// Output: false
// Explanation: 56 is not present in the matrix, so the output is false.
// Input: mat[][] = [[1, 2, 9],[65, 69, 75]], x = 91
// Output: false
// Explanation: 91 is not present in the matrix.

#include <vector>
using namespace std;

class Solution {
public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        for (const auto& row : mat) {
            if (binary_search(row.begin(), row.end(), x)) {
                return true;
            }
        }
        return false;
    }
};
