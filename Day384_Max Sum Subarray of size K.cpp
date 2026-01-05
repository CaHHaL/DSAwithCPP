// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.
// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ k ≤ arr.size()
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = 0;
        long long sum = 0, ans = 0;
        while (j < n)
        {
            sum += arr[j];
            if (j - i + 1 >= k)
            {
                ans = max(ans, sum);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};