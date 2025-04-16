// You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
// The graph may contain negative edge weights, but it does not contain any negative weight cycles.

// Your task is to find the shortest distance between every pair of nodes i and j in the graph.

// Note: Modify the distances for every pair in place.

// Examples :

// Input: dist[][] = [[0, 4, 108, 5, 108], [108, 0, 1, 108, 6], [2, 108, 0, 3, 108], [108, 108, 1, 0, 2], [1, 108, 108, 4, 0]]

// Output: [[0, 4, 5, 5, 7], [3, 0, 1, 4, 6], [2, 6, 0, 3, 5], [3, 7, 1, 0, 2], [1, 5, 5, 4, 0]]

// Explanation: Each cell dist[i][j] in the output shows the shortest distance from node i to node j, computed by considering all possible intermediate nodes.
// Input: dist[][] = [[0, -1, 2], [1, 0, 108], [3, 1, 0]]

// Output: [[0, -1, 2], [1, 0, 3], [2, 1, 0]]

// Explanation: Each cell dist[i][j] in the output shows the shortest distance from node i to node j, computed by considering all possible intermediate nodes.
// From 2 to 0 shortest distance should be 2 by following path 2 -> 1 -> 0
// From 1 to 2 shortest distance should be 3 by following path 1 -> 0 -> 2

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] != 100000000 && dist[via][j] != 100000000 && dist[i][j] > dist[i][via] + dist[via][j])
                    {
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
    }
};