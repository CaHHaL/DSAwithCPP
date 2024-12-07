// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to count inversions during the merge process
    int mergeAndCount(vector<int>& arr, int left, int right) {
        if (left >= right) return 0; // No inversion if one element
        
        int mid = left + (right - left) / 2;
        int invCount = 0;
        
        // Recursively count inversions in left and right halves
        invCount += mergeAndCount(arr, left, mid);
        invCount += mergeAndCount(arr, mid + 1, right);
        
        // Merge the two halves and count the inversions
        invCount += merge(arr, left, mid, right);
        
        return invCount;
    }

    // Function to merge two halves and count inversions
    int merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays
        vector<int> leftArr(n1), rightArr(n2);
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; ++i) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; ++i) rightArr[i] = arr[mid + 1 + i];
        
        int i = 0, j = 0, k = left, invCount = 0;
        
        // Merge the two arrays and count inversions
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                invCount += (n1 - i); // All remaining elements in leftArr are greater
            }
        }
        
        // Copy the remaining elements
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
        
        return invCount;
    }

    // Wrapper function for mergeSort and inversion count
    int countInversions(vector<int>& arr) {
        return mergeAndCount(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = {2, 4, 1, 3, 5};
    cout << "Inversion Count: " << solution.countInversions(arr1) << endl;
    
    vector<int> arr2 = {2, 3, 4, 5, 6};
    cout << "Inversion Count: " << solution.countInversions(arr2) << endl;
    
    vector<int> arr3 = {10, 10, 10};
    cout << "Inversion Count: " << solution.countInversions(arr3) << endl;
    
    return 0;
}
