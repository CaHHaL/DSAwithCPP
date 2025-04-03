// Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

// Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

// Examples:

// Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
// Output: 1
// Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
// Input: mat[][] = [[2, 2, 0, 1]]
// Output: -1
// Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).
// Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
// Output: 0
// Explanation: There is no fresh orange.

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = 0, count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                    count++;
                }
                else if (mat[i][j])
                    count++;
            }
        }
        vector<int> radd = {-1, 1, 0, 0};
        vector<int> cadd = {0, 0, -1, 1};
        while (!q.empty())
        {
            int t = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            ans = max(ans, t);
            count--;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + radd[i], ncol = col + cadd[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({t + 1, {nrow, ncol}});
                }
            }
        }
        if (count == 0)
            return ans;
        else
            return -1;
    }
};