// Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.

// Examples:

// Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
// Output: [3, 3, 4, 5, 5, 5, 6]
// Explanation:
// 1st contiguous subarray [1, 2, 3], max = 3
// 2nd contiguous subarray [2, 3, 1], max = 3
// 3rd contiguous subarray [3, 1, 4], max = 4
// 4th contiguous subarray [1, 4, 5], max = 5
// 5th contiguous subarray [4, 5, 2], max = 5
// 6th contiguous subarray [5, 2, 3], max = 5
// 7th contiguous subarray [2, 3, 6], max = 6
// Input: arr[] = [5, 1, 3, 4, 2], k = 1
// Output: [5, 1, 3, 4, 2]
// Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ k ≤ arr.size()
// 0 ≤ arr[i] ≤ 109
class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        deque<int> dq;
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (!dq.empty() && arr[dq.back()] < arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k)
            {
                dq.pop_front();
            }
            if (i >= k - 1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};