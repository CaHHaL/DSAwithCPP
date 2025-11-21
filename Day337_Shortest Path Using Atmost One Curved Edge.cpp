// Given an undirected, connected graph with V vertices numbered from 0 to V-1 and E double-edges, represented as a 2D array edges[][]. Each double-edge is represented by a tuple (x, y, w1, w2), which indicates that there are two edges between vertices x and y: a straight edge with weight w1 and a curved edge with weight w2.

// You are given two vertices a and b and you have to go from a to b through a series of edges such that in the entire path, you can use at most 1 curved edge. Your task is to find the shortest path from a to b satisfying the above condition.
// If no such path exists that satisfies this restriction, return -1.

// Note: It is guaranteed that the shortest path value will fit in a 32-bit integer.

// Examples:

// Input: V = 4, E = 4, a = 1, b = 3, edges[][] = [[0, 1, 1, 4], [0, 2, 2, 4], [0, 3, 3, 1], [1, 3, 6, 5]]

// Output: 2
// Explanation:
// We can follow the path 1 -> 0 -> 3, this gives a distance of 1+3 = 4 if we follow all straight paths. But we can take the curved path  from 0 -> 3, which costs 1. This will result in a cost of 1 + 1 = 2.
// Input: V = 2, E = 1, a = 0, b = 1, edges[][] = [[0, 1, 4, 1]]

// Output: 1
// Explanation:
// Take the curved path from 0 to 1 which costs 1.

// Constraints:
// 1 ≤ V ≤ 106
// 0 ≤ E ≤ 106
// 0 ≤ a, b ≤ V - 1
// 0 ≤ edges[i][0], edges[i][1] ≤ V-1
// 0 ≤ edges[i][2], edges[i][3] ≤ 104

class Solution
{
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges)
    {
        vector<vector<tuple<int, int, int>>> adj(V);
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w1 = edge[2];
            int w2 = edge[3];
            adj[u].emplace_back(v, w1, w2);
            adj[v].emplace_back(u, w1, w2);
        }
        const int INF = INT_MAX;
        vector<vector<int>> dist(V, vector<int>(2, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[a][0] = 0;
        pq.emplace(0, a, 0);
        while (!pq.empty())
        {
            auto [d, u, curved_count] = pq.top();
            pq.pop();
            if (d > dist[u][curved_count])
            {
                continue;
            }
            for (const auto &edge : adj[u])
            {
                int v = get<0>(edge);
                int w1 = get<1>(edge);
                int w2 = get<2>(edge);
                int new_d1 = d + w1;
                int new_c1 = curved_count;
                if (new_d1 < dist[v][new_c1])
                {
                    dist[v][new_c1] = new_d1;
                    pq.emplace(new_d1, v, new_c1);
                }
                if (curved_count == 0)
                {
                    int new_d2 = d + w2;
                    int new_c2 = 1;
                    if (new_d2 < dist[v][new_c2])
                    {
                        dist[v][new_c2] = new_d2;
                        pq.emplace(new_d2, v, new_c2);
                    }
                }
            }
        }
        int result = min(dist[b][0], dist[b][1]);
        return (result == INF) ? -1 : result;
    }
};