// Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

// Examples:

// Input: arr[] = [3, 2, 1], k = 2
// Output: 5
// Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
// Input: arr[] = [2, 6, 4, 1], k = 3
// Output: 11
// Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.

class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + arr[i];
        priority_queue<int, vector<int>, greater<int>> mH;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int sum = pre[j] - pre[i];
                if (mH.size() < k)
                    mH.push(sum);
                else if (sum > mH.top())
                {
                    mH.pop();
                    mH.push(sum);
                }
            }
        }
        return mH.top();
    }
};