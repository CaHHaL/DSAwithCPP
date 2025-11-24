// Given an undirected graph of V vertices numbered from (0 to V-1) and E edges represented by a 2D array edges[][], where each edges[i] contains three integers [u, v, w], representing an undirected edge from u to v, having weight w.
// Your task is to find the weight of the second best minimum spanning tree of the given graph.
// A second best MST is defined as the minimum-weight spanning tree whose total weight is strictly greater than the weight of the minimum spanning tree.

// Note: If no such second best MST exists, return -1.

// Examples:

// Input: V = 5, E = 7, edges[][] = [[0, 1, 4], [0, 2, 3], [1, 2, 1], [1, 3, 5], [2, 4, 10], [2, 3, 7], [3, 4, 2]]
// Output: 12
// Explanation: Graph through red edges represents MST.

// Input: V = 5, E = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [2, 3, 4], [3, 4, 5]]
// Output: -1
// Explanation: No second best MST exists for this graph.

// Constraints:
// 1 ≤ V ≤ 100
// V-1 ≤ E ≤ V*(V-1)/2
// 0 ≤ edges[i][2] ≤ 103
#include <bits/stdc++.h>
using namespace std;
struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
class Solution
{
public:
    int secondMST(int V, vector<vector<int>> &edges)
    {
        int E = edges.size();
        struct EData
        {
            int u, v, w;
        };
        vector<EData> e(E);
        for (int i = 0; i < E; i++)
            e[i] = {edges[i][0], edges[i][1], edges[i][2]};
        sort(e.begin(), e.end(), [](auto &a, auto &b)
             { return a.w < b.w; });
        DSU d1(V);
        vector<int> mstIndex;
        int mstWeight = 0;
        for (int i = 0; i < E; i++)
        {
            if (d1.unite(e[i].u, e[i].v))
            {
                mstWeight += e[i].w;
                mstIndex.push_back(i);
            }
        }
        if ((int)mstIndex.size() != V - 1)
            return -1;
        int answer = INT_MAX;
        for (int skip : mstIndex)
        {
            DSU d2(V);
            int curWeight = 0;
            int used = 0;
            for (int i = 0; i < E; i++)
            {
                if (i == skip)
                    continue;
                if (d2.unite(e[i].u, e[i].v))
                {
                    curWeight += e[i].w;
                    used++;
                    if (curWeight >= answer)
                        break;
                }
            }
            if (used == V - 1 && curWeight > mstWeight)
                answer = min(answer, curWeight);
        }
        return answer == INT_MAX ? -1 : answer;
    }
};