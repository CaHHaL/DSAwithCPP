// You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [ x, y ] indicates that we need to take course y first if we want to take course x.

//                                                                                                            Find the ordering of courses we should take to complete all the courses.

//                                                                                                            Note : There may be multiple correct orders,
//                                                                                         you just need to return any one of them.If it is impossible to finish all tasks, return an empty array.The Driver code will print true if you return any correct order of courses else it will print false.

//                                                                                                                                                                                 Examples :

//     Input : n = 3,
//                                                                                         prerequisites[][] = [ [ 1, 0 ], [ 2, 1 ] ] Output : true Explanation : To take course 1, you must finish course 0. To take course 2, you must finish course 1. So the only valid order is[0, 1, 2].Input : n = 4, prerequisites[][] = [ [ 2, 0 ], [ 2, 1 ], [ 3, 2 ] ] Output : true Explanation : Course 2
//                                                                                                                                                                                                                                                                                                                                                                                                requires both 0 and 1.
//                                                                                                                                                                                                                                                                                                                                                                                                                Course 3
//                                                                                                                                                                                                                                                                                                                                                                                                             requires course 2.
//                                                                                                                                                                                                                                                                                                                                                                                            Hence,
//                                                                                         both[0, 1, 2, 3] and [ 1, 0, 2, 3 ] are valid.Constraints : 1 ≤ n ≤ 104 0 ≤ prerequisites.size() ≤ 105 0 ≤ prerequisites[i][0],
//                                                                                         prerequisites[i][1] < n All prerequisite pairs are unique prerequisites[i][0] ≠ prerequisites[i][1]
class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        vector<int> order;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (auto next : adj[course])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        if (order.size() == n)
            return order;
        return {};
    }
};