// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Examples:

// Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
// Output: 6
// Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
// Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
// Output: 4
// Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
// Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
// Output: 7
// Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to return the length of the longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        // Step 1: Insert all elements into a set for quick lookup.
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLength = 0;

        // Step 2: Iterate through each number in the array
        for (int num : arr)
        {
            // Step 3: Check if it's the start of a new subsequence
            if (numSet.find(num - 1) == numSet.end())
            { // num - 1 not in set
                int currentNum = num;
                int currentStreak = 1;

                // Step 4: Count the length of the subsequence starting from 'num'
                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum++;
                    currentStreak++;
                }

                // Step 5: Update maxLength with the longest streak found
                maxLength = max(maxLength, currentStreak);
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {2, 6, 1, 9, 4, 5, 3};
    cout << "Length of longest consecutive subsequence: " << sol.longestConsecutive(arr1) << endl;

    vector<int> arr2 = {1, 9, 3, 10, 4, 20, 2};
    cout << "Length of longest consecutive subsequence: " << sol.longestConsecutive(arr2) << endl;

    vector<int> arr3 = {15, 13, 12, 14, 11, 10, 9};
    cout << "Length of longest consecutive subsequence: " << sol.longestConsecutive(arr3) << endl;

    return 0;
}
