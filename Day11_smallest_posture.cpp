// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1. The array can have negative integers too.

// Examples:

// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.
// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.
// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// // Explanation: Smallest positive missing number is 1.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSmallestMissingPositive(vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: Place each number in its correct position (i.e., arr[i] = i+1)
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            // Swap arr[i] and arr[arr[i] - 1]
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    // Step 2: Find the first missing positive number
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1; // First missing positive
        }
    }
    
    // If no missing number, the answer is n + 1
    return n + 1;
}

int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << "Smallest missing positive number is: " << findSmallestMissingPositive(arr) << endl;

    arr = {5, 3, 2, 5, 1};
    cout << "Smallest missing positive number is: " << findSmallestMissingPositive(arr) << endl;

    arr = {-8, 0, -1, -4, -3};
    cout << "Smallest missing positive number is: " << findSmallestMissingPositive(arr) << endl;

    return 0;
}
