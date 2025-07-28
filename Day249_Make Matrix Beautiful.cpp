// A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
// In one operation, you are allowed to increment the value of any single cell by 1.

// Examples:

// Input: mat[][] = [[1, 2],
//                 [3, 4]]
// Output: 4
// Explanation:
// Increment value of cell(0, 0) by 3,
// Increment value of cell(0, 1) by 1.
// Matrix after the operations: [[4, 3],
//                             [3, 4]]
// Here, sum of each row and column is 7.
// Hence total 4 operation are required.
// Input: mat[][] = [[1, 2, 3],
//                 [4, 2, 3],
//                 [3, 2, 1]]
// Output: 6
// Explanation:
// Increment value of cell(0, 0) by 1,
// Increment value of cell(0, 1) by 2,
// Increment value of cell(2, 1) by 1,
// Increment value of cell(2, 2) by 2.
// Matrix after the operations: [[2, 4, 3],
//                             [4, 2, 3],
//                             [3, 3, 3]]
// Here, sum of each row and column is 9.
// Hence total 6 operation are required.

class Solution
{
public:
    int balanceSums(vector<vector<int>> &mat)
    {
        int n = mat.size(), maxsum = 0, operations = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += mat[i][j];
            }
            maxsum = max(maxsum, sum);
        }
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += mat[i][j];
            }
            maxsum = max(maxsum, sum);
        }
        for (int i = 0; i < n; i++)
        {
            int rowsum = 0;
            for (int j = 0; j < n; j++)
            {
                rowsum += mat[i][j];
            }
            operations += maxsum - rowsum;
        }
        return operations;
    }
};