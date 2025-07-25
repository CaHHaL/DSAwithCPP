// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [5, -2, 3, 4]
// Output: 12
// Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.

class Solution
{
public:
    int maxCircularSum(vector<int> &arr)
    {
        int totalSum = 0;
        int curMax = 0;
        int curMin = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
            curMin = min(curMin + arr[i], arr[i]);
            curMax = max(curMax + arr[i], arr[i]);
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }
        return (maxSum > 0) ? max(maxSum, (totalSum - minSum)) : maxSum;
    }
};