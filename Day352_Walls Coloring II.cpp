// You are given n walls arranged in a row, and each wall must be painted using one of the k available colors. The cost of painting ith wall with jth color is given by costs[i][j]. Your task is to determine the minimum total cost required to paint all the walls in such a way that no two adjacent walls share the same color. If it is impossible to paint the walls under this condition, you must return -1.

// Examples:

// Input: n = 4, k = 3,
// costs[][] = [[1, 5, 7],
//            [5, 8, 4],
//            [3, 2, 9],
//            [1, 2, 4]]

// Output: 8
// Explanation:
// Paint wall 0 with color 0. Cost = 1
// Paint wall 1 with color 2. Cost = 4
// Paint wall 2 with color 1. Cost = 2
// Paint wall 3 with color 0. Cost = 1
// Total Cost = 1 + 4 + 2 + 1 = 8
// Input: n = 5, k = 1,
// costs[][] = [[5],
//            [4],
//            [9],
//            [2],
//            [1]]
// Output: -1
// Explanation: It is not possible to color all the walls under the given conditions.
// Constraints:
// 0 ≤ n  ≤ 103
// 0 ≤ k  ≤ 103
// 1 ≤ costs[i][j]  ≤ 105

class Solution
{
public:
    int minCost(vector<vector<int>> &cost)
    {
        int n = cost.size(), k = cost[0].size();
        if (k == 1)
        {
            if (n == 1)
                return cost[0][0];
            return -1;
        }
        pair<int, int> mini = {INT_MAX, -1}, smini = {INT_MAX, -1};
        for (int i = 0; i < k; i++)
        {
            if (cost[0][i] < mini.first)
            {
                smini = mini;
                mini = {cost[0][i], i};
            }
            else if (cost[0][i] < smini.first)
                smini = {cost[0][i], i};
        }
        for (int i = 1; i < n; i++)
        {
            pair<int, int> curMini = {INT_MAX, -1}, curSmini = {INT_MAX, -1};
            for (int j = 0; j < k; j++)
            {
                int x = cost[i][j];
                if (j != mini.second)
                    x += mini.first;
                else
                    x += smini.first;
                if (x < curMini.first)
                {
                    curSmini = curMini;
                    curMini = {x, j};
                }
                else if (x < curSmini.first)
                    curSmini = {x, j};
            }
            mini = curMini;
            smini = curSmini;
        }
        return mini.first;
    }
};