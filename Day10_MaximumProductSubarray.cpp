// Maximum Product Subarray
// Difficulty: MediumAccuracy: 18.09%Submissions: 409K+Points: 4
// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

// Note: It is guaranteed that the output fits in a 32-bit integer.

// Examples

// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
// Input: arr[] = [-1, -3, -10, 0, 6]
// Output: 30
// Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
// Input: arr[] = [2, 3, 4] 
// Output: 24 
// Explanation: For an array with all positive elements, the result is product of all elements. 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int>& arr) {
        // If the array is empty, return 0 (though the problem guarantees there will be elements)
        if (arr.empty()) return 0;

        // Initialize the max and min product as the first element
        int max_prod = arr[0];
        int min_prod = arr[0];
        int result = arr[0];

        // Traverse through the array starting from the second element
        for (int i = 1; i < arr.size(); i++) {
            // If the current element is negative, swap max_prod and min_prod
            if (arr[i] < 0) {
                swap(max_prod, min_prod);
            }

            // Update max_prod and min_prod by considering the current element
            max_prod = max(arr[i], max_prod * arr[i]);
            min_prod = min(arr[i], min_prod * arr[i]);

            // Update the global result with the maximum product found so far
            result = max(result, max_prod);
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    cout << "Maximum product subarray for arr1: " << sol.maxProduct(arr1) << endl;  // Output: 180
    
    // Test case 2
    vector<int> arr2 = {-1, -3, -10, 0, 6};
    cout << "Maximum product subarray for arr2: " << sol.maxProduct(arr2) << endl;  // Output: 30
    
    // Test case 3
    vector<int> arr3 = {2, 3, 4};
    cout << "Maximum product subarray for arr3: " << sol.maxProduct(arr3) << endl;  // Output: 24

    return 0;
}
