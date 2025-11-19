// You are given a 2D array mat[][], of size n*m. Your task is to find the minimum possible path cost from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1) by moving up, down, left, or right between adjacent cells.

// Note: The cost of a path is defined as the maximum absolute difference between the values of any two consecutive cells along that path.

// Examples:

// Input: mat[][] = [[7, 2, 6, 5],
//                [3, 1, 10, 8]]
// Output: 4
// Explanation: The route of [7, 3, 1, 2, 6, 5, 8] has a minimum value of maximum absolute difference between any two consecutive cells in the route, i.e., 4.

// Input: mat[][] = [[2, 2, 2, 1],
//                [8, 1, 2, 7],
//                [2, 2, 2, 8],
//                [2, 1, 4, 7],
//                [2, 2, 2, 2]]
// Output: 0
// Explanation: The route of [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2] has a minimum value of maximum absolute difference between any two consecutive cells in the route, i.e., 0.

// Constraints:
// 1 ≤ n, m ≤ 100
// 0 ≤ mat[i][j] ≤ 106

class Solution
{
public:
    int minCostPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!pq.empty())
        {
            auto [cost, cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;
            if (r == n - 1 && c == m - 1)
                return cost;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int diff = abs(mat[r][c] - mat[nr][nc]);
                    int newCost = max(cost, diff);
                    if (newCost < dist[nr][nc])
                    {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};