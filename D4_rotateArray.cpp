// Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

// Note: Consider the array as circular.

// Examples :

// Input: arr[] = [1, 2, 3, 4, 5], d = 2
// Output: [3, 4, 5, 1, 2]
// Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
// Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
// Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
// Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
// Input: arr[] = [7, 3, 9, 1], d = 9
// Output: [3, 9, 1, 7]
// Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
// Constraints:
// 1 <= arr.size(), d <= 105
// 0 <= arr[i] <= 105

#include <iostream>
#include <vector>
using namespace std;
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; 
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, n - d - 1);
    reverseArray(arr, n - d, n - 1);
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int d1 = 2;
    rotateArray(arr1, d1);
    cout << "Rotated array: ";
    for (int num : arr1) cout << num << " "; 
    cout << endl;
    vector<int> arr2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int d2 = 3;
    rotateArray(arr2, d2);
    cout << "Rotated array: ";
    for (int num : arr2) cout << num << " ";
    cout << endl;
    vector<int> arr3 = {7, 3, 9, 1};
    int d3 = 9;
    rotateArray(arr3, d3);
    cout << "Rotated array: ";
    for (int num : arr3) cout << num << " "; 
    cout << endl;

    return 0;
}
