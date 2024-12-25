// You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

// Examples:

// Input: mat[][] = [[1, -1, 1],
//                 [-1, 0, 1],
//                 [1, -1, 1]]
// Output: [[1, 0, 1],
//         [0, 0, 0],
//         [1, 0, 1]]
// Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
// Input: mat[][] = [[0, 1, 2, 0],
//                 [3, 4, 5, 2],
//                 [1, 3, 1, 5]]
// Output: [[0, 0, 0, 0],
//         [0, 4, 5, 0],
//         [0, 3, 1, 0]]
// Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.

class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Flags to indicate if the first row or first column needs to be zeroed
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row has any zeroes
        for (int j = 0; j < m; ++j)
        {
            if (mat[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column has any zeroes
        for (int i = 0; i < n; ++i)
        {
            if (mat[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and first column to mark rows and columns to be zeroed
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = 0; // Mark the start of the row
                    mat[0][j] = 0; // Mark the start of the column
                }
            }
        }

        // Zero out cells based on marks in the first row and column
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }

        // Zero out the first row if necessary
        if (firstRowZero)
        {
            for (int j = 0; j < m; ++j)
            {
                mat[0][j] = 0;
            }
        }

        // Zero out the first column if necessary
        if (firstColZero)
        {
            for (int i = 0; i < n; ++i)
            {
                mat[i][0] = 0;
            }
        }
    }
};
