// Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

// Examples:

// Input: arr = [10, 2, -2, -20, 10], k = -10
// Output: 3
// Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
// Input: arr = [9, 4, 20, 3, 10, 5], k = 33
// Output: 2
// Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
// Input: arr = [1, 3, 5], k = 0
// Output: 0
// Explaination: No subarray with 0 sum.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> prefixSumMap; // Stores frequency of prefix sums
        int currentSum = 0;                   // Current sum while traversing the array
        int count = 0;                        // Count of subarrays with sum equal to k

        prefixSumMap[0] = 1; // Base case: There's one way to have a sum of 0 (empty subarray)

        // Traverse the array and calculate the prefix sum
        for (int num : arr)
        {
            currentSum += num; // Update the current sum

            // Check if currentSum - k exists in the map, which means there is a subarray with sum k
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end())
            {
                count += prefixSumMap[currentSum - k]; // Add the frequency of the previous sum
            }

            // Update the map with the current prefix sum
            prefixSumMap[currentSum]++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> arr1 = {10, 2, -2, -20, 10};
    int k1 = -10;
    cout << "Count of subarrays with sum " << k1 << " is: "
         << sol.countSubarrays(arr1, k1) << endl;

    // Test case 2
    vector<int> arr2 = {9, 4, 20, 3, 10, 5};
    int k2 = 33;
    cout << "Count of subarrays with sum " << k2 << " is: "
         << sol.countSubarrays(arr2, k2) << endl;

    // Test case 3
    vector<int> arr3 = {1, 3, 5};
    int k3 = 0;
    cout << "Count of subarrays with sum " << k3 << " is: "
         << sol.countSubarrays(arr3, k3) << endl;

    return 0;
}
