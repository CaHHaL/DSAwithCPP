// Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.
// The distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|.
// You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

// Note: It is guaranteed that there is at least one cell with value 1 in the grid.

// Examples

// Input: grid[][] = [[0, 1, 1, 0],
//                 [1, 1, 0, 0],
//                 [0, 0, 1, 1]]
// Output: [[1, 0, 0, 1],
//         [0, 0, 1, 1],
//         [1, 1, 0, 0]]
// Explanation: The grid is -

// - 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

// Input: grid[][] = [[1, 0, 1],
//                 [1, 1, 0],
//                 [1, 0, 0]]
// Output: [[0, 1, 0],
//         [0, 0, 1],
//         [0, 1, 2]]
// Explanation: The grid is -

// - 0's at (0,1), (1,2), (2,1) and (2,2) are at a  distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> op(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    op[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && op[nx][ny] == -1)
                {
                    op[nx][ny] = op[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return op;
    }
};