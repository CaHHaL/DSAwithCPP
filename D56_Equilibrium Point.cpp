// Given an array of integers arr[], the task is to find the first equilibrium point in the array.

// The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists.

// Examples:

// Input: arr[] = [1, 2, 0, 3]
// Output: 2
// Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 0 + 3 = 3.
// Input: arr[] = [1, 1, 1, 1]
// Output: -1
// Explanation: There is no equilibrium index in the array.
// Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
// Output: 3
// Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.

#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return -1;

        int total_sum = 0;
        int left_sum = 0;

        // Calculate total sum of the array
        for (int i = 0; i < n; ++i)
        {
            total_sum += arr[i];
        }

        // Traverse the array to find the equilibrium point
        for (int i = 0; i < n; ++i)
        {
            // Subtract the current element from total_sum to get the sum of elements after index i
            total_sum -= arr[i];

            // If left_sum equals total_sum, then i is the equilibrium index
            if (left_sum == total_sum)
            {
                return i;
            }

            // Add the current element to left_sum
            left_sum += arr[i];
        }

        // If no equilibrium index is found, return -1
        return -1;
    }
};
