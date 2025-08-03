// You are given a 2D integer matrix mat[][] of size n × m and a list of q operations opr[][]. Each operation is represented as an array [v, r1, c1, r2, c2], where:

// v is the value to be added
// (r1, c1) is the top-left cell of a submatrix
// (r2, c2) is the bottom-right cell of the submatrix (inclusive)
// For each of the q operations, add v to every element in the submatrix from (r1, c1) to (r2, c2). Return the final matrix after applying all operations.

// Examples:

// Input: mat[][] = [[1, 2, 3],  opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
//                 [1, 1, 0],
//                 [4,-2, 2]]
// Output: [[3, 4, 3],
//         [2, 2, -1],
//         [3, -3, 1]]
// Explanation:
class Solution
{
public
    ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr)
    {
        int n = mat.length, m = mat[0].length;
        int weightage[][] = new int[n][m];

        for (int[] op : opr)
        {
            int value = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            weightage[r1][c1] += value;
            if (c2 + 1 < m)
                weightage[r1][c2 + 1] -= value;
            if (r2 + 1 < n)
                weightage[r2 + 1][c1] -= value;
            if (r2 + 1 < n && c2 + 1 < m)
                weightage[r2 + 1][c2 + 1] += value;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                weightage[i][j] += weightage[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                weightage[i][j] += weightage[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] += weightage[i][j];
            }
        }

        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            ArrayList<Integer> rowList = new ArrayList<>();
            for (int j = 0; j < m; j++)
            {
                rowList.add(mat[i][j]);
            }
            result.add(rowList);
        }

        return result;
    }
}