// A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

// Examples:

// Input: arr[] = [5, 6, 1, 2, 3, 4]
// Output: 1
// Explanation: 1 is the minimum element in the array.
// Input: arr[] = [3, 1, 2]
// Output: 1
// Explanation: Here 1 is the minimum element.
// Input: arr[] = [4, 2, 3]
// Output: 2
// Explanation: Here 2 is the minimum element 



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
        // Binary search to find the minimum element
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than the rightmost element, 
            // then the minimum element is in the right part of the array.
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else {
                // Otherwise, the minimum is in the left part (including mid).
                right = mid;
            }
        }
        
        // The 'left' pointer will point to the minimum element
        return arr[left];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << "Minimum element: " << sol.findMin(arr) << endl;
    return 0;
}
