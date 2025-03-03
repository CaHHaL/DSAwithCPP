// Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
// If multiple such subarrays exist, return the one that starts at the smallest index.

// Examples:

// Input: arr[] = [8, 4, 2, 6, 7], x = 4
// Output: [4, 2, 6]
// Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is greater than 4.
// Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5
// Output: [2, 4, 7, 2]
// Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5.

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        int n = arr.size();
        deque<int> maxDeque, minDeque;
        int start = 0, maxLen = 0, bestStart = 0;
        for (int end = 0; end < n; end++)
        {
            while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[end])
                maxDeque.pop_back();
            maxDeque.push_back(end);
            while (!minDeque.empty() && arr[minDeque.back()] >= arr[end])
                minDeque.pop_back();
            minDeque.push_back(end);
            while (arr[maxDeque.front()] - arr[minDeque.front()] > x)
            {
                start++;
                if (maxDeque.front() < start)
                    maxDeque.pop_front();
                if (minDeque.front() < start)
                    minDeque.pop_front();
            }
            if (end - start + 1 > maxLen)
            {
                maxLen = end - start + 1;
                bestStart = start;
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};
