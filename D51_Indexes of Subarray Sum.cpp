// Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

// Note: If no such array is possible then, return [-1].

// Examples:

// Input: arr[] = [1, 2, 3, 7, 5], target = 12
// Output: [2, 4]
// Explanation: The sum of elements from 2nd to 4th position is 12.
// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
// Output: [1, 5]
// Explanation: The sum of elements from 1st to 5th position is 15.
// Input: arr[] = [5, 3, 4], target = 2
// Output: [-1]
// Explanation: There is no subarray with sum 2.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0, current_sum = 0;

        // Traverse the array with the right pointer
        for (int right = 0; right < n; ++right)
        {
            current_sum += arr[right];

            // If current_sum exceeds the target, move the left pointer
            while (current_sum > target && left <= right)
            {
                current_sum -= arr[left];
                ++left;
            }

            // If we find the target sum, return the 1-based indices
            if (current_sum == target)
            {
                return {left + 1, right + 1}; // 1-based indexing
            }
        }

        // If no subarray is found, return [-1]
        return {-1};
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {1, 2, 3, 7, 5};
    int target1 = 12;
    vector<int> result1 = sol.subarraySum(arr1, target1);
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target2 = 15;
    vector<int> result2 = sol.subarraySum(arr2, target2);
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr3 = {5, 3, 4};
    int target3 = 2;
    vector<int> result3 = sol.subarraySum(arr3, target3);
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
