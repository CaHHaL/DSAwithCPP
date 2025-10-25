// Given an array arr[], find the minimum number of operations required to make the sum of its elements less than or equal to half of the original sum. In one operation, you may replace any element with half of its value (with floating-point precision).

// Examples:

// Input: arr[] = [8, 6, 2]
// Output: 3
// Explanation: Initial sum = (8 + 6 + 2) = 16, half = 8
// Halve 8 → arr[] = [4, 6, 2], sum = 12 (still 12 > 8)
// Halve 6 → arr[] = [4, 3, 2], sum = 9 (still 9 > 8)
// Halve 2 → arr[] = [4, 3, 1], sum = 8.
// Input: arr[] = [9, 1, 2]
// Output: 2
// Explanation: Initial sum = 12, half = 6
// Halve 9 → arr[] = [4.5, 1, 2], sum = 7.5 (still > 6)
// Halve 4.5 → arr[] = [2.25, 1, 2], sum = 5.25 ≤ 6

class Solution
{
public:
    int minOperations(vector<int> &arr)
    {
        priority_queue<double> pq;
        double tsum = 0;
        for (auto it : arr)
        {
            pq.push(it);
            tsum += it;
        }
        double target = tsum / 2.0;
        int ans = 0;
        while (tsum > target)
        {
            ans++;
            double rem = pq.top();
            pq.pop();
            tsum -= rem;
            pq.push(rem / 2.0);
            tsum += (rem / 2.0);
        }
        return ans;
    }
};