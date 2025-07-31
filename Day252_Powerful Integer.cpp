// You are given a 2D integer array intervals[][] of length n, where each intervals[i] = [start, end] represents a closed interval (i.e., all integers from start to end, inclusive). You are also given an integer k. An integer is called Powerful if it appears in at least k intervals. Find the maximum Powerful Integer.

// Note: If no integer occurs at least k times return -1.

// Examples:

// Input : n = 3, intervals[][] = [[1, 3], [4, 6], [3, 4]], k = 2
// Output: 4
// Explanation: Integers 3 and 4 appear in 2 intervals. The maximum is 4.
// Input : n = 4, intervals[][] = [[1, 4], [12, 45], [3, 8], [10, 12]], k = 3
// Output: -1
// Explanation: No integer appears in at least 3 intervals.
// Input : n = 5, intervals[][] = [[16, 21], [5, 8], [12, 17], [17, 29], [9, 24]], k = 3
// Output: 21
// Explanation: Integers 16, 17, 18, 19, 20 and 21 appear in at least 3 intervals. The maximum is 21.

class Solution
{
public:
    int powerfulInteger(vector<vector<int>> &intervals, int k)
    {
        int cnt = 0, temp = 0;
        int res = -1;
        int size = intervals.size();
        map<int, int> mp;
        for (int i = 0; i < size; i++)
        {
            mp[intervals[i][0]]++;
            mp[intervals[i][1] + 1]--;
        }
        for (auto it : mp)
        {
            cnt += it.second;
            if (cnt >= k)
                res = it.first;
            else if (temp >= k)
                res = it.first - 1;
            temp = cnt;
        }
        return res;
    }
};