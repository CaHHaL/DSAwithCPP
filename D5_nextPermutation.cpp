// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

// Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

// Examples:

// Input: arr = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
// Input: arr = [3, 2, 1]
// Output: [1, 2, 3]
// Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
// Input: arr = [3, 4, 2, 5, 1]
// Output: [3, 4, 5, 1, 2]
// Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105



#include <iostream>
#include <vector>
#include <algorithm>

class NextPermutation {
public:
    void getNextPermutation(std::vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (arr[j] <= arr[i]) {
                j--;
            }
            std::swap(arr[i], arr[j]);
        }
        std::reverse(arr.begin() + i + 1, arr.end());
    }
    void printArray(const std::vector<int>& arr) {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    NextPermutation np;
    std::vector<int> arr1 = {2, 4, 1, 7, 5, 0};
    std::cout << "Original: ";
    np.printArray(arr1);
    np.getNextPermutation(arr1);
    std::cout << "Next Permutation: ";
    np.printArray(arr1);
    std::vector<int> arr2 = {3, 2, 1};
    std::cout << "Original: ";
    np.printArray(arr2);
    np.getNextPermutation(arr2);
    std::cout << "Next Permutation: ";
    np.printArray(arr2);
    std::vector<int> arr3 = {3, 4, 2, 5, 1};
    std::cout << "Original: ";
    np.printArray(arr3);
    np.getNextPermutation(arr3);
    std::cout << "Next Permutation: ";
    np.printArray(arr3);

    return 0;
}
