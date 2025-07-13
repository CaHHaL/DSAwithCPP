// Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

// Examples:

// Input: arr[] = [4, 6, 1, 2, 3, 8]
// Output: 10
// Explanation: The elements which are not in LIS is 4 and 6.
// Input: arr[] = [5, 4, 3, 2, 1]
// Output: 14
// Explanation: The elements which are not in LIS is 5, 4, 3 and 2.

class Solution
{
public:
    int nonLisMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        int total = 0, maxlen = 1, LisSum = INT_MAX;
        vector<int> len(n, 1), sum(n);

        for (int i = 0; i < n; i++)
            total += arr[i];

        for (int i = 0; i < n; i++)
        {
            sum[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && len[j] + 1 >= len[i])
                {
                    len[i] = len[j] + 1;
                    sum[i] = sum[j] + arr[i];
                }
            }
            maxlen = max(maxlen, len[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (len[i] == maxlen)
            {
                LisSum = min(LisSum, sum[i]);
            }
        }
        return total - LisSum;
    }
};