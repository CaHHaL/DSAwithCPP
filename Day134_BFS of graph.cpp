// Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.

// Examples:

// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps:
// Visit 0 → Output: 0
// Visit 2 (first neighbor of 0) → Output: 0, 2
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3,
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
// Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

// Output: [0, 1, 2, 3, 4]
// Explanation: Starting from 0, the BFS traversal proceeds as follows:
// Visit 0 → Output: 0
// Visit 1 (the first neighbor of 0) → Output: 0, 1
// Visit 2 (the next neighbor of 0) → Output: 0, 1, 2
// Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3
// Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};