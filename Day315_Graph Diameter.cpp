// You are given an undirected connected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertex u and vertex v.
// Find the diameter of the graph.
// The diameter of a graph (sometimes called the width) is the number of edges on the longest path between two vertices in the graph.

// Note: Graph do not contains any cycle.

// Examples :

// Input: V = 6, E = 5, edges[][] = [[0, 1], [0, 4], [1, 3], [1, 2], [2, 5]]

// Output: 4
// Explanation: The longest path in the graph is from vertices 4 to vertices 5 (4 -> 0 -> 1 -> 2 -> 5).
// Input: V = 7, E = 6, edges[][] = [[0, 2], [0, 4], [0, 3], [3, 1], [3, 5], [1, 6]]

// Output: 4
// Explanation: The longest path in the graph is from vertices 2 to vertices 6 (2 -> 0 -> 3 -> 1 -> 6).

class Solution
{
public:
    vector<vector<int>> adj;
    int ans = 0;
    int f(int node, int parent, int size)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &i : adj[node])
        {
            if (i != parent)
            {
                pq.push(f(i, node, size + 1));
            }
            if (pq.size() > 2)
                pq.pop();
        }
        int maxa = 0, val = 0;
        while (!pq.empty())
        {
            int temp = pq.top();
            maxa += temp;
            val = max(val, temp);
            pq.pop();
        }
        ans = max(maxa, ans);
        return val + 1;
    }
    int diameter(int V, vector<vector<int>> &edges)
    {
        adj.resize(V);
        for (auto &i : edges)
        {
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
        f(0, -1, 0);
        return ans;
    }
};