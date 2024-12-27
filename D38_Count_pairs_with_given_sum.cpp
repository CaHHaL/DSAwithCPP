// Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

// Examples:

// Input: arr[] = [1, 5, 7, -1, 5], target = 6
// Output: 3
// Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5).
// Input: arr[] = [1, 1, 1, 1], target = 2
// Output: 6
// Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
// Input: arr[] = [10, 12, 10, 15, -1], target = 125
// Output: 0
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        unordered_map<int, int> freqMap; // To store frequencies of elements
        int count = 0;

        // Traverse the array
        for (int num : arr)
        {
            // Check if the complement (target - num) exists in the map
            int complement = target - num;
            if (freqMap.find(complement) != freqMap.end())
            {
                count += freqMap[complement]; // Add the frequency of the complement
            }

            // Now increment the frequency of the current element
            freqMap[num]++;
        }

        return count;
    }
};
