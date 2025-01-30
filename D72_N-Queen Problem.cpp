// The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

// Given an integer n, find all distinct solutions to the n-queens puzzle.
// You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
// For eg. below figure represents a chessboard [3 1 4 2].

// Examples:

// Input: n = 1
// Output: [1]
// Explaination: Only one queen can be placed in the single cell available.
// Input: n = 4
// Output: [[2 4 1 3 ] [3 1 4 2 ]]
// Explaination: There are 2 possible solutions for n = 4.
// Input: n = 2
// Output: []
// Explaination: There are no possible solutions for n = 2.

class Solution
{
public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> result;
        vector<int> current(n, 0);
        set<int> columns;
        set<int> diagonals1;
        set<int> diagonals2;
        backtrack(n, 0, current, result, columns, diagonals1, diagonals2);
        return result;
    }

private:
    void backtrack(int n, int row, vector<int> &current, vector<vector<int>> &result,
                   set<int> &columns, set<int> &diagonals1, set<int> &diagonals2)
    {
        if (row == n)
        {
            result.push_back(current);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (columns.count(col) == 0 && diagonals1.count(row - col) == 0 && diagonals2.count(row + col) == 0)
            {
                current[row] = col + 1;
                columns.insert(col);
                diagonals1.insert(row - col);
                diagonals2.insert(row + col);
                backtrack(n, row + 1, current, result, columns, diagonals1, diagonals2);
                columns.erase(col);
                diagonals1.erase(row - col);
                diagonals2.erase(row + col);
            }
        }
    }
};