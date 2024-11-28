// Given an integer array arr[]. You need to find the maximum sum of a subarray.

// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray {-2} has the largest sum -2.
// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int>& arr) {
        // Initialize variables
        int max_sum = arr[0]; // Max sum will be at least the first element.
        int current_sum = arr[0]; // Current sum starts with the first element.
        
        // Loop through the array starting from the second element
        for (int i = 1; i < arr.size(); i++) {
            // Update current_sum to either the current element alone or the sum of the current element + current_sum
            current_sum = max(arr[i], current_sum + arr[i]);
            
            // Update max_sum to be the maximum of itself and current_sum
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Example 1
    vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    cout << "Maximum sum of subarray is: " << solution.maxSubarraySum(arr1) << endl; // Expected output: 11
    
    // Example 2
    vector<int> arr2 = {-2, -4};
    cout << "Maximum sum of subarray is: " << solution.maxSubarraySum(arr2) << endl; // Expected output: -2
    
    // Example 3
    vector<int> arr3 = {5, 4, 1, 7, 8};
    cout << "Maximum sum of subarray is: " << solution.maxSubarraySum(arr3) << endl; // Expected output: 25

    return 0;
}
