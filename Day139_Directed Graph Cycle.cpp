// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]

// Output: true
// Explanation: 3 -> 3 is a cycle
// Input: V = 3, edges[][] = [[0, 1], [1, 2]]

// Output: false
// Explanation: no cycle in the graph

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++)
        {
            if (isCyclicUtil(i, adj, visited, recStack))
                return true;
        }
        return false;
    }

private:
    bool isCyclicUtil(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
    {
        if (!visited[node])
        {
            visited[node] = true;
            recStack[node] = true;

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor] && isCyclicUtil(neighbor, adj, visited, recStack))
                    return true;
                else if (recStack[neighbor])
                    return true;
            }
        }
        recStack[node] = false;
        return false;
    }
};