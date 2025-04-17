// Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
// Your task is to find the minimum weight cycle in this graph.

// Examples:

// Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]

// Output: 6
// Explanation:

// Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)
// Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]

// Output: 5
// Explanation:

// Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)

class Solution
{
public:
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        const int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(V, INF));
        vector<vector<int>> graph(V, vector<int>(V, INF));
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        int minCycle = INF;
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = i + 1; j < V; j++)
                {
                    if (i != k && j != k && dist[i][j] != INF && graph[i][k] != INF && graph[k][j] != INF)
                    {
                        int cycleLen = dist[i][j] + graph[i][k] + graph[k][j];
                        minCycle = min(minCycle, cycleLen);
                    }
                }
            }
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        return (minCycle == INF) ? -1 : minCycle;
    }
};