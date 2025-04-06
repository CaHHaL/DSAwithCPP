// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes an directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]

class Solution
{
public:
    void dfs(int start, vector<int> &vis, vector<int> &ans, vector<int> adj[])
    {
        vis[start] = 1;
        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                dfs(it, vis, ans, adj);
            }
        }
        ans.push_back(start);
        return;
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> ans;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, ans, adj);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};