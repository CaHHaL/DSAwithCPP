// Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.

// Examples:

// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
// Output: true
// Explanation: arr[3] + arr[4] = 6 + 10 = 16.
// Input: arr[] = [1, 2, 4, 3, 6], target = 11
// Output: false
// Explanation: None of the pair makes a sum of 11.
// Input: arr[] = [11], target = 11
// Output: false
// Explanation: No pair is possible as only one element is present in arr[].

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool twoSum(std::vector<int> &arr, int target)
    {
        std::unordered_set<int> seen; // Hash set to store visited elements
        for (int num : arr)
        {
            int complement = target - num; // Calculate the complement
            if (seen.find(complement) != seen.end())
            {
                return true; // Found a pair whose sum is equal to target
            }
            seen.insert(num); // Add current number to the set
        }
        return false; // No such pair exists
    }
};

int main()
{
    Solution solution;

    std::vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int target1 = 16;
    std::cout << (solution.twoSum(arr1, target1) ? "true" : "false") << std::endl;

    std::vector<int> arr2 = {1, 2, 4, 3, 6};
    int target2 = 11;
    std::cout << (solution.twoSum(arr2, target2) ? "true" : "false") << std::endl;

    std::vector<int> arr3 = {11};
    int target3 = 11;
    std::cout << (solution.twoSum(arr3, target3) ? "true" : "false") << std::endl;

    return 0;
}
