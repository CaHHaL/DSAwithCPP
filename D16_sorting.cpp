// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        
        while (mid <= high) {
            if (arr[mid] == 0) {
                // Swap arr[low] and arr[mid], move both pointers
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                // If the element is 1, just move the mid pointer
                mid++;
            } 
            else { // arr[mid] == 2
                // Swap arr[mid] and arr[high], move the high pointer
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = {0, 1, 2, 0, 1, 2};
    solution.sort012(arr1);
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;  // Output: 0 0 1 1 2 2

    vector<int> arr2 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    solution.sort012(arr2);
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;  // Output: 0 0 0 0 0 1 1 1 1 1 2 2

    return 0;
}
