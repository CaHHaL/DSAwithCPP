// You are given an array heights[] representing the heights of towers and another array cost[] where each element represents the cost of modifying the height of respective tower.

// The goal is to make all towers of same height by either adding or removing blocks from each tower.
// Modifying the height of tower (add or remove) 'i' by 1 unit costs cost[i].
// Return the minimum cost to equalize the heights of all towers.

// Examples:

// Input: heights[] = [1, 2, 3], cost[] = [10, 100, 1000]
// Output: 120
// Explanation: The heights can be equalized by either "Removing one block from 3 and adding one in 1" or "Adding two blocks in 1 and adding one in 2". Since the cost of operation in tower 3 is 1000, the first process would yield 1010 while the second one yields 120.
// Input: heights[] = [7, 1, 5], cost[] = [1, 1, 1]
// Output: 6
// Explanation: The minimum cost to equalize the towers is 6, achieved by setting all towers to height 5.

class Solution
{
public:
    bool check(vector<int> &heights, vector<int> &cost, int mid)
    {
        long long costMid = 0;
        long long costMidP1 = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            costMid += (long long)abs(heights[i] - mid) * cost[i];
            costMidP1 += (long long)abs(heights[i] - (mid + 1)) * cost[i];
        }
        return costMid < costMidP1;
    }
    int minCost(vector<int> &heights, vector<int> &cost)
    {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        int targetH = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(heights, cost, mid))
            {
                targetH = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        long long result = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            result += (long long)abs(heights[i] - targetH) * cost[i];
        }
        return (int)result;
    }
};