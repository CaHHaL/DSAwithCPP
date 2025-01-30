// Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

// Examples:

// Input: mat[][] =

// Output:

// Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
// Input: mat[][] =

// Output:

// Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.

class Solution
{
public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (mat[row][i] == num)
                return false;
        }
        for (int i = 0; i < 9; i++)
        {
            if (mat[i][col] == num)
                return false;
        }
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i + startRow][j + startCol] == num)
                    return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<int>> &mat)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (mat[row][col] == 0)
                {
                    for (int num = 1; num <= 9; num++)
                    {
                        if (isSafe(mat, row, col, num))
                        {
                            mat[row][col] = num;
                            if (solve(mat))
                            {
                                return true;
                            }
                            mat[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat)
    {
        solve(mat);
    }
};