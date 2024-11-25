// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: no candidate occur more than n/3 times.
// Constraint:
// 1 <= arr.size() <= 106
// -109 <= arr[i] <= 109

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

std::vector<int> findMajority(std::vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: Find two potential candidates using Boyer-Moore Voting Algorithm
    int candidate1 = INT_MIN, candidate2 = INT_MIN;
    int count1 = 0, count2 = 0;
    
    for (int num : arr) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Count the occurrences of candidate1 and candidate2
    count1 = 0, count2 = 0;
    for (int num : arr) {
        if (num == candidate1) count1++;
        if (num == candidate2) count2++;
    }

    // Step 3: Collect the result if they appear more than n/3 times
    std::vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    // Step 4: Sort the result to return in increasing order
    std::sort(result.begin(), result.end());
    
    return result;
}

int main() {
    // Example 1
    std::vector<int> arr1 = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    std::vector<int> result1 = findMajority(arr1);
    for (int num : result1) std::cout << num << " ";  // Output: 5 6
    std::cout << std::endl;

    // Example 2
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::vector<int> result2 = findMajority(arr2);
    if (result2.empty()) std::cout << "[]";  // Output: []
    
    return 0;
}
