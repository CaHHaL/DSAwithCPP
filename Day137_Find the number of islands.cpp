// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
// Output: 4
// Explanation:
// The image below shows all the 4 islands in the grid.

// Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
// Output: 2
// Expanation:
// The image below shows 2 islands in the grid.

class Solution
{
public:
    int n, m;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    void solve(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'W')
            return;
        grid[i][j] = 'W';
        for (auto &it : dir)
        {
            int newi = i + it[0];
            int newj = j + it[1];
            solve(grid, newi, newj);
        }
    }
    int countIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L')
                {
                    solve(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};