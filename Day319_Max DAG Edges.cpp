// Given a directed acyclic graph (DAG) with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v, find the maximum number of additional edges that can be added to the graph without forming any cycles.

// Note: The resulting graph must remain a DAG, meaning that adding any further edge would not create a cycle.

// Examples:

// Input: V = 3, E = 2, edges[][] = [[0, 1], [1, 2]]
// Output: 1
// Explanation: The given DAG allows one more edge, 0 -> 2, which keeps the structure acyclic. Adding anything else would create a cycle.
// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: 2
// Explanation: Two additional edges (0 -> 3, 1 -> 3) can be added without forming cycles.

class Solution
{
public:
    virtual int maxEdgesToAdd(int V, vector<vector<int>> &edges)
    {
        int maxEdges = (V * (V - 1)) / 2;
        return ((maxEdges) - (edges.size()));
    }
};