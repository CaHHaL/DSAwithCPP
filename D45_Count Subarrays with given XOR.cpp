// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

// Examples:

// Input: arr[] = [4, 2, 2, 6, 4], k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
// Input: arr[] = [5, 6, 7, 8, 9], k = 5
// Output: 2
// Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
// Input: arr[] = [1, 1, 1, 1], k = 0
// Output: 4
// Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // Map to store frequency of prefix XORs
        unordered_map<int, int> prefixXorCount;

        // Initializing with the prefix XOR of 0
        prefixXorCount[0] = 1;

        int currentXor = 0;
        long count = 0;

        // Iterate over the array to calculate prefix XOR and count the valid subarrays
        for (int i = 0; i < arr.size(); ++i)
        {
            // Update the current prefix XOR
            currentXor ^= arr[i];

            // Check if there is a prefix XOR that satisfies the condition
            if (prefixXorCount.find(currentXor ^ k) != prefixXorCount.end())
            {
                count += prefixXorCount[currentXor ^ k];
            }

            // Update the map with the current prefix XOR
            prefixXorCount[currentXor]++;
        }

        return count;
    }
};

// Example usage:
int main()
{
    Solution solution;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << solution.subarrayXor(arr, k) << endl; // Output: 4

    vector<int> arr2 = {5, 6, 7, 8, 9};
    int k2 = 5;

    cout << solution.subarrayXor(arr2, k2) << endl; // Output: 2

    vector<int> arr3 = {1, 1, 1, 1};
    int k3 = 0;

    cout << solution.subarrayXor(arr3, k3) << endl; // Output: 4

    return 0;
}
