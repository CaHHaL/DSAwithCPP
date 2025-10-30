// You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Examples:

// Input:
// grid[][] = [['X', 'X', 'X', 'X'],
//           ['X', 'O', 'X', 'X'],
//           ['X', 'O', 'O', 'X'],
//           ['X', 'O', 'X', 'X'],
//           ['X', 'X', 'O', 'O']]
// Output:
// [['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'O', 'O']]
// Explanation: We only changed those 'O' that are surrounded by 'X'
// Input:
// grid[][] = [['X', 'O', 'X', 'X'],
//           ['X', 'O', 'X', 'X'],
//           ['X', 'O', 'O', 'X'],
//           ['X', 'O', 'X', 'X'],
//           ['X', 'X', 'O', 'O']]
// Output:
// [['X', 'O', 'X', 'X'],
// ['X', 'O', 'X', 'X'],
// ['X', 'O', 'O', 'X'],
// ['X', 'O', 'X', 'X'],
// ['X', 'X', 'O', 'O']]
// Explanation: There's no 'O' that's surround by 'X'.
// Input:
// grid[][] = [['X', 'X', 'X'],
//           ['X', 'O', 'X'],
//           ['X', 'X', 'X']]
// Output:
// [['X', 'X', 'X'],
// ['X', 'X', 'X'],
// ['X', 'X', 'X']]
// Explanation: There's only one 'O' that's surround by 'X'.

class Solution
{
public:
    void fill(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 'O')
                q.push({i, 0});
            if (grid[i][m - 1] == 'O')
                q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 'O')
                q.push({0, j});
            if (grid[n - 1][j] == 'O')
                q.push({n - 1, j});
        }
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 'O')
                continue;
            grid[x][y] = '#';
            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X';
                else if (grid[i][j] == '#')
                    grid[i][j] = 'O';
            }
        }
    }
};