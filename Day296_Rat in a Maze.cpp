// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.
// Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.

class Solution
{
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    char dirChar[] = {'U', 'R', 'D', 'L'};
    int vis[][] = new int[5][5];
    ArrayList<String> res;
public
    ArrayList<String> ratInMaze(int[][] mat)
    {
        int n = mat.length;
        res = new ArrayList<>();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
        {
            return res;
        }
        path(mat, 0, 0, "", n);
        Collections.sort(res);
        return res;
    }
    void path(int[][] m, int x, int y, String dir, int n)
    {
        if (x == n - 1 && y == n - 1)
        {
            res.add(dir);
            return;
        }
        if (m[x][y] == 0 || vis[x][y] == 1)
        {
            return;
        }

        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
            {
                path(m, newX, newY, dir + dirChar[i], n);
            }
        }
        vis[x][y] = 0;
    }
}