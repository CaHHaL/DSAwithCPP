// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

// Examples :

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to find the first occurrence of target using binary search
    int findFirstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int first = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;  // Move to the left part to find the first occurrence
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return first;
    }
    
    // Helper function to find the last occurrence of target using binary search
    int findLastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int last = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;  // Move to the right part to find the last occurrence
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return last;
    }

    // Function to return the count of target occurrences in arr
    int countFreq(vector<int>& arr, int target) {
        int first = findFirstOccurrence(arr, target);
        if (first == -1) {
            return 0;  // Target is not present in the array
        }
        int last = findLastOccurrence(arr, target);
        return last - first + 1;  // Calculate the number of occurrences
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    
    cout << "Count of " << target << " is: " << sol.countFreq(arr, target) << endl;
    
    target = 4;
    cout << "Count of " << target << " is: " << sol.countFreq(arr, target) << endl;

    target = 12;
    vector<int> arr2 = {8, 9, 10, 12, 12, 12};
    cout << "Count of " << target << " is: " << sol.countFreq(arr2, target) << endl;

    return 0;
}
