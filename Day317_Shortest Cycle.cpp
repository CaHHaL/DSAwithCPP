// You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertex u and v.
// Find the length of the shortest cycle in the graph. If the graph does not contain any cycle, return -1.

// Note: A cycle is a path that starts and ends at the same vertex without repeating any edge or vertex (except the start/end vertex). The shortest cycle is the one with the minimum number of edges.

// Examples

// Input: V = 7, E = 8, edges[][] = [[0, 5], [0, 6], [5, 1], [6, 1], [6, 2], [2, 3], [3, 4], [1, 4]]

// Output: 4
// Explanation: Possible cycles are:
// 0 → 5 → 1 → 6 → 0 (length = 4)
// 1 → 4 → 3 → 2 → 6 → 1 (length = 5)
// The smallest one is 0 → 5 → 1 → 6 → 0, with length 4.
// Input: V = 7, E = 9, edges[][] = [[0, 5], [0, 6], [1, 2], [1, 4], [1, 5], [1, 6], [2, 6], [2, 3], [3, 4]]

// Output: 3
// Explanation: Possible cycles include:
// 1 → 2 → 6 → 1 (length = 3)
// 1 → 2 → 3 → 4 → 1 (length = 4)
// 0 → 5 → 1 → 6 → 0 (length = 4)
// The smallest one is 1 → 2 → 6 → 1, with length 3.

class Solution
{
public:
    int shortCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            vector<int> dist(V, -1);
            vector<int> par(V, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        par[v] = u;
                        q.push(v);
                    }
                    else if (par[u] != v)
                    {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};