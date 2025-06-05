// Given a Directed Acyclic Graph (DAG) with V nodes labeled from 0 to V-1, and a list of directed edges, count the total number of distinct paths from a given start node to a destination node. Each edge is represented as edges[i] = [u, v], indicating a directed edge from u to v.

// Examples :

// Input: edges[][] = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, src = 2, dest = 3
// Output: 3
// Explanation: There are three ways to reach at 3 from 2. These are: 2 -> 1 -> 3, 2 -> 0 -> 3 and 2 -> 0 -> 1 -> 3.
// Print-all-paths-1
// Input: edges[][] = [[0,1], [1,2], [1,3], [2,3]], V = 4, src = 0, dest = 3
// Output: 2
// Explanation: There is two way to reach at 3 from 0 that is : 0 -> 1 -> 2 -> 3 and 0 -> 1 -> 3.
// Print-all-paths-2

class Solution
{
public:
    int dfs(int u, int dest, vector<vector<int>> &adj, vector<int> &dp)
    {
        if (u == dest)
        {
            return 1;
        }
        if (dp[u] != -1)
        {
            return dp[u];
        }

        int count = 0;
        for (int v : adj[u])
        {
            count += dfs(v, dest, adj, dp);
        }
        return dp[u] = count;
    }
    int countPaths(vector<vector<int>> &edges, int V, int src, int dest)
    {
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> dp(1001, -1);
        return dfs(src, dest, adj, dp);
    }
};