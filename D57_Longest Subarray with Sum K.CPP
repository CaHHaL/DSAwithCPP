// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

// Examples:

// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0;
        int maxLength = 0;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++)
        {
            prefixSum += arr[i];

            // If the prefix sum equals k, update maxLength
            if (prefixSum == k)
            {
                maxLength = i + 1;
            }

            // If (prefixSum - k) is already in the map, calculate the subarray length
            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end())
            {
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
            }

            // If prefixSum is not in the map, store it with its index
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end())
            {
                prefixSumMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

// Test the function
int main()
{
    Solution sol;
    vector<int> arr1 = {10, 5, 2, 7, 1, -10};
    int k1 = 15;
    cout << "Length of longest subarray: " << sol.longestSubarray(arr1, k1) << endl;

    vector<int> arr2 = {-5, 8, -14, 2, 4, 12};
    int k2 = -5;
    cout << "Length of longest subarray: " << sol.longestSubarray(arr2, k2) << endl;

    vector<int> arr3 = {10, -10, 20, 30};
    int k3 = 5;
    cout << "Length of longest subarray: " << sol.longestSubarray(arr3, k3) << endl;

    return 0;
}
