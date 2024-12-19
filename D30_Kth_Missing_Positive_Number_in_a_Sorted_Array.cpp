// Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  

// Examples :

// Input: arr[] = [2, 3, 4, 7, 11], k = 5
// Output: 9
// Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.
// Input: arr[] = [1, 2, 3], k = 2
// Output: 5
// Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
// Input: arr[] = [3, 5, 9, 10, 11, 12], k = 2
// Output: 2
// Explanation: Missing are 1, 2, 4, 6… and 2nd missing number is 2.


#include <vector>
using namespace std;

class Solution {
public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int missing = 0;
        int current = 1;  // Start checking from 1
        
        // Iterate over the array
        for (int i = 0; i < n; i++) {
            while (current < arr[i]) {
                missing++;  // Missing a number
                if (missing == k) {
                    return current;  // We've found the kth missing number
                }
                current++;
            }
            current = arr[i] + 1;  // Move past the current element in the array
        }
        
        // If we haven't found kth missing number by the end of the array,
        // keep counting beyond the last element in the array.
        while (missing < k) {
            missing++;
            if (missing == k) {
                return current;
            }
            current++;
        }
        
        return -1;  // Should never reach here if k is valid
    }
};
