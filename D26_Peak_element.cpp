// Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist). If there are multiple peak elements, return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

// Note: Consider the element before the first element and the element after the last element to be negative infinity.

// Examples :

// Input: arr = [1, 2, 4, 5, 7, 8, 3]
// Output: true
// Explanation: arr[5] = 8 is a peak element because arr[4] < arr[5] > arr[6].
// Input: arr = [10, 20, 15, 2, 23, 90, 80]
// Output: true
// Explanation: arr[1] = 20 and arr[5] = 90 are peak elements because arr[0] < arr[1] > arr[2] and arr[4] < arr[5] > arr[6]. 
// Input: arr = [1, 2, 3]
// Output: true
// Explanation: arr[2] is a peak element because arr[1] < arr[2] and arr[2] is the last element, so it has negative infinity to its right.



#include <vector>
using namespace std;

class Solution {
public:
    int peakElement(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the peak element
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }
            // If left neighbor is greater, the peak must be in the left half
            else if (mid > 0 && arr[mid] < arr[mid - 1]) {
                high = mid - 1;
            }
            // If right neighbor is greater, the peak must be in the right half
            else {
                low = mid + 1;
            }
        }
        
        return -1; // In case the array is empty (although it's assumed to always have a peak)
    }
};
