// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
// Output: 52
// Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
// Constraints:
// 1 <= arr.size() <= 105
// -104 <= arr[i] <= 104


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the maximum subarray sum using Kadane's Algorithm
    int kadane(const vector<int>& arr) {
        int max_sum = arr[0];
        int current_sum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            current_sum = max(arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }

    // Function to find the minimum subarray sum using Kadane's Algorithm (modified)
    int minKadane(const vector<int>& arr) {
        int min_sum = arr[0];
        int current_sum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            current_sum = min(arr[i], current_sum + arr[i]);
            min_sum = min(min_sum, current_sum);
        }
        return min_sum;
    }

    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Find the normal maximum subarray sum using Kadane's algorithm
        int max_normal = kadane(arr);
        
        // Step 2: Find the total sum of the array
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
        }
        
        // Step 3: Find the minimum subarray sum using Kadane's algorithm (modified)
        int min_subarray_sum = minKadane(arr);
        
        // Step 4: If all elements are negative, we can't take the circular subarray, so return the max_normal.
        if (total_sum == min_subarray_sum) {
            return max_normal;
        }
        
        // Step 5: Compute the circular maximum subarray sum
        int max_circular = total_sum - min_subarray_sum;
        
        // Return the maximum of normal max subarray sum and circular max subarray sum
        return max(max_normal, max_circular);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Maximum Circular Subarray Sum: " << solution.circularSubarraySum(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Maximum Circular Subarray Sum: " << solution.circularSubarraySum(arr2) << endl;
    
    // Test case 3
    vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout << "Maximum Circular Subarray Sum: " << solution.circularSubarraySum(arr3) << endl;

    return 0;
}
