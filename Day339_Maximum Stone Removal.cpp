// Given an 2D array of non-negative integers stones[][] where stones[i] = [xi , yi] represents the location of the ith stone on a 2D plane, the task is to return the maximum possible number of stones that you can remove.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Note: Each coordinate point may have at most one stone.

// Examples:

// Input: stones[][] = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
// Output: 5
// Explanation:

// One way to remove 5 stones is as follows:
// 1. Remove stone [2, 2] because it shares the same row as [2, 1].
// 2. Remove stone [2, 1] because it shares the same column as [0, 1].
// 3. Remove stone [1, 2] because it shares the same row as [1, 0].
// 4. Remove stone [1, 0] because it shares the same column as [0, 0].
// 5. Remove stone [0, 1] because it shares the same row as [0, 0].
// Stone [0, 0] cannot be removed since it does not share any row/column with another stone still on the plane.
// Input: stones[][] = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
// Output: 3
// Explanation:

// One way to remove 3 stones is as follows:
// 1. Remove stone [2, 2] because it shares the same row as [2, 0].
// 2. Remove stone [2, 0] because it shares the same column as [0, 0].
// 3. Remove stone [0, 2] because it shares the same row as [0, 0].
// Stones [0, 0] and [1, 1] cannot be removed since they do not share any row/column with another stone still on the plane.
// Constraints:
// 1 ≤ stones.size() ≤ 1000
// 0 ≤ xi, yi ≤ 104
// No two stones are at same position.

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones)
    {
        int ans = 0;
        int n = stones.size();
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> row, col;
        for (int i = 0; i < n; i++)
        {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        for (auto [x, y] : row)
        {
            if (y.size() > 1)
            {
                for (int i = 1; i < y.size(); i++)
                {
                    adj[y[0]].push_back(y[i]);
                    adj[y[i]].push_back(y[0]);
                }
            }
        }
        for (auto [x, y] : col)
        {
            if (y.size() > 1)
            {
                for (int i = 1; i < y.size(); i++)
                {
                    adj[y[0]].push_back(y[i]);
                    adj[y[i]].push_back(y[0]);
                }
            }
        }
        vector<bool> vis(n, false);
        int cnt = 0;
        auto dfs = [&](auto &&dfs, int node) -> void
        {
            cnt++;
            vis[node] = true;
            for (auto &x : adj[node])
            {
                if (!vis[x])
                {
                    dfs(dfs, x);
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int old = cnt;
                dfs(dfs, i);
                ans += cnt - old - 1;
            }
        }
        return ans;
    }
};