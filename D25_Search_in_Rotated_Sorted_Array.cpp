// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
// Output: 8
// Explanation: 3 is found at index 8.
// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: There is no element that has value 6.
// Input: arr[] = [33, 42, 72, 99], key = 42
// Output: 1
// Explanation: 42 is found at index 1.




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the key is at the mid index
            if (arr[mid] == key) {
                return mid;
            }

            // Check if the left part is sorted
            if (arr[left] <= arr[mid]) {
                // If key lies in the sorted part, search in left part
                if (arr[left] <= key && key < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Else, the right part is sorted
            else {
                // If key lies in the sorted part, search in right part
                if (arr[mid] < key && key <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // If key is not found
        return -1;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int result = solution.search(arr, key);
    cout << "Key found at index: " << result << endl;  // Output: 8
    
    key = 6;
    result = solution.search(arr, key);
    cout << "Key found at index: " << result << endl;  // Output: 1
    
    key = 6;
    vector<int> arr2 = {3, 5, 1, 2};
    result = solution.search(arr2, key);
    cout << "Key found at index: " << result << endl;  // Output: -1
    
    return 0;
}
